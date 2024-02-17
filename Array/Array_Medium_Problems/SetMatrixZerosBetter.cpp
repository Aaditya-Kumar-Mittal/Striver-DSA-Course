/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to set zeros in the matrix
void SetMatrixZeros(vector<vector<int>> &arr, int n, int m)
{
    // Create arrays to mark rows and columns with zeros
    vector<int> column(m, 0);
    vector<int> row(n, 0);

    // Iterate through the matrix to mark rows and columns containing zeros
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;     // Mark row i
                column[j] = 1;  // Mark column j
            }
        }
    }

    // Iterate through the matrix again to set marked rows and columns to zeros
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || column[j])
            {
                arr[i][j] = 0;  // Set arr[i][j] to zero if row i or column j is marked
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
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: O(N) is for using the row array and O(M) is for using the col array.
*/
