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
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int get(int);
    int count();
    void printArray();
    ~Array(); // destructor
};

Array::Array(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[cap];
}

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
            ptr[index] = ptr[index + 1];
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
    for (int i = 0; i < lastIndex; i++)
    {
        cout
            << ptr[i] << " ";
    }
    cout << endl;
}

Array::~Array()
{
    delete[] ptr;
}

int main()
{
    Array obj(5);
    if (obj.isEmpty())
        cout
             << "array is empty"<<endl;

    obj.append(20);
    obj.append(40);
    obj.append(60);
    obj.insert(1, 30);

    obj.printArray();

    obj.del(2);
    obj.printArray();

    cout
        << endl;
    return 0;
}