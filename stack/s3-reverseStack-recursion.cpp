#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int ele)
{

    if (s.empty())
    {
        s.push(ele); //5 will be pushed here then 4,3,2,1
        return;
    }
    int topEle = s.top(); // top value decrease with function call
    s.pop();

    insertAtBottom(s, ele);

    s.push(topEle); // inserting top element after recursion
}

void reverseStack(stack<int> &s)
{

    if (s.empty())
    {
        return;
    }

    // save top element
    int topEle = s.top();
    s.pop(); // pop top element

    reverseStack(s);
    insertAtBottom(s, topEle);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}