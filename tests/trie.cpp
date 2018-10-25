//
// Created by alanpark on 18. 10. 25.
//
#include "gtest/gtest.h"
#include "../src/trie.h"

TEST(Trie, insert_and_contains) {
    Trie<string, char> trie;
    trie.Insert("Hello");
    ASSERT_TRUE(trie.Contains("Hello"));
    ASSERT_FALSE(trie.Contains("Hello1"));
    ASSERT_FALSE(trie.Contains("Apple"));
}