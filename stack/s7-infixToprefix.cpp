#include <bits\stdc++.h>

using namespace std;

// function that will compare the operator
// we assign integer value to operator so thir comparision will be easy

int prec(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }

    else if (c == '*' || c == '/')
    {
        return 2;
    }

    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1; // char is not operator
    }
}

// infix to  postfix

string infixToPrefix(string str)
{
    stack<char> st; // conversion not evalution
    string result;  // for storing postfix expression

    // reverse string
    reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            result += str[i]; // adding operand to string
        }

        else if (str[i] == ')')
        {
            st.push(str[i]);
        }

        else if (str[i] == '(')
        {
            while (!str.empty() && st.top() != ')') // while ')' in stack is  not encountered pop and it is not empty
            {
                result += st.top();
                st.pop();
            }
            if (!str.empty())
            {
                st.pop(); // loop pop element before '(' we need top it as well ,it is not included in string
            }
        }
        // operator case

        else
        {
            while (!st.empty() && prec(str[i]) < prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(str[i]); // pushing operator
        }
    }
    // while stack is not empty
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string str = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(str);

    return 0;
}