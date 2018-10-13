//
// Created by alanpark on 18. 10. 13.
//

#include "queue.h"
#include "gtest/gtest.h"

template<class T>
bool queue<T>::dequeue(T& data) {
    if(m_list.empty()) { return false; }
    else { data=m_list.pop_front(); return true;}
}

template<class T>
void queue<T>::enqueue(const T& data) { m_list.push_back(data);}

template<class T>
bool queue<T>::empty() const { return m_list.empty(); }

template<class T>
int queue<T>::size() const { return m_list.size(); }

TEST(queue, enqueue_one) {
    queue<int> queTest;
    queTest.enqueue(3);
    ASSERT_EQ(queTest.size(), 1);
}

TEST(queue, enqueue_two) {
    queue<int> queTest;
    queTest.enqueue(3);
    queTest.enqueue(5);
    ASSERT_EQ(queTest.size(), 2);
}