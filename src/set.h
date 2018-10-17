//
// Created by alanpark on 18. 10. 17.
//

#ifndef MLDSA_CPP_SET_H
#define MLDSA_CPP_SET_H
#include <vector>
#include <memory>

template<class T>
class AVLTree;

template <class T, class Container = AVLTree<T> >
class Set {
public:
    typedef std::shared_ptr<Set<T>> Set_;
    static Set_ Create() {
        return std::make_shared<Container>();
    }
    virtual bool empty() const = 0;
    virtual void Insert(const T&) = 0;
    virtual bool Contains(const T&) const = 0;
    virtual std::shared_ptr<std::vector<T>> GetAllElements() const = 0;
};

template<class T>
std::shared_ptr<Set<T>> Union(const Set<T>& set_a, const Set<T>& set_b){
    const auto elements_in_a = set_a.GetAllElements();
    auto set_to_return = Set<T>::Create();
    for ( auto element : *elements_in_a ) {
        if(set_b.Contains(element)){
            set_to_return->Insert(element);
        }
    }
    return set_to_return;
}

#endif //MLDSA_CPP_SET_H
