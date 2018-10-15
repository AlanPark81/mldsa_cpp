//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_AVL_TREE_H
#define MLDSA_CPP_AVL_TREE_H

#include "binary_search_tree.h"

template<class T>
class AVLTree : public BinarySearchTree<T> {
protected:
    void RotateLeft() {

    }

    void RotateRight() {

    }

    void RotateRightAndLeft(){

    }

    void RotateLeftAndRight(){

    }
public:
    bool Balance() {
        if(root_ == nullptr) return false;
        const int level_diff=root_->GetLevelDiff();
        if( level_diff < -1 ) {
            if(root_->left_ == nullptr ) {
                return false;
            }

            if(root_->left_->GetLevelDiff() > 0 ) {
                RotateLeft();
            } else {
                RotateRightAndLeft();
            }
        } else if( level_diff > 1){
            if(root_->right_ == nullptr ){
                return false;
            }
            if(root_->right_->GetLevelDiff() < 0 ) {
                RotateRight();
            } else {
                RotateLeftAndRight();
            }
        } else {
            return false;
        }
        return true;
    }

    void Insert(const T& data) {
        BinarySearchTree<T>::Insert(data);
        Balance();
    }

    bool Remove(const T&) {
        if(!BinarySearchTree::Remove(data))
            return false;
        Balance();
        return true;
    }
};

#endif //MLDSA_CPP_AVL_TREE_H
