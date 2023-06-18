#include <bits/stdc++.h>
using namespace std;

bool isbalanced(string str)
{
    stack<char> st;
    bool ans =true ;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            st.push(str[i]); // pushing opening brackets
        }


         else if (str[i] == '}' )
        {
            if(st.top() == '{'){
            st.pop();
            }
            else{
                ans = false ;
                break ;

            }
        }

         else if (str[i] == ']' )
        {
            if(st.top() == '['){
            st.pop();
            }
            else{
                ans = false ;
                break ;

            }
        }

         else if (str[i] == ')' )
        {
            if(st.top() == '('){
            st.pop();
            }
            else{
                ans = false ;
                break ;

            }
        }
    }
    return ans ;
}
int main()
{
    string str = "{{()}}";
   if( isbalanced(str)){
    cout<<"valid string "<<endl ;
   }
   else{
    cout <<"invalid string " ;
   }

    return 0;
}