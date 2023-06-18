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

node *linkListReverse(node *head)
{

    node *prev = NULL; //taking 3 pointer is important
    node *curr = head;
    node *nxt ;

    while (curr  != NULL)
    {
        nxt = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nxt ;  
    }

    return prev;
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

    cout << "Before reverse  " << endl;

    display(head);
    cout << endl;

    cout << "after reverse " << endl;
    head = linkListReverse(head);
    display(head);

    return 0;
}