//
// Created by alanpark on 18. 10. 15.
//

#include "../src/binary_search_tree.h"
#include "gtest/gtest.h"

TEST(BinarySearchTree, insert_once) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_TRUE(bst.Contains(0));
}

TEST(BinarySearchTree, insert_twice) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
}

TEST(BinarySearchTree, insert_three_times) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
}

TEST(BinarySearchTree, insert_four_times) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
}

TEST(BinarySearchTree, insert_once_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));

}

TEST(BinarySearchTree, insert_twice_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
}

TEST(BinarySearchTree, insert_three_times_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
}

TEST(BinarySearchTree, insert_four_times_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));

    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(-2));
    ASSERT_FALSE(bst.Contains(-2));
}

TEST(BinarySearchTree, insert_seven_times_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-3));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(2));
    ASSERT_TRUE(bst.Contains(3));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
    ASSERT_TRUE(bst.Contains(-3));

    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(2));
    ASSERT_FALSE(bst.Contains(2));
    ASSERT_TRUE(bst.Remove(3));
    ASSERT_FALSE(bst.Contains(3));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(-2));
    ASSERT_FALSE(bst.Contains(-2));
    ASSERT_TRUE(bst.Remove(-3));
    ASSERT_FALSE(bst.Contains(-3));

    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-3));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(2));
    ASSERT_TRUE(bst.Contains(3));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
    ASSERT_TRUE(bst.Contains(-3));

    ASSERT_TRUE(bst.Remove(-3));
    ASSERT_FALSE(bst.Contains(-3));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(3));
    ASSERT_FALSE(bst.Contains(3));
    ASSERT_TRUE(bst.Remove(2));
    ASSERT_FALSE(bst.Contains(2));
    ASSERT_TRUE(bst.Remove(-2));
    ASSERT_FALSE(bst.Contains(-2));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
}