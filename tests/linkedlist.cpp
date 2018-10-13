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

void forward_iteration_items(const size_t count) {
    linkedlist<int> listTest;
    ASSERT_EQ(listTest.size(), 0);
    ASSERT_TRUE(listTest.empty());
    for(int i=0;i<count;i++) {
        listTest.push_back(i);
        ASSERT_EQ(listTest.back(), i);
        ASSERT_EQ(listTest.front(), 0);
        ASSERT_EQ(listTest.size(), i+1);
        ASSERT_FALSE(listTest.empty());
    }

    auto iterator=listTest.begin();
    ASSERT_EQ(listTest.size(), count);
    for(int i=0;i<count;i++)
    {
        ASSERT_TRUE(iterator.valid());
        ASSERT_EQ(iterator.next(), i);
    }

    ASSERT_FALSE(iterator.valid());
    ASSERT_ANY_THROW(iterator.next());
}

void backward_iteration_items(const size_t count) {
    linkedlist<int> listTest;
    ASSERT_EQ(listTest.size(), 0);
    ASSERT_TRUE(listTest.empty());
    for(int i=0;i<count;i++) {
        listTest.push_back(i);
        ASSERT_EQ(listTest.back(), i);
        ASSERT_EQ(listTest.front(), 0);
        ASSERT_EQ(listTest.size(), i+1);
        ASSERT_FALSE(listTest.empty());
    }

    auto iterator=listTest.end();
    for(int i=0;i<count;i++)
    {
        ASSERT_TRUE(iterator.valid());
        ASSERT_EQ(iterator.prev(), count-1-i);
    }

    ASSERT_FALSE(iterator.valid());
    ASSERT_ANY_THROW(iterator.prev());
}

TEST(linkedlist, one_item_iteration) {
    forward_iteration_items(1);
}

TEST(linkedlist, two_item_iteration) {
    forward_iteration_items(2);
}

TEST(linkedlist, three_item_iteration) {
    forward_iteration_items(3);
}

TEST(linkedlist, one_item_backward_iteration) {
    backward_iteration_items(1);
}

TEST(linkedlist, two_item_backward_iteration) {
    backward_iteration_items(2);
}

TEST(linkedlist, three_item_backward_iteration) {
    backward_iteration_items(3);
}

TEST(linkedlist, iterator_insert_after_one_item) {
    linkedlist<int> listTest;
    listTest.push_back(1);
    auto iter=listTest.begin();
    listTest.insert_after(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, iterator_insert_after_middle_of_two_item) {
    linkedlist<int> listTest;
    listTest.push_back(1);
    listTest.push_back(3);
    auto iter=listTest.begin();
    listTest.insert_after(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, iterator_insert_after_end_of_two_item) {
    linkedlist<int> listTest;
    listTest.push_back(1);
    listTest.push_back(2);
    auto iter=listTest.begin();
    iter.next();
    listTest.insert_after(iter, 3);
    iter = listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, iterator_insert_before_one_item) {
    linkedlist<int> listTest;
    listTest.push_back(2);
    auto iter=listTest.begin();
    listTest.insert_before(iter, 1);
    iter=listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, end_iterator_insert_after_one_item) {
    linkedlist<int> listTest;
    listTest.push_back(1);
    auto iter=listTest.end();
    listTest.insert_after(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, end_iterator_insert_after_middle_of_two_item) {
    linkedlist<int> listTest;
    listTest.push_back(1);
    listTest.push_back(3);
    auto iter=listTest.end();
    listTest.insert_before(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.prev(), listTest.size()-i);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, end_iterator_insert_after_end_of_two_item) {
    linkedlist<int> listTest;
    listTest.push_back(1);
    listTest.push_back(2);
    auto iter=listTest.end();
    listTest.insert_after(iter, 3);
    iter = listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}

TEST(linkedlist, end_iterator_insert_before_one_item) {
    linkedlist<int> listTest;
    listTest.push_back(2);
    auto iter=listTest.end();
    listTest.insert_before(iter, 1);
    iter=listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.next(), i+1);
    }
    ASSERT_ANY_THROW(iter.next());
}