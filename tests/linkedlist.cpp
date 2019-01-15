//
// Created by alanpark on 18. 10. 13.
//

#include "../src/linkedlist.h"

#include "gtest/gtest.h"

inline void PushBack_popBack_test(const int count) {
    LinkedList<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.PushBack(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.PopBack());
        ASSERT_EQ(nRet, count-1-i);
    }
    ASSERT_ANY_THROW(linkedlist1.PopBack());
}

inline void PushFront_PopFront_test(const int count) {
    LinkedList<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.PushFront(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.PopFront());
        ASSERT_EQ(nRet, count-1-i);
    }
    ASSERT_ANY_THROW(linkedlist1.PopFront());
}

inline void PushBack_PopFront_test(const int count) {
    LinkedList<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.PushBack(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.PopFront());
        ASSERT_EQ(nRet, i);
    }
    ASSERT_ANY_THROW(linkedlist1.PopFront());
}


inline void PushFront_popBack_test(const int count) {
    LinkedList<int> linkedlist1;
    ASSERT_TRUE(linkedlist1.empty());
    ASSERT_EQ(linkedlist1.size(), 0);
    for (int i=0;i<count; i++) {
        linkedlist1.PushBack(i);
        ASSERT_FALSE(linkedlist1.empty());
        ASSERT_EQ(linkedlist1.size(), i+1);
    }
    for (int i=0;i<count; i++) {
        int nRet=-1;
        ASSERT_NO_THROW(nRet=linkedlist1.PopFront());
        ASSERT_EQ(nRet, i);
    }
    ASSERT_ANY_THROW(linkedlist1.PopFront());
}

TEST(LinkedList, empty_front_back_test) {
    LinkedList<int> linked_list;
    ASSERT_ANY_THROW(linked_list.Front());
    ASSERT_ANY_THROW(linked_list.Back());
}

TEST(LinkedList, zero_item_PushBack) {
    PushBack_popBack_test(0);
}

TEST(LinkedList, one_item_PushBack) {
    PushBack_popBack_test(1);
}

TEST(LinkedList, two_item_PushBack) {
    PushBack_popBack_test(2);
}

TEST(LinkedList, three_item_PushBack) {
    PushBack_popBack_test(3);
}

TEST(LinkedList, zero_item_PushFront) {
    PushFront_PopFront_test(0);
}

TEST(LinkedList, one_item_PushFront) {
    PushFront_PopFront_test(1);
}

TEST(LinkedList, two_item_PushFront) {
    PushFront_PopFront_test(2);
}

TEST(LinkedList, three_item_PushFront) {
    PushFront_PopFront_test(3);
}

TEST(LinkedList, zero_item_PushBack_PopFront) {
    PushBack_PopFront_test(0);
}

TEST(LinkedList, one_item_PushBack_PopFront) {
    PushBack_PopFront_test(1);
}

TEST(LinkedList, two_item_PushBack_PopFront) {
    PushBack_PopFront_test(2);
}

TEST(LinkedList, three_item_PushBack_PopFront) {
    PushBack_PopFront_test(3);
}

TEST(LinkedList, zero_item_PushFront_popBack) {
    PushFront_popBack_test(0);
}

TEST(LinkedList, one_item_PushFront_popBack) {
    PushFront_popBack_test(1);
}

TEST(LinkedList, two_item_PushFront_popBack) {
    PushFront_popBack_test(2);
}

TEST(LinkedList, three_item_PushFront_popBack) {
    PushFront_popBack_test(3);
}

void forward_iteration_items(const size_t count) {
    LinkedList<int> listTest;
    ASSERT_EQ(listTest.size(), 0);
    ASSERT_TRUE(listTest.empty());
    for(int i=0;i<count;i++) {
        listTest.PushBack(i);
        ASSERT_EQ(listTest.Back(), i);
        ASSERT_EQ(listTest.Front(), 0);
        ASSERT_EQ(listTest.size(), i+1);
        ASSERT_FALSE(listTest.empty());
    }

    auto iterator=listTest.begin();
    ASSERT_EQ(listTest.size(), count);
    for(int i=0;i<count;i++)
    {
        ASSERT_TRUE(iterator.valid());
        ASSERT_EQ(iterator.Next(), i);
    }

    ASSERT_FALSE(iterator.valid());
    ASSERT_ANY_THROW(iterator.Next());
}

void Backward_iteration_items(const size_t count) {
    LinkedList<int> listTest;
    ASSERT_EQ(listTest.size(), 0);
    ASSERT_TRUE(listTest.empty());
    for(int i=0;i<count;i++) {
        listTest.PushBack(i);
        ASSERT_EQ(listTest.Back(), i);
        ASSERT_EQ(listTest.Front(), 0);
        ASSERT_EQ(listTest.size(), i+1);
        ASSERT_FALSE(listTest.empty());
    }

    auto iterator=listTest.end();
    for(int i=0;i<count;i++)
    {
        ASSERT_TRUE(iterator.valid());
        ASSERT_EQ(iterator.Prev(), count-1-i);
    }

    ASSERT_FALSE(iterator.valid());
    ASSERT_ANY_THROW(iterator.Prev());
}

TEST(LinkedList, one_item_iteration) {
    forward_iteration_items(1);
}

TEST(LinkedList, two_item_iteration) {
    forward_iteration_items(2);
}

TEST(LinkedList, three_item_iteration) {
    forward_iteration_items(3);
}

TEST(LinkedList, one_item_Backward_iteration) {
    Backward_iteration_items(1);
}

TEST(LinkedList, two_item_Backward_iteration) {
    Backward_iteration_items(2);
}

TEST(LinkedList, three_item_Backward_iteration) {
    Backward_iteration_items(3);
}

TEST(LinkedList, iterator_insertAfter_one_item) {
    LinkedList<int> listTest;
    listTest.PushBack(1);
    auto iter=listTest.begin();
    listTest.insertAfter(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, iterator_insertAfter_middle_of_two_item) {
    LinkedList<int> listTest;
    listTest.PushBack(1);
    listTest.PushBack(3);
    auto iter=listTest.begin();
    listTest.insertAfter(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, iterator_insertAfter_end_of_two_item) {
    LinkedList<int> listTest;
    listTest.PushBack(1);
    listTest.PushBack(2);
    auto iter=listTest.begin();
    iter.Next();
    listTest.insertAfter(iter, 3);
    iter = listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, iterator_insertBefore_one_item) {
    LinkedList<int> listTest;
    listTest.PushBack(2);
    auto iter=listTest.begin();
    listTest.insertBefore(iter, 1);
    iter=listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, end_iterator_insertAfter_one_item) {
    LinkedList<int> listTest;
    listTest.PushBack(1);
    auto iter=listTest.end();
    listTest.insertAfter(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, end_iterator_insertAfter_middle_of_two_item) {
    LinkedList<int> listTest;
    listTest.PushBack(1);
    listTest.PushBack(3);
    auto iter=listTest.end();
    listTest.insertBefore(iter, 2);
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Prev(), listTest.size()-i);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, end_iterator_insertAfter_end_of_two_item) {
    LinkedList<int> listTest;
    listTest.PushBack(1);
    listTest.PushBack(2);
    auto iter=listTest.end();
    listTest.insertAfter(iter, 3);
    iter = listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, end_iterator_insertBefore_one_item) {
    LinkedList<int> listTest;
    listTest.PushBack(2);
    auto iter=listTest.end();
    listTest.insertBefore(iter, 1);
    iter=listTest.begin();
    for(int i=0;i<listTest.size();i++){
        ASSERT_EQ(iter.Next(), i+1);
    }
    ASSERT_ANY_THROW(iter.Next());
}

TEST(LinkedList, false_polite_visitor_test) {
    class AccumulateVisitor : public Visitor<int> {
    public:
        bool PoliteVisit(const int& input) override {
            return false;
        }
    };
    LinkedList<int> a;
    a.PushBack(1);
    AccumulateVisitor visitor1;
    a.PoliteAccept(visitor1);
}

TEST(LinkedList, false_visitor_test) {
    class AccumulateVisitor : public Visitor<int> {
    public:
        bool PoliteVisit(const int& input) override {
            return false;
        }
    };
    LinkedList<int> a;
    a.PushBack(1);
    AccumulateVisitor visitor1;
    a.Accept(visitor1);
}

TEST(LinkedList, visitor_test ) {
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
            return false;
        }

        bool Visit(int& input) override {
            input++;
            return true;
        }
    };

    AccumulateVisitor visitor1;
    AddOneVisitor visitor2;

    LinkedList<int> linkedlist1;
    for(int i=0;i<10;i++) linkedlist1.PushBack(i);
    linkedlist1.PoliteAccept(visitor1);
    auto array=visitor1.GetArray();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i],i);
    ASSERT_EQ(linkedlist1.size(), array.size());
    linkedlist1.Accept(visitor2);
    visitor1.Clear();
    linkedlist1.PoliteAccept(visitor1);
    array=visitor1.GetArray();
    for(int i=0;i<10;i++) ASSERT_EQ(array[i],i+1);
    ASSERT_EQ(linkedlist1.size(), array.size());
}