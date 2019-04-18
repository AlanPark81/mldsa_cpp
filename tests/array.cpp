//
// Created by alanp on 19/04/2019.
//

#include "../src/array.h"
#include "gtest/gtest.h"


TEST(Array, CreateAndGet) {
    auto test = Array<int, 2>().get(1).option_;
    ASSERT_EQ(test, None);
}

TEST(Array, CreateAndSetOutOfBound) {
    auto array_test = Array<int, 2>();
    auto test = array_test.set(2, 1);
    ASSERT_EQ(test, FAIL);
    test = array_test.set(-1, 1);
    ASSERT_EQ(test, FAIL);
    auto result = array_test.get(2);
    ASSERT_EQ(result.option_, None);
    result = array_test.get(-1);
    ASSERT_EQ(result.option_, None);
}

TEST(Array, CreateAndSetAndGet) {
    auto array_test = Array<int, 2>();
    ASSERT_EQ(array_test.get(1).option_, None);
    ASSERT_EQ(array_test.set(1, 1), SUCCESS);
    ASSERT_EQ(array_test.get(1).option_, Some);
}

TEST(Array, CreateAndSetAndGetOutOfBound) {
    auto array_test = Array<int, 2>();
    ASSERT_EQ(array_test.get(2).option_, None);
    ASSERT_EQ(array_test.set(2, 1), FAIL);
    ASSERT_EQ(array_test.get(2).option_, None);
    ASSERT_EQ(array_test.get(-1).option_, None);
    ASSERT_EQ(array_test.set(-1, 1), FAIL);
    ASSERT_EQ(array_test.get(-1).option_, None);
}