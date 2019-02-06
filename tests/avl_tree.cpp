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
    ASSERT_FALSE(bst.Remove(0));
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_FALSE(bst.Remove(-3));
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

TEST(AVLTree, insert_17_times_and_delete) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(-8));
    ASSERT_NO_THROW(bst.Insert(-7));
    ASSERT_NO_THROW(bst.Insert(-6));
    ASSERT_NO_THROW(bst.Insert(-5));
    ASSERT_NO_THROW(bst.Insert(-4));
    ASSERT_NO_THROW(bst.Insert(-3));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(8));
    ASSERT_NO_THROW(bst.Insert(7));
    ASSERT_NO_THROW(bst.Insert(6));
    ASSERT_NO_THROW(bst.Insert(5));
    ASSERT_NO_THROW(bst.Insert(4));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Remove(0));
}

TEST(AVLTree, right_only_left) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_TRUE(bst.Remove(2));
}

TEST(AVLTree, left_only_left) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(4));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_TRUE(bst.Remove(4));
}

TEST(AVLTree, left_only_left_left) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(3));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_TRUE(bst.Remove(3));
}

TEST(AVLTree, middle_number) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(-8));
    ASSERT_NO_THROW(bst.Insert(8));
    ASSERT_NO_THROW(bst.Insert(-4));
    ASSERT_NO_THROW(bst.Insert(4));
    ASSERT_NO_THROW(bst.Insert(-12));
    ASSERT_NO_THROW(bst.Insert(12));
    ASSERT_NO_THROW(bst.Insert(-11));
    ASSERT_NO_THROW(bst.Insert(11));
    ASSERT_TRUE(bst.Remove(0));
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
        bool PoliteVisit(const int& input) override {
            array.push_back(input);
            return true;
        }

        std::vector<int> GetArray() const {
            return array;
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
        bool PoliteVisit(const int& input) override {
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
    bst1.PoliteAccept(visitor1);
    int expected_seq[8] = {3, 1, 5, 0, 2, 4, 6, 7};
    for(auto i = 0; i < 8 ; i++){
        ASSERT_EQ(visitor1.GetArray()[i], expected_seq[i]);
    }
}

TEST(AVLTree, left_right) {
    AVLTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_NO_THROW(bst.Insert(2));
    ASSERT_NO_THROW(bst.Insert(-4));
    ASSERT_NO_THROW(bst.Insert(4));
    ASSERT_NO_THROW(bst.Insert(-8));
    ASSERT_NO_THROW(bst.Insert(8));
    ASSERT_NO_THROW(bst.Insert(-5));
    ASSERT_NO_THROW(bst.Insert(5));
    ASSERT_TRUE(bst.Remove(0));
}

TEST(AVLTree, visitor_test ) {
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool PoliteVisit(const int& input) override {
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
        bool PoliteVisit(const int& input) override {
            return input < INT32_MAX;
        }

        bool Visit(int& input) override {
            if (!PoliteVisit(input)) return false;
            input++;
            return true;
        }
    };

    AccumulateVisitor visitor1;
    AddOneVisitor visitor2;

    AVLTree<int> bst1;
    for(int i=0;i<10;i++) bst1.Insert(i);
    bst1.PoliteAccept(visitor1);
    auto array=visitor1.GetArray();
    for(auto data : array ) ASSERT_TRUE(bst1.Contains(data));
    ASSERT_EQ(*std::min_element(array.begin(), array.end()), 0);
    ASSERT_EQ(*std::max_element(array.begin(), array.end()), 9);
    ASSERT_EQ(array.size(), bst1.size());
    bst1.Accept(visitor2);
    visitor1.Clear();
    bst1.PoliteAccept(visitor1);
    array=visitor1.GetArray();
    for(auto data : array ) ASSERT_TRUE(bst1.Contains(data));
    ASSERT_EQ(*std::min_element(array.begin(), array.end()), 1);
    ASSERT_EQ(*std::max_element(array.begin(), array.end()), 10);
    ASSERT_EQ(array.size(), bst1.size());
}

TEST(AVLTree, inorder_preorder_postorder_visitor_test ) {
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool PoliteVisit(const int &input) override {
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

    AVLTree<int> bst1;
    for (int i = 0; i < 10; i++) bst1.Insert(i);
    bst1.InvitePreorder(visitor1);
    auto array = visitor1.GetArray();
    visitor1.Clear();
    ASSERT_EQ(array.size(), 10);
    int expected_seq[]={3,1,0,2,7,5,4,6,8,9};
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(array[i], expected_seq[i]);
    }
    bst1.InviteInorder(visitor1);
    array = visitor1.GetArray();
    visitor1.Clear();
    for (int i = 0; i < 10; i++) ASSERT_EQ(array[i], i);
    bst1.InvitePostorder(visitor1);
    array = visitor1.GetArray();
    visitor1.Clear();
    ASSERT_EQ(array.size(), 10);
    int expected_seq2[]={0,2,1,4,6,5,9,8,7,3};
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(array[i], expected_seq2[i]);
    }
    ASSERT_EQ(array.size(), bst1.size());
}