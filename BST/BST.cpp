#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node left;
    int item;
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
void BST::insert(int data){
    node *n=new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;

    if(isempty()){
        root=n;
    }
    else{
        node*ptr=root;
        while(n->item!=ptr->item){
            if(n->item<=ptr->item){
                if(ptr->left!=NULL){
                    ptr=ptr->left;
                }
                else{
                    ptr->left=n;
                    break;
                }
            }
            else{
                  if(ptr->right!=NULL){
                    ptr=ptr->right;
                }
                else{
                    ptr->right=n;
                }
            }
        }
    }
}
