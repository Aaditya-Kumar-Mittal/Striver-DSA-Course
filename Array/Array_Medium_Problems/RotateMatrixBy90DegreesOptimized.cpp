/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void RotateMatrixby90Degrees(vector<vector<int>> &matrix, int n, int m)
{
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Define a 2D vector to store the matrix
    vector<vector<int>> matrix(n, vector<int>(m));

    // Input matrix elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Output original matrix elements
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Rotate the matrix by 90 degrees
    RotateMatrixby90Degrees(matrix, n, m);

    // Output rotated matrix elements
    cout << "90 Degree Rotated Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: Rotate Matrix by 90 Degrees
Time Complexity: O(N*N) + O(N*N), where N is the number of rows in the matrix. One O(N*N) is for transposing the matrix, and the other is for reversing the matrix.
Space Complexity: O(1) as we are not using any extra space.
*/
