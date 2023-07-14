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

// calculate path of n1 and n2 and strore in vector if n1 or n2 not found then return false
// it is type bool so path is stored using adress
bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data); // storing root data into the path vector
    if (root->data == key)
    {
        return true;
    }
    if (getPath(root->left, key, path)  || getPath(root->right, key, path) )
    {
        return true;
    }

    path.pop_back(); // if path is not correct
    return false;
}

// LCA

int LCA(Node *root, int n1, int n2)
{
   
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    { // if  n1 and n2 are not present
        return -1;
    }

    int pc ; // store lca  path count
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    { // pe<smallsize path

        if (path1[pc] != path2[pc])
        { // checking 1st uncommon node
            break;
        }
    }
    return path1[pc-1]; //return path data ..lca 
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

    int Lca = LCA(root, 4, 5);
    cout << "LCA is : " << Lca;

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

LCA of 4,5 = 2

     */
}