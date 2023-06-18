#include <iostream>
using namespace std;

void towerofHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }

    towerofHanoi(n - 1, src, helper, dest);
    cout << "Mover from " << src << " to " << dest << endl;
    towerofHanoi(n - 1, helper, dest, src);
}
int main()
{
    int n = 5;
  
    towerofHanoi(n, 'A', 'C', 'B');

    return 0;
}