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

// traversal postorder
//postorder
void Postorder(struct node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}


//search function 
int search(int inorder[],int start ,int end ,int curr){

for(int i= start ; i <= end ;i++){
    if(inorder[i] == curr){
        return i ; //return pos of idx in inorder
    }
}
}
node *buildTree(int postorder[], int inorder[],int start,int end){
    static int  idx  = end ;
    if(start > end){ //base condition
        return NULL;
    }
    int curr = postorder[idx];
    node *Node = new node(curr);
    idx-- ; //increment index

    if(start == end ){
        return Node ;
    }

    int pos = search(inorder,start,end,curr); //searh function

    //recursion
   Node->right =  buildTree(postorder,inorder,pos+1,end); //building right subtree
   Node->left  =  buildTree(postorder,inorder,start,pos-1); //building left subtree

}

int main()
{

int postorder[] = {4,5,2,6,7,3,1} ;
int intorder[] = {4,2,5,1,6,3,7} ;
node *root = buildTree(postorder,intorder,0,6) ;

Postorder(root);
//print postorder if everthing is correct



    return 0;

    /*    1
        /   \
       2     3
      / \   / \
     4  5   6  7

preorder  =1,2,4,5,3,6,7
inorder   =4,2,5,1,6,3,7
postorder =4,5,2,6,7,3,1
     */
}