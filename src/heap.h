//
// Created by alanpark on 18. 10. 14.
//

#ifndef MLDSA_CPP_HEAP_H
#define MLDSA_CPP_HEAP_H

#include <vector>
#include <iostream>
#include <memory>

template<class T>
class heap {
    std::vector<T> array;
    bool min_heap;
public:
    explicit heap(const bool& min_heap=true )
    : min_heap(min_heap) {}

    static std::shared_ptr<heap<T>> heapify(const std::vector<T>& data_array, bool min_heap=true) {
        auto heap1=std::make_shared<heap<int>>(min_heap);
        for(const T& item : data_array){
            heap1->insert(item);
        }
        return heap1;
    }

    static std::shared_ptr<heap<T>> merge(const heap<T>& heap1, const heap<T>& heap2){
        if(heap1.min_heap != heap2.min_heap) {
            throw std::exception();
        }
        std::vector<T> array_all;
        array_all.insert(array_all.end(), heap1.array.begin(), heap1.array.end());
        array_all.insert(array_all.end(), heap2.array.begin(), heap2.array.end());
        return heapify(array_all, heap1.min_heap);
    }

#define PARENT_INDEX(n) (((n)-1)/2)
    void insert(const T& data) {
        array.push_back(data);
        auto current_index = array.size()-1;
        if( current_index == 0 ) {
            return;
        }
        auto index = PARENT_INDEX(current_index);
        while( min_heap ?  (array[index] > array[current_index]) : (array[index] < array[current_index]) ) {
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


#define LEFT_CHILD(n) ((2*(n)+1))
#define RIGHT_CHILD(n) ((2*(n)+2))
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

#define HEAP_REMOVE_LOOP(ARRAY, INDEX, INDEX_LEFT_CHILD, INDEX_RIGHT_CHILD, OP) {\
while( (INDEX_LEFT_CHILD) < (ARRAY).size() and ( (ARRAY)[(INDEX_LEFT_CHILD)] OP (ARRAY)[(INDEX)] or (ARRAY)[(INDEX_RIGHT_CHILD)] OP (ARRAY)[(INDEX)] ) ) {\
    if ( (INDEX_RIGHT_CHILD) >= (ARRAY).size() ) { \
        if( (ARRAY)[(INDEX_LEFT_CHILD)] OP (ARRAY)[(INDEX)]  ) { \
            std::swap( (ARRAY)[(INDEX)], (ARRAY)[(INDEX_LEFT_CHILD)] ); \
        } \
        break; \
    } \
    if( (ARRAY)[(INDEX_LEFT_CHILD)] OP (ARRAY)[(INDEX_RIGHT_CHILD)] ) { \
        std::swap((ARRAY)[(INDEX_LEFT_CHILD)], (ARRAY)[(INDEX)]); \
        (INDEX)=(INDEX_LEFT_CHILD); \
    } else { \
        std::swap((ARRAY)[(INDEX_RIGHT_CHILD)], (ARRAY)[(INDEX)]); \
        (INDEX)=(INDEX_RIGHT_CHILD); \
    } \
    (INDEX_LEFT_CHILD) = LEFT_CHILD((INDEX)); \
    (INDEX_RIGHT_CHILD) = RIGHT_CHILD((INDEX)); \
} \
}
    void replace(const T& data) {
        if( array.size() == 0 ) {
            throw std::exception();
        }
        array[0]=data;
        auto current_index = 0;
        auto left_child_index = LEFT_CHILD(current_index);
        auto right_child_index = RIGHT_CHILD(current_index);
        if(min_heap)
        {
            HEAP_REMOVE_LOOP(array, current_index, left_child_index, right_child_index, <);
        } else {
            HEAP_REMOVE_LOOP(array, current_index, left_child_index, right_child_index, >);
        }
    }
};

#endif //MLDSA_CPP_HEAP_H
