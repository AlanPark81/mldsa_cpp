//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_QUEUE_H
#define MLDSA_CPP_QUEUE_H


#include "linkedlist.h"

template<class T>
class Queue {
    LinkedList<T> m_list;
public:
    Queue() = default;

    T Dequeue() {
        if(m_list.empty()) { throw std::exception(); }
        T ret_val=m_list.Front(); m_list.PopFront(); return ret_val;
    }

    void Enqueue(const T &data) { m_list.PushBack(data);}
    bool empty() const { return m_list.empty(); }
    size_t size() const { return m_list.size(); }
};


#endif //MLDSA_CPP_QUEUE_H
