//#pragma once

#include <iostream>
#include <vector>

using namespace std;

class SingleHash {
    int buckets;
    std::vector<long long>* table;

public:
    explicit SingleHash(int v) {
        buckets = v;
        table = new vector<long long>[buckets];
    }

    void insertItem(long long key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(long long key) {
        int index = hashFunction(key);

        std::vector<long long>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == key)
                break;
        }

        if (i != table[index].end()) {
            table[index].erase(i);
        }
    }

    int hashFunction(long long x) {
        return x % (long long)buckets;
    }

    void displayHash() {
        for (int i = 0; i < buckets; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }

    void displaySizes() {
        for (int i = 0; i < buckets; i++) {
            cout << i << "-->" << table[i].size() << '\n';
        }
    }

    void findNumber(long long key) {
        int index = hashFunction(key);
        int k = 0;
        std::vector<long long>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            k++;
            if (*i == key)
                break;
        }

        if (i != table[index].end()) {
            cout << "Found the number in list " << index << " at index " << k << '\n';
        }
        else {
            cout << "Not Found" << '\n';
        }
    }

    long long getNumber(int index, int lst) {
        auto i = table[lst].begin();
        advance(i, index - 1);
        return *i;
    }
};
