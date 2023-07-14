#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// total nodes in tree
int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
   
    return  countNode(root->left) + countNode(root->right) + 1;
}

bool isCBT(Node *root, int index, int n)
{

    if (root == NULL)
    {
        return true;
    }
    if (index >= n) // zero based indexing
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, index * 2 + 1, n);

        bool right = isCBT(root->right, index * 2 + 2, n);
        return (left && right);
    }
}

// check Heap max order

bool isMaxOrder(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    // compare root and left child
  if (root->right == NULL && (root->left->data < root->data ))
    {
        return true;
    }

    // compare left and right with child
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && 
        (root->right->data < root->data && root->left->data < root->data));
    }
}
// check if tree is Heap or not
bool isHeap(Node *root)
{
    int n = countNode(root);
    int index = 0  ;
    // checking for complete binary tree and
    // cheking for heap

    if (isCBT(root, index, n) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    struct Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(30);

    root->left->left = new Node(20);

    root->left->right = new Node(10);

    cout << isHeap(root);

    return 0;

    /* 50
      /  \
     40  30
     / \
    20  10

isHeap = true

  */
}