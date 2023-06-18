#include <iostream>
using namespace std;

// using macros to fix the value of array
#define n 100

// stack

class stack
{

    int *arr;
    int top;

public:
    // constructor
    stack()
    {
        arr = new int[n]; // memory allocation to array using macros
        top = -1;
    }

    // push operation
    void push(int x)
    {
        if (top == n - 1) // check if stack is full
        {
            cout << "Stack Overflow " << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    // pop operation
    void pop()
    {
        if (top == -1) // check if stack is empty
        {
            cout << "No element to pop " << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    // top

    int Top()
    {
        if (top == -1) // check if stack is empty
        {
            cout << "No element in stack " << endl;
            return -1;
        }
        return arr[top];
    }

    // empty

    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "top value : " << st.Top() << endl;
    cout << "stack is empty :" << st.empty() << endl;

    st.pop();
    cout << "top value after pop : " << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << "stack is empty : " << st.empty() << endl;

    return 0;
}