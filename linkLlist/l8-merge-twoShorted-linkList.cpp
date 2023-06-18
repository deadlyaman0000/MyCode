
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
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Merge shorted linkList

node *MergelinkList(node *head1, node *head2)
{

    // making 3 pointers
    node *p1 = head1;
    node *p2 = head2;

    // dummyNode node
    node *dummyNode = new node();

    node *p3 = dummyNode;


    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    // nodes that are left after one link list reaches NULL

    while (p1 != NULL)
    {
        p3->next = p1;
        p3 = p3->next;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p3 = p3->next;
        p2 = p2->next;
    }

    // next of last node is alredy  Null
    return dummyNode->next;
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

    // linklist 2

    node *head2 = new node;
    node *n22 = new node;
    node *n33 = new node;

    head2->data = 11;
    n22->data = 22;
    n33->data = 33;

    head2->next = n22;
    n22->next = n33;
    n33->next = NULL;

    // calling function
    node *newHead = MergelinkList(head, head2);
    display(newHead);

    return 0;
}