#include <iostream>
using namespace std;

// first occurance

int firstoccur(int arr[], int n, int i, int key)
{ // i =0 ;
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstoccur(arr, n, i + 1, key);
}

// last occurance

int lastoccur(int arr[], int n, int i, int key)
{ // i =0 ;

    if (i == n)
    {
        return -1;
    }

    int restArr = lastoccur(arr, n, i + 1, key);

    if (restArr != -1)
    {
        return restArr;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int arr[8] = {0, 1, 2, 3, 5, 7, 8, 3};
    cout << firstoccur(arr, 8, 0, 3);
    cout << endl;

    cout << lastoccur(arr, 8, 0, 3);

    return 0;
}