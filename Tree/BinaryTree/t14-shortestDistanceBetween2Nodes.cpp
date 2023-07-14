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

// LCA function
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

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA == NULL && rightLCA == NULL)
    {
        return NULL;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
// function to calculate distance of n1 and n2 from LCA

int findDist(Node *root, int key, int dis) // measure level distance
{
    if (root == NULL)
    {
        return 0; // no distance
    }

    if (root->data == key)
    {
        return dis;
    }


    return findDist(root->left, key, dis + 1) + findDist(root->right, key, dis + 1); //short code
    //if n1 or n2 is in right or left both are traversed from lca 
}

// shortestfindistance function
int shortDist(Node *root, int n1, int n2)
{
    Node *Lca = LCA2(root, n1, n2); // return LCA

    int d1 = findDist(Lca, n1, 0); // 0 to get distance
    int d2 = findDist(Lca, n2, 0);

    return (d1 + d2);
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

    cout << shortDist(root, 5, 7);

    cout << endl;

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

lca of 4,5 = 2
shortest distance between 4 and 5 is : 2

     */
}
