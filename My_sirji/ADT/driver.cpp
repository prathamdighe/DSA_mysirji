
#include "/workspaces/DSA_mysirji/ADT/adt2.cpp"
#include <iostream>
using namespace std;
int main()
{
    ExtendArray obj(7);
    obj.append(20);
    // calling from the parent class
    obj.append(40);
    obj.append(60);
    obj.append(0);
    obj.append(20);
    obj.append(60);
    obj.append(0);
    obj.removeDuplicate();
    

    obj.printArray();
    cout<<endl<<obj.secondLargest();

    cout<<endl<<obj.count();
    

    cout <<endl<< "Greatsest element is " << obj.greatest();

    cout << endl;
    return 0;
}