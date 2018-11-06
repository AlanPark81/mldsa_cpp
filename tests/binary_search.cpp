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