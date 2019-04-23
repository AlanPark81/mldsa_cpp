//
// Created by alanp on 19/04/2019.
//

#ifndef MLDSA_CPP_ARRAY_H
#define MLDSA_CPP_ARRAY_H

#include <cstddef>
#include "common.h"

template<class T>
class Array {
    const size_t size_;
    Option<T>* inner_array_;
public:
    explicit Array(const size_t size) : size_(size) {
        inner_array_ = new Option<T>[size_];
    }

    virtual ~Array() {
        delete inner_array_;
    }
    Option<T> get(const size_t index) const {
        if (index >= size_ || index < 0) return Option<T>();
        return inner_array_[index];
    }

    Result set(const size_t index, const T& data) {
        if (index >= size_ || index < 0) return FAIL;
        inner_array_[index] = data;
        return SUCCESS;
    }
};
#endif //MLDSA_CPP_ARRAY_H
