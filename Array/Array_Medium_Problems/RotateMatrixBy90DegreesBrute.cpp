#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> RotateMatrixby90Degrees(vector<vector<int>> matrix, int n, int m)
{
    vector<vector<int>> ans(m, vector<int>(n)); // Transposed matrix dimensions

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][n - i - 1] = matrix[i][j]; // Rotate 90 degrees clockwise
        }
    }

    return ans;
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
    vector<vector<int>> ans = RotateMatrixby90Degrees(matrix, n, m);

    // Output rotated matrix elements
    cout << "90 Degree Rotated Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: Rotate Matrix by 90 Degrees
Time Complexity: O(N*M) to iterate over each element of the matrix and copy it into the new rotated matrix.
Space Complexity: O(N*M) to store the rotated matrix.
*/
