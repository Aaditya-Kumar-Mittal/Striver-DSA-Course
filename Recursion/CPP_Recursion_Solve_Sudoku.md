# Recursion Problem - Sudoku Solver

## Problem Statement

Solve a given Sudoku puzzle by filling empty cells (denoted by '.') with numbers from '1' to '9'. The placement of numbers must satisfy the following conditions:

- Each number must appear exactly once in each row.
- Each number must appear exactly once in each column.
- Each number must appear exactly once in each 3x3 sub-grid.

## Code Implementation

```cpp
class Solution {
public:
    /**
     * Function to solve the Sudoku puzzle.
     * This function initiates the backtracking algorithm to solve the board.
     *
     * @param board A 2D vector representing the Sudoku board with empty cells denoted by '.'
     */
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);  // Start solving the board
    }

    /**
     * Recursive helper function to solve the Sudoku puzzle using backtracking.
     *
     * @param board A reference to the 2D vector representing the Sudoku board.
     * @return A boolean indicating whether the Sudoku board is solvable from the current state.
     */
    bool sudoku(vector<vector<char>>& board) {
        // Traverse each cell in the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                // If the cell is empty (denoted by '.'), attempt to fill it
                if (board[i][j] == '.') {

                    // Try placing digits from '1' to '9' in the empty cell
                    for (char c = '1'; c <= '9'; c++) {

                        // Check if placing digit 'c' in the current cell (i, j) is valid
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;  // Place digit 'c' in the cell

                            // Recursively try to solve the rest of the board
                            if (sudoku(board) == true)
                                return true;  // Return true if the board is solved

                            // If placing 'c' results in a dead-end, undo the placement (backtrack)
                            board[i][j] = '.';
                        }
                    }

                    // If no valid digit can be placed in the current cell, return false (backtrack)
                    return false;
                }
            }
        }

        // If all cells are filled correctly, return true
        return true;
    }

    /**
     * Helper function to check if placing a digit 'c' in the position (row, col) is valid.
     * A placement is valid if:
     * - The digit 'c' does not already exist in the current row.
     * - The digit 'c' does not already exist in the current column.
     * - The digit 'c' does not already exist in the 3x3 sub-grid that contains the position (row, col).
     *
     * @param board A reference to the 2D vector representing the Sudoku board.
     * @param row The row index of the cell being checked.
     * @param col The column index of the cell being checked.
     * @param c The digit (as a character) to be placed in the cell.
     * @return A boolean indicating whether the placement of 'c' in the cell is valid.
     */
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Check the row, column, and 3x3 sub-grid for validity
        for (int i = 0; i < 9; i++) {
            // Check if 'c' is already in the current row
            if (board[row][i] == c)
                return false;

            // Check if 'c' is already in the current column
            if (board[i][col] == c)
                return false;

            // Check if 'c' is already in the current 3x3 sub-grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }

        // If no conflicts are found, the placement is valid
        return true;
    }
};
```

## Algorithm Analysis

### Time Complexity

- **Worst Case Time Complexity**:  
  In the worst case, we may need to try all 9 possible digits in each of the 81 empty cells, leading to a time complexity of approximately `O(9^81)`. This is an extremely large number, but the actual time is often significantly reduced by early exits through backtracking and pruning.

### Space Complexity

- **Space Complexity**
  The algorithm operates in-place on the input `board` and does not use any additional data structures apart from the recursion stack. The maximum depth of the recursion stack is `O(81)` (one call per cell). Hence, the overall space complexity is `O(1)` if the input space is excluded and `O(81)` if recursion space is counted.

## Approach

### 1. **Backtracking Approach**

- The solution uses a backtracking approach where we attempt to place a digit in each empty cell.
- After placing a digit, we recursively attempt to solve the rest of the board.
- If the placement leads to a valid solution, the board is solved.
- If the placement leads to an invalid state, we backtrack by removing the digit and trying the next possible digit.

### 2. **Validity Check**

- For each placement of a digit, we check whether:
- The digit does not already exist in the same row.
- The digit does not already exist in the same column.
- The digit does not already exist in the 3x3 sub-grid that contains the cell.

### 3. **Recursive Search and Pruning**

- The recursion explores the board cell by cell, attempting to solve each empty cell.
- Backtracking ensures that when a solution path leads to an invalid state, the algorithm retraces its steps, undoing previous moves, and tries a different path.
- This pruning helps reduce the time complexity from `O(9^81)` in practice.

## Conclusion

The backtracking algorithm efficiently solves the Sudoku puzzle by trying possible numbers in each empty cell while ensuring validity through row, column, and sub-grid checks. Though the worst-case time complexity is exponential, practical instances of Sudoku are often solved much faster due to early exits from backtracking. This solution effectively demonstrates the power of recursive search combined with constraint validation.
