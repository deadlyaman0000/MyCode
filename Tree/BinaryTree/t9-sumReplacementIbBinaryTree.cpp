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

void sumReplace(node *root) // it is not printing any values
{
    if (root == NULL)
    {
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    // visualise post order data print
    // instead of printing we are storing sum of subtree in root node
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

// traversal preorder
void preorder(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

    cout << "Preorder " << endl;
    preorder(root);
    cout << endl;

    cout << "Sum Replace Binary Tree " << endl;
    sumReplace(root);
    preorder(root); // preorder is changed by sum replace
    cout << endl;

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

sum replacement tree

  /*      28
        /   \
       11    16
      / \    / \
     4   5   6  7

     */
}