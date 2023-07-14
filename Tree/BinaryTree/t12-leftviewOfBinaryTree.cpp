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

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root); // pushing root

    while (!q.empty()) // this loops runs untill all levels are traversed level by level
    {
        int n = q.size();            // size of queue that changes with each level
        for (int i = 1; i <= n; i++) // loop will run for one level
        {
            Node *node = q.front();
            q.pop();

            if (i == 1)
            {
                cout << node->data << " "; // printing rightmost element in each level
            }

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
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

    leftView(root);
    cout << endl;

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

leftView  =1,2,4

     */
}