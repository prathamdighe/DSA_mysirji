#include "adt.cpp"


class ExtendArray : public Array
{
public:
    int greatest();
    void sort();
    int smallest();
    int sum();
    float avg();
    void rotateRightByOne();
    void removeDuplicate();
    int secondLargest();
};

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

void ExtendArray::sort()
{

    int round, temp, i;
    for (round = 1; round <= count() - 1; round++)
    {
        for (i = 0; i <= count() - 1 - round; i++)
        {
            if (get(i) > get(i + 1))
            {
                temp = get(i);
                edit(i, get(i + 1));
                edit(i + 1, temp);
            }
        }
    }
}

int ExtendArray::secondLargest()
{
    if (count() >= 2)
    {
        for (int r = 1; r <= 2; r++)
        {
            for (int i = 0; i <= count() - r; i++)
            {
                if (get(i) > get(i + 1))
                {
                    int temp = get(i);
                    edit(i, get(i + 1));
                    edit(i + 1, temp);
                }
            }
        }
        return get(count() - 2); // for the second last number;
    }
    return -1; // wrong need to update
}

int ExtendArray::smallest()
{
    int min = get(0);
    if (isEmpty())
    {
        cout << "array is empty";
        return -1;
    }
    else
    {
        for (int i = 1; i <= count(); i++)
        {
            if (min > get(i))
            {
                min = get(i);
            }
        }
        return min;
    }
}

int ExtendArray::sum()

{
    int sum = 0;
    for (int i = 0; i < count(); i++)
    {
        sum = sum + get(i);
    }
    return sum;
}

float ExtendArray::avg()
{
    return (float)sum() / count();
}

void ExtendArray::rotateRightByOne()
{

    int temp;
    int lastIndex;
    if (!isEmpty())
    {
        lastIndex = count() - 1;
        temp = lastIndex;
        for (int i = lastIndex; i > 0; i--)
        {
            edit(i, get(i - 1));
        }
        edit(0, temp);
    }
}

void ExtendArray::removeDuplicate()
{
    for (int i = 0; i < count(); i++)
    {
        for (int j = i + 1; j < count(); j++)
        {
            if (get(i) == get(j))
            {
                del(j);
            }
        }
    }
}