
#include "adt2.cpp"
#include <iostream>
using namespace std;
int main()
{
    ExtendArray obj(5);
    obj.append(20);
    // calling from the parent class
    obj.append(40);
    obj.append(60);
    obj.append(0);

    cout << "Greatsest element is " << obj.greatest();

    cout << endl;
    return 0;
}