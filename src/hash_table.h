//
// Created by alanpark on 18. 10. 26.
//

#ifndef MLDSA_CPP_HASH_TABLE_H
#define MLDSA_CPP_HASH_TABLE_H

#include<functional>
#include <memory>
using namespace std;

template<class T, const size_t Length=256>
class HashTable {
    typedef size_t HashTableIndex;
    typedef function<HashTableIndex(const T&)> HashFunc;
    shared_ptr<T> array[Length];
    HashFunc hash;
protected:
    HashTableIndex FindEmptyIndex(const T& data) const {
        size_t index = hash(data) % Length;
        size_t count = 0;
        for( ; count < Length and array[index] != nullptr; count++ ){
            ++index%=Length;
        }

        if( count >= Length ) {
            throw exception();
        }
        return index;
    }

    HashTableIndex FindDataIndex(const T& data) const {
        size_t index = hash(data) % Length;
        size_t count = 0;
        for( ; count < Length and ( array[index] == nullptr or *array[index] != data ); count++ ){
            ++index%=Length;
        }

        if( count >= Length ) {
            throw exception();
        }
        return index;
    }
public:
    explicit HashTable(const HashFunc& fn ) : hash(fn) {}

    void Insert(const T &data) {
        auto index = FindEmptyIndex(data);
        array[index] = make_shared<T>();
        *(array[index]) = data;
    }

    const T& Retrieve(const T &data) const {
        auto index = FindDataIndex(data);
        return *(array[index]);
    }
};
#endif //MLDSA_CPP_HASH_TABLE_H
