#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    int data;

public:
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    // push operation
    void push(int x)
    {

        node *n = new node(x);
        if (front == NULL) // 1st eklement push
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    // pop operation
    void pop()
    {

        if (front == NULL)
        {
            cout << "No element to pop " << endl;
            return;
        }
        node *del = front; // delete node
        front = front->next;
        delete del;
    }
    // peek operation
    int peek()
    {
        if (front == NULL)
        {
            cout << "No element in Queue " << endl;
            return -1;
        }
        return front->data;
    }

    // empty
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};
int main()
{

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.peek() << endl;
        q.pop();
    }

    cout << endl;
    q.pop();
    cout << q.empty();

    return 0;
}