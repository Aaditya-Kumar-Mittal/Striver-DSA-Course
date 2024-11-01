# Maximum Sum Combination

## Problem Statement

Given two integer arrays, `A` and `B`, each of size `N`, this program finds the `K` largest valid sum combinations. A "sum combination" is created by adding one element from array `A` and another element from array `B`.

The output must be a list of the maximum `K` distinct sum combinations, sorted in non-increasing order.

### Example

#### Example 1

**Input:**

```bash
N = 2, K = 2
A = [3, 2]
B = [1, 4]
```

**Output:**

```bash
[7, 6]
```

**Explanation:**

- 7 = (A: 3) + (B: 4)
- 6 = (A: 2) + (B: 4)

#### Example 2

**Input:**

```bash
N = 4, K = 3
A = [1, 4, 2, 3]
B = [2, 5, 1, 6]
```

**Output:**

```bash
[10, 9, 9]
```

**Explanation:**

- 10 = (A: 4) + (B: 6)
- 9 = (A: 4) + (B: 5)
- 9 = (A: 3) + (B: 6)

## Constraints

- \(1 \leq N \leq 10^5\)
- \(1 \leq K \leq N\)
- \(1 \leq A[i], B[i] \leq 10^4\)

## Approach

### Steps

1. **Sort Arrays in Descending Order:**  
   First, sort both arrays `A` and `B` in descending order. This allows us to start generating the largest possible sums from the beginning of each array.

2. **Use a Max Heap to Track Largest Sums:**  
   We use a max heap (priority queue) to keep track of the largest sum combinations. Each entry in the heap contains:

   - The sum of elements from `A` and `B`
   - A pair of indices that generated this sum

3. **Track Visited Index Pairs:**  
   Use a `set` to track pairs of indices from arrays `A` and `B` that have been pushed to the heap to prevent duplicates.

4. **Generate the Top K Sums:**  
   Repeatedly extract the largest sum from the heap and add it to the results list `ans` until we have `K` sums. For each extracted pair of indices:
   - Push the next possible combination involving `A[x+1]` and `B[y]` (if `x + 1 < N`) and check if it hasn't been added yet.
   - Push the next possible combination involving `A[x]` and `B[y+1]` (if `y + 1 < N`) and check if it hasn't been added yet.

### Code Explanation

Here is the implementation in C++:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Sort both arrays in descending order to start with largest sums
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        vector<int> ans;                  // Stores the largest K sums
        set<pair<int, int>> hashSet;      // Tracks visited index pairs
        priority_queue<pair<int, pair<int, int>>> maxHeap; // Max-heap for largest sums

        // Start with the largest possible sum (A[0] + B[0])
        maxHeap.push({A[0] + B[0], {0, 0}});
        hashSet.insert({0, 0}); // Mark initial index pair as visited

        // Extract the top K sums
        for (int i = 0; i < K; i++) {
            if (maxHeap.empty()) break;

            // Extract the maximum sum and its corresponding indices
            pair<int, pair<int, int>> p = maxHeap.top();
            maxHeap.pop();

            ans.push_back(p.first); // Add the sum to result

            int x = p.second.first;
            int y = p.second.second;

            // Insert the next pair from A (x+1) and current y in B, if valid and unvisited
            if (x + 1 < N && hashSet.find({x + 1, y}) == hashSet.end()) {
                maxHeap.push({A[x + 1] + B[y], {x + 1, y}});
                hashSet.insert({x + 1, y});
            }

            // Insert the next pair from B (y+1) and current x in A, if valid and unvisited
            if (y + 1 < N && hashSet.find({x, y + 1}) == hashSet.end()) {
                maxHeap.push({A[x] + B[y + 1], {x, y + 1}});
                hashSet.insert({x, y + 1});
            }
        }

        return ans; // Return the list of largest K sums
    }
};

// Main function for testing
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }

        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
```

### Complexity Analysis

- **Time Complexity**: \(O(N \log N)\), due to sorting both arrays and managing heap operations.
- **Space Complexity**: \(O(K + N)\), where `K` is the number of required top sums and `N` is the size of the `hashSet`.

## Edge Cases

1. **K > N**: If `K` exceeds `N`, the function will handle only the possible `N` pairs.
2. **Duplicate Elements in A or B**: The code ensures that only unique pairs are pushed to the max heap using `hashSet`.
3. **Minimum Array Size**: The code works effectively even for the smallest array sizes (e.g., `N = 1`).

## Conclusion

This approach leverages sorting and a max heap to efficiently obtain the top `K` largest sum combinations. Using a `set` to prevent duplicate index pairs ensures that each combination is unique and valid, meeting the requirements for optimal performance and correctness.

## Other Solutions

### Solution - 1

```cpp
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
  int n = A.size();
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  priority_queue<pair<int, pair<int, int>>> pq;
  set<pair<int, int>> st;
  pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
  st.insert({n - 1, n - 1});
  vector<int> ans;
  while (K--)
  {
    auto curr = pq.top();
    ans.push_back(curr.first);
    pq.pop();
    int i = curr.second.first;
    int j = curr.second.second;
    if (i - 1 >= 0 && st.find({i - 1, j}) == st.end())
    {
      pq.push({A[i - 1] + B[j], {i - 1, j}});
      st.insert({i - 1, j});
    }
    if (j - 1 >= 0 && st.find({i, j - 1}) == st.end())
    {
      pq.push({A[i] + B[j - 1], {i, j - 1}});
      st.insert({i, j - 1});
    }
  }
  return ans;
}
```
