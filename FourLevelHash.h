#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include "AVL.h"

using namespace std;

class FourLevelHash {
    //    list < list < list < list <long long>* >* >* > *table;
    vector<int> hashLevel;
    vector<vector<vector<vector<AVL> > > > table;
public:
    explicit FourLevelHash(vector<int> v) {
        hashLevel = std::move(v);

        table = vector<vector<vector<vector<AVL> > > >(hashLevel[0]);
        for (int i = 0; i < hashLevel[0]; i++) {
            table[i] = vector<vector<vector<AVL> > >(hashLevel[1]);
            for (int j = 0; j < hashLevel[1]; j++) {
                table[i][j] = vector<vector<AVL> >(hashLevel[2]);
                for (int k = 0; k < hashLevel[2]; k++) {
                    table[i][j][k] = vector<AVL>(hashLevel[3]);
                    for (int o = 0; o < hashLevel[3]; o++)
                    {
                        table[i][j][k][o] = AVL();
                    }
                }
            }
        }
    }

    static int hashFunction(long long x, int hashNumber) {
        return x % (long long)hashNumber;
    }

    void insertItem(long long key) {
        int id1 = hashFunction(key, hashLevel[0]);
        int id2 = hashFunction(key, hashLevel[1]);
        int id3 = hashFunction(key, hashLevel[2]);
        int id4 = hashFunction(key, hashLevel[3]);
        table[id1][id2][id3][id4].insert(key);
    }

    void displaySizes() {
        for (auto i = 0; i < hashLevel[0]; i++) {
            for (auto j = 0; j < hashLevel[1]; j++) {
                for (auto k = 0; k < hashLevel[2]; k++) {
                    for (auto o = 0; o < hashLevel[3]; o++) {
                        cout << i << "-->" << j << "-->" << k << "-->" << o << "-->" << table[i][j][k][o].size()
                            << endl;
                    }
                }
            }
        }
    }

    void findNumber(long long key) {
        int id1 = hashFunction(key, hashLevel[0]);
        int id2 = hashFunction(key, hashLevel[1]);
        int id3 = hashFunction(key, hashLevel[2]);
        int id4 = hashFunction(key, hashLevel[3]);

        /*int k = 0;
        std::vector<long long>::iterator i;
        for (i = table[id1][id2][id3][id4].begin(); i != table[id1][id2][id3][id4].end(); i++) {
            k++;
            if (*i == key)
                break;
        }*/
        int result = table[id1][id2][id3][id4].search(key);


        if (result) {
            cout << "Found the number in HashTable" << endl;
        }
        else {
            cout << "Not Found" << '\n';
        }
    }
};
