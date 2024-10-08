# Celebrity Problem

## Problem Description

In this problem, we need to identify if there is a celebrity at a party. A **celebrity** is a person who:

- **Is known by everyone** but **does not know** anyone else at the party.

The input is represented as a square matrix `mat` of size `n x n` where:

- `mat[i][j] = 1` indicates that the `i-th` person knows the `j-th` person.
- `mat[i][j] = 0` indicates that the `i-th` person does not know the `j-th` person.

### Problem Statement

Write a function that finds the celebrity in the given matrix. If there is a celebrity, return their index (0-based). If no celebrity exists, return `-1`.

### Constraints

- `1 <= mat.size() <= 300`
- `0 <= mat[i][j] <= 1`

---

## Examples

### Example 1

- **Input**:

  ```plaintext
  mat = [
    [0 1 0],
    [0 0 0],
    [0 1 0]
  ]
  ```

- **Output**: `1`
- **Explanation**:
  - Person `0` knows `1` but `1` does not know `0`.
  - Person `2` knows `1` but `1` does not know `2`.
  - Person `1` is known by `0` and `2` but does not know anyone, making them a celebrity.

### Example 2

- **Input**:

  ```plaintext
  mat = [
    [0 1],
    [1 0]
  ]
  ```

- **Output**: `-1`
- **Explanation**:
  - Person `0` knows `1` and `1` knows `0`.
  - Neither of them qualifies as a celebrity because they know each other.

---

## Approach

### Approach 1: Naive Approach (Using Counting Arrays)

1. **Count the number of people each person knows** (`countWhoIKnow`) and the number of people who know each person (`countWhoKnowsMe`).
2. Iterate through the matrix and update the counters for each pair `mat[i][j]`.
3. After populating the counters, find a person `i` such that:
   - `countWhoKnowsMe[i] == n - 1` (everyone knows `i`).
   - `countWhoIKnow[i] == 0` (`i` does not know anyone).
4. If such a person is found, return their index; otherwise, return `-1`.

#### Code Implementation - 1

```cpp
class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> countWhoKnowsMe(n, 0), countWhoIKnow(n, 0);

        // Count how many people each person knows and how many people know them.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    countWhoKnowsMe[j]++;
                    countWhoIKnow[i]++;
                }
            }
        }

        // Check for a potential celebrity.
        for(int i = 0; i < n; i++) {
            if(countWhoKnowsMe[i] == n - 1 && countWhoIKnow[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
```

#### Time Complexity Implementation - 1

- **Time**: `O(n^2)` because of the nested loop that checks the relations between each pair of people.
- **Space**: `O(n)` for the two counting arrays.

#### Drawbacks

- This approach is simple to implement but not efficient in terms of time complexity due to the `O(n^2)` operations. It does not meet the problem's constraints for larger values of `n`.

---

### Approach 2: Optimized Approach (Using Two Pointers)

1. Use two pointers `top` and `down`:
   - Initialize `top` to `0` and `down` to `n-1`.
2. **Identify a Potential Celebrity**:
   - If `mat[top][down] == 1`, it means `top` knows `down`, so `top` cannot be a celebrity. Move `top` up.
   - If `mat[down][top] == 1`, it means `down` knows `top`, so `down` cannot be a celebrity. Move `down` down.
   - Continue this until `top` and `down` converge.
3. **Verify the Potential Celebrity**:
   - Once `top` and `down` converge, verify if the remaining person is a true celebrity:
     - Ensure they do not know anyone.
     - Ensure everyone knows them.
   - If they pass both conditions, return the index. Otherwise, return `-1`.

#### Code Implementation - 2

```cpp
class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        // Step 1: Find the potential celebrity.
        while (top < down) {
            if (mat[top][down] == 1) {
                top++;
            } else {
                down--;
            }
        }

        // Step 2: Verify the potential celebrity.
        int potentialCeleb = top;
        for (int i = 0; i < n; i++) {
            if (i != potentialCeleb &&
                (mat[potentialCeleb][i] == 1 || mat[i][potentialCeleb] == 0)) {
                return -1;
            }
        }

        return potentialCeleb;
    }
};
```

```cpp
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {

        int n = mat.size();

        vector<int> countWhoKnowsMe(n , 0), countWhoIKnow(n , 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(mat[i][j] == 1)
                {
                    countWhoKnowsMe[j]++;
                    countWhoIKnow[i]++;
                }
            }
        }

        for(int i = 0 ; i < n; i++)
        {
            if(countWhoKnowsMe[i] == n-1 && countWhoIKnow[i] == 0)
            {
                return i;
            }
        }

        return -1;


        int size = mat.size();

        int top = 0, down = size - 1;

        while(top < down)
        {
            if(mat[top][down] == 1)
            {
                top = top + 1;
            }
            else if(mat[down][top] == 1){
                down = down - 1;
            }
            else{
                top++;
                down--;
            }
        }

        if(top > down) return -1;

        for(int i = 0; i < size ; i++)
        {
            if(i == top) continue;

            if(mat[top][i] == 0 && mat[i][top] == 1)
            {
                continue;
            }
            else{
                return -1;
            }
        }

        return top;
    }
};
```

#### Time Complexity of Implementation - 2

- **Time**: `O(n)` for identifying a potential celebrity + `O(n)` for verifying = `O(n)`.
- **Space**: `O(1)` as no additional data structures are used.

#### Explanation

- The two-pointer approach first narrows down a potential candidate for being a celebrity.
- It then verifies if that candidate truly fulfills the conditions of a celebrity.

#### Advantages

- This approach is optimal and meets the problem's constraints for larger input sizes.
- It reduces the problem from `O(n^2)` complexity to `O(n)`.

---

## Summary

- **Approach 1 (Naive)**: Uses two counting arrays to identify the celebrity. Time complexity is `O(n^2)`.
- **Approach 2 (Optimized)**: Uses a two-pointer approach to efficiently identify and verify a potential celebrity. Time complexity is `O(n)`.
- **Preferred Approach**: The two-pointer method is more efficient and should be used for larger inputs.

---

## How to Use

1. **Input**: Provide the `n x n` matrix `mat` representing who knows whom.
2. **Output**: The function will return the index of the celebrity if one exists; otherwise, it will return `-1`.
3. **Edge Cases**: Handle matrices of size `1x1` and cases where everyone knows each other or no one knows anyone.

---

## References

- Problem Link: [GFG - The Celebrity Problem](https://www.geeksforgeeks.org/the-celebrity-problem/)
- Concepts Used: Matrix traversal, two-pointer technique, space optimization.

---

### Approach - 3 (using Stack)

```cpp
// C++ program to find celebrity using
// stack data structure
#include <bits/stdc++.h>
using namespace std;

// knows function check if a knows b
bool knows(int a, int b, vector<vector<int> >& matrix)
{
    return matrix[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int> >& matrix)
{

    stack<int> s;
    // Celebrity
    int C;

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2

    // Find a potential celebrity
    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B, matrix)) {
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C)
            && (knows(C, i, matrix)
                || !knows(i, C, matrix)))
            return -1;
    }

    return C;
}

// Driver code
int main()
{
    int n = 4;
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };

    int id = findCelebrity(n, matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;
    return 0;
}
```
