
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

bool isIdenticalBST(Node *root, Node *root2)
{

    if (root == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root == NULL || root2 == NULL) // if one node is null
    {
        return false;
    }

    // checking for 3 conditions
    else
    {
        bool cond1 = root->data == root2->data;
        bool cond2 = isIdenticalBST(root->left, root2->left);
        bool cond3 = isIdenticalBST(root->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
    }
    return false;

 
}

int main()
{
    // BST1
    struct Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);

    // BST 2
    struct Node *root2 = new Node(5);
    root2->left = new Node(1);
    root2->right = new Node(70); //
    root2->left->right = new Node(3);
    root2->left->right->left = new Node(2);
    root2->left->right->right = new Node(4);

    cout << " Checking if binary search tree is Identical or not " << endl<<endl ;
    if( isIdenticalBST(root, root2)){
        cout << " BST is identical " <<endl ;
    }
    else {
        cout << "BST is not identical " <<endl;
    }

    return 0;

    

/* BST1
          5
        /   \                               
       1     7
        \
         3
        / \
       2   4

BST2
    /*    5
        /   \
       1     70
        \
         3
        / \
       2   4

BST isIdenticalBST = false
     */
}
