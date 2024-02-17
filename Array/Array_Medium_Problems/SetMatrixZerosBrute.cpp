#include <iostream>
#include <vector>
using namespace std;

// Function to mark all elements in a row as -1
void markRow(vector<vector<int>> &arr, int i, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

// Function to mark all elements in a column as -1
void markColumn(vector<vector<int>> &arr, int j, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

// Function to set zeros in the matrix
void SetMatrixZeros(vector<vector<int>> &arr, int n, int m)
{
    // Iterate through the matrix to find cells with value 0 and mark their row and column
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(arr, i, m);    // Mark row i
                markColumn(arr, j, n); // Mark column j
            }
        }
    }

    // Iterate through the matrix again to set marked elements to zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Define a 2D vector to store the matrix
    vector<vector<int>> arr(n, vector<int>(m));

    // Input matrix elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output original matrix elements
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Set zeros in the matrix
    SetMatrixZeros(arr, n, m);

    // Output modified matrix elements
    cout << "Modified Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: Set Matrix Zeros
Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix. The first term accounts for traversing and marking rows and columns, and the second term accounts for marking cells with -1 as 0 finally.
Space Complexity: O(1) as we are not using any extra space.
*/
