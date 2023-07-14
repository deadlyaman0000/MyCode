#include <bits\stdc++.h>
using namespace std;

int findKthElement(int *arr, int size, int k)
{
    priority_queue<int> pq;
    // step 1 push  kth element in heap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step 2 compare and pop root

    for (int i = k; i < size; i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //step 3 top element of heap is ans
    int ans  = pq.top() ;
    return ans ;
}
int main()
{
    int size = 6;
    int arr[size] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "3rd smallest element in array is :" ;
   cout << findKthElement(arr, size, k);
    return 0;

    
}