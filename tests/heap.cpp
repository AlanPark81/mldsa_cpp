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

TEST(heap, heap_insert_delete_twice) {
    heap<int> heapTest;
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.insert(4);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.delete_top();
    ASSERT_NO_THROW(heapTest.delete_top());
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, heap_insert_delete_three_times) {
    heap<int> heapTest;
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.insert(4);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.insert(5);
    ASSERT_EQ(heapTest.size(), 3);
    ASSERT_NO_THROW(heapTest.delete_top());
    ASSERT_EQ(heapTest.size(), 2);
    ASSERT_NO_THROW(heapTest.delete_top());
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_NO_THROW(heapTest.delete_top());
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

TEST(heap, heap_insert_extract_twice) {
    heap<int> heapTest;
    heapTest.insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.insert(2);
    ASSERT_EQ(heapTest.size(), 2);

    ASSERT_EQ(heapTest.extract_top(), 1);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.extract_top(), 2);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, max_heap_insert_extract_twice) {
    heap<int> heapTest(false);
    heapTest.insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.insert(2);
    ASSERT_EQ(heapTest.size(), 2);

    ASSERT_EQ(heapTest.extract_top(), 2);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.extract_top(), 1);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, heap_insert_extract_three_times) {
    heap<int> heapTest;
    heapTest.insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.insert(2);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 3);

    ASSERT_EQ(heapTest.extract_top(), 1);
    ASSERT_EQ(heapTest.size(), 2);
    ASSERT_EQ(heapTest.extract_top(), 2);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.extract_top(), 3);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, max_heap_insert_extract_three_times) {
    heap<int> heapTest(false);
    heapTest.insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.insert(2);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.insert(3);
    ASSERT_EQ(heapTest.size(), 3);

    ASSERT_EQ(heapTest.extract_top(), 3);
    ASSERT_EQ(heapTest.size(), 2);
    ASSERT_EQ(heapTest.extract_top(), 2);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.extract_top(), 1);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.find_top());
}

TEST(heap, heapify_test) {
    std::vector<int> array={3,1,4,2};
    auto heap1 = heap<int>::heapify(array);
    ASSERT_EQ(heap1->extract_top(), 1);
    ASSERT_EQ(heap1->extract_top(), 2);
    ASSERT_EQ(heap1->extract_top(), 3);
    ASSERT_EQ(heap1->extract_top(), 4);
    ASSERT_ANY_THROW(heap1->find_top());
}

TEST(heap, max_heapify_test) {
    std::vector<int> array={3,1,4,2};
    auto heap1 = heap<int>::heapify(array, false);
    ASSERT_EQ(heap1->extract_top(), 4);
    ASSERT_EQ(heap1->extract_top(), 3);
    ASSERT_EQ(heap1->extract_top(), 2);
    ASSERT_EQ(heap1->extract_top(), 1);
    ASSERT_ANY_THROW(heap1->find_top());
}

TEST(heap, min_union_test) {
    std::vector<int> array={6,2,0,4};
    auto heap1 = heap<int>::heapify(array, true);
    std::vector<int> array1={7,3,1,5};
    auto heap2 = heap<int>::heapify(array1, true);
    auto heap_merged=heap<int>::merge(*heap1, *heap2);

    ASSERT_EQ(heap_merged->extract_top(), 0);
    ASSERT_EQ(heap_merged->extract_top(), 1);
    ASSERT_EQ(heap_merged->extract_top(), 2);
    ASSERT_EQ(heap_merged->extract_top(), 3);
    ASSERT_EQ(heap_merged->extract_top(), 4);
    ASSERT_EQ(heap_merged->extract_top(), 5);
    ASSERT_EQ(heap_merged->extract_top(), 6);
    ASSERT_EQ(heap_merged->extract_top(), 7);

    ASSERT_ANY_THROW(heap_merged->find_top());
}

TEST(heap, max_union_test) {
    std::vector<int> array={6,2,0,4};
    auto heap1 = heap<int>::heapify(array, false);
    std::vector<int> array1={7,3,1,5};
    auto heap2 = heap<int>::heapify(array1, false);
    auto heap_merged=heap<int>::merge(*heap1, *heap2);
    ASSERT_EQ(heap_merged->extract_top(), 7);
    ASSERT_EQ(heap_merged->extract_top(), 6);
    ASSERT_EQ(heap_merged->extract_top(), 5);
    ASSERT_EQ(heap_merged->extract_top(), 4);
    ASSERT_EQ(heap_merged->extract_top(), 3);
    ASSERT_EQ(heap_merged->extract_top(), 2);
    ASSERT_EQ(heap_merged->extract_top(), 1);
    ASSERT_EQ(heap_merged->extract_top(), 0);
    ASSERT_ANY_THROW(heap_merged->find_top());
}

TEST(heap, heap_sort_test_one) {
    std::vector<int> array={1};
    heap<int>::sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array.size(),1);
}

TEST(heap, heap_sort_test_two) {
    std::vector<int> array={1,7};
    heap<int>::sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 7);
    ASSERT_EQ(array.size(),2);
}

TEST(heap, heap_sort_test_three) {
    std::vector<int> array={1,7,4};
    heap<int>::sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 4);
    ASSERT_EQ(array[2], 7);
    ASSERT_EQ(array.size(),3);
}

TEST(heap, heap_sort_test_four) {
    std::vector<int> array={1,7,4,6};
    heap<int>::sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 4);
    ASSERT_EQ(array[2], 6);
    ASSERT_EQ(array[3], 7);
    ASSERT_EQ(array.size(),4);
}

TEST(heap, heap_sort_test_five) {
    std::vector<int> array={1,7,4,6,5};
    heap<int>::sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 4);
    ASSERT_EQ(array[2], 5);
    ASSERT_EQ(array[3], 6);
    ASSERT_EQ(array[4], 7);
    ASSERT_EQ(array.size(),5);
}

TEST(heap, heap_sort_test) {
    std::vector<int> array={1,7,4,6,5,3};
    heap<int>::sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 3);
    ASSERT_EQ(array[2], 4);
    ASSERT_EQ(array[3], 5);
    ASSERT_EQ(array[4], 6);
    ASSERT_EQ(array[5], 7);
    ASSERT_EQ(array.size(),6);
}