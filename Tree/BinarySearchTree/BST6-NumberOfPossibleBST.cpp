#include <bits/stdc++.h>
#include <vector>
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

int Preorder(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
// possible binary search tree

vector<Node *> constructPossibleBST(int start, int end)
{

    vector<Node *> listOfRoots;

    // if start > end   then subtree will be empty so returning NULL
    //  in the list
    if (start > end)
    {
        listOfRoots.push_back(NULL);
        return listOfRoots;
    }

    // constructing left and right subtree
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtrees = constructPossibleBST(start, i - 1);
        vector<Node *> rightSubtrees = constructPossibleBST(i + 1, end);
       
        // connecting left and right subtree to root
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *Left = leftSubtrees[j];

            for (int k = 0; k < rightSubtrees.size(); k++)
            {

                Node *Right = rightSubtrees[k];
    
                // creating node and pushing its root to vector
                Node *node = new Node(i);
                node->left = Left;
                node->right = Right;
                listOfRoots.push_back(node); // adding root to vector
               
            }
        }
        
    }
    return listOfRoots;
}

int main()
{
    vector<Node *> totalRoots;

    totalRoots = constructPossibleBST(1, 3);
    for (int i = 0; i < totalRoots.size(); i++)
    {
        cout << "Preorder traversal of Bst   : " << i + 1 << endl;
        Preorder(totalRoots[i]);
        cout << endl;
    }

    return 0;
}