#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int infixEvalution(string str)
{
    stack<int> st;
    // we need to put string in reverse order
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0'); // push operation if operand is encountered
            // we need to convert string into int for performing operation
        }

        else
        {
            int opr1 = st.top(); // popping operand for evalution
            st.pop();
            int opr2 = st.top();
            st.pop();

            // performing evalution according to encountered operator using switch

            switch (str[i])
            {
            case '+':
                st.push(opr1 + opr2);
                break;

            case '-':
                st.push(opr1 - opr2);
                break;

            case '*':
                st.push(opr1 * opr2);
                break;

            case '/':
                st.push(opr1 / opr2);
                break;
            case '^':
                st.push(pow(opr1, opr2));
                break;

           
            }
        }
    }
    return st.top(); // final result
}
int main()
{

    string str = "-+7*45+20";
    cout << infixEvalution(str);

    return 0;
}//"-+7*45+20"