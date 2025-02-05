#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node left;
    int data;
    node right;
};

class BST
{
private:
    node *root;

public:
    BST();
    bool isempty();
    void insert(int);
};

BST::BST()
{
    root = NULL;
}

bool BST::isempty()
{
    return root == NULL;
}
void BST::insert(int data){}
