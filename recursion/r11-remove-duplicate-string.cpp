#include <iostream>
using namespace std;

//for sorted string

string removeDup(string str)
{
    if (str.length() == 0)
    {
        return "";
    }
    char ch = str[0];
    string ans = removeDup(str.substr(1));

    if (ch == ans[0])
    {
        return ans;
    }
    return (ch + ans);
}
int main()
{
    string str = "aaaabbbbccccddddeeeffffggg";
  
   cout << removeDup(str);

    return 0;
}