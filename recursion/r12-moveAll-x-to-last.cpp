#include <iostream>
using namespace std;

string removeAllx(string str)
{
    if (str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    string ans = removeAllx(str.substr(1));
    if (ch == 'x')
    {
        return (ans + ch);
    }
    return (ch + ans);
}
int main()
{
    string str = "xxabcdxxjdfjxx";

    cout << removeAllx(str);
    return 0;
}