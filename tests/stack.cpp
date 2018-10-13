//
// Created by alanpark on 18. 10. 13.
//

#include "../src/stack.h"
#include "gtest/gtest.h"

inline void pop_test(const auto count) {
    stack<int> stackTest;
    ASSERT_TRUE(stackTest.empty());
    ASSERT_EQ(stackTest.size(), 0);
    for (int i=0;i<count; i++) {
        stackTest.push(i);
        ASSERT_FALSE(stackTest.empty());
        ASSERT_EQ(stackTest.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=stackTest.pop());
        ASSERT_EQ(nRet, count-1-i);
    }
    ASSERT_THROW(stackTest.pop(), std::exception);
}

TEST(stack, pop_from_empty_stack) {
    pop_test(0);
}

TEST(stack, pop_from_one_member_stack) {
    pop_test(1);
}

TEST(stack, pop_from_two_member_stack) {
    pop_test(2);
}

TEST(stack, pop_from_three_member_stack) {
    pop_test(3);
}