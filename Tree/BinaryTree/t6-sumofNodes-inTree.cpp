#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


int sumNodes( node *root)
{
    // base condition
    if (root == NULL)
    {
        return 0;
    }
  
  return sumNodes(root->left) + sumNodes(root->right) + root->data; // current node data
}

int main()
{

    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout <<sumNodes(root);

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

sum of nodes = 28
     */
}