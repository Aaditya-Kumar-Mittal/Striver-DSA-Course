# Minimum Multiplications to Reach End

## Table of Contents

- [Minimum Multiplications to Reach End](#minimum-multiplications-to-reach-end)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

This problem involves finding the minimum number of steps required to transform a starting number into an ending number by repeatedly multiplying by any number from a given array and taking the result modulo \(100000\). If it is impossible to reach the target number, return \(-1\).

---

## Problem Description

### Input

- **`arr`**: Array of integers, where each element is a multiplier.
- **`start`**: The starting number.
- **`end`**: The target number.

### Output

- An integer denoting the minimum steps required to reach `end` starting from `start` using the given operations, or \(-1\) if it is not possible.

---

## Examples

### Example 1

**Input:**

```plaintext
arr = [2, 5, 7]
start = 3
end = 30
```

**Output:**

```plaintext
2
```

**Explanation:**

1. Multiply \(3 \times 2 = 6\), modulo \(100000\) gives \(6\).
2. Multiply \(6 \times 5 = 30\), modulo \(100000\) gives \(30\).

### Example 2

**Input:**

```plaintext
arr = [3, 4, 65]
start = 7
end = 66175
```

**Output:**

```plaintext
4
```

**Explanation:**

1. Multiply \(7 \times 3 = 21\), modulo \(100000\) gives \(21\).
2. Multiply \(21 \times 3 = 63\), modulo \(100000\) gives \(63\).
3. Multiply \(63 \times 65 = 4095\), modulo \(100000\) gives \(4095\).
4. Multiply \(4095 \times 65 = 266175\), modulo \(100000\) gives \(66175\).

---

## Constraints

- \(1 \leq n \leq 10^4\)
- \(1 \leq \text{arr}[i] \leq 10^4\)
- \(1 \leq \text{start}, \text{end} < 10^5\)

---

## Approach

### Breadth-First Search (BFS)

This problem can be solved using **Breadth-First Search (BFS)** as it ensures the shortest path in an unweighted graph:

1. Treat each number as a node in a graph.
2. Multiply the current number by each element in `arr` to generate the next states.
3. Use a **distance array** to store the minimum steps required to reach each number modulo \(100000\).
4. If `end` is reached during BFS, return the current number of steps.
5. If BFS completes without finding `end`, return \(-1\).

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 100000; // Modulo value as per problem statement
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Special case: If start is equal to end
        if (start == end) return 0;

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({start, 0}); // {current number, steps taken}

        // Distance array to track minimum steps to each node
        vector<int> distance(mod, INT_MAX);
        distance[start] = 0;

        // BFS traversal
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto multiplier : arr) {
                int nextNode = (node * multiplier) % mod;

                // If we found a shorter path to `nextNode`
                if (steps + 1 < distance[nextNode]) {
                    distance[nextNode] = steps + 1;

                    // If the target is reached
                    if (nextNode == end) return steps + 1;

                    q.push({nextNode, steps + 1});
                }
            }
        }

        // If end is unreachable
        return -1;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    int mod = 100000; // Modulo value as per problem statement

    public int minimumMultiplications(int[] arr, int start, int end) {
        // Special case: If start is equal to end
        if (start == end) return 0;

        // Queue for BFS
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{start, 0}); // {current number, steps taken}

        // Distance array to track minimum steps to each node
        int[] distance = new int[mod];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[start] = 0;

        // BFS traversal
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int node = current[0];
            int steps = current[1];

            for (int multiplier : arr) {
                int nextNode = (node * multiplier) % mod;

                // If we found a shorter path to `nextNode`
                if (steps + 1 < distance[nextNode]) {
                    distance[nextNode] = steps + 1;

                    // If the target is reached
                    if (nextNode == end) return steps + 1;

                    q.add(new int[]{nextNode, steps + 1});
                }
            }
        }

        // If end is unreachable
        return -1;
    }
}

// Driver Code
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            int start = sc.nextInt();
            int end = sc.nextInt();
            Solution obj = new Solution();
            System.out.println(obj.minimumMultiplications(arr, start, end));
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Traversal:** \(O(10^5)\), as BFS explores each possible number modulo \(100000\) at most once.
- **Array Traversal:** Each node processes \(n\) multipliers from the array.
- **Total:** \(O(n \cdot 10^5)\).

### Space Complexity

- **Queue:** \(O(10^5)\), as at most \(100000\) numbers can be in the queue.
- **Distance Array:** \(O(10^5)\).
- **Total:** \(O(10^5)\).

---

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file.
2. Compile using `g++ filename.cpp`.
3. Run the executable and provide input.

### For Java

1. Copy the code into a `.java` file.
2. Compile using `javac filename.java`.
3. Run the program using `java filename`.
