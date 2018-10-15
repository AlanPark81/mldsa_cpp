//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_LINKEDLIST_H
#define MLDSA_CPP_LINKEDLIST_H

#include <bits/exception.h>
#include <memory>
#include "visitor.h"

template <class T>
class ListNode {
public:
    std::shared_ptr<ListNode> prev, next;
    T data;

    explicit ListNode(const T& data) : prev(nullptr), next(nullptr), data(data) {}
};

template<class T>
class LinkedListIterator {
public:
    std::shared_ptr<ListNode<T>> curr_node;
    explicit LinkedListIterator(const std::shared_ptr<ListNode<T>>& node) : curr_node(node) {}

    T Next() {
        if(curr_node == nullptr)
            throw std::exception();
        const auto ret_val=curr_node->data;
        curr_node=curr_node->next;
        return ret_val;
    }

    bool valid() const { return curr_node != nullptr; }

    T Prev() {
        if(curr_node == nullptr)
            throw std::exception();
        const auto ret_val=curr_node->data;
        curr_node=curr_node->prev;
        return ret_val;
    }
};

template <class T>
class LinkedList : public VisitorAcceptor<T>{
    std::shared_ptr<ListNode<T>> head, tail;
    size_t list_size;
public:
    LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    void PushBack(const T& data) {
        if( head == nullptr ) {
            head = std::shared_ptr<ListNode<T>>(new ListNode(data));
            tail = head;
        } else {
            std::shared_ptr<ListNode<T>> new_node = std::make_shared<ListNode<T>>(data);
            new_node->prev = tail;
            tail->next=new_node;
            tail=new_node;
        }
        list_size++;
    }

    void PushFront(const T& data) {
        if( head == nullptr ) {
            head = std::make_shared<ListNode<T>>(data);
            tail = head;
        } else {
            std::shared_ptr<ListNode<T>> new_node = std::make_shared<ListNode<T>>(data);
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        list_size++;
    }

    T PopFront() {
        if( head == nullptr) {
            throw std::exception();
        } else if ( head == tail ) {
            std::shared_ptr<ListNode<T>> node = head;
            head = nullptr;
            tail = nullptr;
            list_size--;
//            ASSERT_EQ(list_size, 0);
            return node->data;
        } else {
            std::shared_ptr<ListNode<T>> node = head;
            head = head->next;
            head->prev = nullptr;
            list_size--;
            return node->data;
        }
    }

    T PopBack() {
        if( head == nullptr) {
            throw std::exception();
        } else if ( head == tail ) {
            std::shared_ptr<ListNode<T>> node = head;
            head = nullptr;
            tail = nullptr;
            list_size--;
//            ASSERT_EQ(list_size, 0);
            return node->data;
        } else {
            std::shared_ptr<ListNode<T>> node = tail;
            tail = tail->prev;
            tail->next = nullptr;
            list_size--;
            return node->data;
        }
    }

    bool empty() const { return head == nullptr; }

    T& Front() const {
        if(empty()) {
            throw std::exception();
        }
        return head->data;
    }
    T& Back() const {
        if(empty()) {
            throw std::exception();
        }
        return tail->data;
    }

    size_t size() const { return list_size; }

    LinkedListIterator<T> begin() {
        if(empty()) { throw std::exception(); }
        return LinkedListIterator<T>(head);
    }

    LinkedListIterator<T> end() {
        if(empty()) { throw std::exception(); }
        return LinkedListIterator<T>(tail);
    }

    void insertAfter(LinkedListIterator<T>& location, const T& data) {
        auto node=location.curr_node;
        auto new_node=std::make_shared<ListNode<T>>(data);

        new_node->prev = node;
        new_node->next = node->next;
        if( node == tail)
        {
            tail=new_node;
        } else {
            node->next->prev = new_node;
        }
        node->next = new_node;
        list_size++;
    }

    void insertBefore(LinkedListIterator<T>& location, const T& data) {
        auto node=location.curr_node;
        auto new_node=std::make_shared<ListNode<T>>(data);
        new_node->prev = node->prev;
        new_node->next = node;
        if(head == node) {
            head = new_node;
        } else {
            node->prev->next = new_node;
        }
        node->prev = new_node;
        list_size++;
    }

    bool Accept(Visitor<T>& visitor1) {
        std::shared_ptr<ListNode<T>> ptr=this->head;
        while( ptr != nullptr ){
            if(!visitor1.Visit(ptr->data))
                return false;
            ptr=ptr->next;
        }
        return true;
    }
};
#endif //MLDSA_CPP_LINKEDLIST_H
