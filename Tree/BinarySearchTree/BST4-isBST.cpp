
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
// function to check if a binary search tree is BST or not 

bool isBST(Node * root ,Node * min ,Node *max){
    if(root  == NULL){
        return true ;
    }

    if(min != NULL && root->data <= min->data ){
        return false ;
    }
     if(max != NULL && root->data >= max->data ){
        return false ;
    }

    bool leftValid = isBST(root->left ,min,root);
    bool rightValid = isBST(root->right ,root,max);

    return (leftValid && rightValid);
}


int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);

    root->left->right = new Node(3);

    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);
     Inorder(root ) ;
    if(isBST(root,NULL,NULL))  {
        cout <<"Valid BST " ;
    }
    else {
        cout <<"Invalid BST ";
    }
   

    return 0;

    /*   5
       /   \
      1     7
       \
        3
       / \
      2   4

is BST = true
    */
}
