//
// Created by alanpark on 18. 10. 14.
//

#include "../src/heap.h"
#include "gtest/gtest.h"

TEST(Heap, heap_insert_once) {
    Heap<int> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.FindTop(), 3);
}

TEST(Heap, max_heap_insert_once) {
    Heap<int, std::greater<>> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.FindTop(), 3);
}


TEST(Heap, heap_insert_lots) {
    Heap<int> heapTest;
    for(int i = 0; i < 100; i++) heapTest.Insert(i);
    heapTest.Insert(5);
    ASSERT_EQ(heapTest.FindTop(), 0);
}

TEST(Heap, heap_insert_replace_once) {
    Heap<int> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Replace(1);
    ASSERT_EQ(heapTest.FindTop(), 1);
}

TEST(Heap, max_heap_insert_replace_once) {
    Heap<int, std::greater<>> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Replace(5);
    ASSERT_EQ(heapTest.FindTop(), 5);
}

TEST(Heap, heap_delete_from_empty) {
    Heap<int> heapTest;
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_ANY_THROW(heapTest.DeleteTop());
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.ExtractTop());
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.Replace(3));
}

TEST(Heap, heap_insert_delete_once) {
    Heap<int> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.DeleteTop();
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, heap_insert_delete_twice) {
    Heap<int> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Insert(4);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.DeleteTop();
    ASSERT_NO_THROW(heapTest.DeleteTop());
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, heap_insert_delete_three_times) {
    Heap<int> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Insert(4);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.Insert(5);
    ASSERT_EQ(heapTest.size(), 3);
    ASSERT_NO_THROW(heapTest.DeleteTop());
    ASSERT_EQ(heapTest.size(), 2);
    ASSERT_NO_THROW(heapTest.DeleteTop());
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_NO_THROW(heapTest.DeleteTop());
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, max_heap_insert_delete_once) {
    Heap<int, std::greater<>> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.DeleteTop();
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, heap_insert_extract_once) {
    Heap<int> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.ExtractTop(), 3);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, max_heap_insert_extract_once) {
    Heap<int, std::greater<>> heapTest;
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.ExtractTop(), 3);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, heap_insert_extract_twice) {
    Heap<int> heapTest;
    heapTest.Insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Insert(2);
    ASSERT_EQ(heapTest.size(), 2);

    ASSERT_EQ(heapTest.ExtractTop(), 1);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.ExtractTop(), 2);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, max_heap_insert_extract_twice) {
    Heap<int, std::greater<>> heapTest;
    heapTest.Insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Insert(2);
    ASSERT_EQ(heapTest.size(), 2);

    ASSERT_EQ(heapTest.ExtractTop(), 2);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.ExtractTop(), 1);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, heap_insert_extract_three_times) {
    Heap<int> heapTest;
    heapTest.Insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Insert(2);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 3);

    ASSERT_EQ(heapTest.ExtractTop(), 1);
    ASSERT_EQ(heapTest.size(), 2);
    ASSERT_EQ(heapTest.ExtractTop(), 2);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.ExtractTop(), 3);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, max_heap_insert_extract_three_times) {
    Heap<int, std::greater<>> heapTest;
    heapTest.Insert(1);
    ASSERT_EQ(heapTest.size(), 1);
    heapTest.Insert(2);
    ASSERT_EQ(heapTest.size(), 2);
    heapTest.Insert(3);
    ASSERT_EQ(heapTest.size(), 3);

    ASSERT_EQ(heapTest.ExtractTop(), 3);
    ASSERT_EQ(heapTest.size(), 2);
    ASSERT_EQ(heapTest.ExtractTop(), 2);
    ASSERT_EQ(heapTest.size(), 1);
    ASSERT_EQ(heapTest.ExtractTop(), 1);
    ASSERT_EQ(heapTest.size(), 0);
    ASSERT_TRUE(heapTest.empty());
    ASSERT_ANY_THROW(heapTest.FindTop());
}

TEST(Heap, heapify_test) {
    std::vector<int> array={3,1,4,2};
    auto heap1 = Heap<int>::Heapify(array);
    ASSERT_EQ(heap1->ExtractTop(), 1);
    ASSERT_EQ(heap1->ExtractTop(), 2);
    ASSERT_EQ(heap1->ExtractTop(), 3);
    ASSERT_EQ(heap1->ExtractTop(), 4);
    ASSERT_ANY_THROW(heap1->FindTop());
}

TEST(Heap, max_heapify_test) {
    std::vector<int> array={3,1,4,2};
    auto heap1 = Heap<int, std::greater<>>::Heapify(array);
    ASSERT_EQ(heap1->ExtractTop(), 4);
    ASSERT_EQ(heap1->ExtractTop(), 3);
    ASSERT_EQ(heap1->ExtractTop(), 2);
    ASSERT_EQ(heap1->ExtractTop(), 1);
    ASSERT_ANY_THROW(heap1->FindTop());
}

TEST(Heap, min_union_test) {
    std::vector<int> array={6,2,0,4};
    auto heap1 = Heap<int>::Heapify(array);
    std::vector<int> array1={7,3,1,5};
    auto heap2 = Heap<int>::Heapify(array1);
    auto heap_merged=Heap<int>::Merge(*heap1, *heap2);

    ASSERT_EQ(heap_merged->ExtractTop(), 0);
    ASSERT_EQ(heap_merged->ExtractTop(), 1);
    ASSERT_EQ(heap_merged->ExtractTop(), 2);
    ASSERT_EQ(heap_merged->ExtractTop(), 3);
    ASSERT_EQ(heap_merged->ExtractTop(), 4);
    ASSERT_EQ(heap_merged->ExtractTop(), 5);
    ASSERT_EQ(heap_merged->ExtractTop(), 6);
    ASSERT_EQ(heap_merged->ExtractTop(), 7);

    ASSERT_ANY_THROW(heap_merged->FindTop());
}

TEST(Heap, max_union_test) {
    std::vector<int> array={6,2,0,4};
    auto heap1 = Heap<int, std::greater<>>::Heapify(array);
    std::vector<int> array1={7,3,1,5};
    auto heap2 = Heap<int, std::greater<>>::Heapify(array1);
    auto heap_merged=Heap<int, std::greater<>>::Merge(*heap1, *heap2);
    ASSERT_EQ(heap_merged->ExtractTop(), 7);
    ASSERT_EQ(heap_merged->ExtractTop(), 6);
    ASSERT_EQ(heap_merged->ExtractTop(), 5);
    ASSERT_EQ(heap_merged->ExtractTop(), 4);
    ASSERT_EQ(heap_merged->ExtractTop(), 3);
    ASSERT_EQ(heap_merged->ExtractTop(), 2);
    ASSERT_EQ(heap_merged->ExtractTop(), 1);
    ASSERT_EQ(heap_merged->ExtractTop(), 0);
    ASSERT_ANY_THROW(heap_merged->FindTop());
}

TEST(Heap, heap_sort_test_one) {
    std::vector<int> array={1};
    Heap<int, std::greater<>>::Sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array.size(),1);
}

TEST(Heap, heap_sort_test_two) {
    std::vector<int> array={1,7};
    Heap<int, std::greater<>>::Sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 7);
    ASSERT_EQ(array.size(),2);
}

TEST(Heap, heap_sort_test_three) {
    std::vector<int> array={1,7,4};
    Heap<int, std::greater<>>::Sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 4);
    ASSERT_EQ(array[2], 7);
    ASSERT_EQ(array.size(),3);
}

TEST(Heap, heap_sort_test_four) {
    std::vector<int> array={1,7,4,6};
    Heap<int, std::greater<>>::Sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 4);
    ASSERT_EQ(array[2], 6);
    ASSERT_EQ(array[3], 7);
    ASSERT_EQ(array.size(),4);
}

TEST(Heap, heap_sort_test_five) {
    std::vector<int> array={1,7,4,6,5};
    Heap<int, std::greater<>>::Sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 4);
    ASSERT_EQ(array[2], 5);
    ASSERT_EQ(array[3], 6);
    ASSERT_EQ(array[4], 7);
    ASSERT_EQ(array.size(),5);
}

TEST(Heap, heap_sort_test) {
    std::vector<int> array={1,7,4,6,5,3};
    Heap<int, std::greater<>>::Sort(array);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 3);
    ASSERT_EQ(array[2], 4);
    ASSERT_EQ(array[3], 5);
    ASSERT_EQ(array[4], 6);
    ASSERT_EQ(array[5], 7);
    ASSERT_EQ(array.size(),6);
}