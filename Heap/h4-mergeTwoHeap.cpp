#include <bits/stdc++.h>
using namespace std;

// heapify

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = i * 2 +1 ;
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

// merge array
vector<int> mergeHeaps(vector<int> &v1, vector<int> &v2)
{

    vector<int> ans;
   // ans.push_back(-1); //one based indexing

    // step 1 merging vector
    for (auto i : v1)
    {
        ans.push_back(i);
    }
    for (auto i : v2)
    {
        ans.push_back(i);
    }

    // call heapfiy for mergged vector
    int n = ans.size();
    int i = (n / 2) -1;
    //build heap
    for ( i ; i >= 0; i--)
    {
        heapify(ans, n, i);
    }

    return ans;
}
int main()
{
    // vec 1
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(2);
   

    // vec 2
    vector<int> v2;
    v2.push_back(12);
    v2.push_back(7);
    v2.push_back(9);
 

    vector<int> v3 = mergeHeaps(v1, v2);
    for (auto i : v3)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}