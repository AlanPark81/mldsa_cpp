//
// Created by alanpark on 18. 11. 6.
//

#pragma once

#include <cstddef>
#include <vector>
#include <string>

using namespace std;

template<class T>
size_t binary_search( const vector<T>& array, const T& key) {
    auto begin = array.begin();
    auto end = array.end();
    while(end > begin) {
        const auto mid = begin + (end - begin)/2;
        if ( *mid == key ){
            return mid-array.begin();
        } else if( *mid > key ) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    throw exception();
}

template<class InputIterator, class T>
InputIterator UpperBound(InputIterator begin, InputIterator end, T target) {
    int count = end - begin;
    while (count > 0) {
        const int step = count / 2;
        auto it = begin + step;
        if (*it <= target) {
            begin = it + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return begin;
}

template<class Iterator, class T>
Iterator LowerBound(Iterator begin, Iterator end, T target) {
    int count = end - begin;
    while(count > 0){
        const int step = count / 2;
        auto it = begin + step;
        if (*it < target) {
            begin = it + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return begin;
}