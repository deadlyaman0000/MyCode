
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

void Inorder(Node *root)
{

    if (root == NULL)
    {
        return ;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// build BST

Node *buildBST(Node *root, int val)
{ 
       if(root == NULL){
        return new Node(val);
       }
       if( val < root->data){
        root->left = buildBST(root->left,val);
       }
       if( val > root->data){
        root->right = buildBST(root->right,val);
       }
       return root ;
}
int main()
{
    // build BST
    // creating null node then pass data from the array {5,1,3,4,2,7}

    struct Node *root = NULL;
   root = buildBST(root, 5);
    buildBST(root, 1);
    buildBST(root, 3);
    buildBST(root, 4);
    buildBST(root, 2);
    buildBST(root, 7);


    cout << "Inorder traversal of binary search tree is " << endl;
    Inorder(root);

    return 0;

    /*    5
        /   \
       1     7
        \
         3
        / \
       2   4

BST Inorder ={1,2,3,4,5,6,7}
     */
}
