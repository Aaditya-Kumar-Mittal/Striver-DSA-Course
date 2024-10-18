# Minimum Cost of Ropes

## Table of Contents

- [Minimum Cost of Ropes](#minimum-cost-of-ropes)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Input/Output](#inputoutput)
    - [Constraints](#constraints)
    - [Expected Complexity](#expected-complexity)
  - [Solution Overview](#solution-overview)
    - [Approach](#approach)
    - [Why Min-Heap?](#why-min-heap)
  - [Code Explanation](#code-explanation)
    - [Explanation](#explanation)
  - [Example](#example)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Usage](#usage)
    - [Output](#output)
  - [Time and Space Complexity](#time-and-space-complexity)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Problem Description

**Problem**: Given an array `arr` containing the lengths of different ropes, the task is to connect the ropes into one rope. The cost to connect two ropes is equal to the sum of their lengths. We need to minimize this cost.

### Input/Output

- **Input**:
  - `arr`: A vector of `n` integers, where each integer represents the length of a rope.
- **Output**: An integer representing the minimum cost to connect all the ropes into one rope.

### Constraints

- `1 ≤ arr.size() ≤ 2 * 10^5`
- `1 ≤ arr[i] ≤ 10^6`

### Expected Complexity

- **Time Complexity**: `O(n log n)`
- **Auxiliary Space**: `O(n)`

---

## Solution Overview

### Approach

1. **Using a Min-Heap**:
   - Use a min-heap (priority queue) to keep track of the smallest ropes.
   - Insert all rope lengths into the min-heap.
   - While there is more than one rope in the heap:
     - Extract the two smallest ropes.
     - Add their lengths (which is the cost of connecting them) to the total cost.
     - Insert the combined rope length back into the min-heap.
   - Repeat this until only one rope remains in the heap.
   - The total cost represents the minimum cost of connecting all ropes.

### Why Min-Heap?

- By always combining the smallest ropes, we minimize the cost at each step, ensuring an overall minimum cost for the entire process.

---

## Code Explanation

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief A class to find the minimum cost to connect ropes.
 */
class Solution {
public:
    /**
     * @brief Function to return the minimum cost of connecting the ropes.
     * @param arr A vector of long long integers representing lengths of the ropes.
     * @return A long long integer representing the minimum cost to connect all ropes.
     */
    long long minCost(vector<long long>& arr) {
        // Create a min-heap (priority queue) to store the lengths of ropes.
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());

        long long cost = 0;  // Variable to store the total cost.

        // While more than one rope is left, continue combining ropes.
        while (pq.size() > 1) {
            // Extract the two smallest ropes from the heap.
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            // Calculate the cost to combine these ropes.
            cost += (a + b);

            // Push the combined rope back into the heap.
            pq.push(a + b);
        }

        // Return the total cost to connect all ropes.
        return cost;
    }
};

int main() {
    long long t;  // Number of test cases.
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        // Read input as a line and parse it into a vector of integers.
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        // Create an instance of Solution and call minCost function.
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}
```

### Explanation

1. **Min-Heap Initialization**:
   - A min-heap (`priority_queue`) is used to store the lengths of ropes in ascending order.
2. **Extract and Combine**:
   - While more than one rope remains in the heap:
     - Extract the two shortest ropes.
     - Add their lengths to `cost` (which represents the cost of combining them).
     - Push the combined rope length back into the heap.
3. **Return Total Cost**:
   - Once only one rope remains, return the accumulated `cost`.

---

## Example

### Example 1

**Input**:

- `arr[] = [4, 3, 2, 6]`

**Output**: `29`

**Explanation**:

- Combine `2` and `3` → New array: `[4, 5, 6]` → Cost = `5`
- Combine `4` and `5` → New array: `[6, 9]` → Cost = `9`
- Combine `6` and `9` → New array: `[15]` → Cost = `15`
- Total cost: `5 + 9 + 15 = 29`.

### Example 2

**Input**:

- `arr[] = [4, 2, 7, 6, 9]`

**Output**: `62`

**Explanation**:

- Combine `2` and `4` → New array: `[6, 7, 6, 9]` → Cost = `6`
- Combine `6` and `6` → New array: `[12, 7, 9]` → Cost = `12`
- Combine `7` and `9` → New array: `[12, 16]` → Cost = `16`
- Combine `12` and `16` → New array: `[28]` → Cost = `28`
- Total cost: `6 + 12 + 16 + 28 = 62`.

---

## Usage

```cpp
int main() {
    vector<long long> arr = {4, 3, 2, 6};
    Solution sol;

    long long result = sol.minCost(arr);
    cout << "Minimum cost to connect ropes: " << result << endl;

    return 0;
}
```

### Output

```bash
Minimum cost to connect ropes: 29
```

---

## Time and Space Complexity

### Time Complexity

- **Building the Min-Heap**: `O(n)` where `n` is the number of elements in `arr`.
- **Combining Ropes**: Each extraction and insertion in the heap takes `O(log n)`, and we perform this `n-1` times.
- **Overall Complexity**: `O(n log n)`.

### Space Complexity

- **Min-Heap Storage**: `O(n)` to store the ropes.
- **Auxiliary Space**: `O(1)` if excluding input storage.
