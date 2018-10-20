//
// Created by alanpark on 18. 10. 15.
//

#include "../src/avl_tree.h"
#include "gtest/gtest.h"

TEST(AVLTree, insert_once) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_TRUE(bst.Contains(0));
}

TEST(AVLTree, insert_twice) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
}

TEST(AVLTree, insert_three_times) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
}

TEST(AVLTree, insert_four_times) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
}

TEST(AVLTree, insert_once_and_delete) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));

}

TEST(AVLTree, insert_twice_and_delete) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
}

TEST(AVLTree, insert_three_times_and_delete) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
}

TEST(AVLTree, insert_four_times_and_delete) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));

    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(-2));
    ASSERT_FALSE(bst.Contains(-2));
}

TEST(AVLTree, insert_seven_times_and_delete) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-3));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(2));
    ASSERT_TRUE(bst.Contains(3));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
    ASSERT_TRUE(bst.Contains(-3));

    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(2));
    ASSERT_FALSE(bst.Contains(2));
    ASSERT_TRUE(bst.Remove(3));
    ASSERT_FALSE(bst.Contains(3));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(-2));
    ASSERT_FALSE(bst.Contains(-2));
    ASSERT_TRUE(bst.Remove(-3));
    ASSERT_FALSE(bst.Contains(-3));

    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-3));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(2));
    ASSERT_TRUE(bst.Contains(3));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
    ASSERT_TRUE(bst.Contains(-3));

    ASSERT_TRUE(bst.Remove(-3));
    ASSERT_FALSE(bst.Contains(-3));
    ASSERT_TRUE(bst.Remove(-1));
    ASSERT_FALSE(bst.Contains(-1));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(3));
    ASSERT_FALSE(bst.Contains(3));
    ASSERT_TRUE(bst.Remove(2));
    ASSERT_FALSE(bst.Contains(2));
    ASSERT_TRUE(bst.Remove(-2));
    ASSERT_FALSE(bst.Contains(-2));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
}

TEST(AVLTree, totally_unbalanced_input_left) {
    AVLTree<int> bst1;
    for(int i=7;i>=0;i--) bst1.Insert(i);
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool Visit(int& input) override {
            array.push_back(input);
            return true;
        }

        std::vector<int> GetArray() const {
            return array;
        }

        void Clear() {
            array.clear();
        }
    };
    AccumulateVisitor visitor1;
    bst1.Accept(visitor1);

    int expected_seq[8] = {4,2,6,1,3,5,7,0};
    for(auto i = 0; i < 8 ; i++){
        ASSERT_EQ(visitor1.GetArray()[i], expected_seq[i]);
    }
}

TEST(AVLTree, totally_unbalanced_input_right) {
    AVLTree<int> bst1;
    for(int i=0;i<8;i++) bst1.Insert(i);
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool Visit(int& input) override {
            array.push_back(input);
            return true;
        }

        std::vector<int> GetArray() const {
            return array;
        }

        void Clear() {
            array.clear();
        }
    };
    AccumulateVisitor visitor1;
    bst1.Accept(visitor1);
    int expected_seq[8] = {3, 1, 5, 0, 2, 4, 6, 7};
    for(auto i = 0; i < 8 ; i++){
        ASSERT_EQ(visitor1.GetArray()[i], expected_seq[i]);
    }
}

TEST(AVLTree, visitor_test ) {
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool Visit(int& input) override {
            array.push_back(input);
            return true;
        }

        std::vector<int> GetArray() const {
            return array;
        }

        void Clear() {
            array.clear();
        }
    };

    class AddOneVisitor : public Visitor<int> {
    public:
        bool Visit(int& input) override {
            input++;
            return true;
        }
    };

    AccumulateVisitor visitor1;
    AddOneVisitor visitor2;

    AVLTree<int> bst1;
    for(int i=0;i<10;i++) bst1.Insert(i);
    bst1.Accept(visitor1);
    auto array=visitor1.GetArray();
    for(auto data : array ) ASSERT_TRUE(bst1.Contains(data));
    ASSERT_EQ(*std::min_element(array.begin(), array.end()), 0);
    ASSERT_EQ(*std::max_element(array.begin(), array.end()), 9);
    ASSERT_EQ(array.size(), bst1.size());
    bst1.Accept(visitor2);
    visitor1.Clear();
    bst1.Accept(visitor1);
    array=visitor1.GetArray();
    for(auto data : array ) ASSERT_TRUE(bst1.Contains(data));
    ASSERT_EQ(*std::min_element(array.begin(), array.end()), 1);
    ASSERT_EQ(*std::max_element(array.begin(), array.end()), 10);
    ASSERT_EQ(array.size(), bst1.size());
}