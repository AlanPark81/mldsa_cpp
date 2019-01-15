//
// Created by alanpark on 18. 10. 25.
//
#include "gtest/gtest.h"
#include "../src/trie.h"

TEST(Trie, insert_and_contains) {
    Trie<string, char> trie;
    ASSERT_FALSE(trie.Contains("Hello"));
    trie.Insert("Hello");
    trie.Insert("Halo");
    trie.Insert("Apple");
    trie.Insert("April");
    ASSERT_TRUE(trie.Contains("Hello"));
    ASSERT_TRUE(trie.Contains("Halo"));
    ASSERT_TRUE(trie.Contains("Apple"));
    ASSERT_TRUE(trie.Contains("April"));
    ASSERT_FALSE(trie.Contains("Hell"));
    trie.Insert("Hell");
    ASSERT_TRUE(trie.Contains("Hell"));
    ASSERT_FALSE(trie.Contains("Appl"));
    ASSERT_FALSE(trie.Contains("Hello1"));
}