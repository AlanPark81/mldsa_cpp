//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_BINARY_SEARCH_TREE_H
#define MLDSA_CPP_BINARY_SEARCH_TREE_H

#include <memory>
#include "visitor.h"
#include "queue.h"
#include "set.h"
#include <iostream>
#include <functional>

template<class T>
class BinaryTreeNode : public VisitorAcceptor<T> {
public:
    typedef std::shared_ptr<BinaryTreeNode<T>> Node_;
    Node_ left_, right_;
    T data_;
    explicit BinaryTreeNode(const T& data) : data_(data), left_(nullptr), right_(nullptr) {}

    static Node_ Create(const T& data) {
        return std::make_shared<BinaryTreeNode<T>>(data);
    }

    size_t GetLevel() const {
        size_t ret_val=0;
        const auto left_size = ((left_ != nullptr)? left_->GetLevel(): 0 );
        const auto right_size = ( (right_ != nullptr)? right_->GetLevel() : 0 );
        ret_val+=std::max( left_size, right_size );
        ret_val++;
        return ret_val;
    }

    int GetLevelDiff() const {
        const auto left_size = ( ( left_ != nullptr )? ( (int)left_->GetLevel() ) : 0 );
        const auto right_size = ( ( right_ != nullptr )? ( (int)right_->GetLevel() ) : 0 );
        return  left_size - right_size;
    }

    bool TakeMiddleNumber() {
        if( left_ == nullptr &&  right_ == nullptr ) {
            return false;
        }
        if( left_ != nullptr ){
            if ( left_->right_ == nullptr ){
                data_= left_->data_;
                left_=left_->left_;
                return true;
            }
            Node_ parent_node = left_;
            Node_ curr_node = parent_node->right_;

            while(curr_node->right_ != nullptr) {
                parent_node = curr_node;
                curr_node = parent_node->right_;
            }
            parent_node->right_=curr_node->left_;
            data_=curr_node->data_;
            return true;
        } else if( right_ != nullptr ) {
            if ( right_->left_ == nullptr ){
                data_ = right_->data_;
                right_=right_->right_;
                return true;
            }
            Node_ parent_node = right_;
            Node_ curr_node = parent_node->left_;

            while(curr_node->left_ != nullptr) {
                parent_node = curr_node;
                curr_node = parent_node->left_;
            }
            parent_node->left_=curr_node->right_;
            data_=curr_node->data_;
            return true;
        } else {
            throw std::exception();
        }
    }

    bool Accept(Visitor<T>& visitor) override {
        return visitor.Visit(data_);
    }

    bool PoliteAccept(PoliteVisitor<T>& visitor) const override {
        return visitor.PoliteVisit(data_);
    }

    bool InvitePreorder(Visitor<T>& visitor) {
        if(!visitor.Visit(data_))
            return false;
        auto result = (left_ != nullptr)? left_->InvitePreorder(visitor) : true;
        if (!result)
            return result;
        return (right_ != nullptr)? right_->InvitePreorder(visitor) : true;
    }

    bool InvitePreorder(PoliteVisitor<T>& visitor) const {
        if(!visitor.Visit(data_))
            return false;
        auto result = (left_ != nullptr)? left_->InvitePreorder(visitor) : true;
        if (!result)
            return result;
        return (right_ != nullptr)? right_->InvitePreorder(visitor) : true;
    }

    bool InviteInorder(Visitor<T>& visitor) {
        auto result = (left_ != nullptr)? left_->InviteInorder(visitor) : true;
        if (!result)
            return false;
        if(!visitor.Visit(data_))
            return false;
        return (right_ != nullptr)? right_->InviteInorder(visitor) : true;
    }

    bool InviteInorder(PoliteVisitor<T>& visitor) const {
        auto result = (left_ != nullptr)? left_->InviteInorder(visitor) : true;
        if (!result)
            return false;
        if(!visitor.Visit(data_))
            return false;
        return (right_ != nullptr)? right_->InviteInorder(visitor) : true;
    }

    bool InvitePostorder(Visitor<T>& visitor) {
        auto result = (left_ != nullptr)? left_->InvitePostorder(visitor) : true;
        if (!result)
            return false;
        result = (right_ != nullptr)? right_->InvitePostorder(visitor) : true;
        if (!result)
            return false;
        return visitor.Visit(data_);
    }

    bool InvitePostorder(PoliteVisitor<T>& visitor) const {
        auto result = (left_ != nullptr)? left_->InvitePostorder(visitor) : true;
        if (!result)
            return result;
        result = (right_ != nullptr)? right_->InvitePostorder(visitor) : true;
        if (!result)
            return result;
        return visitor.Visit(data_);
    }
};

template<class T>
class BinarySearchTree : public VisitorAcceptor<T>, public Set<T> {
protected:
    typedef std::shared_ptr<BinaryTreeNode<T>> Node_;
    Node_ root_;

    Node_ FindParent(const T& data) const {
        Node_ parent_node = nullptr;
        Node_ curr_node = root_;

        while( curr_node != nullptr ){
            if( curr_node->data_ == data ){
                return parent_node;
            } else if( curr_node->data_ < data) {
                parent_node=curr_node;
                curr_node=parent_node->right_;
            } else if( curr_node->data_ > data) {
                parent_node=curr_node;
                curr_node=parent_node->left_;
            }
        }
        return nullptr;
    }
public:
    typedef std::shared_ptr<BinarySearchTree<T>> BinarySearchTree_;

    static BinarySearchTree_ Create() {
        return std::make_shared<BinarySearchTree<T>>();
    }

    BinarySearchTree() : root_(nullptr) {}

    bool empty() const override {
        return ( root_== nullptr );
    }

    void Insert(const T& data) override {
        if( root_ == nullptr ) {
            root_ = BinaryTreeNode<T>::Create(data);
            return;
        }
        Node_ curr_node = root_;
        while(curr_node != nullptr) {
            if(data < curr_node->data_) {
                if(curr_node->left_ == nullptr){
                    curr_node->left_= BinaryTreeNode<T>::Create(data);
                    break;
                } else {
                    curr_node = curr_node->left_;
                }
            } else {
                if(curr_node->right_ == nullptr){
                    curr_node->right_= BinaryTreeNode<T>::Create(data);
                    break;
                } else {
                    curr_node = curr_node->right_;
                }
            }
        }
        if( curr_node == nullptr ) {
            throw std::exception();
        }
    }

    bool Contains(const T& data) const override {
        if( root_ == nullptr ) {
            return false;
        }

        Node_ curr_node = root_;
        while(curr_node != nullptr) {
            if(data == curr_node->data_) {
                return true;
            }
            if(data < curr_node->data_) {
                if(curr_node->left_ == nullptr){
                    break;
                } else {
                    curr_node = curr_node->left_;
                }
            } else {
                if(curr_node->right_ == nullptr){
                    break;
                } else {
                    curr_node = curr_node->right_;
                }
            }
        }
        return false;
    }

    virtual bool Remove(const T &data) {
        if( root_ == nullptr ) {
            return false;
        }

        if( root_->data_ == data ) {
            if( !root_->TakeMiddleNumber() ) {
                root_ = nullptr;
            }
        } else {
            Node_ parent_node = FindParent(data);
            if( parent_node == nullptr ) {
                return false;
            }
            if( parent_node->data_ < data )
            {
                if( !parent_node->right_->TakeMiddleNumber()) {
                    parent_node->right_ = nullptr;
                }
            } else {
                if( !parent_node->left_->TakeMiddleNumber() ) {
                    parent_node->left_ = nullptr;
                }
            }
        }
        return true;
    }

    bool Accept(Visitor<T>& visitor) override {
        Queue<Node_> queue_nodes;
        queue_nodes.Enqueue(root_);
        while(!queue_nodes.empty()) {
            Node_ curr_node=queue_nodes.Dequeue();
            if(!curr_node->Accept(visitor)) return false;

            if(curr_node->left_ != nullptr) {
                queue_nodes.Enqueue(curr_node->left_);
            }
            if(curr_node->right_ != nullptr) {
                queue_nodes.Enqueue(curr_node->right_);
            }
        }
        return true;
    }

    bool PoliteAccept(PoliteVisitor<T>& polite_visitor) const override {
        Queue<Node_> queue_nodes;
        if( root_ != nullptr ){
            queue_nodes.Enqueue(root_);
        }
        while(!queue_nodes.empty()) {
            Node_ curr_node=queue_nodes.Dequeue();
            if(!curr_node->PoliteAccept(polite_visitor)) return false;

            if(curr_node->left_ != nullptr) {
                queue_nodes.Enqueue(curr_node->left_);
            }
            if(curr_node->right_ != nullptr) {
                queue_nodes.Enqueue(curr_node->right_);
            }
        }
        return true;
    }

    size_t size() const {
        size_t ret_val=0;
        Queue<Node_> queue_nodes;
        if(root_ == nullptr) return ret_val;
        queue_nodes.Enqueue(root_);
        while(!queue_nodes.empty()) {
            Node_ curr_node=queue_nodes.Dequeue();
            ret_val++;

            if(curr_node->left_ != nullptr) {
                queue_nodes.Enqueue(curr_node->left_);
            }
            if(curr_node->right_ != nullptr) {
                queue_nodes.Enqueue(curr_node->right_);
            }
        }
        return ret_val;
    }

    std::shared_ptr<std::vector<T>> GetAllElements() const override {
        StoreVisitor<T> visitor;
        this->PoliteAccept(visitor);
        return visitor.GetSeq();
    }

    bool InvitePreorder(Visitor<T>& visitor) {
        return root_->InvitePreorder(visitor);
    }

    bool InvitePreorder(PoliteVisitor<T>& visitor) {
        return root_->InvitePreorder(visitor);
    }

    bool InviteInorder(Visitor<T>& visitor) {
        return root_->InviteInorder(visitor);
    }

    bool InviteInorder(PoliteVisitor<T>& visitor) {
        return root_->InviteInorder(visitor);
    }

    bool InvitePostorder(Visitor<T>& visitor) {
        return root_->InvitePostorder(visitor);
    }

    bool InvitePostorder(PoliteVisitor<T>& visitor) {
        return root_->InvitePostorder(visitor);
    }
};

#endif //MLDSA_CPP_BINARY_SEARCH_TREE_H
