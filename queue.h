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
    queue() = default;

    bool dequeue(T& data);
    void enqueue(const T& data);
    bool empty() const;
    size_t size() const;
};


#endif //MLDSA_CPP_QUEUE_H
