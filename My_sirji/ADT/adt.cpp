#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int cap);
    Array(Array &);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int get(int);
    int count();
    int find(int);
    void printArray();
    int getCapacity();
    void operator=(Array &arr);
    ~Array(); // destructor
};

Array::Array(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[cap];
}
Array::Array(Array &arr)
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
};

bool Array::isEmpty()
{
    return lastIndex == -1;
}

bool Array::isFull()
{
    return lastIndex == capacity - 1;
}

void Array::append(int data)
{
    if (isFull())
    {
        cout << "array is full";
    }
    else
    {
        lastIndex++;
        ptr[lastIndex] = data;
    }
}

void Array::insert(int index, int data)
{
    int i = 0;
    if (isFull())
    {
        cout << endl
             << "array is full";
    }
    else if (index < 0 || index > lastIndex + 1)
    {
        cout << endl
             << "cannot insert at the index";
    }
    else
    {
        for (i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

void Array::edit(int index, int data)
{
    if (index >= 0 && index <= lastIndex)
    {
        ptr[index] = data;
    }
}

void Array::del(int index)

{
    int i = 0;
    if (isEmpty())
    {
        cout << endl
             << "array is empty";
    }
    else if (index < 0 || index > lastIndex)
    {
        cout << endl
             << "the index is empty";
    }
    else
    {
        for (i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
    }
}

int Array::get(int index)

{
    if (index >= 0 && index <= lastIndex)
    {
        return ptr[index];
    }
    else
    {
        cout << endl
             << "invalid index";
        return -1;
    }
}

int Array::count()
{
    return lastIndex + 1;
}

void Array::printArray()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        cout
            << ptr[i] << " ";
    }
    cout << endl;
}

int Array::find(int data)
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
int Array::getCapacity()
{
    return capacity;
};

// deep copy.
void Array::operator=(Array &arr)
{
    capacity = arr.getCapacity();
    lastIndex = arr.lastIndex;
    if (ptr != NULL)
    {
        delete[] ptr;
    }

    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}

Array::~Array()
{
    delete[] ptr;
}
