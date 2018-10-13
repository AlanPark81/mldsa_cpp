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

    bool dequeue(T& data) {
        if(m_list.empty()) { return false; }
        else { data=m_list.front(); m_list.pop_front(); return true;}
    }
    void enqueue(const T& data) { m_list.push_back(data);}
    bool empty() const { return m_list.empty(); }
    size_t size() const { return m_list.size(); }
};


#endif //MLDSA_CPP_QUEUE_H
