//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_VISITOR_H
#define MLDSA_CPP_VISITOR_H
template<class T>
class PoliteVisitor {
public:
    virtual bool PoliteVisit(const T &) = 0;
};

template<class T>
class Visitor : public PoliteVisitor<T> {
public:
    virtual bool PoliteVisit(const T& data) {
        return false;
    }

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
    virtual bool Accept(Visitor<T> & visitor) {
        return this->PoliteAccept((PoliteVisitor<T>&)visitor);
    }
};
#endif //MLDSA_CPP_VISITOR_H
