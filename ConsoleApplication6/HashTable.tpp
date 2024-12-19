#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() = default;

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable& other) : table(other.table) {}

template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
    clear();
}

template <typename Key, typename Value>
void HashTable<Key, Value>::clear() {
    table.clear();
}

template <typename Key, typename Value>
size_t HashTable<Key, Value>::size() const {
    return table.size();
}

template <typename Key, typename Value>
void HashTable<Key, Value>::saveToFile(const string& filePath) const {
    ofstream file(filePath);
    if (!file.is_open()) throw ios_base::failure("Ошибка при открытии файла для записи.");
    for (const auto& [key, value] : table) {
        file << key << " " << value << "\n";
    }
}

template <typename Key, typename Value>
void HashTable<Key, Value>::loadFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) throw ios_base::failure("Ошибка при открытии файла для чтения.");
    table.clear();
    Key key;
    Value value;
    while (file >> key >> ws && getline(file, value)) {
        table[key] = value;
    }
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::operator==(const HashTable& other) const {
    return table == other.table;
}

template <typename Key, typename Value>
HashTable<Key, Value>& HashTable<Key, Value>::operator<<(const pair<Key, Value>& kv) {
    add(kv.first, kv.second);
    return *this;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::add(const Key& key, const Value& value) {
    table[key] = value;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::remove(const Key& key) {
    table.erase(key);
}

template <typename Key, typename Value>
Value& HashTable<Key, Value>::operator[](const Key& key) {
    return table[key];
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::contains(const Key& key) const {
    return table.find(key) != table.end();
}

template <typename Key, typename Value>
HashTable<Key, Value> HashTable<Key, Value>::operator&&(const HashTable& other) const {
    HashTable<Key, Value> result;
    for (const auto& [key, value] : table) {
        if (other.contains(key) && other.table.at(key) == value) {
            result.add(key, value);
        }
    }
    return result;
}
