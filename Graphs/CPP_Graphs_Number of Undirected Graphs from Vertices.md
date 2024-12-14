# Number of Undirected Graphs from Vertices

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Number of Undirected Graphs from Vertices](#number-of-undirected-graphs-from-vertices)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Approach](#approach)
    - [Mathematical Explanation](#mathematical-explanation)
    - [Recursive Approach](#recursive-approach)
    - [Direct Formula-Based Approach](#direct-formula-based-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Recursive Solution](#recursive-solution)
      - [Formula-Based Solution](#formula-based-solution)
    - [Java Implementation](#java-implementation)
      - [Formula-Based Solution](#formula-based-solution-1)
  - [Complexity Analysis](#complexity-analysis)
    - [Recursive Approach](#recursive-approach-1)
    - [Formula-Based Approach](#formula-based-approach)
  - [Key Insights](#key-insights)

---

## Introduction

This problem involves finding the total number of **undirected graphs** (not necessarily connected) that can be formed using `n` vertices. The task is to compute this count efficiently.

---

## Problem Description

### Input

- A single integer `n` representing the number of vertices.

### Output

- The total number of undirected graphs possible with `n` vertices.

---

## Examples

### Example 1

**Input:**

```bash
n = 2
```

**Output:**

```bash
2
```

**Explanation:**  
With 2 vertices, there are only 2 possible graphs:

1. No edge between the two vertices.
2. A single edge between the two vertices.

---

### Example 2

**Input:**

```bash
n = 5
```

**Output:**

```bash
1024
```

**Explanation:**  
With 5 vertices, the total number of edges possible is **\( \binom{5}{2} = 10 \)**.  
Thus, the total number of graphs is **\( 2^{10} = 1024 \)**.

---

## Approach

### Mathematical Explanation

In an undirected graph:

1. **Number of possible edges** between `n` vertices is **\( \frac{n \times (n-1)}{2} \)**, as each pair of vertices can have at most one edge.
2. For each possible edge, there are 2 options: either the edge exists or it does not.  
   This gives **\( 2^{\text{number of possible edges}} \)**.

Thus, the total number of undirected graphs with `n` vertices is:
**\[
\text{Total graphs} = 2^{\frac{n \times (n-1)}{2}}
\]**

---

### Recursive Approach

The problem can also be solved recursively:

1. For the **\( n \)-th vertex**, it has the option to connect or not connect to each of the **\( (n-1) \) vertices**.  
   This results in **\( 2^{n-1} \)** possibilities.
2. Multiply this with the number of graphs that can be formed with \( (n-1) \) vertices.

Recursive formula:
**\[
\text{count}(n) = 2^{(n-1)} \times \text{count}(n-1)
\]**

Base cases:

- \( \text{count}(0) = 1 \)
- \( \text{count}(1) = 1 \)

---

### Direct Formula-Based Approach

Using the mathematical explanation, the formula to compute the count is:
**\[
\text{count}(n) = 2^{\frac{n \times (n-1)}{2}}
\]**

This approach avoids recursion and computes the result in \( O(1) \) time.

---

## Detailed Explanation of Code

### C++ Implementation

#### Recursive Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long count(int n) {
        // Base case
        if (n <= 2) {
            return n;
        }

        // Recursive step
        return (1LL << (n - 1)) * count(n - 1);
    }
};

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n; // Number of vertices
        cin >> n;

        Solution ob;
        cout << ob.count(n) << endl;
    }
    return 0;
}
```

#### Formula-Based Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long count(int n) {
        // Using the formula: 2^((n * (n-1)) / 2)
        long long edges = (n * (n - 1)) / 2;
        return pow(2, edges);
    }
};

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n; // Number of vertices
        cin >> n;

        Solution ob;
        cout << ob.count(n) << endl;
    }
    return 0;
}
```

---

### Java Implementation

#### Formula-Based Solution

```java
import java.util.Scanner;

class Solution {
    public long count(int n) {
        // Using the formula: 2^((n * (n-1)) / 2)
        long edges = (n * (n - 1)) / 2;
        return (long) Math.pow(2, edges);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases

        while (t-- > 0) {
            int n = sc.nextInt(); // Number of vertices

            Solution ob = new Solution();
            System.out.println(ob.count(n));
        }

        sc.close();
    }
}
```

---

## Complexity Analysis

### Recursive Approach

- **Time Complexity:** \( O(n) \), due to recursive calls for \( n \) levels.
- **Space Complexity:** \( O(n) \), for recursion stack.

### Formula-Based Approach

- **Time Complexity:** \( O(1) \), as the formula is computed in constant time.
- **Space Complexity:** \( O(1) \).

---

## Key Insights

1. The formula-based approach is optimal for this problem as it avoids recursion overhead.
2. Recursive solutions provide a step-by-step breakdown but are less efficient for larger values of \( n \).
3. This problem highlights the exponential growth of graph combinations as the number of vertices increases.
