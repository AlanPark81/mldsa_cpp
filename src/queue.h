//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_QUEUE_H
#define MLDSA_CPP_QUEUE_H


#include "linkedlist.h"

template<class T>
class queue {
    linkedlist<T> m_list;
public:
    queue() = default;

    T dequeue() {
        if(m_list.empty()) { throw std::exception(); }
        T ret_val=m_list.front(); m_list.pop_front(); return ret_val;
    }

    void enqueue(const T& data) { m_list.push_back(data);}
    bool empty() const { return m_list.empty(); }
    size_t size() const { return m_list.size(); }
};


#endif //MLDSA_CPP_QUEUE_H
