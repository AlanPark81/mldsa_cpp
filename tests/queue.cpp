//
// Created by alanpark on 18. 10. 13.
//

#include "../src/queue.h"
#include "gtest/gtest.h"

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

TEST(queue, dequeue_empty) {
    queue<int> queTest;
    ASSERT_TRUE(queTest.empty());
    int nRet;
    ASSERT_FALSE(queTest.dequeue(nRet));
    ASSERT_EQ(queTest.size(), 0);
}

TEST(queue, dequeue_one) {
    queue<int> queTest;
    queTest.enqueue(3);
    ASSERT_FALSE(queTest.empty());
    int nRet;
    ASSERT_TRUE(queTest.dequeue(nRet));
    ASSERT_EQ(nRet, 3);
    ASSERT_EQ(queTest.size(), 0);
    ASSERT_TRUE(queTest.empty());
}