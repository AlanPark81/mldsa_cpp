//
// Created by alanpark on 18. 10. 17.
//

#include "../src/set.h"
#include "../src/avl_tree.h"
#include <gtest/gtest.h>

TEST(Set, avl_tree) {
    AVLTree<int> avl_tree;
    Set<int> &a=avl_tree;
    ASSERT_TRUE(a.empty());
    ASSERT_NO_THROW(a.Insert(1));
    ASSERT_NO_THROW(a.Insert(3));
    ASSERT_NO_THROW(a.Insert(5));
    ASSERT_TRUE(a.Contains(1));
    ASSERT_TRUE(a.Contains(3));
    ASSERT_TRUE(a.Contains(5));
    ASSERT_FALSE(a.empty());
    AVLTree<int> avl_tree2;
    Set<int> &b = avl_tree2;
    ASSERT_TRUE(b.empty());
    ASSERT_NO_THROW(b.Insert(3));
    ASSERT_NO_THROW(b.Insert(5));
    ASSERT_NO_THROW(b.Insert(7));
    ASSERT_TRUE(b.Contains(3));
    ASSERT_TRUE(b.Contains(5));
    ASSERT_TRUE(b.Contains(7));
    ASSERT_FALSE(b.empty());

    auto intersect = Union(avl_tree, avl_tree2);
    auto all_elements=intersect->GetAllElements();
    ASSERT_EQ(all_elements->size(), 2);
    std::sort(all_elements->begin(), all_elements->end());
    ASSERT_EQ((*all_elements)[0], 3);
    ASSERT_EQ((*all_elements)[1], 5);
}