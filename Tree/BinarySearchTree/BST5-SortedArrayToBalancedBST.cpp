
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

int Inorder(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// build Balanced BST

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]); // making new node from array mid

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
int main()
{

    int arr[5] = {10, 20, 30, 40, 50}; // sorted array ;
    struct Node *root = NULL;
    root = sortedArrayToBST(arr, 0, 4);

    cout << "Inorder traversal of balanced binary search tree is " << endl;
    Inorder(root);

    return 0;

    /*     30
         /    \
        10    40
         \       \
          20     50
BST balanced inorder ={10,20,30,40,50}
     */
}
