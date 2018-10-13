//
// Created by alanpark on 18. 10. 13.
//

#ifndef MLDSA_CPP_LINKEDLIST_H
#define MLDSA_CPP_LINKEDLIST_H

#include <bits/exception.h>
#include <memory>

template <class T>
class listnode {
public:
    std::shared_ptr<listnode> prev, next;
    T data;

    explicit listnode(const T& data) : prev(nullptr), next(nullptr), data(data) {}
};

template<class T>
class linkedlist_iterator {
public:
    std::shared_ptr<listnode<T>> curr_node;
    explicit linkedlist_iterator(const std::shared_ptr<listnode<T>>& node) : curr_node(node) {}

    T next() {
        if(curr_node == nullptr)
            throw std::exception();
        const auto ret_val=curr_node->data;
        curr_node=curr_node->next;
        return ret_val;
    }

    bool valid() const { return curr_node != nullptr; }

    T prev() {
        if(curr_node == nullptr)
            throw std::exception();
        const auto ret_val=curr_node->data;
        curr_node=curr_node->prev;
        return ret_val;
    }
};

template <class T>
class linkedlist{
    std::shared_ptr<listnode<T>> head, tail;
    size_t list_size;
public:
    linkedlist() : head(nullptr), tail(nullptr), list_size(0) {}

    void push_back(const T& data) {
        if( head == nullptr ) {
            head = std::shared_ptr<listnode<T>>(new listnode(data));
            tail = head;
        } else {
            std::shared_ptr<listnode<T>> new_node = std::make_shared<listnode<T>>(data);
            new_node->prev = tail;
            tail->next=new_node;
            tail=new_node;
        }
        list_size++;
    }

    void push_front(const T& data) {
        if( head == nullptr ) {
            head = std::make_shared<listnode<T>>(data);
            tail = head;
        } else {
            std::shared_ptr<listnode<T>> new_node = std::make_shared<listnode<T>>(data);
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        list_size++;
    }

    T pop_front() {
        if( head == nullptr) {
            throw std::exception();
        } else if ( head == tail ) {
            std::shared_ptr<listnode<T>> node = head;
            head = nullptr;
            tail = nullptr;
            list_size--;
//            ASSERT_EQ(list_size, 0);
            return node->data;
        } else {
            std::shared_ptr<listnode<T>> node = head;
            head = head->next;
            head->prev = nullptr;
            list_size--;
            return node->data;
        }
    }

    T pop_back() {
        if( head == nullptr) {
            throw std::exception();
        } else if ( head == tail ) {
            std::shared_ptr<listnode<T>> node = head;
            head = nullptr;
            tail = nullptr;
            list_size--;
//            ASSERT_EQ(list_size, 0);
            return node->data;
        } else {
            std::shared_ptr<listnode<T>> node = tail;
            tail = tail->prev;
            tail->next = nullptr;
            list_size--;
            return node->data;
        }
    }

    bool empty() const { return head == nullptr; }

    T& front() const {
        if(empty()) {
            throw std::exception();
        }
        return head->data;
    }
    T& back() const {
        if(empty()) {
            throw std::exception();
        }
        return tail->data;
    }

    size_t size() const { return list_size; }

    linkedlist_iterator<T> begin() {
        if(empty()) { throw std::exception(); }
        return linkedlist_iterator<T>(head);
    }

    linkedlist_iterator<T> end() {
        if(empty()) { throw std::exception(); }
        return linkedlist_iterator<T>(tail);
    }

    void insert_after(linkedlist_iterator<T>& location, const T& data) {
        auto node=location.curr_node;
        auto new_node=std::make_shared<listnode<T>>(data);

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

    void insert_before(linkedlist_iterator<T>& location, const T& data) {
        auto node=location.curr_node;
        auto new_node=std::make_shared<listnode<T>>(data);
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
};
#endif //MLDSA_CPP_LINKEDLIST_H
