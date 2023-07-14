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

     return max( calcHeight(root->left),calcHeight(root->right)) +1 ;
}

int calcDiameter(node *root){
     // base condition
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left); //left height of current  node
    int rHeight = calcHeight(root->right);//right height of current node
    int currdiameter = lHeight + rHeight +1 ;

    int ldiameter = calcDiameter(root->left); //root not included 
    int rdiameter = calcDiameter(root->right);

    return max (currdiameter, max(ldiameter,rdiameter));
    
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

 
    cout <<calcDiameter(root);

    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7


Diameter = 6
     */
}