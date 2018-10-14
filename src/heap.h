//
// Created by alanpark on 18. 10. 14.
//

#ifndef MLDSA_CPP_HEAP_H
#define MLDSA_CPP_HEAP_H

#include <vector>
#include <iostream>
#include <memory>

#define LEFT_CHILD(n) ((2*(n)+1))
#define RIGHT_CHILD(n) ((2*(n)+2))

template<class T, class Compare = std::less<>>
class heap {
private:
    std::vector<T> array;
protected:
    static void heapify_loop(std::vector<T>& array, const size_t begin_index, const size_t end_index) {
        Compare compare;
        auto index = begin_index;
        auto index_left_child = LEFT_CHILD(index);
        auto index_right_child = RIGHT_CHILD(index);
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
            index_left_child = LEFT_CHILD(index);
            index_right_child = RIGHT_CHILD(index);
        }
    }
public:
    heap() = default;

    static std::shared_ptr<heap<T, Compare>> heapify(const std::vector<T>& data_array) {
        auto heap1=std::make_shared<heap<T, Compare>>();
        for(const T& item : data_array){
            heap1->insert(item);
        }
        return heap1;
    }

    static std::shared_ptr<heap<T, Compare>> merge(const heap<T, Compare>& heap1, const heap<T, Compare>& heap2){
        std::vector<T> array_all;
        array_all.insert(array_all.end(), heap1.array.begin(), heap1.array.end());
        array_all.insert(array_all.end(), heap2.array.begin(), heap2.array.end());
        return heapify(array_all);
    }

#define PARENT_INDEX(n) (((n)-1)/2)
    void insert(const T& data) {
        Compare compare;
        array.push_back(data);
        auto current_index = array.size()-1;
        if( current_index == 0 ) {
            return;
        }
        auto index = PARENT_INDEX(current_index);
        while( compare( array[current_index], array[index] ) ) {
            std::swap(array[index], array[current_index]);
            current_index = index;
            if(current_index<=0) { break; }
            index = PARENT_INDEX(current_index);
        }
    }

    size_t size() const {
        return array.size();
    }

    bool empty() const {
        return array.empty();
    }

    T find_top() const {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        return array[0];
    }

    T extract_top() {
        if( array.size() == 0 ) {
            throw std::exception();
        }

        auto ret_val=array[0];
        delete_top();
        return ret_val;
    }

    void delete_top() {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        auto data=array[array.size()-1];
        array.resize(array.size()-1);
        if(!empty()) {
            replace(data);
        }
    }


    void replace(const T& data) {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        array[0]=data;
        heapify_loop(array, 0, array.size());
    }

    static void sort(std::vector<T>& array_to_sort){
        const auto array_size=(int)array_to_sort.size();
        for (auto i = array_size/2;i>=0;i--){
            heapify_loop(array_to_sort, i, array_size);
        }

        for ( auto max_index = array_size-1; max_index > 0; max_index -- ){
            std::swap(array_to_sort[max_index], array_to_sort[0]);
            heapify_loop(array_to_sort, 0, max_index);
        }
    }
};

#endif //MLDSA_CPP_HEAP_H
