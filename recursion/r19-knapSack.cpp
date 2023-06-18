#include <iostream>
#include<cmath>
using namespace std;

int knapSack(int value[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
    { // capacity of knapSack is full

        return 0;
    }
    if (wt[n - 1] > W)
    { // weight of item is greater than  knapSack
        return knapSack(value, wt, n - 1, W);
    }

    return max(knapSack(value, wt, n - 1,  W - wt[n - 1]) + value[n-1], knapSack(value, wt, n - 1, W));
    // maximum value will be returned
}

int main()
{
   
    int W = 50;
    int value[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    cout << knapSack(value, wt, 3, W);
    return 0;
}