#include <iostream>
using namespace std;

class heap
{
public:
    int data;
    int arr[100];
    int size;

    // index 0 will be empty in heap
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // insert in max heap

    void insert(int val)
    {
        size = size + 1; // size increase after insrtion
        int index = size;
        // inserting value in size index
        arr[size] = val;

        while (index > 1)
        {
            // comparing with parent to put value in correct position
            int Parent = index / 2; // property
            if (arr[Parent] < arr[index])
            {
                swap(arr[Parent], arr[index]); // swapping done
                Parent = index;                // after swap parent change
            }
            else
            {
                return;
            }
        }
    }

    // delete root
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "No item to delete " << endl;
            return;
        }

        arr[1] = arr[size]; // step 1 replace root  with last node
        size--;             // step 2  delete last node(root)
        int i = 1;

        // step 3 putting root in coorect position
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            if (rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deleteFromHeap();
    cout << "after deletion " << endl;
    h.print();

    return 0;
}