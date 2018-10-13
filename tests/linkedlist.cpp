//
// Created by alanpark on 18. 10. 13.
//

#include "../src/linkedlist.h"

#include "gtest/gtest.h"

inline void push_back_pop_back_test(const auto count) {
    linkedlist<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.push_back(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.pop_back());
        ASSERT_EQ(nRet, count-1-i);
    }
    ASSERT_ANY_THROW(linkedlist1.pop_back());
}

inline void push_front_pop_front_test(const auto count) {
    linkedlist<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.push_front(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.pop_front());
        ASSERT_EQ(nRet, count-1-i);
    }
    ASSERT_ANY_THROW(linkedlist1.pop_front());
}

inline void push_back_pop_front_test(const auto count) {
    linkedlist<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.push_back(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.pop_front());
        ASSERT_EQ(nRet, i);
    }
    ASSERT_ANY_THROW(linkedlist1.pop_front());
}


inline void push_front_pop_back_test(const auto count) {
    linkedlist<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.push_back(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.pop_front());
        ASSERT_EQ(nRet, i);
    }
    ASSERT_ANY_THROW(linkedlist1.pop_front());
}

TEST(linkedlist, zero_item_push_back) {
    push_back_pop_back_test(0);
}

TEST(linkedlist, one_item_push_back) {
    push_back_pop_back_test(1);
}

TEST(linkedlist, two_item_push_back) {
    push_back_pop_back_test(2);
}

TEST(linkedlist, three_item_push_back) {
    push_back_pop_back_test(3);
}

TEST(linkedlist, zero_item_push_front) {
    push_front_pop_front_test(0);
}

TEST(linkedlist, one_item_push_front) {
    push_front_pop_front_test(1);
}

TEST(linkedlist, two_item_push_front) {
    push_front_pop_front_test(2);
}

TEST(linkedlist, three_item_push_front) {
    push_front_pop_front_test(3);
}

TEST(linkedlist, zero_item_push_back_pop_front) {
    push_back_pop_front_test(0);
}

TEST(linkedlist, one_item_push_back_pop_front) {
    push_back_pop_front_test(1);
}

TEST(linkedlist, two_item_push_back_pop_front) {
    push_back_pop_front_test(2);
}

TEST(linkedlist, three_item_push_back_pop_front) {
    push_back_pop_front_test(3);
}

TEST(linkedlist, zero_item_push_front_pop_back) {
    push_front_pop_back_test(0);
}

TEST(linkedlist, one_item_push_front_pop_back) {
    push_front_pop_back_test(1);
}

TEST(linkedlist, two_item_push_front_pop_back) {
    push_front_pop_back_test(2);
}

TEST(linkedlist, three_item_push_front_pop_back) {
    push_front_pop_back_test(3);
}