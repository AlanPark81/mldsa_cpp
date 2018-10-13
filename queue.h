//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_QUEUE_H
#define MLDSA_CPP_QUEUE_H

#include <list>

template<class T>
class queue {
    std::list<T> m_list;
public:
    queue() {}

    bool dequeue(T& data);
    void enqueue(const T& data);
    bool empty() const;
    int size() const;
};


#endif //MLDSA_CPP_QUEUE_H
