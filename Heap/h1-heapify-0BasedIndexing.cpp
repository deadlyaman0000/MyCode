#include <iostream>
using namespace std;

// heapify

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = i * 2+1;
    int right = i * 2 + 2;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i) // compare largest with i
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); // call heapify
    }
}

int main()
{
    int arr[5] = { 54, 53, 55, 52, 50};
    int n = 5;
    int i = ((n / 2)-1); // leaf nodes are alredy heap

    while (i >= 0)
    {
        heapify(arr, 5, i);
        i--;
    }

    cout << " array after heapify " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}