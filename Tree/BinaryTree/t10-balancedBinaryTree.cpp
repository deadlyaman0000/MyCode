#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calcHeight(node *root)
{
    // base condition
    if (root == NULL)
    {
        return 0;
    }

    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}
// isBalanced

bool isBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = calcHeight(root->left); // calcultating height of left subtree by function call
    int rh = calcHeight(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << endl;
    if (isBalanced(root))
    {
        cout << "Balcned binary tree" << endl;
    }
    else
    {

        cout << "Unbalanced binary tree";
    }

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7
balanced binary tree
     */
}