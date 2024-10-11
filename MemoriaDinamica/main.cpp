#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    vector v;
    v.add(1);
    for (int i = 0; i < v.getsize() ; i++)
    {
        cout << v.get(i) << " ";
    }
    cout << endl;
    return 0;
}