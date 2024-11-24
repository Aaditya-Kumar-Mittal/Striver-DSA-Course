# Validate BST Inorder Traversal

## Table of Contents

- [Validate BST Inorder Traversal](#validate-bst-inorder-traversal)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The task is to verify if a given array represents the **inorder traversal** of a valid Binary Search Tree (BST). In a valid BST:

- The inorder traversal must be in **strictly increasing order**.
- All elements in the array are unique.

---

## Problem Description

### Examples

**Example 1:**  
**Input:**  
`arr[] = [8, 14, 45, 64, 100]`  
**Output:**  
`True`  
**Explanation:** The array is strictly increasing.

---

**Example 2:**  
**Input:**  
`arr[] = [5, 6, 1, 8, 7]`  
**Output:**  
`False`  
**Explanation:** The array is not strictly increasing (e.g., `6 > 1`).

---

### Constraints

- \(1 \leq n \leq 10^5\)
- \(1 \leq arr[i] \leq 10^9\)

---

## Approach

- Traverse the array to check if it is **strictly increasing**:
  - Compare each element with its previous element.
  - If any element is less than or equal to the previous one, return `false`.
- Return `true` if the entire array satisfies the condition.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBSTTraversal(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        cout << (res ? "True" : "False") << "\n";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public boolean isBSTTraversal(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = sc.nextInt();
            }

            Solution sol = new Solution();
            boolean res = sol.isBSTTraversal(nums);
            System.out.println(res ? "True" : "False");
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\) — Traverse the array once to check the condition.

- **Space Complexity:**  
  \(O(1)\) — No additional space is used.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `ValidateInorder.cpp`.
2. Compile the file:

   ```bash
   g++ -o ValidateInorder ValidateInorder.cpp
   ```

3. Run the executable:

   ```bash
   ./ValidateInorder
   ```

### For Java

1. Save the code in a file, e.g., `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
