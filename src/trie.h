//
// Created by alanpark on 18. 10. 25.
//

#ifndef MLDSA_CPP_TRIE_H
#define MLDSA_CPP_TRIE_H

#include <vector>
#include <memory>
#include <map>

using namespace std;

template <class T, class C>
class Trie {
    struct TrieNode {
        bool end_;
        typedef shared_ptr<TrieNode> Self_;
        std::map<C, Self_> children_;
        TrieNode() : end_(false) {}

        static Self_ Create() {
            return make_shared<TrieNode>();
        }
    };

    typedef shared_ptr<TrieNode> NodePtr_;
    NodePtr_ root_;
public:
    Trie() = default;
    void Insert(const T& data ){
        auto iter=data.cbegin();
        if( root_ == nullptr) {
            root_= TrieNode::Create();
        }
        auto node = root_;
        while(iter != data.cend()) {
            auto map_iter = node->children_.find(*iter);
            if( map_iter == node->children_.end()){
                node->children_[*iter]=TrieNode::Create();
            }
            node=node->children_[*iter];
            iter++;
        }
        node->end_ = true;
    }

    bool Contains(const T& data) {
        if (root_ == nullptr) {
            return false;
        }
        auto iter = data.cbegin();
        auto node = root_;
        NodePtr_ parent = nullptr;
        while(iter != data.cend() && node->children_.find(*iter) != node->children_.end()) {
            parent = node;
            node = node->children_[*iter++];
        }

        return iter == cend(data) and node->end_;
    }
};
#endif //MLDSA_CPP_TRIE_H