#include <bits/stdc++.h>
using namespace std;

void SpiralTraversingMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    cout << "Spirally Traversing the Matrix: " << endl;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << matrix[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
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

    SpiralTraversingMatrix(matrix, n, m);

    return 0;
}

/*
Analysis of Problem

Name: Spiral Matrix Traversal
Time Complexity: O(m x n)
Space Complexity: O(1)
Explanation:
- Time Complexity: Since all the elements are being traversed once, and there are total n x m elements (m elements in each row and total n rows), the time complexity will be O(n x m).
- Space Complexity: No extra space is used other than a few variables, so the space complexity is O(1).
*/
