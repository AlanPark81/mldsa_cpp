//
// Created by alanp on 19/04/2019.
//

#ifndef MLDSA_CPP_ARRAY_H
#define MLDSA_CPP_ARRAY_H

#include <cstddef>

typedef enum {
    FAIL,
    SUCCESS
} Result;

typedef enum {
    None,
    Some
} Exist;

template <class T>
struct Option {
    Exist option_;
    T val_;
public:
    Option() : option_(None) {}
    Option(const T& data) : option_(Some), val_(data) {}
    const Option& operator= (const T& data) {
        option_ = Some;
        val_ = data;
        return *this;
    }
};

template<class T, size_t size>
class Array {
    Option<T> inner_array_[size];
public:
    Array() = default;

    Option<T> get(const int index) const {
        if (index >= size || index < 0) return Option<T>();
        return inner_array_[index];
    }

    Result set(const int index, const T& data) {
        if (index >= size || index < 0) return FAIL;
        inner_array_[index] = data;
        return SUCCESS;
    }
};
#endif //MLDSA_CPP_ARRAY_H
