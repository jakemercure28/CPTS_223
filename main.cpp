//
// Created by jake on 3/20/21.
// This program builds using CLion and Cmake.
// Ive attempted to build it in Visual studio code but would recommend using Cmake.
// I dont know how to use cmake in Visual Studio Code.
//
#include "AVLtree.h"
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    AVLtree<int> t1;
    AVLtree<int> t2;
    AVLtree<int> t3;

    vector<int> v(50);
    int j = 0;

    for (int i = 1; i < 100; i += 2) { // shuffle numbers
        v[j] = i;
        j++;
    }

    random_device rd; // shuffle numbers
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);

    for (int i = 1; i < 100; i += 2) // add odd numbers in ascending order
        t1.insert(i);

    for (int i = 99; i > 0; i -= 2) // descending order
        t2.insert(i);

    for (auto &it : v)  // shuffled
        t3.insert(it);

    cout << "t1 height: " << t1.height() << endl;
    cout << "t2 height: " << t2.height() << endl;
    cout << "t3 height: " << t3.height() << endl << endl;

    cout << "t1 validation: " << t1.validate() << endl;
    cout << "t2 validation: " << t2.validate() << endl;
    cout << "t3 validation: " << t3.validate() << endl << endl;

    for (int i = 1; i < 100; i += 2) {
        if (!t1.contains(i))
            cout << "My AVL tree implementation is wrong";
    }
    for (int i = 1; i < 100; i += 2) {
        if (!t1.contains(i))
            cout << "My AVL tree implementation is wrong";
    }
    for (int i = 1; i < 100; i += 2){
        if (!t1.contains(i))
            cout << "My AVL tree implementation is wrong";
}

    return 0;
}