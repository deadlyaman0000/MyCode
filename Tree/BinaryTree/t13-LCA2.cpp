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

// assuming  both  n1 and n2 are present in tree
Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n1, n2); // checking if n1 or n2 is in left subtree
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA && rightLCA)
    { // if both leftLCA and rightLCS is not null
        return root;
    }

    
   if (leftLCA == NULL && rightLCA  == NULL)
    {
        return NULL;
    }  

    return (leftLCA != NULL) ? leftLCA : rightLCA; // if leftLca is not null return rightLCA
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

    Node *lca = LCA2(root, 4, 5);
    cout << lca->data;
    cout << endl;

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

lca of 4,5 = 2

     */
}