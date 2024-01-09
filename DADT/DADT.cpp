#include <iostream>
using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    DynArray(int);
    void doubleArray();
    void halfArray();
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int get(int);
    int count();
    void printArray();
    int find(int);
    ~DynArray(); // destructor
};

DynArray::DynArray(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

bool DynArray::isEmpty()
{
    return lastIndex == -1;
}

bool DynArray::isFull()
{
    return capacity == lastIndex + 1;
}

void DynArray::edit(int index, int data)
{
    if (index >= 0 && index <= lastIndex)
    {
        ptr[index] = data;
    }
}

int DynArray::get(int index)
{
    if (index >= 0 && index <= lastIndex)
    {
        return ptr[index];
    }
    else
    {
        return -1;
    }
}

int DynArray::count()
{
    return lastIndex + 1;
}

DynArray::~DynArray()
{
    delete[] ptr;
}

int DynArray::find(int data)
{
    int i;
    for (i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

void DynArray::doubleArray()
{

    int *temp = new int[capacity * 2]; // local temp pointer

    int i;
    for (i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    capacity = capacity * 2;
}

void DynArray::halfArray(){
    int *temp=new int[capacity/2];
    for (int i=0;i<=lastIndex;i++){
        temp[i]=ptr[i];
    }
    ptr=temp;
    capacity/=2;
}