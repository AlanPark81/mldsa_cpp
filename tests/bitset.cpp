//
// Created by alanp on 15/02/2019.
//

#include "gtest/gtest.h"
#include "../src/bitset.h"
#include <iostream>

TEST(bitset, Contructors) {
    Bitset bs1;
    const unsigned long long input2 = 13ULL * 256 * 256 * 256 * 256 + 13ULL * 256 * 256 * 256 + 13ULL * 256 * 256 + 13ULL * 256 + 13ULL;
    Bitset bs2(input2);
    Bitset bs3(std::vector<byte>(5, 13));
    ASSERT_EQ(bs1.GetBytes().size(), 0);
    ASSERT_EQ(bs2.GetBytes().size(), 5);
    ASSERT_EQ(bs3.GetBytes().size(), 5);
    ASSERT_EQ(bs2.GetBytes(), bs3.GetBytes());
    ASSERT_EQ(bs2.GetULL(), input2);
    ASSERT_EQ(bs3.GetULL(), input2);
}

TEST(bitset, Initialise) {
    Bitset bs1(std::vector<byte>(5, 13));
    Bitset bs2;
    bs2.Initialise(std::vector<byte>(5, 13));
    ASSERT_EQ(bs1.GetBytes(), bs2.GetBytes());
}

TEST(bitset, Reverse) {
    Bitset bs1(std::vector<byte>(5, 13));
    Bitset bs2(std::vector<byte>(5, 13));
    bs2.Reverse();
    ASSERT_NE(bs1.GetBytes(), bs2.GetBytes());
    bs2.Reverse();
    ASSERT_EQ(bs1.GetBytes(), bs2.GetBytes());
    bs1.Reverse();
    ASSERT_NE(bs1.GetBytes(), bs2.GetBytes());
    bs2.Reverse();
    ASSERT_EQ(bs1.GetBytes(), bs2.GetBytes());
}

TEST(bitset, array_index_reverse) {
    Bitset bs1(13U);
    Bitset bs2(13U);
    for (int i = 0; i < bs2.GetLength() / 2; i++) {
        std::swap(bs2[i], bs2[bs2.GetLength() - i - 1]);
    }
    for (int i = 0; i < bs2.GetLength() / 2; i++) {
        std::swap(bs2[i], bs2[bs2.GetLength() - i - 1]);
    }
    ASSERT_EQ(bs1.GetBytes(), bs2.GetBytes());
    for (int i = 0; i < bs1.GetLength() / 2; i++) {
        std::swap(bs1[i], bs1[bs2.GetLength() - i - 1]);
    }
    for (int i = 0; i < bs2.GetLength() / 2; i++) {
        std::swap(bs2[i], bs2[bs2.GetLength() - i - 1]);
    }
    ASSERT_EQ(bs1.GetBytes(), bs2.GetBytes());
}