//
// Created by alanpark on 18. 10. 15.
//

#ifndef MLDSA_CPP_VISITOR_H
#define MLDSA_CPP_VISITOR_H

template<class T>
class visitor {
public:
    virtual bool visit(T&) = 0;
};

template<class T>
class visitor_acceptor {
public:
    virtual bool accept(visitor<T>&) = 0 ;
};
#endif //MLDSA_CPP_VISITOR_H
