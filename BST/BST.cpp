#include <iostream>
using namespace std;

struct node
{
    int item;
    node *left;
    node *right;
};

class BST
{
private:
    node *root;

protected:
    void preorderRec(node *);
    void inorderRec(node *);
    void postorderRec(node *);
    node *deleteNode(node *ptr, int data);

public:
    BST();
    bool isempty();
    void insert(int);
    void preorder();
    void inorder();
    void postorder();
    void del(int);
    node *search(int);
    ~BST();
};

BST::BST()
{
    root = NULL;
}

bool BST::isempty()
{
    return root == NULL;
}

// Also possible through recursion.
void BST::insert(int data)
{
    node *n = new node;
    n->item = data;
    n->left = NULL;
    n->right = NULL;

    if (isempty())
    {
        root = n;
    }
    else
    {
        node *ptr = root;
        while (n->item != ptr->item)
        {
            if (data <= ptr->item)
            {
                if (ptr->left != NULL)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr->left = n;
                    break;
                }
            }
            else // data > ptr->item
            {
                if (ptr->right != NULL)
                {
                    ptr = ptr->right;
                }
                else
                {
                    ptr->right = n;
                    break; // Break after inserting on right side
                }
            }
        }
    }
}

void BST::preorder()
{
    preorderRec(root); // ordering starts from root;
}

void BST::inorder()
{
    inorderRec(root);
}

void BST::postorder()
{
    postorderRec(root);
}

void BST::preorderRec(node *ptr)
{
    if (ptr)
    {
        cout << " " << ptr->item;
        preorderRec(ptr->left);
        preorderRec(ptr->right); // recursion
    }
}

void BST::inorderRec(node *ptr) /*Traverse the left subtree. Visit the root node. Traverse the right subtree.*/
{
    if (ptr)
    {
        inorderRec(ptr->left);
        cout << " " << ptr->item;
        inorderRec(ptr->right); // recursion
    }
}

void BST::postorderRec(node *ptr) /*Traverse the left subtree. Traverse the right subtree. Visit the root node.*/
{
    if (ptr)
    {
        postorderRec(ptr->left);
        postorderRec(ptr->right);
        cout << " " << ptr->item;
    }
}

void BST::del(int data)
{
    root = deleteNode(root, data);
}
node *BST::deleteNode(node *ptr, int data)
{

    if (ptr == NULL)
    {
        return NULL;
    }
    if (data < ptr->item)
    {
        ptr->left = deleteNode(ptr->left, data);
    }
    else if (data > ptr->item))
        {
            ptr->right = deleteNode(ptr->right, data);
        }
    else
    {
        // no child
        if (ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            return NULL;
        }
        // one child
        else if (ptr->left == NULL || ptr->right == NULL)
        {
            node *child;
            if (ptr->left != NULL)
            {
                child = ptr->left;
            }
            else
            {
                child = ptr->right;
            }
            delete ptr;
            return child;
        }
        // Two child
        else
        {
            node *parapred;
            node *pred;
            parapred = ptr;
            pred = ptr->left;
            while (pred->right != NULL)
            {
                parapred = pred;
                pred = pred->right;
            }
            ptr->item = pred->item;
            // Delete the predecessor node.
            // If the predecessor is the immediate left child.
            if (predParent == ptr)
            {
                ptr->left = deleteNode(ptr->left, pred->item);
            }
            else
            {
                predParent->right = deleteNode(predParent->right, pred->item);
            }
        }
        return ptr;
    }
}

node *BST::search(int data)
{
    node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->item == data)
        {
            return ptr;
        }
        if (ptr->item > data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return ptr;
}

BST::~BST()
{
    while (root != NULL)
    {
        deleteNode(root, root->item);
    }
}

int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Preorder:";
    tree.preorder();
    cout << "\nInorder:";
    tree.inorder();
    cout << "\nPostorder:";
    tree.postorder();
    cout << endl;

    return 0;
}
