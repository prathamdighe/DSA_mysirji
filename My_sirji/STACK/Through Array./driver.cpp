#include "/workspaces/DSA_mysirji/STACK/STACKA.cpp"
#include <iostream>
using namespace std;

void pushInStack(Stack &a, Stack &minStack, int data)
{
     a.push(data);
     if (minStack.isEmpty())
     {
          minStack.push(data);
     }
     else
     {
          if (data > minStack.peek())
          {
               minStack.push(minStack.peek());
          }
          else
          {
               minStack.push(data);
          }
     }
}
void popFromStack(Stack &s, Stack &minStack)
{
     s.pop();
     minStack.pop();
}

int main()
{

     Stack a(5);
     Stack minStack(5);
     pushInStack(a, minStack, 50);
     cout << endl
          << "current min value is" << minStack.peek();
     pushInStack(a, minStack, 40);
     cout << endl
          << "current min value is" << minStack.peek();
     pushInStack(a, minStack, 60);
     cout << endl
          << "current min value is" << minStack.peek();
     pushInStack(a, minStack, 70);
     cout << endl
          << "current min value is" << minStack.peek();
     pushInStack(a, minStack, 30);
     cout << endl
          << "current min value is" << minStack.peek();

     cout << endl
          << "poping";
     popFromStack(s, minStack);
     cout << endl
          << "current min value is" << minStack.peek();

     // cout << a.peek() << endl;

     // a.reverseStack(a); // Call the method using the object
     // cout << a.peek() << endl;

     return 0;
}
