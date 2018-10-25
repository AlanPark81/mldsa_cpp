//
// Created by alanpark on 18. 10. 25.
//

#ifndef MLDSA_CPP_MERKLE_TREE_H
#define MLDSA_CPP_MERKLE_TREE_H

#include <vector>
#include <functional>
#include <memory>

using namespace std;

template<class HashType>
class MerkleTree {
    typedef shared_ptr<MerkleTree> MerkleTree_;
    typedef function<HashType(const HashType&, const HashType&)> HashForTwoType;
    vector<HashType> tree_content_;
    size_t input_length;
    HashForTwoType hash;
public:
    static size_t GetTreeLengthForInput(const size_t& length) {
        size_t len = length;
        size_t count = 0;
        while( len > 1 ) {
            count+=len;
            len = len - (len>>1);
        }
        return count+1;
    }


    static MerkleTree_ EmptyTree(const HashForTwoType& hash_for_two){
        return make_shared<MerkleTree>(vector<HashType>{}, hash_for_two);
    }

    MerkleTree(const vector<HashType>&  initial_hashes
            , const HashForTwoType& hash_for_two)
            : tree_content_(GetTreeLengthForInput(initial_hashes.size())), input_length(initial_hashes.size()), hash(hash_for_two) {
        tree_content_.insert(tree_content_.end(), initial_hashes.cbegin(), initial_hashes.cend());
        vector<HashType> curr_level(initial_hashes);
        vector<HashType> next_level;

        while(curr_level.size() > 1) {
            const size_t curr_size = curr_level.size();
            next_level.reserve( (curr_level.size() + 1) / 2 );
            int i=0;
            while( (i+1) < curr_size) {
                next_level.push_back( hash_for_two(curr_level[i], curr_level[i+1]) );
                i+=2;
            }
            if(i < curr_size) {
                next_level.push_back(hash_for_two(curr_level[i], curr_level[i]));
            }
            curr_level=next_level;
            tree_content_.insert(tree_content_.end(), next_level.cbegin(), next_level.cend());
        }
    }

    HashType GetRoot() const {
        if(tree_content_.empty()) throw exception();
        return tree_content_[tree_content_.size()-1];
    }
};

#endif //MLDSA_CPP_MERKLE_TREE_H
