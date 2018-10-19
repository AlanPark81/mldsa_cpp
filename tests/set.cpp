//
// Created by alanpark on 18. 10. 17.
//

#include "../src/set.h"
#include "../src/avl_tree.h"
#include <gtest/gtest.h>

TEST(Set, avl_tree) {
    AVLTree<int> avl_tree;
    Set<int> &a = avl_tree;
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
}

TEST(Set, Intersect) {
    int set_a_elements[] = {1,3,5};
    int set_b_elements[] = {3,5,7};
    auto set_a = Set<int>::CreateSetWith(set_a_elements, 3);
    auto set_b = Set<int>::CreateSetWith(set_b_elements, 3);
    auto intersect = Intersect(*set_a, *set_b);
    auto all_elements = intersect->GetAllElements();
    ASSERT_EQ(all_elements->size(), 2);
    std::sort(all_elements->begin(), all_elements->end());
    ASSERT_EQ((*all_elements)[0], 3);
    ASSERT_EQ((*all_elements)[1], 5);
}

TEST(Set, Union) {
    int a_elements[] = {1,3,5};
    int b_elements[] = {3,5,7};
    auto set_a = Set<int>::CreateSetWith(a_elements, 3);
    auto set_b = Set<int>::CreateSetWith(std::vector<int>(b_elements, b_elements + 3));
    auto union_set= Union(*set_a, *set_b);
    auto all_elements=union_set->GetAllElements();
    for( auto data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    auto set_a_elements=set_a->GetAllElements();
    for( auto data : *set_a_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }

    auto set_b_elements=set_b->GetAllElements();
    for( auto data : *set_b_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }
}

TEST(Set, Difference) {
    int a_elements[] = {1,3,5};
    int b_elements[] = {3,5,7};
    auto set_a = Set<int>::CreateSetWith(std::vector<int>(a_elements, a_elements + 3));
    auto set_b = Set<int>::CreateSetWith(std::vector<int>(b_elements, b_elements + 3));
    auto diff_set= Difference(*set_a, *set_b);
    auto all_elements=diff_set->GetAllElements();
    for( auto data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    ASSERT_EQ(all_elements->size(), 1);

    auto set_a_elements=set_a->GetAllElements();
    for( auto data : *set_a_elements ) {
        if( !set_b->Contains(data)) {
            ASSERT_TRUE(diff_set->Contains(data));
        }
    }

    auto set_b_elements=set_b->GetAllElements();
    for( auto data : *set_b_elements ) {
        ASSERT_FALSE(diff_set->Contains(data));
    }
}

TEST(Set, Distinct) {
    int a_elements[] = {1,3,5};
    int b_elements[] = {3,5,7};
    int c_elements[] = {7,9,11};
    auto set_a = Set<int>::CreateSetWith(std::vector<int>(a_elements, a_elements + 3));
    auto set_b = Set<int>::CreateSetWith(std::vector<int>(b_elements, b_elements + 3));
    auto set_c = Set<int>::CreateSetWith(c_elements, 3);

    ASSERT_FALSE(set_a->IsDistinctWith(*set_b));
    ASSERT_FALSE(set_b->IsDistinctWith(*set_c));
    ASSERT_TRUE(set_a->IsDistinctWith(*set_c));
}


TEST(Set, subset) {
    int a_elements[] = {1,2,3,4,5};
    auto set_a = Set<int>::CreateSetWith(a_elements, 5);
    auto subset = set_a->GetSubsetSatisfying([](const int& data) { return data%2==1; });
    auto all_elements_in_a = set_a->GetAllElements();
    auto all_elements_in_subset = subset->GetAllElements();
    for( auto data : *all_elements_in_a ) {
        if(data%2==1) {
            ASSERT_TRUE(subset->Contains(data));
        }
    }
    for( auto data : *all_elements_in_subset ) {
        ASSERT_TRUE(set_a->Contains(data));
    }
}