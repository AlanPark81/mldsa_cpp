//
// Created by alanp on 05/02/2019.
//
#include <vector>
#include "./gtest/gtest.h"
#include "../src/sort.h"

TEST(QuickSort, zero_element) {
    std::vector<size_t> array;

    ASSERT_NO_FATAL_FAILURE(QuickSort(array.begin(), array.end()));
}

TEST(QuickSort, one_element) {
    std::vector<size_t> array{1};

    ASSERT_NO_FATAL_FAILURE(QuickSort(array.begin(), array.end()));
}

TEST(QuickSort, two_elements) {
    std::vector<size_t> array1{1, 2};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array1.begin(), array1.end()));
    std::vector<size_t> array2{2, 1};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array2.begin(), array2.end()));
    ASSERT_TRUE(std::is_sorted(array1.begin(), array1.end()));
    ASSERT_TRUE(std::is_sorted(array2.begin(), array2.end()));
}

TEST(QuickSort, three_elements) {
    std::vector<size_t> array1{1, 2, 3};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array1.begin(), array1.end()));
    std::vector<size_t> array2{2, 1, 3};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array2.begin(), array2.end()));
    std::vector<size_t> array3{3, 1, 2};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array3.begin(), array3.end()));
    std::vector<size_t> array4{3, 2, 1};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array4.begin(), array4.end()));
    std::vector<size_t> array5{1, 3, 2};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array5.begin(), array5.end()));
    std::vector<size_t> array6{2, 3, 1};
    ASSERT_NO_FATAL_FAILURE(QuickSort(array6.begin(), array6.end()));
    ASSERT_TRUE(std::is_sorted(array1.begin(), array1.end()));
    ASSERT_TRUE(std::is_sorted(array2.begin(), array2.end()));
    ASSERT_TRUE(std::is_sorted(array3.begin(), array3.end()));
    ASSERT_TRUE(std::is_sorted(array4.begin(), array4.end()));
    ASSERT_TRUE(std::is_sorted(array5.begin(), array5.end()));
    ASSERT_TRUE(std::is_sorted(array6.begin(), array6.end()));
}

TEST(MergeSort, zero_element) {
    std::vector<size_t> array;

    ASSERT_NO_FATAL_FAILURE(MergeSort(array));
}

TEST(MergeSort, one_element) {
    std::vector<size_t> array{1};

    ASSERT_NO_FATAL_FAILURE(MergeSort(array));
}

TEST(MergeSort, two_elements) {
    std::vector<size_t> array1{1, 2};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array1));
    std::vector<size_t> array2{2, 1};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array2));
    ASSERT_TRUE(std::is_sorted(array1.begin(), array1.end()));
    ASSERT_TRUE(std::is_sorted(array2.begin(), array2.end()));
}

TEST(MergeSort, three_elements) {
    std::vector<size_t> array1{1, 2, 3};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array1));
    std::vector<size_t> array2{2, 1, 3};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array2));
    std::vector<size_t> array3{3, 1, 2};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array3));
    std::vector<size_t> array4{3, 2, 1};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array4));
    std::vector<size_t> array5{1, 3, 2};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array5));
    std::vector<size_t> array6{2, 3, 1};
    ASSERT_NO_FATAL_FAILURE(MergeSort(array6));
    ASSERT_TRUE(std::is_sorted(array1.begin(), array1.end()));
    ASSERT_TRUE(std::is_sorted(array2.begin(), array2.end()));
    ASSERT_TRUE(std::is_sorted(array3.begin(), array3.end()));
    ASSERT_TRUE(std::is_sorted(array4.begin(), array4.end()));
    ASSERT_TRUE(std::is_sorted(array5.begin(), array5.end()));
    ASSERT_TRUE(std::is_sorted(array6.begin(), array6.end()));
}

TEST(ShellSort, zero_element) {
    std::vector<size_t> array;

    ASSERT_NO_FATAL_FAILURE(ShellSort(array.begin(), array.end()));
}

TEST(ShellSort, one_element) {
    std::vector<size_t> array{1};

    ASSERT_NO_FATAL_FAILURE(ShellSort(array.begin(), array.end()));
}

TEST(ShellSort, two_elements) {
    std::vector<size_t> array1{1, 2};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array1.begin(), array1.end()));
    std::vector<size_t> array2{2, 1};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array2.begin(), array2.end()));
    ASSERT_TRUE(std::is_sorted(array1.begin(), array1.end()));
    ASSERT_TRUE(std::is_sorted(array2.begin(), array2.end()));
}

TEST(ShellSort, three_elements) {
    std::vector<size_t> array1{1, 2, 3};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array1.begin(), array1.end()));
    std::vector<size_t> array2{2, 1, 3};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array2.begin(), array2.end()));
    std::vector<size_t> array3{3, 1, 2};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array3.begin(), array3.end()));
    std::vector<size_t> array4{3, 2, 1};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array4.begin(), array4.end()));
    std::vector<size_t> array5{1, 3, 2};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array5.begin(), array5.end()));
    std::vector<size_t> array6{2, 3, 1};
    ASSERT_NO_FATAL_FAILURE(ShellSort(array6.begin(), array6.end()));
    ASSERT_TRUE(std::is_sorted(array1.begin(), array1.end()));
    ASSERT_TRUE(std::is_sorted(array2.begin(), array2.end()));
    ASSERT_TRUE(std::is_sorted(array3.begin(), array3.end()));
    ASSERT_TRUE(std::is_sorted(array4.begin(), array4.end()));
    ASSERT_TRUE(std::is_sorted(array5.begin(), array5.end()));
    ASSERT_TRUE(std::is_sorted(array6.begin(), array6.end()));
}