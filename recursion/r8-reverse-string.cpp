#include <iostream>
using namespace std;

// print reverse
//  void reverse(string str, int n)
//  {
//      if (n == 0)
//      {
//          cout << str[n];
//          return;
//      }
//      cout << str[n];
//      reverse(str, n - 1);
//  }

void reverse(string str)
{
    if (str.length() == 0)
    {
        return;
    }
    string restOfStr = str.substr(1);
    reverse(restOfStr);
    cout << str[0];
}

int main()
{
    string str = "binod";
    //  reverse(str, str.length());
    reverse(str);

    return 0;
}