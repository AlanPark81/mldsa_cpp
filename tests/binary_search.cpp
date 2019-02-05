//
// Created by alanpark on 18. 11. 6.
//
#include "gtest/gtest.h"
#include "../src/binary_search.h"

#include <vector>

using namespace std;


TEST(BinarySearch, binary_search_test_one) {
    vector<size_t> array;
    for(size_t i=0; i < 100; i++) {
        array.push_back(i);
    }

    for(size_t i=0; i < 100; i++) {
        const auto index = binary_search<size_t>(array, i);
        ASSERT_EQ(index, i);
        ASSERT_EQ(array[index], i);
    }
    ASSERT_ANY_THROW(binary_search<size_t>(array, 100));
}

TEST(BinarySearch, binary_search_test_two) {
    vector<string> array;
    for(size_t i=0; i < 100; i++) {
        string to_push(i, 'a');
        array.push_back(to_push);
    }

    for(size_t i=0; i < 100; i++) {
        const auto index = binary_search<string>(array, string(i, 'a'));
        ASSERT_EQ(array[index], string(i, 'a'));
    }
}

TEST(UpperBound, zero_element) {
    vector<size_t> array;

    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 2) == array.end());
    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 1) == array.end());
    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 0) == array.end());
}

TEST(UpperBound, one_element) {
    vector<size_t> array{1};

    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 2) == array.end());
    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 1) == array.end());
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 0) == 1);
}

TEST(UpperBound, two_elements) {
    vector<size_t> array{1, 3};

    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 3) == array.end());
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 2) == 3);
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 1) == 3);
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 0) == 1);
}

TEST(UpperBound, three_elements) {
    vector<size_t> array{1, 3, 5};

    ASSERT_TRUE(UpperBound(array.begin(), array.end(), 5) == array.end());
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 4) == 5);
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 3) == 5);
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 2) == 3);
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 1) == 3);
    ASSERT_TRUE(*UpperBound(array.begin(), array.end(), 0) == 1);
}

TEST(LowerBound, zero_element) {
    vector<size_t> array;

    ASSERT_TRUE(LowerBound(array.begin(), array.end(), 2) == array.end());
    ASSERT_TRUE(LowerBound(array.begin(), array.end(), 1) == array.end());
    ASSERT_TRUE(LowerBound(array.begin(), array.end(), 0) == array.end());
}

TEST(LowerBound, one_element) {
    vector<size_t> array{1};

    ASSERT_TRUE(LowerBound(array.begin(), array.end(), 2) == array.end());
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 1) == 1);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 0) == 1);
}

TEST(LowerBound, two_elements) {
    vector<size_t> array{1, 3};

    ASSERT_TRUE(LowerBound(array.begin(), array.end(), 4) == array.end());
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 3) == 3);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 2) == 3);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 1) == 1);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 0) == 1);
}

TEST(LowerBound, three_elements) {
    vector<size_t> array{1, 3, 5};

    ASSERT_TRUE(LowerBound(array.begin(), array.end(), 6) == array.end());
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 5) == 5);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 4) == 5);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 3) == 3);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 2) == 3);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 1) == 1);
    ASSERT_TRUE(*LowerBound(array.begin(), array.end(), 0) == 1);
}