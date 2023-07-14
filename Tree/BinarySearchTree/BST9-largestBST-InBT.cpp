
#include <bits/stdc++.h>
#include <math.h>
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

// create structure for 5 Information

struct Info
{
    int Min;
    int Max;
    int Size;
    int Ans;
    bool IsBST;
};

// largest BST in a BTree

Info largestBSTInBTree(Node *root)
{
    if (root == NULL)
    {
        return { INT_MAX,INT_MIN, 0, 0, true}; // typecasting to Info
        //will only come here if already traversed left  and right / left is NULL so 
        //we put INT_MAX in  rightInfo.min as null  means  it has to be greater than
        // root in all cases  and we  put INT_MIN in leftInfo.max as null  means  it has 
        //to be less than root in all cases.  LOOK ORDER IS REVERSED FOR max and min AND 
        //INT_MIN and INT_MAX.
    }

    // checking for leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return {root->data, root->data, 1, 1, true};
    }

    Info leftInfo = largestBSTInBTree(root->left);
    Info rightInfo = largestBSTInBTree(root->right);

    // current node information
    Info curr;

    curr.Size = (1 + leftInfo.Size + rightInfo.Size);

    // checking condition
    //1.check for left and right subBTree if they are bst or not 
    //compare left and right with root->data 
    if ( leftInfo.IsBST && rightInfo.IsBST &&   leftInfo.Max < root->data && rightInfo.Min > root->data )
    {

        curr.Min = min(leftInfo.Min,  root->data);
        curr.Max = max(rightInfo.Max,  root->data);

        curr.Ans = curr.Size;
        curr.IsBST = true;
        return curr;
    }
    // not BST
    curr.Ans = max(leftInfo.Ans, rightInfo.Ans);
    curr.IsBST = false;
    return curr;
}

int main()
{

    struct Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);

    root->left->right = new Node(3);

    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);

    cout<<largestBSTInBTree(root).Ans <<endl ;
   

    return 0;

    /*    5
        /   \
       1     7
        \
         3
        / \
       2   4

largest BST in a BTree = 6
     */
}
