//
// Created by alanpark on 18. 10. 26.
//

#include "gtest/gtest.h"
#include "../src/hash_table.h"

size_t hash_test(const int& input) {
    return (size_t)input;
}

TEST(HashTable, collision1) {
    HashTable<int,1> hash_table(hash_test);
    ASSERT_NO_THROW(hash_table.Insert(1));
    ASSERT_ANY_THROW(hash_table.Insert(1));
}

TEST(HashTable, collision128) {
    HashTable<int,128> hash_table(hash_test);
    for(int i=0;i<128;i++) {
        ASSERT_NO_THROW(hash_table.Insert(1));
    }
    ASSERT_ANY_THROW(hash_table.Insert(1));
}


TEST(HashTable, insert_retrieve_same) {
    HashTable<int,128> hash_table(hash_test);
    for(int i=0;i<128;i++) {
        auto value=0;
        ASSERT_NO_THROW(hash_table.Insert(1));
        ASSERT_NO_THROW(value=hash_table.Retrieve(1));
        ASSERT_EQ(value, 1);
    }
    ASSERT_ANY_THROW(hash_table.Insert(1));
    ASSERT_ANY_THROW(hash_table.Retrieve(2));
}

TEST(HashTable, insert_retrieve_unique) {
    HashTable<int,128> hash_table(hash_test);
    for(int i=0;i<128;i++) {
        auto value=0;
        ASSERT_NO_THROW(hash_table.Insert(i));
        ASSERT_NO_THROW(value=hash_table.Retrieve(i));
        ASSERT_EQ(value, i);
    }
    for(int i=0;i<128;i++) {
        auto value=0;
        ASSERT_NO_THROW(value=hash_table.Retrieve(i));
        ASSERT_EQ(value, i);
    }

    ASSERT_ANY_THROW(hash_table.Insert(1));
    //ASSERT_ANY_THROW(hash_table.Retrieve(2));
}