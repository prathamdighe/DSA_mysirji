#include <iostream>
#include <stdio.h>
#include "/workspaces/DSA_mysirji/SLL/SLL.cpp"
using namespace std;

int is_cycle(SLL &obj)
{

    node *t1, *t2;
    t1 = obj.getFirst();
    t2 = t1;
    if (t1)
    {
        do
        {
            if (t1 == NULL)
            {
                return 0;
            }
            if (t1->next != NULL)
            {
                t1->next->next;
            }
            else
            {
                return 0;
            }
            t2 = t2->next;
        } while (t1 != t2)
    }
}

int length_of_cycle(SLL &obj)
{
    if (is_cycle())
    {
    }
}