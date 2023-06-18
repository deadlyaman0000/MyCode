#include <iostream>
using namespace std;

int countPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }
    return count;
}
int main()
{
    int s = 0, e = 3 ;
    cout << countPath(s,e);

    return 0;
}