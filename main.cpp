//
// Created by jake on 3/20/21.
//
#include "AVLtree.h"

using namespace std;

int main()
{
    AVLtree<int> t1;
    AVLtree<int> t2;
    AVLtree<int> t3;

    for(int i = 0; i < 50;i++)
        t1.insert(i);

    for(int i = 50;i > 1; i--)
        t2.insert(i);

    //for(int i = 0;i < 50;i++)
   // t3.insert(i);

    cout << "t1 height: " << t1.height() << endl;
    cout << "t2 height: " << t2.height() << endl;
    cout << "t3 height: " << t3.height() << endl;

    cout << "t1 validation: " << t1.validate() << endl;
    cout << "t2 validation: " << t2.validate() << endl;
    cout << "t3 validation: " << t3.validate() << endl;


    return 0;
}