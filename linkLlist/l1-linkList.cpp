#include <bits\stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

public:
    node(int data2)
    {
        data = data2; //dont use same name
        next = NULL ;
        
    }
};
void display(node* head)
{
    node * temp =head ;

    while (temp!= NULL)
    {
        cout << temp->data << endl;
        temp = temp ->next ;
    }
    
}

int main()
{

  
    node n1(55);
    node n2(35);
    node n3(25);
    node n4(15);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    display(&n1);

    return 0;
}