#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
    HashTable ht(11, DOUBLE);
    int probe;
    double s  = 0;
    double l = 0;
    ht.insert(2672);
    ht.insert(1452);
    ht.insert(2488);
    ht.insert(3510);
    ht.insert(4653);
    ht.insert(5767);
    ht.insert(6877);
    ht.insert(8043);
    ht.search(5767, probe);
    ht.display();
    ht.analyze(s, l);
    cout<<s<<endl;
    cout<<l<<endl;
    return 0;
}
