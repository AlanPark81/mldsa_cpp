//
// Created by alanpark on 18. 10. 25.
//

#include "../src/merkle_tree.h"
#include "gtest/gtest.h"


typedef vector<unsigned char> Hash;

Hash test_hash_1(const Hash& a, const Hash& b) {
    return a;
}


Hash test_hash_2(const Hash& a, const Hash& b) {
    return b;
}

Hash test_hash_3(const Hash& a, const Hash& b) {
    return Hash{0x07};
}

Hash test_hash_4(const Hash& a, const Hash& b) {
    return Hash(32, 0x07);
}

Hash test_hash_5(const Hash& a, const Hash& b) {
    Hash hash1;
    for( auto data1 : a) {
        hash1.push_back(data1+3);
    }
    return hash1;
}

TEST(MerkleTree, no_value) {
    auto tree=MerkleTree<Hash>::EmptyTree(test_hash_1);
    ASSERT_ANY_THROW(tree->GetRoot());
}

TEST(MerkleTree, one_value) {
    Hash hash_a(32, 0x01);
    vector<Hash> hashes;
    hashes.push_back(hash_a);
    MerkleTree<vector<unsigned char>> tree1(hashes, test_hash_1);
    ASSERT_EQ(tree1.GetRoot(), hash_a);
    MerkleTree<vector<unsigned char>> tree3(hashes, test_hash_3);
    ASSERT_EQ(tree3.GetRoot(), hash_a);
    MerkleTree<vector<unsigned char>> tree4(hashes, test_hash_4);
    ASSERT_EQ(tree4.GetRoot(), hash_a);
    MerkleTree<vector<unsigned char>> tree5(hashes, test_hash_5);
    ASSERT_EQ(tree5.GetRoot(), hash_a);
}


TEST(MerkleTree, two_value) {
    Hash hash_a(32, 0x01);
    Hash hash_b(32, 0x02);
    vector<Hash> hashes;
    hashes.push_back(hash_a);
    hashes.push_back(hash_b);
    MerkleTree<vector<unsigned char>> tree1(hashes, test_hash_1);
    ASSERT_EQ(tree1.GetRoot(), hash_a);
    MerkleTree<vector<unsigned char>> tree2(hashes, test_hash_2);
    ASSERT_EQ(tree2.GetRoot(), hash_b);
    MerkleTree<vector<unsigned char>> tree3(hashes, test_hash_3);
    ASSERT_EQ(tree3.GetRoot(), Hash{0x07});
    MerkleTree<vector<unsigned char>> tree4(hashes, test_hash_4);
    ASSERT_EQ(tree4.GetRoot(), Hash(32,0x07));
    MerkleTree<vector<unsigned char>> tree5(hashes, test_hash_5);
    ASSERT_EQ(tree5.GetRoot()[0], hash_a[0]+3);
}

TEST(MerkleTree, three_value) {
    Hash hash_a(32, 0x01);
    Hash hash_b(32, 0x02);
    Hash hash_c(32, 0x03);
    vector<Hash> hashes;
    hashes.push_back(hash_a);
    hashes.push_back(hash_b);
    hashes.push_back(hash_c);
    MerkleTree<vector<unsigned char>> tree1(hashes, test_hash_1);
    ASSERT_EQ(tree1.GetRoot(), hash_a);
    MerkleTree<vector<unsigned char>> tree2(hashes, test_hash_2);
    ASSERT_EQ(tree2.GetRoot(), hash_c);
    MerkleTree<vector<unsigned char>> tree3(hashes, test_hash_3);
    ASSERT_EQ(tree3.GetRoot(), Hash{0x07});
    MerkleTree<vector<unsigned char>> tree4(hashes, test_hash_4);
    ASSERT_EQ(tree4.GetRoot(), Hash(32,0x07));
    MerkleTree<vector<unsigned char>> tree5(hashes, test_hash_5);
    ASSERT_EQ(tree5.GetRoot()[0], hash_a[0]+6);
}