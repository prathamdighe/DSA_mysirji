#include <iostream>
#include <std.io>
using namespace std;

struct node
{
    node *left;
    node *right;
    int item;
    int height;
};

class AVL
{
private:
    node *root;

public:
    AVL();
    ~AVL();
};

AVL::AVL()
{
    root = NULL;
}

AVL::~AVL()
{
}
