#include <iostream>
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

// case 1  print data at k distance node
// it will be called by case 1
void printSubTreeNodes(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printSubTreeNodes(root->left, k - 1);
    printSubTreeNodes(root->right, k - 1);
}

// case 2

int printNodeAtK(Node *root, int target, int k)
{

    if (root == NULL)
    {
        return -1;
    }
    if (root->data == target)
    {
        printSubTreeNodes(root, k); // call case 1
        return 0;
    }

    // root found in left or right

    int dl = printNodeAtK(root->left, target, k); // dl is variale
    // here function is alredy called so if it find target it have dl value
    // by return dl+1 ;
    // if target is not found then dl = -1 ;

    if (dl != -1)
    {
        
        if (dl + 1 == k)
        {
            cout << root->data << " "; // k is at root
        }
        else
        {
            printSubTreeNodes(root->right, k - dl - 2); // we start from left so
            // root increase 1 and root->right increase 1 ;
        }
        return dl + 1; // increment dl variable with function call
    }

    // root is in right them ancestor are in left
    int dr = printNodeAtK(root->right, target, k);
    if (dr != -1)
    {
        
        if (dr + 1 == k)
        {
            cout << root->data << " "; // k is at root
        }
        else
        {
            printSubTreeNodes(root->left, k - dr - 2); // we start from left so
            // root increase 1 and root->right increase 1 ;
        }
        return dr + 1; // increment dl variable with function call
    }
    return -1;
}
int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printNodeAtK(root, 2,1);

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7
    / \
   8   9
distance at k node target 2 = {4,5,1}
     */
}