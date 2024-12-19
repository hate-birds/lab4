#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class HashTable {
private:
    unordered_map<Key, Value> table;

public:
    HashTable();
    HashTable(const HashTable& other);
    ~HashTable();

    void clear();
    size_t size() const;
    void saveToFile(const string& filePath) const;
    void loadFromFile(const string& filePath);
    bool operator==(const HashTable& other) const;
    HashTable& operator<<(const pair<Key, Value>& kv);
    void add(const Key& key, const Value& value);
    void remove(const Key& key);
    Value& operator[](const Key& key);
    bool contains(const Key& key) const;
    HashTable operator&&(const HashTable& other) const;
};

#include "HashTable.tpp" // Реализация шаблонных методов

#endif // HASHTABLE_H
