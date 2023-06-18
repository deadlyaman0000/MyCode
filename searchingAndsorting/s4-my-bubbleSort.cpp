#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    

    for (int i = 0; i < n; n--) 
    {
        for (int j = 0; j < n; j++) //comparing with j+1 so no need to write j<=n
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {11, 2, 5, 4, 36, 3, 4,5544,4333457,6789866,3345676,232435,5674,-34,-665543,0,5755};
    bubbleSort(arr, 16);
    for (int i = 0; i < 17; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}