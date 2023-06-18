#include <iostream>
using namespace std;

// swap function
void swap2(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partition function return index of pivot
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) //do not put j = 0 
    {
        if (arr[j] < pivot)
        {
            i++;
            swap2(arr, i, j);
        }
    }
    swap2(arr, (i + 1), r); // i+1 element is swap with old pivot
    return (i + 1);
}

// quicksort

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    { // don't forget the base condition
        int pi;
        pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main()
{
    int arr[] = {1, 2, 4, 9, 8, 3, 6, 5, 7};
    quickSort(arr, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}