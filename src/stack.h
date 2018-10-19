//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_STACK_H
#define MLDSA_CPP_STACK_H

#include "linkedlist.h"

template <class T>
class Stack {
    LinkedList<T> m_list;
public:
    typedef std::shared_ptr<Stack<T>> Stack_;
    Stack() = default;

    static Stack_ Create() {
        return std::make_shared<Stack<T>>();
    }

    void Push(const T& data) {m_list.PushBack(data);}
    T Pop() { if(empty()) throw std::exception(); const auto ret_val=m_list.Back(); m_list.PopBack(); return ret_val;}
    size_t size() const { return m_list.size(); }
    bool empty() const { return m_list.empty(); }
};

#endif //MLDSA_CPP_STACK_H
