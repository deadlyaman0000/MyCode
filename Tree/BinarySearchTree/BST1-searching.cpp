
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

// searching in bst

Node *searchBST(Node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return searchBST(root->left, key); //we write return so that the below code  not exicute
    }
   else if (key > root->data)
    {
        return searchBST(root->right, key);
    }
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);

    root->left->right = new Node(3);

    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);

    Node *key = searchBST(root, 3);
    if (key == NULL)
    {
        cout << "element not found in BST " << endl;
    }
    else
    {
        cout << "key found : " <<  key->data;
    }

    return 0;

    /*   5
       /   \
      1     7
       \
        3
       / \
      2   4

BST Preorder ={5,1,3,4,2,7}
search 3 =found
    */
}
