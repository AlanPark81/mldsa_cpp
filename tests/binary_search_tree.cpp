//
// Created by alanpark on 18. 10. 15.
//

#include "../src/binary_search_tree.h"
#include "gtest/gtest.h"

TEST(BinarySearchTree, remove_from_empty) {
    BinarySearchTree<int> bst;
    ASSERT_FALSE(bst.Remove(0));
}

TEST(BinarySearchTree, remove_not_found) {
    BinarySearchTree<int> bst;
    bst.Insert(1);
    ASSERT_FALSE(bst.Remove(0));
}

TEST(BinarySearchTree, insert_once) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_TRUE(bst.Contains(0));
}

TEST(BinarySearchTree, insert_twice) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
}

TEST(BinarySearchTree, insert_three_times) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
}

TEST(BinarySearchTree, insert_four_times) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_NO_THROW(bst.Insert(-1));
    ASSERT_NO_THROW(bst.Insert(-2));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Contains(-1));
    ASSERT_TRUE(bst.Contains(-2));
}

TEST(BinarySearchTree, insert_once_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));

}

TEST(BinarySearchTree, insert_twice_and_delete) {
    BinarySearchTree<int> bst;
    ASSERT_NO_THROW(bst.Insert(0));
    ASSERT_NO_THROW(bst.Insert(1));
    ASSERT_TRUE(bst.Contains(0));
    ASSERT_TRUE(bst.Contains(1));
    ASSERT_TRUE(bst.Remove(0));
    ASSERT_FALSE(bst.Contains(0));
    ASSERT_TRUE(bst.Remove(1));
    ASSERT_FALSE(bst.Contains(1));
}

TEST(BinarySearchTree, insert_three_times_and_delete) {
    BinarySearchTree<int> bst;
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

TEST(BinarySearchTree, insert_four_times_and_delete) {
    BinarySearchTree<int> bst;
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

TEST(BinarySearchTree, insert_17_times_and_delete) {
    BinarySearchTree<int> bst;
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
}

TEST(BinarySearchTree, insert_seven_times_and_delete) {
    BinarySearchTree<int> bst;
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

TEST(BinarySearchTree, visitor_test) {
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool PoliteVisit(const int& input) override {
            if (input < 0) return false;
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
            return false;
        }

        bool Visit(int& input) override {
            input++;
            return true;
        }
    };

    AccumulateVisitor visitor1;
    AddOneVisitor visitor2;

    BinarySearchTree<int> bst1;
    for(int i=0;i<10;i++) bst1.Insert(i);
    bst1.Accept(visitor1);
    auto array=visitor1.GetArray();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i],i);
    ASSERT_EQ(array.size(), bst1.size());
    bst1.Accept(visitor2);
    visitor1.Clear();
    bst1.Accept(visitor1);
    array=visitor1.GetArray();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i],i+1);
    ASSERT_EQ(array.size(), bst1.size());
    BinarySearchTree<int> bst2;
    bst2.Insert(-1);
    visitor1.Clear();
    bst2.Accept(visitor1);
    auto empty_array = visitor1.GetArray();
    ASSERT_TRUE(empty_array.empty());
}

TEST(BinarySearchTree, inorder_preorder_postorder_visitor_test ) {
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

    BinarySearchTree<int> bst1;
    for(int i=0;i<10;i++) bst1.Insert(i);
    bst1.InvitePreorder(visitor1);
    auto array=visitor1.GetArray();
    visitor1.Clear();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i],i);
    bst1.InviteInorder(visitor1);
    array=visitor1.GetArray();
    visitor1.Clear();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i],i);
    bst1.InvitePostorder(visitor1);
    array=visitor1.GetArray();
    visitor1.Clear();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i], 9-i);
    ASSERT_EQ(array.size(), bst1.size());
}

TEST(BinarySearchTree, inorder_preorder_postorder_visitor_test2) {
    class AccumulateVisitor : public Visitor<int> {
        std::vector<int> array;
    public:
        bool PoliteVisit(const int& input) override {
            return false;
        }

        std::vector<int> GetArray() const {
            return array;
        }

        void Clear() {
            array.clear();
        }
    };

    AccumulateVisitor visitor1;

    BinarySearchTree<int> bst1;
    for(int i=0;i<10;i++) bst1.Insert(i);
    for(int i=1;i<10;i++) bst1.Insert(-i);
    ASSERT_FALSE(bst1.InvitePreorder(visitor1));
    ASSERT_FALSE(bst1.InviteInorder(visitor1));
    ASSERT_FALSE(bst1.InvitePostorder(visitor1));
}