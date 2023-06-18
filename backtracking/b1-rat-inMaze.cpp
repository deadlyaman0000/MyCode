#include <iostream>
using namespace std;

// function to chek if path is blocked or not
bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    { // arr[x][y] == 1 quardinates of block is 1 when it is open
        return true;
    }
    return false;
}

bool ratinMaze(int **arr, int x, int y, int n, int **ansArr)
{

    if ((x == (n - 1)) && (y == (n - 1)))
    {
        ansArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        ansArr[x][y] = 1;

        if (ratinMaze(arr, x + 1, y, n, ansArr))
        {
            return true;
        }

        if (ratinMaze(arr, x, y + 1, n, ansArr))
        {
            return true;
        }

        ansArr[x][y] = 0; // backtrack
        return false;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    // input array
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n]; // 2d array
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j]; // cin
        }
    }

    // output array

    int **ansArr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        ansArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ansArr[i][j] = 0; // assgning ansArr to 0
        }
    }

    // function call

    cout << endl
         << endl;

    if (ratinMaze(arr, 0, 0, n, ansArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ansArr[i][j] << " "; // printing output values
            }
            cout << endl;
        }
    }
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1