//
// Created by alanpark on 18. 10. 14.
//

#ifndef MLDSA_CPP_HEAP_H
#define MLDSA_CPP_HEAP_H

#include <vector>
#include <iostream>
#include <memory>

inline size_t LeftChild( size_t n ) {
    return 2*n+1;
}

inline size_t RightChild( size_t n ) {
    return 2*n+2;
}

inline int ParentIndex(const int n) {
    return (((n)-1)/2);
}

template<class T, class Compare = std::less<>>
class Heap {
private:
    std::vector<T> array;
protected:
    static void HeapifyLoop(std::vector<T> &array, const size_t begin_index, const size_t end_index) {
        Compare compare;
        auto index = begin_index;
        auto index_left_child = LeftChild(index);
        auto index_right_child = RightChild(index);
        while (index_left_child < end_index and
               ( compare(array[index_left_child], array[index])
                 or compare(array[index_right_child], array[index] ) ) ) {
            if (index_right_child >= end_index) {
                if ( compare(array[index_left_child], array[index])  ) {
                    std::swap(array[index], array[index_left_child]);
                }
                break;
            }

            if ( compare(array[index_left_child], array[index_right_child]) ) {
                std::swap(array[index_left_child], array[index]);
                index = index_left_child;
            } else {
                std::swap(array[index_right_child], array[index]);
                index = index_right_child;
            }
            index_left_child = LeftChild(index);
            index_right_child = RightChild(index);
        }
    }
public:
    Heap() = default;

    static std::shared_ptr<Heap<T, Compare>> Heapify(const std::vector<T> &data_array) {
        auto heap1=std::make_shared<Heap<T, Compare>>();
        for(const T& item : data_array){
            heap1->Insert(item);
        }
        return heap1;
    }

    static std::shared_ptr<Heap<T, Compare>> Merge(const Heap<T, Compare>& heap1, const Heap<T, Compare>& heap2){
        std::vector<T> array_all;
        array_all.insert(array_all.end(), heap1.array.begin(), heap1.array.end());
        array_all.insert(array_all.end(), heap2.array.begin(), heap2.array.end());
        return Heapify(array_all);
    }
    
    void Insert(const T &data) {
        Compare compare;
        array.push_back(data);
        auto current_index = array.size()-1;
        if( current_index == 0 ) {
            return;
        }
        auto index = ParentIndex(current_index);
        while( compare( array[current_index], array[index] ) ) {
            std::swap(array[index], array[current_index]);
            current_index = index;
            if(current_index<=0) { break; }
            index = ParentIndex(current_index);
        }
    }

    size_t size() const {
        return array.size();
    }

    bool empty() const {
        return array.empty();
    }

    T FindTop() const {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        return array[0];
    }

    T ExtractTop() {
        if( array.size() == 0 ) {
            throw std::exception();
        }

        auto ret_val=array[0];
        DeleteTop();
        return ret_val;
    }

    void DeleteTop() {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        auto data=array[array.size()-1];
        array.resize(array.size()-1);
        if(!empty()) {
            Replace(data);
        }
    }


    void Replace(const T &data) {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        array[0]=data;
        HeapifyLoop(array, 0, array.size());
    }

    static void Sort(std::vector<T> &array_to_sort){
        const auto array_size=(int)array_to_sort.size();
        for (auto i = array_size/2;i>=0;i--){
            HeapifyLoop(array_to_sort, (size_t) i, (size_t) array_size);
        }

        for ( auto max_index = array_size-1; max_index > 0; max_index -- ){
            std::swap(array_to_sort[max_index], array_to_sort[0]);
            HeapifyLoop(array_to_sort, 0, (size_t) max_index);
        }
    }
};

#endif //MLDSA_CPP_HEAP_H
