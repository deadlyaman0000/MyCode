#include <iostream>
using namespace std;

// decreasing order
void dec(int n)
{
    if (n == 1)
    {
        cout << "1" <<endl ;
        return;
    }
    cout << n << endl;
    dec(n - 1);
}

// Increasing order
void Inc(int n)
{
    if (n == 1) 
    {
        cout << "1" <<endl ;
        return;
    }
    Inc(n - 1);
    cout << n << endl; // below function call
}

int main()
{
    int n = 9;
   
    cout << endl;
    dec(n);
    cout << endl;
    Inc(n);
    return 0;
}