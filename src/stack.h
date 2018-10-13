//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_STACK_H
#define MLDSA_CPP_STACK_H

#include "linkedlist.h"

template <class T>
class stack {
    linkedlist<T> m_list;
public:
    stack() = default;
    void push(const T& data) {m_list.push_back(data);}
    T pop() { if(empty()) throw std::exception(); const auto ret_val=m_list.back(); m_list.pop_back(); return ret_val;}
    size_t size() const { return m_list.size(); }
    bool empty() const { return m_list.empty(); }
};

#endif //MLDSA_CPP_STACK_H
