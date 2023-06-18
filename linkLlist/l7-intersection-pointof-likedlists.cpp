#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

// length function

int length(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// intersection function

int intersection(node *head1, node *  head2)
{

    // calling length function
    int len1 = length(head1);
    int len2 = length(head2);

    // making poinnter to store head
    node *ptr1;
    node *ptr2;

    int diff = 0;

    // we store greater length in ptr1
    if (len1 > len2)
    {
        ptr1 = head1;
        ptr2 = head2;
        diff = len1 - len2;
    }

    else
    {
        ptr1 = head2;
        ptr2 = head1;
        diff = len2 - len1;
    }
    // no need to check for equal condition

    // traverse the diffrence and store new head vallue in ptr1
    while (diff)
    {
        ptr1 = ptr1->next;
        diff--;
    }

    // finding intersection
    
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
      
    }
    return -1;
}

int main()
{
    //linklist 1
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

    // linklist 2
    node *head2 = new node;
    node *n22 = new node;
   

    head2->data = 11;
    n22->data = 22;

    head2->next = n22;
    n22->next = n3;

    cout<< intersection(head,head2);

 

    return 0;
}