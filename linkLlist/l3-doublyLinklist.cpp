#include <bits\stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void display(node *head)
{

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

node *insertAtStart(node *head, int data2)
{
    node *n = new node;
    n->data = data2;
    n->next = head;
    n->prev = NULL;

    head->prev = n;
    return n;
}

// insert at end
node *insertAtend(node *head, int data2)
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
    ptr->prev = start;
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
    ptr->prev = start;
    ptr->next = p;
    p->prev = ptr;
    return ptr;
}

// Deletion
// deletion at start

void deletionAtStart(node *&head)
{
    node *del = head;
    del->next->prev = NULL;
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
    ptr2->next->prev= ptr3;
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

    head->prev = NULL;
    n2->prev = head;
    n3->prev = n2;
    n4->prev = n3;

    cout << "Before reverse  " << endl;

    display(head);

    cout << "prev " << n2->prev->data << endl;
    head = insertAtStart(head, 100);
    cout << "After insertion at start " << endl;
    display(head);
    cout << "After insertion at end " << endl;
    insertAtend(head, 999);
    display(head);

    cout << "After insertion at index " << endl;
    insertAtIndex(head, 333, 3);
    display(head);

    cout << "After deletion at start  " << endl;
    deletionAtStart(head);
    display(head);

    cout << "deletion at end " << endl;
    deletionAtEnd(head);
    display(head);

     cout << "deletion at index" << endl;
    deletionAtIndex(head,3);
    display(head);

    return 0;
}