#include <iostream>
using namespace std;

class queue
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    queue(int);
    bool isFull();
    void insert(int);

}

queue::queue(int cap    )
{

    capacity = cap;
    front = -1;
    rear = -1;
    ptr = new capacity[data];
}

bool queue::isFull(){
    return front==0 && rear== cap-1 || rear+1==front;
}

void queue::insert(int data){
    if(isFull()){
        cout<< " queue is full";
    }
    else{}
}