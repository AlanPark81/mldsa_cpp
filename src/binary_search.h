//
// Created by alanpark on 18. 11. 6.
//

#pragma once

#include <cstddef>
#include <vector>
#include <string>

using namespace std;
//
//template<class T>
//size_t binary_search_index( const vector<T>& array, const T& key, const size_t begin , const size_t fin ) {
//    const auto mid = begin+(fin - begin)/2;
//    if(array[mid] == key) {
//        return mid;
//    } else {
//        if( begin == fin ) {
//            throw exception();
//        }
//        if(array[mid] > key) {
//            return binary_search_index(array, key, begin, mid);
//        } else {
//            return binary_search_index(array, key, mid+1, fin);
//        }
//    }
//}

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