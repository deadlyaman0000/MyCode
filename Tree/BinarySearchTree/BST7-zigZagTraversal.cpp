
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

// zig zag traversal of binary search tree
void zigZagTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);
    while (!currLevel.empty())
    {

        Node *temp = currLevel.top(); // storing root to a Node
        currLevel.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }

            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }

            // swapping stack and changing left to right
            if (currLevel.empty())
            {
                leftToRight = !leftToRight;
                swap(currLevel, nextLevel);
            }
        }
    }
}

Node *buildBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = buildBST(root->left, val);
    }
    if (val > root->data)
    {
        root->right = buildBST(root->right, val);
    }
    return root;
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

    cout << "zig zag traversal of binary search tree is " << endl;
    zigZagTraversal(root);

    return 0;

    /*    5
        /   \
       1     7
        \
         3
        / \
       2   4

BST zig zag ={5,7,1,3,2,4}
     */
}
