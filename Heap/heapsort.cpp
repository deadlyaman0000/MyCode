#include <iostream>
using namespace std;

// heapify

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= n && arr[largest] < arr[left]) //= because 1 based indexing
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

// heapsort
void heapsort(int *arr, int n)
{
    int size = n;
    while (size > 1) // 1 because last element alredy sorted
    {

        swap(arr[1], arr[size]); // step 1 swap
        size--;
        heapify(arr, size, 1); // step 2
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // heap creation
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "array after heapify " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // heapsort
    heapsort(arr, n);
    cout << "array after heapsort " << endl;
    for (int j = 1; j <= n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}