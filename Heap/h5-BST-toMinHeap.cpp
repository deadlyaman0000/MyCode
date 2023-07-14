
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

void Preorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}


//storing value of BST in deque
void Inorder(Node *root, deque<int> &arr) 
{

    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, arr);
    arr.push_back(root->data);//push value in deque
    Inorder(root->right, arr);
}

// build preorder

void buildPreorderHeap(Node *root, deque<int> &arr )
{
   
    if (root == NULL)
    {
        return;
    }
    root->data = arr.front(); //puuting inorder data heap
    arr.pop_front();
   
        buildPreorderHeap(root->left, arr);
        buildPreorderHeap(root->right, arr);
    
}

// Bst to heap
void convertToMinHeapUtil(Node *root)
{
    deque<int> arr; //creating deque to store inorder 

   // int i = -1 ; //index for deque 
    Inorder(root, arr);
    buildPreorderHeap(root, arr); //passing &i because index change recursively
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Function call
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    Preorder(root);

    return 0;
}
