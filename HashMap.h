#ifndef HASHMAP_H
#define HASHMAP_H

#include "Vector.h" 
#include "List.h"   
#include "Algorithm.h" 

namespace MyStd {
    template<typename K>
    struct Hash;
}

template<typename K, typename V>
struct Pair {
    K key;
    V value;
    
    Pair() : key(), value() {}
    Pair(const K& k, const V& v) : key(k), value(v) {}
    Pair(K&& k, V&& v) : key(MyStd::move(k)), value(MyStd::move(v)) {}

    bool operator==(const Pair& other) const {
        return key == other.key;
    }
};

template<typename K, typename V>
class HashMap {
private:
    using KeyValuePair = Pair<K, V>;
    Vector<List<KeyValuePair>> _buckets;
    size_t _size;        
    size_t _bucketCount;

public:
    HashMap(size_t bucketCount = 8) : _bucketCount(bucketCount), _size(0) {
        _buckets.resize(bucketCount);
    }

    V& operator[](const K& key) {
        size_t hashValue = MyStd::Hash<K>{}(key);
        size_t index = hashValue % _bucketCount;
        
        auto& bucket = _buckets[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if ((*it).key == key) {
                return (*it).value;
            }
        }

        bucket.push_back(KeyValuePair(key, V()));
        _size++;
        
        return bucket.back().value;
    }

    void put(const K& key, const V& value) {
        size_t hashValue = MyStd::Hash<K>{}(key);
        size_t index = hashValue % _bucketCount;

        auto& bucket = _buckets[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if ((*it).key == key) {
                (*it).value = value;
                return;
            }
        }
        
        bucket.push_back(KeyValuePair(key, value));
        _size++;
    }

    bool contains(const K& key) const{
        size_t hashValue = MyStd::Hash<K>{}(key);
        size_t index = hashValue % _bucketCount;

        auto& bucket = _buckets[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if ((*it).key == key) {
                return true;
            }
        }
        return false;
    }

    void remove(const K& key) {
        size_t hashValue = MyStd::Hash<K>{}(key);
        size_t index = hashValue % _bucketCount;
        
        auto& bucket = _buckets[index];
        bucket.remove(KeyValuePair(key, V()));
    }
};

#endif