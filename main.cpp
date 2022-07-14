#include <chrono>
#include <iostream>
#include <random>

#include "FourLevelHash.h"
#include "SingleHash.h"

int main() {
    SingleHash H(17);
    vector<int> primes = {5, 7, 17, 29};
    FourLevelHash H4(primes);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 1000000000.0);

    std::cout << "Hashing With Chaining!!" << std::endl;

    int size = 1000000;
    long long valueInHash, find;
    auto start1 = std::chrono::high_resolution_clock::now();

    ofstream fin;
    fin.open("InputFile.txt");
    cout << "Allocating Items" << endl;
    for (auto i = 0; i < size; i++) {
        auto temp = (long long)(dist(mt));
        fin << (long long)temp << '\n';
        if (i == 70000) valueInHash = temp;
        H.insertItem(temp);
        H4.insertItem(temp);
    }
    fin.close();
    // cin >> find;
    cout << "Items Allocated" << endl;
    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 =
        std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1);
    cout << "Item Allocation Duration: " << duration1.count() << " seconds"
         << endl;

    H.displaySizes();
    // H4.displaySizes();
    while (true) {
        int ch;
        cout << "\n1. Find a random value.\n";
        cout << "2. Enter value to find.\n";
        cout << "3. Find a value present in the hash function(70000th "
                "number).\n";
        cout << "4. Exit.\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) {
            find = (long long)(dist(mt));
            cout << "Finding : " << find << '\n';
        } else if (ch == 2) {
            cout << "Enter the value: ";
            cin >> find;
        } else if (ch == 3) {
            find = valueInHash;
        } else if (ch == 4) {
            cout << "Thank you";
            break;
        } else {
            cout << "Invalid Input\n";
            continue;
        }
        cout << '\n';
        auto start2 = std::chrono::high_resolution_clock::now();
        H.findNumber(find);
        auto stop2 = std::chrono::high_resolution_clock::now();

        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(
            stop2 - start2);
        cout << "\nSingle Hash Function completed searching in "
             << duration2.count() << " microseconds\n"
             << endl;

        auto start3 = std::chrono::high_resolution_clock::now();
        H4.findNumber(find);
        auto stop3 = std::chrono::high_resolution_clock::now();

        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(
            stop3 - start3);
        cout << "\nFour Level Hash Function completed searching in "
             << duration3.count() << " microseconds" << endl;
    }

    return 0;
}
