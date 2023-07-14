
#include <bits/stdc++.h>
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

int printPreorder(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}


int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder traversal of binary tree is " << endl;
    printPreorder(root);

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

height = 3
     */
}
