//
// Created by alanp on 19/04/2019.
//

#ifndef MLDSA_CPP_COMMON_H
#define MLDSA_CPP_COMMON_H

typedef enum {
    FAIL,
    SUCCESS
} Result;

typedef enum {
    None,
    Some
} Exist;

template <class T>
class Option {
    Exist exist_;
    T val_;
public:
    Option() : exist_(None) {}
    explicit Option(const T& data) : exist_(Some), val_(data) {}
    Option& operator= (const T& data) {
        exist_ = Some;
        val_ = data;
        return *this;
    }

    bool operator== (const Option& option) const {
        return (option.exist_ == None && exist_ == None) || (option.val_ == val_ && option.exist_ == exist_);
    }

    bool operator== (const T& data) const {
        return exist_ == Some && val_ == data;
    }

    bool operator== (const Exist& input) const {
        return input == None && exist_ == None;
    }
};

#endif //MLDSA_CPP_COMMON_H
