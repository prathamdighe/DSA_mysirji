#include "/workspaces/DSA_mysirji/STACK/STACKA.cpp"
#include <iostream>
using namespace std;

int main()
{
     Stack a(4);

     a.push(10);
     a.push(20);
     a.push(30);

     cout << a.peek() << endl;
     

     a.reverseStack(a); // Call the method using the object
     cout << a.peek() << endl;

     return 0;
}
