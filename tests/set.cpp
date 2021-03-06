//
// Created by alanpark on 18. 10. 17.
//

#include "../src/set.h"
#include "../src/avl_tree.h"
#include "../src/hash_table.h"
#include "../src/trie.h"
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
    for( const auto& data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    auto set_a_elements=set_a->GetAllElements();
    for( const auto& data : *set_a_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }

    auto set_b_elements=set_b->GetAllElements();
    for( const auto& data : *set_b_elements ) {
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
    for( const auto& data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    ASSERT_EQ(all_elements->size(), 1);

    auto set_a_elements=set_a->GetAllElements();
    for( const auto& data : *set_a_elements ) {
        if( !set_b->Contains(data)) {
            ASSERT_TRUE(diff_set->Contains(data));
        }
    }

    auto set_b_elements=set_b->GetAllElements();
    for( const auto& data : *set_b_elements ) {
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
    for( const auto& data : *all_elements_in_a ) {
        if(data%2==1) {
            ASSERT_TRUE(subset->Contains(data));
        }
    }
    for( const auto& data : *all_elements_in_subset ) {
        ASSERT_TRUE(set_a->Contains(data));
    }
}

TEST(Set, hash_table) {
    HashTable<int> hash_table([](int a) { return a%256; });
    Set<int> &a = hash_table;
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

TEST(Set, HashTable_Intersect) {
    int set_a_elements[] = {1,3,5};
    int set_b_elements[] = {3,5,7};
    auto set_a = HashTable<int>::Create();
    for( const auto& data : set_a_elements){
        set_a->Insert(data);
    }
    auto set_b = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : set_b_elements){
        set_b->Insert(data);
    }
    auto intersect = Intersect(*set_a, *set_b);
    auto all_elements = intersect->GetAllElements();
    ASSERT_EQ(all_elements->size(), 2);
    std::sort(all_elements->begin(), all_elements->end());
    ASSERT_EQ((*all_elements)[0], 3);
    ASSERT_EQ((*all_elements)[1], 5);
}

TEST(Set, HashTableUnion) {
    int a_elements[] = {1,3,5};
    int b_elements[] = {3,5,7};
    auto set_a = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto set_b = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : b_elements){
        set_b->Insert(data);
    }
    auto union_set= Union(*set_a, *set_b);
    auto all_elements=union_set->GetAllElements();
    for( const auto& data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    auto set_a_elements=set_a->GetAllElements();
    for( const auto& data : *set_a_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }

    auto set_b_elements=set_b->GetAllElements();
    for( const auto& data : *set_b_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }
}

TEST(Set, HashTableDifference) {
    int a_elements[] = {1,3,5};
    int b_elements[] = {3,5,7};
    auto set_a = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto set_b = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : b_elements){
        set_b->Insert(data);
    }
    auto diff_set= Difference(*set_a, *set_b);
    auto all_elements=diff_set->GetAllElements();
    for( const auto& data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    ASSERT_EQ(all_elements->size(), 1);

    auto set_a_elements=set_a->GetAllElements();
    for( const auto& data : *set_a_elements ) {
        if( !set_b->Contains(data)) {
            ASSERT_TRUE(diff_set->Contains(data));
        }
    }

    auto set_b_elements=set_b->GetAllElements();
    for( const auto& data : *set_b_elements ) {
        ASSERT_FALSE(diff_set->Contains(data));
    }
}

TEST(Set, HashTableDistinct) {
    int a_elements[] = {1,3,5};
    int b_elements[] = {3,5,7};
    int c_elements[] = {7,9,11};
    auto set_a = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto set_b = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : b_elements){
        set_b->Insert(data);
    }

    auto set_c = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : c_elements){
        set_c->Insert(data);
    }

    ASSERT_FALSE(set_a->IsDistinctWith(*set_b));
    ASSERT_FALSE(set_b->IsDistinctWith(*set_c));
    ASSERT_TRUE(set_a->IsDistinctWith(*set_c));
}


TEST(Set, HashTableSubset) {
    int a_elements[] = {1,2,3,4,5};
    auto set_a = HashTable<int>::Create([](int a) { return a%256; });
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto subset = set_a->GetSubsetSatisfying([](const int& data) { return data%2==1; });
    auto all_elements_in_a = set_a->GetAllElements();
    auto all_elements_in_subset = subset->GetAllElements();
    for( const auto& data : *all_elements_in_a ) {
        if(data%2==1) {
            ASSERT_TRUE(subset->Contains(data));
        }
    }
    for( const auto& data : *all_elements_in_subset ) {
        ASSERT_TRUE(set_a->Contains(data));
    }
}

TEST(Set, Trie) {
    Trie<string, char> trie;
    Set<string> &a = trie;
    ASSERT_TRUE(a.empty());
    ASSERT_NO_THROW(a.Insert("1"));
    ASSERT_NO_THROW(a.Insert("123"));
    ASSERT_NO_THROW(a.Insert("12345"));
    ASSERT_TRUE(a.Contains("1"));
    ASSERT_TRUE(a.Contains("123"));
    ASSERT_TRUE(a.Contains("12345"));
    ASSERT_FALSE(a.empty());
    Trie<string, char> trie2;
    Set<string> &b = trie2;
    ASSERT_TRUE(b.empty());
    ASSERT_NO_THROW(b.Insert("123"));
    ASSERT_NO_THROW(b.Insert("12345"));
    ASSERT_NO_THROW(b.Insert("1234567"));
    ASSERT_TRUE(b.Contains("123"));
    ASSERT_TRUE(b.Contains("12345"));
    ASSERT_TRUE(b.Contains("1234567"));
    ASSERT_FALSE(b.empty());
}

TEST(Set, Trie_Intersect) {
    string set_a_elements[] = {"1","123","12345","1234567"};
    string set_b_elements[] = {"123","12345","1234567","123456789"};
    auto set_a = Trie<string, char>::Create();
    for( const auto& data : set_a_elements){
        set_a->Insert(data);
    }
    auto set_b = Trie<string, char>::Create();
    for( const auto& data : set_b_elements){
        set_b->Insert(data);
    }
    auto intersect = Intersect(*set_a, *set_b);
    auto all_elements = intersect->GetAllElements();
    ASSERT_EQ(all_elements->size(), 3);
    std::sort(all_elements->begin(), all_elements->end());
    ASSERT_EQ((*all_elements)[0], "123");
    ASSERT_EQ((*all_elements)[1], "12345");
    ASSERT_EQ((*all_elements)[2], "1234567");
}

TEST(Set, Trie_Union) {
    string a_elements[] = {"1","123","12345"};
    string b_elements[] = {"123","12345","1234567"};
    auto set_a = Trie<string, char>::Create();
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto set_b = Trie<string, char>::Create();
    for( const auto& data : b_elements){
        set_b->Insert(data);
    }
    auto union_set= Union(*set_a, *set_b);
    auto all_elements=union_set->GetAllElements();
    for( const auto& data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    auto set_a_elements=set_a->GetAllElements();
    for( const auto& data : *set_a_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }

    auto set_b_elements=set_b->GetAllElements();
    for( const auto& data : *set_b_elements ) {
        ASSERT_TRUE(union_set->Contains(data));
    }
}

TEST(Set, TrieDifference) {
    string a_elements[] = {"11","12","13","15"};
    string b_elements[] = {"13","15","17"};
    auto set_a = Trie<string, char>::Create();
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto set_b = Trie<string, char>::Create();
    for( const auto& data : b_elements){
        set_b->Insert(data);
    }
    auto diff_set= Difference(*set_a, *set_b);
    auto all_elements=diff_set->GetAllElements();
    for( const auto& data : *all_elements ) {
        ASSERT_TRUE( set_a->Contains(data) or set_b->Contains(data));
    }

    ASSERT_EQ(all_elements->size(), 2);

    auto set_a_elements=set_a->GetAllElements();
    for( const auto& data : *set_a_elements ) {
        if( !set_b->Contains(data)) {
            ASSERT_TRUE(diff_set->Contains(data));
        }
    }

    auto set_b_elements=set_b->GetAllElements();
    for( const auto& data : *set_b_elements ) {
        ASSERT_FALSE(diff_set->Contains(data));
    }
}


TEST(Set, TrieDistinct) {
    string a_elements[] = {"11","13","15"};
    string b_elements[] = {"13","15","17"};
    string c_elements[] = {"17","19","21"};
    auto set_a = Trie<string, char>::Create();
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto set_b = Trie<string, char>::Create();
    for( const auto& data : b_elements){
        set_b->Insert(data);
    }

    auto set_c = Trie<string, char>::Create();
    for( const auto& data : c_elements){
        set_c->Insert(data);
    }

    ASSERT_FALSE(set_a->IsDistinctWith(*set_b));
    ASSERT_FALSE(set_b->IsDistinctWith(*set_c));
    ASSERT_TRUE(set_a->IsDistinctWith(*set_c));
}

TEST(Set, TrieSubset) {
    string a_elements[] = {"11","12","13","14","15"};
    auto set_a = Trie<string, char>::Create();
    for( const auto& data : a_elements){
        set_a->Insert(data);
    }
    auto subset = set_a->GetSubsetSatisfying([](const string& data) { return data.find('2')!=-1; });
    auto all_elements_in_a = set_a->GetAllElements();
    auto all_elements_in_subset = subset->GetAllElements();
    for( const auto& data : *all_elements_in_a ) {
        if(data.find('2')!=-1) {
            ASSERT_TRUE(subset->Contains(data));
        }
    }
    for( const auto& data : *all_elements_in_subset ) {
        ASSERT_TRUE(set_a->Contains(data));
    }
}
