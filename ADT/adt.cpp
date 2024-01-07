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
        void insert(int,int);
        void edit(int,int);
};


Array::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[cap];
}

bool Array::isEmpty(){
    return lastIndex==-1;
}

bool Array::isFull(){
    return lastIndex==capacity-1;
}

void Array::append(int data){
    if(isFull()){
        cout<<"array is full";
    }
    else{
        lastIndex++;
        ptr[lastIndex]==data;
    }
}

void Array::insert(int index,int data){
    int i=0;
    if(isFull()){
        cout<<endl<<"array is full";
    }
    else if(index<0 || index>lastIndex+1){
        cout<<endl<<"cannot insert at the index";
    }
    else{
        for(i=lastIndex;i>=index;i--){
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
}

void Array::edit(int index,int data){
    if(index>=0&&index<=lastIndex){
        ptr[index]=data;
    }
}