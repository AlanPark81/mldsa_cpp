//
// Created by alanpark on 18. 10. 13.
//

#include "../src/queue.h"
#include "gtest/gtest.h"

TEST(Queue, enqueue_one) {
    Queue<int> queTest;
    queTest.Enqueue(3);
    ASSERT_EQ(queTest.size(), 1);
}

TEST(Queue, enqueue_two) {
    Queue<int> queTest;
    queTest.Enqueue(3);
    queTest.Enqueue(5);
    ASSERT_EQ(queTest.size(), 2);
}

TEST(Queue, dequeue_empty) {
    Queue<int> queTest;
    ASSERT_TRUE(queTest.empty());
    ASSERT_ANY_THROW(queTest.Dequeue());
    ASSERT_EQ(queTest.size(), 0);
}

TEST(Queue, dequeue_one) {
    Queue<int> queTest;
    queTest.Enqueue(3);
    ASSERT_FALSE(queTest.empty());
    int nRet=-1;
    ASSERT_NO_THROW(nRet= queTest.Dequeue());
    ASSERT_EQ(nRet, 3);
    ASSERT_EQ(queTest.size(), 0);
    ASSERT_TRUE(queTest.empty());
}