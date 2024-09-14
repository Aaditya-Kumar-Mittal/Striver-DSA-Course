# Recursion Problem : N-Queens Puzzle Solution Using Backtracking

## Problem Description

- The n-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.
- Given an integer `n`, this function returns all distinct solutions to the n-queens puzzle.
- Each solution contains a distinct board configuration where `'Q'` represents a queen and `'.'` represents an empty space.

## N-Queens Visualizer

You can explore the N-Queens puzzle through an interactive visualizer using the link below:

[N-Queens Visualizer](https://haseebq.com/n-queens-visualizer/)

This visualizer helps in understanding how the queens are placed on the board without attacking each other.

## Code

```cpp
class Solution {
  public:
    /*
        Function to place queens on the board recursively.

        Parameters:
        - col: The current column we're trying to place a queen in.
        - board: The current configuration of the chessboard.
        - ans: A vector to store all valid board configurations.
        - leftRow: A vector to track if a queen is placed in a particular row.
        - upperDiagonal: A vector to track if a queen is placed in the upper diagonal (row - col remains constant).
        - lowerDiagonal: A vector to track if a queen is placed in the lower diagonal (row + col remains constant).
        - n: The size of the chessboard (n x n).

        This function uses recursion and backtracking to generate all valid n-queens solutions.
    */
    void placeNQueens(int col, vector<string>& board, vector<vector<string>>& ans, 
                      vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        // Base case: If all columns are filled, we have a valid solution
        if (col == n) {
            ans.push_back(board);  // Add the current board configuration to the result
            return;
        }

        // Try placing the queen in each row of the current column
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                // Place the queen on the board
                board[row][col] = 'Q';
                // Mark the current row, upper diagonal, and lower diagonal as unsafe
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recursively place the queen in the next column
                placeNQueens(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack: Remove the queen and reset the markers
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    /*
        Function to solve the n-queens problem.

        Parameters:
        - n: The size of the chessboard (n x n).

        Returns:
        - A vector of vectors containing all valid board configurations, where each configuration
          is represented as a vector of strings, with 'Q' for a queen and '.' for an empty space.
    */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;  // To store all valid solutions

        // Create an empty chessboard filled with '.'
        vector<string> board(n);
        string s(n, '.');  // A string with n '.' characters
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        // Helper vectors to mark rows and diagonals as unsafe
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        // Start placing queens from the 0th column
        placeNQueens(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

        return ans;  // Return all valid solutions
    }
};

//{ Driver Code Starts.
int main() {
    int n;
    cin >> n;  // Input the size of the board

    Solution ob;
    vector<vector<string>> solutions = ob.solveNQueens(n);  // Get all valid n-queens solutions

    // Print all solutions
    for (auto& solution : solutions) {
        for (auto& row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
```

## Analysis

**Problem:** n-Queens Puzzle  
**Difficulty:** Hard

### Approach

1. **Backtracking**:
   - We try to place queens column by column.
   - For each column, we try placing the queen in all rows (0 to n-1) and check whether it's a valid placement using three conditions:
     - The current row must not have a queen (`leftRow`).
     - The upper diagonal (row - col) must not have a queen (`upperDiagonal`).
     - The lower diagonal (row + col) must not have a queen (`lowerDiagonal`).
   - If the placement is valid, we proceed to place the queen in the next column.
   - If the placement is invalid, we backtrack by removing the queen and resetting the markers.

2. **Efficiency**:
   - We use 3 auxiliary arrays (`leftRow`, `upperDiagonal`, and `lowerDiagonal`) to efficiently track whether a queen can be placed in a particular row or diagonal.

### Time Complexity

- The time complexity is O(N!), where N is the size of the board. This is because for each column, we try placing a queen in N rows, and each valid placement leads to recursive calls for the next column.

### Space Complexity

- The space complexity is O(N^2) to store the board and the result, plus O(3N) for the auxiliary arrays.

### Example

For `n = 4`, one of the solutions would be:

|N - Queens Chess Board for n = 4|
|----------------------|
|![N-Queens](./Recursion%20Codes/n_queens.jpg)|

[](./Recursion%20Codes/n_queens.jpg)

```cpp
. Q . .
. . . Q
Q . . .
. . Q .
```

This indicates the positions where the queens are placed on the 4x4 chessboard.
