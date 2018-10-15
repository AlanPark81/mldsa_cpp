//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_VISITOR_H
#define MLDSA_CPP_VISITOR_H

template<class T>
class Visitor {
public:
    virtual bool Visit(T &) = 0;
};

template<class T>
class VisitorAcceptor {
public:
    virtual bool Accept(Visitor<T> &) = 0 ;
};
#endif //MLDSA_CPP_VISITOR_H
