//
// Created by alanpark on 18. 10. 14.
//

#include "../src/heap.h"
#include "gtest/gtest.h"

TEST(heap, heap_insert_once) {
    heap<int> heapTest;
    heapTest.insert(3);
    ASSERT_EQ(heapTest.find_top(), 3);
}

TEST(heap, max_heap_insert_once) {
    heap<int> heapTest(false);
    heapTest.insert(3);
    ASSERT_EQ(heapTest.find_top(), 3);
}

TEST(heap, heap_insert_replace_once) {
    heap<int> heapTest;
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.replace(1);
    ASSERT_EQ(heapTest.find_top(), 1);
}

TEST(heap, max_heap_insert_replace_once) {
    heap<int> heapTest(false);
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.replace(5);
    ASSERT_EQ(heapTest.find_top(), 5);
}

TEST(heap, heap_insert_delete_once) {
    heap<int> heapTest;
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.delete_top();
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, max_heap_insert_delete_once) {
    heap<int> heapTest(false);
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.delete_top();
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, heap_insert_extract_once) {
    heap<int> heapTest;
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.extract_top(), 3);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, max_heap_insert_extract_once) {
    heap<int> heapTest(false);
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.extract_top(), 3);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}