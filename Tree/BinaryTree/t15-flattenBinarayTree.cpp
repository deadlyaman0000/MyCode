#include <iostream>
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

//link list traversal of flatten binary tree
void printLink(Node * root){
    Node *temp = root ;
    while(temp != NULL){
        cout << temp->data <<" " ;
        temp = temp ->right;
    }
}
//inorder
void inorder(struct Node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// flatten function

void flatten(Node *root)
{

    if (root == NULL || (root->right == NULL && root->left == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right; // previous last root left    check for last root in right subtree
        while (t->right != NULL)
        {
            t = t->right;
        }

        t->right = temp;
    }
    flatten(root->right);
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

    flatten(root);
    cout << "inorder for flatten binary tree " << endl;
    inorder(root);
    cout << endl;
    printLink(root); //link list traversal

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

preorder  =1,2,4,5,3,6,7
flatten binary tree
1->2->4->5->3->6->7
     */
}