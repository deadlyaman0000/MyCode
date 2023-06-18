#include <iostream>
using namespace std;

// macro
#define n 20

class Queue
{

    int *arr;
    int front;
    int back;

public:
    // constructor
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    // push operation
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue is overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;
        // in case of first element we need to consider  front also
        // because front value is increased after insertion of first element
        if (front == -1)
        {
            front++;
        }
    }

    // pop operation
    void pop()
    {

        if (front == -1 || front > back)
        {
            cout << "No element to pop " << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "There is no front element " << endl;
            return -1; // important
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
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
    q.push(5);

    while (!q.empty())
    {
        cout << q.peek() << endl;
        q.pop();
    }

    q.pop() ;
  cout <<   q.empty();

    return 0;
}