#include <iostream>
#include <stack>

using namespace std;

void reverse(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";

        while (s[i] != ' ' && i < s.length())
        { // store word until space is encountered
            word += s[i];
            i++;
        }
        st.push(word); // push word by word
    }

    // int len = st.size();
    // for (int i = 0; i < len; i++) //do not write i<st.size() its value decrease after pop
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    while(!st.empty()){
        cout<<st.top() <<" " ;
        st.pop();
    }
}
int main()
{
    string str = "Hey, how are you doing?";
    reverse(str);

    return 0;
}