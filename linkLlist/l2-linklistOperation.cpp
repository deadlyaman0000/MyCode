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

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

// insert at begning

node *insertAtStart(node *head, int data2)
{
    node *n = new node;
    n->data = data2;
    n->next = head;
    return n;
}

// insert at end
void insertAtend(node *head, int data2)
{
    node *ptr = new node;
    ptr->data = data2;
    ptr->next = NULL;

    node *start = head;

    while (start->next != NULL)
    {
        start = start->next;
    }
    start->next = ptr;
   // return ptr;
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
     if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }

    node *del = head;
    head = head->next;
    delete del;
}

// deletion at end
void deletionAtEnd(node *head)
{

    node *ptr2 = head;
    while (ptr2->next->next != NULL)
    {
        ptr2 = ptr2->next;
    }
    cout << "delete at end   " << ptr2->next->data << endl;
    node* del = ptr2->next ;
    ptr2->next = NULL;
    delete del ;
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
    node *ptr3 = ptr2 ;
    ptr2 = ptr2 ->next ;
    ptr3->next= ptr2->next ;
   delete ptr2 ;

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

    cout << "Before Insertion  " << endl;

    display(head);
    cout << endl;

    cout << "After Insertion " << endl;
    head = insertAtStart(head, 0); // must use new node is added before head so head =

    insertAtend(head, 5);

    int index = 3;
    insertAtIndex(head, 33, index);
    display(head);

    cout << "list after deletion " << endl;
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