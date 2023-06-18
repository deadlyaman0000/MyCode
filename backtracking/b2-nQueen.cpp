#include <iostream>
using namespace std;

// function to check presence of queen
bool isSafe(int **arr, int x, int y, int n)
{
    // checking if queen is present in row or not
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    // checking left diagonal
    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // checking right diagonal
    row = x;
    col = y;

    while (row >= 0 && col < n) 
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true ; //don't forget 
}

// function for placing queen
// no need to take y and ansArr

bool nQueen(int **arr, int x, int n)
{
    // base condition if all queen are placed then return true
    if (x >= n)
    {
        return true;
    }
    // checking isSafe
    // checking coloum

    for (int col = 0; col < n; col++)
    {

        if (isSafe(arr, x, col, n))
        { 
            arr[x][col] = 1;
        

        if (nQueen(arr, x + 1, n))
        { // checking next  row 
            return true;
        }

        arr[x][col] = 0; // backtrack
    }
    } //if end

    return false;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}