#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int postfixEvalution(string str)
{
    stack<int> st;
    
    for (int i = 0; i < str.length() ; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0'); // push operation if operand is encountered
            // we need to convert string into int for performing operation
        }

        else
        {
            int opr2 = st.top(); // popping operand for evalution 
            //in postfix order of evalution change
            st.pop();
            int opr1 = st.top();
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

    string str = "46+2/5*7+";
    cout << postfixEvalution(str);

    return 0;
}//"46+2/5*7+"