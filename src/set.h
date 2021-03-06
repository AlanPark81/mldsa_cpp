//
// Created by alanpark on 18. 10. 17.
//

#ifndef MLDSA_CPP_SET_H
#define MLDSA_CPP_SET_H
#include <vector>
#include <memory>
#include "visitor.h"
#include <functional>

template<class T>
class AVLTree;

template <class T >
class Set : public PoliteVisitorAcceptor<T>{
public:
    typedef std::shared_ptr<Set<T>> Set_;
    static Set_ CreateSet() {
        return std::make_shared<AVLTree<T>>();
    }

    static Set_ CreateSetWith(const std::vector<T> &elements) {
        auto ret_val = std::make_shared<AVLTree<T>>();
        for( auto data : elements ) {
            ret_val->Insert(data);
        }
        return ret_val;
    }

    static Set_ CreateSetWith(const T *elements, const int length) {
        auto ret_val = std::make_shared<AVLTree<T>>();
        for( auto i = 0 ; i<length ; i++ ) {
            ret_val->Insert(elements[i]);
        }
        return ret_val;
    }

    bool IsDistinctWith(const Set<T>& another_set) const {
        class NonInclusionTestVisior : public PoliteVisitor<T> {
            const Set<T>& another_set;
        public:
            explicit NonInclusionTestVisior(const Set<T>& check_set) : another_set(check_set){}
            bool PoliteVisit(const T& data) {
                return !( another_set.Contains(data) );
            }
        } visitor(another_set);

        return this->PoliteAccept(visitor);
    }
    Set_ GetSubsetSatisfying(const std::function<bool(const T&)>& condition_checker) const {
        auto set = CreateSet();
        auto elements = this->GetAllElements();
        for(auto elem : *elements ) {
            if(condition_checker(elem))
                set->Insert(elem);
        }
        return set;
    }

    virtual bool empty() const = 0;
    virtual void Insert(const T&) = 0;
    virtual bool Contains(const T&) const = 0;
    virtual std::shared_ptr<std::vector<T>> GetAllElements() const = 0;
};

template<class T>
std::shared_ptr<Set<T>> Intersect(const Set<T>& set_a, const Set<T>& set_b){
    const auto elements_in_a = set_a.GetAllElements();
    auto set_to_return = Set<T>::CreateSet();
    for ( auto element : *elements_in_a ) {
        if(set_b.Contains(element)){
            set_to_return->Insert(element);
        }
    }
    return set_to_return;
}

template<class T>
std::shared_ptr<Set<T>> Union(const Set<T>& set_a, const Set<T>& set_b){
    const auto elements_in_a = set_a.GetAllElements();
    const auto elements_in_b = set_b.GetAllElements();
    auto set_to_return = Set<T>::CreateSet();
    for ( auto element : *elements_in_a ) {
        set_to_return->Insert(element);
    }
    for ( auto element : *elements_in_b ) {
        if(!set_a.Contains(element)) {
            set_to_return->Insert(element);
        }
    }

    return set_to_return;
}


template<class T>
std::shared_ptr<Set<T>> Difference(const Set<T>& set_a, const Set<T>& set_b){
    const auto elements_in_a = set_a.GetAllElements();
    auto set_to_return = Set<T>::CreateSet();
    for ( auto element : *elements_in_a ) {
        if(!set_b.Contains(element)){
            set_to_return->Insert(element);
        }
    }
    return set_to_return;
}
#endif //MLDSA_CPP_SET_H
