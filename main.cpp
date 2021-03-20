//
// Created by jake on 3/20/21.
//
#include "AVLtree.h"

using namespace std;

int main()
{
    AVLtree t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    cout << t.height() << endl;
    cout << t.validate() << endl;

    return 0;
}