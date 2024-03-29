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
    int currentCap();
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

void DynArray::halfArray()
{
    int *temp = new int[capacity / 2];
    for (int i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    ptr = temp;
    capacity /= 2;
}

int DynArray::currentCap()
{
    return capacity;
}

void DynArray::append(int data)
{

    if (isFull())
    {
        doubleArray();
    }
    ptr[lastIndex + 1] = data; //++lastindex no need of new line index++
    lastIndex++;
}

void DynArray::insert(int index, int data)
{
    if (index < 0 || index >= lastIndex + 1)
    {
        cout << endl
             << "index invalid";
    }
    else
    {
        if (isFull())
        {
            doubleArray();
        }
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

void DynArray::del(int index)
{

    if (isEmpty())
    {
        cout << "Array is empty";
    }
    else if (index > lastIndex || index < 0)
    {
        cout << "invalid index";
    }
    else
    {
        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
        if (capacity / 2 >= lastIndex + 1 && capacity > 1) // boundary situation  >=  && capacity >1
        {
            halfArray();
        }
    }
}