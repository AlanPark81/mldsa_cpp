//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_VISITOR_H
#define MLDSA_CPP_VISITOR_H
#include <memory>
#include <vector>

using namespace std;

template<class T>
class PoliteVisitor {
public:
    virtual bool PoliteVisit(const T &) = 0;
};

template<class T>
class Visitor : public PoliteVisitor<T> {
public:
    virtual bool Visit(T & data) {
        return this->PoliteVisit(data);
    }
};

template <class T>
class PoliteVisitorAcceptor {
public:
    virtual bool PoliteAccept(PoliteVisitor<T>&) const = 0;
};

template<class T>
class VisitorAcceptor : public PoliteVisitorAcceptor<T> {
public:
    virtual bool Accept(Visitor<T> & visitor) = 0;
};

template<class T>
struct StoreVisitor : PoliteVisitor<T> {
    shared_ptr<vector<T>> array_;
    StoreVisitor() {
        array_ = make_shared<vector<T>>();
    }

    bool PoliteVisit(const T& data) {
        array_->push_back(data);
        return true;
    }

    shared_ptr<vector<T>> GetSeq() {
        return array_;
    }
};

#endif //MLDSA_CPP_VISITOR_H
