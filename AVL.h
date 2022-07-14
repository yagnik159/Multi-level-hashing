#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdexcept> // std::runtime_error
#include <sstream>
#include "AVLutilities.h"
// This header file contains the code for AVL self balancing tree

class AVL
{
private:
    struct AVLnode* root;
public:
    AVL();
    ~AVL();
    void AddData(std::string filename, int isHeading);
    void insert(int key);
    void traverse(int mode);
    void deleteKey(int key);
    int search(int key);
    void PrettyPrinting();
    int size();
};

AVL::AVL()
{
    root = nullptr;
}

AVL::~AVL()
{
    using namespace std;
    releaseMemoryTree(root);
}

void AVL::insert(int key) {
    root = insertObject(root, key);
}

int AVL::size() {
    return count(root);
}

int AVL::search(int key) {
    struct AVLnode* node = root;

    while (node)
    {
        if (node->key == key)
        {
            return 1;
        }
        else if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return 0;
}

void AVL::AddData(std::string filename, int isHeading = 1) {
    using namespace std;
    // working with csv in CPP
    // https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/

    ifstream myFile(filename);
    // if(!myFile.is_open()) throw runtime_error("Could not open file");

    string line, word;
    int val;

    if (isHeading)  getline(myFile, line);

    // Read data, line by line
    while (getline(myFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);
        pair<int, int> data;

        // add the column data
        // of a row to a pair
        getline(ss, word, ',');
        data.first = stoi(word);

        getline(ss, word, ',');
        data.second = stoi(word);

        insert(data.first);
    }

    // Close file
    myFile.close();
}

void AVL::traverse(int mode = 1) {
    using namespace std;

    cout << "===========================" << endl;
    cout << "Key --> Value" << endl;
    cout << "===========================" << endl;
    if (mode == 0) {
        cout << "Preorder" << endl;
        traversePreorder(root);
    }
    else if (mode == 1) {
        cout << "Inorder" << endl;
        traverseInorder(root);
    }
    else if (mode == 2) {
        cout << "Postorder" << endl;
        traversePostorder(root);
    }
    else {
        cout << "Invalid Mode" << endl;
        cout << "Inorder" << endl;
        traverseInorder(root);
    }
    cout << "===========================\n" << endl;
}

void AVL::PrettyPrinting() {
    std::cout << "---------------------------------" << std::endl;
    printBT("", root, false);
}

void AVL::deleteKey(int key) {
    root = delete_node(root, key);
}
