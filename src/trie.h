//
// Created by alanpark on 18. 10. 25.
//

#ifndef MLDSA_CPP_TRIE_H
#define MLDSA_CPP_TRIE_H

#include <vector>
#include <memory>
#include <map>
#include "set.h"
#include <queue>

using namespace std;

template <class T, class C>
class Trie : public Set<T>{
    struct TrieNode {
        bool end_;
        T key_;
        typedef shared_ptr<TrieNode> Self_;
        std::map<C, Self_> children_;

        TrieNode() : end_(false) {}
        explicit TrieNode(const T& key) : end_(false), key_(key) {}


        static Self_ CreateRoot() {
            return make_shared<TrieNode>();
        }

        static Self_ Create(const T& key) {
            return make_shared<TrieNode>(key);
        }
    };

    typedef shared_ptr<TrieNode> NodePtr_;
    NodePtr_ root_;
public:
    Trie() = default;

    bool empty() const override {
        return (root_ == nullptr or root_->children_.empty());
    }

    void Insert(const T& data ){
        auto iter=data.cbegin();
        if( root_ == nullptr) {
            root_= TrieNode::CreateRoot();
        }
        auto node = root_;
        while(iter != data.cend()) {
            auto map_iter = node->children_.find(*iter);
            if( map_iter == node->children_.end()){
                node->children_[*iter]=TrieNode::Create(T(data.begin(), iter+1));
            }
            node=node->children_[*iter];
            iter++;
        }
        node->end_ = true;
    }

    bool Contains(const T& data) const {
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

        return iter == cend(data) and node->end_ and node->key_ == data;
    }

    std::shared_ptr<std::vector<T>> GetAllElements() const override {
        StoreVisitor<T> visitor;
        PoliteAccept(visitor);
        return visitor.GetSeq();
    }

    bool PoliteAccept(PoliteVisitor<T>& visitor) const override {
        auto ret_val = make_shared<std::vector<T>>();
        auto node = root_;
        queue<decltype(root_)> queue1;
        queue1.push(root_);

        while(!queue1.empty()) {
            auto got = queue1.front();
            queue1.pop();
            if( got->end_ ) {
                if(!visitor.PoliteVisit(got->key_)){
                    return false;
                }
            }
            for(auto i=0 ; i< got->children_.size(); i++ ){
                if(got->children_[i] != nullptr)
                    queue1.push(got->children_[i]);
            }
        }
        return true;
    }
};
#endif //MLDSA_CPP_TRIE_H
