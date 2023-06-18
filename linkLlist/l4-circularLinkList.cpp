#include <bits\stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
void display(node *head)
{
    node *start = head;

    while (start->next != head)
    {
        cout << start->data << endl;
        start = start->next;
    }
    cout << start->data << endl;
}

// insert at begning

node *insertAtStart(node *head, int data2)
{
    node *start = head;
    while (start->next != head)
    {
        start = start->next;
    }
    node *ptr = new node;
    ptr->data = data2;
    ptr->next = head;
    start->next = ptr; // end node of circular link list
    return ptr;
}

// insert at end
node *insertAtend(node *head, int data2)
{
    node *ptr = new node;
    ptr->data = data2;
    ptr->next = head;

    node *start = head;

    while (start->next != head)
    {
        start = start->next;
    }
    start->next = ptr;
    return ptr;
}

// insert at Index
node *insertAtIndex(node *head, int data2, int index)
{
    node *ptr = new node;
    ptr->data = data2;

    node *start = head;
    int i = 1;
    while (i < index)
    {
        start = start->next;
        i++;
    }
    node *p = start->next;
    start->next = ptr;
    ptr->next = p;
    return ptr;
}

// Deletion
// deletion at start

void deletionAtStart(node *&head)
{
    node *start = head;
    node *del = head;

    while (start->next != head)
    {
        start = start->next;
    }
    head = head->next;
    start ->next =head ; //last node 

    delete del;
}

// deletion at end
void deletionAtEnd(node *head)
{

    node *ptr2 = head;
    
    while (ptr2->next->next != head)
    {
        ptr2 = ptr2->next;
    }
  
    node * del = ptr2->next ;
    ptr2->next = head;
    delete del ;//deleting last node 
    
    
}

// deletion at index

void deletionAtIndex(node *head, int index)
{

    node *ptr2 = head;
    int i = 1;
    while (i != (index - 1))
    {
        ptr2 = ptr2->next;
        i++;
    }
    node *ptr3 = ptr2;
    ptr2 = ptr2->next;
    ptr3->next = ptr2->next;
    delete ptr2;
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
    n4->next = head;

    cout << "Before Insertion  " << endl;

    display(head);
    cout << endl;

    cout << "After Insertion at start " << endl;
    head = insertAtStart(head, 0); // must use new node is added before head so head =
    display(head);

    cout << "After Insertion at end " << endl;
    insertAtend(head, 999); // must use new node is added before head so head =

    display(head);

    cout << "after insertion at index " << endl;
    int index = 3;
    insertAtIndex(head, 33, index);
    display(head);

    cout << "list after deletion from start " << endl;
    deletionAtStart(head);
    display(head);

    cout << "list after deletion at end " << endl;
    deletionAtEnd(head);
    display(head);

    cout << "list after deletion at index " << endl;

    deletionAtIndex(head, 3);
    display(head);

    return 0;
}