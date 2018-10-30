//
// Created by alanpark on 18. 10. 26.
//

#ifndef MLDSA_CPP_HASH_TABLE_H
#define MLDSA_CPP_HASH_TABLE_H
#include <functional>
#include <memory>
#include "set.h"

using namespace std;

template<class T, const size_t Length=256>
class HashTable : public Set<T> {
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
    typedef shared_ptr<HashTable<T>> HashTable_;
    static HashTable_ Create(const HashFunc& fn = [](int a) { return a%256; } ) {
        return make_shared<HashTable<T>>(fn);
    }

    bool empty() const {
        for(int i=0;i<Length; i++) {
            if(array[i]!=nullptr) {
                return false;
            }
        }
        return true;
    }

    size_t size() const {
        size_t count=0;
        for(int i=0;i<Length; i++) {
            if(array[i]!=nullptr) {
                count++;
            }
        }
        return count;
    }

    bool Contains(const T& data) const override {
        try {
            auto index = FindDataIndex(data);
            return (array[index]!=nullptr);
        } catch( exception&){
            return false;
        }
    }

    std::shared_ptr<std::vector<T>> GetAllElements() const override {
        auto to_return = make_shared<std::vector<T>>();
        for(int i = 0;i < Length; i++) {
            if( array[i] != nullptr ){
                to_return->push_back(*array[i]);
            }
        }
        return to_return;
    }

    void Insert(const T &data) {
        auto index = FindEmptyIndex(data);
        array[index] = make_shared<T>();
        *(array[index]) = data;
    }

    const T& Retrieve(const T &data) const {
        auto index = FindDataIndex(data);
        return *(array[index]);
    }

    bool PoliteAccept(PoliteVisitor<T>& visitor) const override {
        for(int i = 0;i < Length ; i++) {
            if(array[i] != nullptr && !visitor.PoliteVisit(*array[i]))
                return false;
        }
        return true;
    }
};
#endif //MLDSA_CPP_HASH_TABLE_H
