#include <iostream>
#include <vector>
#include <list>
#include <functional>
using namespace std;

class HashMap {
    typedef list<pair<int, int>> Bucket;
    typedef vector<Bucket> Table;

    Table table;
    int entries;

    size_t _hash(int a) {
        return hash<int>()(a) % table.size();
    }

    void grow() {
        Table rehashTable(table);
        table.assign(table.size() * 2, Bucket());
        entries = 0;

        for (auto it = rehashTable.begin(); it != rehashTable.end(); ++it)
            for (auto node = it->begin(); node != it->end(); ++node)
                this->insert(*node);
        
        cout << "New table size: " << table.size() << endl;
    }

    Bucket::iterator find(Bucket::iterator begin, Bucket::iterator end, int key) {
        for (; begin != end; ++begin)
            if (begin->first == key)
                break;

        return begin;
    };

public:
    HashMap(int size = 128): table(size, Bucket()), entries(0) {}

    void insert(pair<int,int> kv) {this->insert(kv.first, kv.second);}

    void insert(int key, int value) {
        auto &bucket = table[_hash(key)];
        auto node = find(bucket.begin(), bucket.end(), key);

        if (node == bucket.end())
            bucket.push_back(make_pair(key, value));
        else
            node->second = value;

        ++entries;

        if (double(entries) / table.size() > 0.7)
            grow();
    }

    pair<int, int> get(int key) {
        auto &bucket = table[_hash(key)];
        auto node = find(bucket.begin(), bucket.end(), key);

        if (node == bucket.end())
            return make_pair(-1, -1);
        else
            return *node;
    }

    void remove(int key) {
        auto &bucket = table[_hash(key)];
        auto node = find(bucket.begin(), bucket.end(), key);

        if (node == bucket.end())
            return;
        else {
            bucket.erase(node);
            --entries;
        }
    }
};

int main() {
    HashMap hashmap;

    hashmap.insert(5, 1);
    cout << hashmap.get(5).second << endl;
    hashmap.insert(5, 2);
    cout << hashmap.get(5).second << endl;
    hashmap.remove(5);
    cout << hashmap.get(5).second << endl;

    cout << "grow check" << endl;
    int size = 10;
    double load_factor = 0.7;
    HashMap hashmap1(size);
    for (int i = 0; i < size * load_factor + 1; ++i) {
        hashmap1.insert(i, i);
    }
}