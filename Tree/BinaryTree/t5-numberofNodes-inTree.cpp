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


int countNodes( node *root)
{
    // base condition
    if (root == NULL)
    {
        return 0;
    }
  
  return countNodes(root->left) + countNodes(root->right) + 1; //1 for current node
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

    cout <<countNodes(root);

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

number of nodes = 7
     */
}