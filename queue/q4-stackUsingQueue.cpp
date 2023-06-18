#include <iostream>
#include <queue>
using namespace std;

class stack
{
    int N; // size of stack
    queue<int> q1;
    queue<int> q2;

public:
    stack()
    {
        N = 0;
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "No element to pop " << endl;
            return;
        }
        // pop till last element
        while (q1.size() != 1)
        {
            q2.push(q1.front()); // push q1 element to q2
            q1.pop();
        }
        q1.pop(); // pop done
        N--;      // decrase size of stack

        // temp queue for copy elements from q2 to q1
        queue<int> temp = q2;
        q1 = q2;
        q2 = temp;
    }

    void push(int x)
    {
        q1.push(x);
        N++; // element pushed so size of stack increase
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int topVal = q1.front(); // save return value
        q2.push(topVal);         // we do not perform pop we will push the element

        queue<int> temp = q2;
        q1 = q2;
        q2 = temp;

        return topVal;
    }

    int size()
    {
        return N;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while (st.size() != 0)
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout <<endl ;
    cout << "top value : " << st.top() << endl;
    cout << "stack is empty :" << st.size() << endl;

    return 0;
}