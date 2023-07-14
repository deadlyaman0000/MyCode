
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

// calcMaxSum
int calcMaxUtil(Node *root, int &ans) // address of ans
{
    if (root == NULL)
    {
        return 0;
    }

    int l = calcMaxUtil(root->left, ans);
    int r = calcMaxUtil(root->right, ans);

    int max_single = max(max(l, r) + root->data, root->data);
    int max_top = max(max_single, l + r + root->data); // max value of each node no ancestor data
    ans = (ans, max_top);
    // max value of all 4 is stored in ans
    cout << "max_single " << max_single << endl;
    return max_single; // node left or right value according to function call
}

// maximum path sum

int maxPathSum(Node *root)
{
    int ans = INT_MIN; // assign negative infinity value
    calcMaxUtil(root, ans);
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(-12);
    root->right = new Node(3);

    root->left->left = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(-6);
    cout << "Max sum path is : " << endl;
    cout << maxPathSum(root);

    return 0;

    /*    1
        /   \
      -12    3
      /     / \
     4     5  -6

maximum path sum  = 9
     */
}
