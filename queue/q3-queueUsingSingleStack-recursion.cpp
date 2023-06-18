#include <iostream>
#include <stack>
using namespace std;

class queue
{

    stack<int> s1;

    // push
public:
    void push(int x)
    {
        s1.push(x); // stack
    }
    // pop
    int pop()
    {
        if (s1.empty())
        {
            cout << "No element to pop " << endl;
            return -1;
        }

        int x = s1.top(); // last element is stored in x;
        s1.pop();
        if (s1.empty())
        {
            return x; // return last element fifo
            //x store last element value then return it 
        }
        int item = pop();
        s1.push(x);  // pushing element again in stack
        return item; // recursion
    }

    // empty
    bool empty()
    {
        if (s1.empty())
        {

            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.pop() << endl;
    }

    cout << endl;
    q.pop();
    cout << q.empty();

    return 0;
}