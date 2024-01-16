#include "adt.cpp"

class ExtendArray : public Array
{
public:
    ExtendArray(int);
    int greatest();
};
ExtendArray::ExtendArray(int cap) : Array(cap)
{
}
int ExtendArray::greatest() // removed Array obj since it is now child class
{
    int max;
    if (isEmpty())
    {
        cout << "array is empty";
        return -1;
    }
    max = get(0);
    for (int i = 1; i < count(); i++)
    {
        if (max < get(i))
        {
            max = get(i);
        }
    }
    return max;
};