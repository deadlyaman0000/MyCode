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

void printLevelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root); // pushing root
    q.push(NULL); // pushing null

    while (!q.empty())
    {
        Node *node = q.front(); // node pointer to acess tree elements
        q.pop();                // pop element
        if (node != NULL)
        { // NULL is not element
            cout << node->data << " ";
            // not put }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
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

    printLevelorder(root);
    cout << endl;

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

levelorder  =1,2,3,4,5,6,7

     */
}