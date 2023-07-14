
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

//inorder traversal
void inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// find inorder succesor
// lefttmost node of the right subtree from root
Node *inoderSuccesor(Node *root)
{

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}


// delete in bst for all 3 cases

Node *deleteInBST(Node *root, int key)
{

    if (root == NULL)
    {
        return root;
    }

    // travrsal
    else if (key < root->data)
    {
        root->left = deleteInBST(root->left, key); // root->left to update the value of left after each function call
                                                   // because we are deleting a node
    }
    
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }

    else // delete element found
    {

        if (root->left == NULL && root->right == NULL && root->data == key) // delete root node
        {
            delete root;
            root = NULL;
           
        }

        else if (root->left == NULL)
        {
            Node *temp= root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp= root;
            root = root->left;
            delete temp;
        }
        else {

        Node *isuccesor = inoderSuccesor(root->right);
        root->data = isuccesor->data;                            // swapping root data with succesor
        root->right = deleteInBST(root->right, isuccesor->data); // ipre is in left
        // it calls recursively untill  the node that we want to delete reaches leaf then it will be deleted
    }
    }
    return root;
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);

    cout << "inorder before delete " << endl;
    inorder(root);
    cout << endl;
    root = deleteInBST(root, 6);
    cout << "inorder after delete " << endl;
    inorder(root);

    return 0;

    /*   4
       /   \
      2     5
     /  \    \
    1    3    6



BST inorder ={1,2,3,4,5,6}
    */
}
