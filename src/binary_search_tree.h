//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_BINARY_SEARCH_TREE_H
#define MLDSA_CPP_BINARY_SEARCH_TREE_H

#include <memory>
#include <iostream>

template<class T>
class BinaryTreeNode {
public:
    typedef std::shared_ptr<BinaryTreeNode<T>> Node_;
    Node_ left_, right_;
    T data_;
    explicit BinaryTreeNode(const T& data) : data_(data), left_(nullptr), right_(nullptr) {}
    static Node_ Create(const T& data) {
        return std::make_shared<BinaryTreeNode<T>>(data);
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
};

template<class T>
class BinarySearchTree {
    typedef std::shared_ptr<BinaryTreeNode<T>> Node_;


protected:
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
    BinarySearchTree() : root_(nullptr) {}

    void Insert(const T& data) {
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

    bool Contains(const T& data) const {
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
                    return false;
                } else {
                    curr_node = curr_node->left_;
                }
            } else {
                if(curr_node->right_ == nullptr){
                    return false;
                } else {
                    curr_node = curr_node->right_;
                }
            }
        }
        if( curr_node == nullptr ) {
            throw std::exception();
        }
    }

    bool Remove(const T &data) {
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
};


#endif //MLDSA_CPP_BINARY_SEARCH_TREE_H
