//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_AVL_TREE_H
#define MLDSA_CPP_AVL_TREE_H

#include "binary_search_tree.h"
#include "stack.h"
#include <memory>

template<class T>
class AVLTree : public BinarySearchTree<T> {
protected:
    typedef std::shared_ptr<BinaryTreeNode<T>> Node_;
public:
    typedef std::shared_ptr<AVLTree<T>> AVLTree_;

    static AVLTree_ Create() {
        return std::make_shared<AVLTree<T>>();
    }

    AVLTree() = default;
protected:
    static bool InsertNode(Node_& node, const T& data) {
        if( data < node->data_ ) {
            if(node->left_ == nullptr ){
                node->left_ = BinaryTreeNode<T>::Create(data);
            } else {
                InsertNode( node->left_, data );
            }
        } else {
            if(node->right_ == nullptr ){
                node->right_ = BinaryTreeNode<T>::Create(data);
            } else {
                InsertNode( node->right_, data );
            }
        }
        return NodeBalance(node);
    }

    static void RotateLeft(Node_& node) {
        Node_ right_node = node->right_;
        node->right_ = right_node->left_;
        right_node->left_ = node;
        node = right_node;
    }

    static void RotateRight(Node_& node) {
        Node_ left_node = node->left_;
        node->left_ = left_node->right_;
        left_node->right_ = node;
        node = left_node;
    }

    static void RotateLeftAndLeft(Node_& node){
        if( node->right_ != nullptr ){
            RotateLeft(node->right_);
        }
        RotateLeft(node);
    }

    static void RotateRightAndRight(Node_& node){
        if( node->left_ != nullptr ){
            RotateRight(node->left_);
        }
        RotateRight(node);
    }

    static void RotateRightAndLeft(Node_& node){
        if( node->right_ != nullptr ){
            RotateRight(node->right_);
        }
        RotateLeft(node);
    }

    static void RotateLeftAndRight(Node_& node){
        if( node->left_ != nullptr ){
            RotateLeft(node->left_);
        }
        RotateRight(node);
    }
    static bool NodeBalance(Node_& node) {
        if( node == nullptr or ( node->left_ == nullptr and node->right_ == nullptr ) ) return false;
        const int level_diff=node->GetLevelDiff();
        if( level_diff > 1 ) {
            const auto left_level_diff=node->left_->GetLevelDiff();
            if ( left_level_diff > 1 )
            {
                RotateRightAndRight(node);
            } else if ( left_level_diff > 0 ) {
                RotateRight(node);
            } else {
                RotateLeftAndRight(node);
            }
        } else if( level_diff < -1){
            const auto right_level_diff=node->right_->GetLevelDiff();
            if ( right_level_diff < -1 ) {
                RotateLeftAndLeft(node);
            } else if( right_level_diff < 0 ) {
                RotateLeft(node);
            } else {
                RotateRightAndLeft(node);
            }
        } else {
            return false;
        }
        return true;
    }
public:
    void Insert(const T& data) override {
        if( this->root_ == nullptr ) {
            this->root_ = BinaryTreeNode<T>::Create(data);
        } else {
            InsertNode( this->root_, data);
        }
    }

    bool Remove(const T& data) override {
        if( this->root_ == nullptr) {
            return false;
        }
        Node_ parent = nullptr;
        Node_ node_to_delete = this->root_;
        Stack<Node_> path_for_delete;
        while( node_to_delete != nullptr && node_to_delete->data_ != data ) {
            path_for_delete.Push(node_to_delete);
            parent=node_to_delete;
            if( data < node_to_delete->data_ ){
                node_to_delete = node_to_delete->left_;
            } else {
                node_to_delete = node_to_delete->right_;
            }
        }
        if( node_to_delete == nullptr ) {
            return false;
        } else if ( node_to_delete == this->root_ ) {
            if( ! this->root_->TakeMiddleNumber() ) {
                this->root_ = nullptr;
            }
            return true;
        }

        if( node_to_delete -> left_ == nullptr and node_to_delete -> right_ == nullptr){
            if( node_to_delete -> data_ < parent -> data_ ) {
                parent->left_= nullptr;
            } else {
                parent->right_ = nullptr;
            }
        } else if( node_to_delete -> left_ != nullptr and node_to_delete -> right_ == nullptr ) {
            if( node_to_delete -> data_ < parent -> data_ ) {
                parent->left_= node_to_delete->left_;
            } else {
                parent->right_ = node_to_delete->left_;
            }
        } else if( node_to_delete -> left_ == nullptr and node_to_delete -> right_ != nullptr){
            if( node_to_delete -> data_ < parent -> data_ ) {
                parent->left_= node_to_delete -> right_;
            } else {
                parent->right_ = node_to_delete -> right_;
            }
        } else if( node_to_delete -> left_ != nullptr and node_to_delete -> right_ != nullptr ) {
            node_to_delete->TakeMiddleNumber();
        }

        Node_ child = nullptr;

        while( !path_for_delete.empty() ) {
            auto node_to_balance = path_for_delete.Pop();
            if( child != nullptr ){
                if(child -> data_ < node_to_balance->data_ ){
                    node_to_balance->left_=child;
                } else {
                    node_to_balance->right_=child;
                }
            }
            if( node_to_balance == this->root_ ){
                NodeBalance(node_to_balance);
                this->root_ = node_to_balance;
                break;
            }
            NodeBalance(node_to_balance);
            child = node_to_balance;
        }
        return true;
    }
};

#endif //MLDSA_CPP_AVL_TREE_H
