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
\
Hash test_hash_3(const Hash& a, const Hash& b) {
    return Hash{0x07};
}




TEST(MerkleTree, totally_unbalanced_input_right) {

    Hash hash_a(32, 0x01);
    Hash hash_b(32, 0x02);
    vector<Hash> hashes;
    hashes.push_back(hash_a);
    hashes.push_back(hash_b);
    MerkleTree<vector<unsigned char>> tree(hashes, test_hash_1);
    ASSERT_EQ(tree.GetRoot(), hash_a);
    MerkleTree<vector<unsigned char>> tree1(hashes, test_hash_2);
    ASSERT_EQ(tree1.GetRoot(), hash_b);
    MerkleTree<vector<unsigned char>> tree2(hashes, test_hash_3);
    ASSERT_EQ(tree2.GetRoot(), Hash{0x07});
}