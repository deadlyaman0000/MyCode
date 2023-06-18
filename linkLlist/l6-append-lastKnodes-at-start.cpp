#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
void display(node *head)
{
node * temp = head ;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL" <<endl ;
}

// length function

int length(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp!= NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// append function
node *kAppend(node *head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head; // traverse from head to tail

    int len = length(head); // length of linklist function call
    int count = 1;
    k=k%len; //if value of k is higher so in normal case k=3,l=7 then  3%7 = 3

    while (tail->next != NULL)
    {
    
        if (count == len - k)
        {
            newTail = tail;
        }
        if (count == len - (k + 1))
        {
            newHead = tail;
        }
        tail = tail->next; 
        count++ ; 
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}
int main()
{
    node *head = new node;
    node *n2 = new node;
    node *n3 = new node;
    node *n4 = new node;

    head->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

   node* newhead = kAppend(head,2); //create new node that will store the new head
    display(newhead) ;

    return 0;
}