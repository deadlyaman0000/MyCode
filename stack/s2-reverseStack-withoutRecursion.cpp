#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<int> &s)
{
    stack<int> s2;
    int len = s.size();

    for (int i = 0; i < len; i++)
    {
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);

    return 0;
}