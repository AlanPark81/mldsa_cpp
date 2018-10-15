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
public:
    bool Balance() {
        if(root_ == nullptr) return false;
        const size_t left_level=root_->left_->get_level();
        const size_t right_level=root_->right_->get_level();
        const int level_diff=(int)left_level - (int)right_level;
        if( level_diff < -1 ) {
            RotateLeft();
        } else if( level_diff > 1){
            RotateRight();
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
