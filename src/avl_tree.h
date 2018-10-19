//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_AVL_TREE_H
#define MLDSA_CPP_AVL_TREE_H

#include "binary_search_tree.h"
#include <memory>

template<class T>
class AVLTree : public BinarySearchTree<T> {
protected:
    typedef std::shared_ptr<BinaryTreeNode<T>> Node_;
    void RotateLeft() {
        Node_ right_node = this->root_->right_;
        this->root_->right_ = right_node->left_;
        right_node->left_ = this->root_;
        this->root_ = right_node;
    }

    void RotateRight() {
        Node_ left_node = this->root_->left_;
        this->root_->left_ = left_node->right_;
        left_node->right_ = this->root_;
        this->root_ = left_node;
    }

    void RotateLeftAndLeft(){
        if( this->root_->right_ != nullptr ){
            AVLTree<T> tree;
            tree.root_=this->root_->right_;
            tree.RotateLeft();
            this->root_->right_=tree.root_;
        }
        RotateLeft();
    }

    void RotateRightAndRight(){
        if( this->root_->left_ != nullptr ){
            AVLTree<T> tree;
            tree.root_=this->root_->left_;
            tree.RotateRight();
            this->root_->left_=tree.root_;
        }
        RotateRight();
    }

    void RotateRightAndLeft(){
        if( this->root_->right_ != nullptr ){
            AVLTree<T> tree;
            tree.root_=this->root_->right_;
            tree.RotateRight();
            this->root_->right_ = tree.root_;
        }
        RotateLeft();
    }

    void RotateLeftAndRight(){
        if( this->root_->left_ != nullptr ){
            AVLTree<T> tree;
            tree.root_=this->root_->left_;
            tree.RotateLeft();
            this->root_->left_ = tree.root_;
        }
        RotateRight();
    }
public:
    typedef std::shared_ptr<AVLTree<T>> AVLTree_;

    static AVLTree_ Create() {
        return std::make_shared<AVLTree<T>>();
    }

    AVLTree() = default;

    bool Balance() {
        if(this->root_ == nullptr or ( this->root_->left_ == nullptr and this->root_->right_ == nullptr ) ) return false;
        const int level_diff=this->root_->GetLevelDiff();
        if( level_diff > 1 ) {
            const auto left_level_diff=this->root_->left_->GetLevelDiff();
            if ( left_level_diff > 1 )
            {
                RotateRightAndRight();
            } else if ( left_level_diff > 0 ) {
                RotateRight();
            } else {
                RotateLeftAndRight();
            }
        } else if( level_diff < -1){
            const auto right_level_diff=this->root_->right_->GetLevelDiff();
            if ( right_level_diff < -1 )
            {
                RotateLeftAndLeft();
            } else if( right_level_diff < 0 ) {
                RotateLeft();
            } else {
                RotateRightAndLeft();
            }
        } else {
            return false;
        }
        return true;
    }

    void Insert(const T& data) override {
        BinarySearchTree<T>::Insert(data);
        Balance();
    }

    bool Remove(const T& data) override {
        if(!BinarySearchTree<T>::Remove(data))
            return false;
        Balance();
        return true;
    }
};

#endif //MLDSA_CPP_AVL_TREE_H
