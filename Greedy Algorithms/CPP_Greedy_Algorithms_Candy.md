# 135. Candy

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [135. Candy](#135-candy)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Greedy Approach with Two Passes](#greedy-approach-with-two-passes)
    - [Greedy Peak and Valley Approach](#greedy-peak-and-valley-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementations](#c-implementations)
      - [Two Pass Solution](#two-pass-solution)
      - [Peak and Valley Solution](#peak-and-valley-solution)
    - [Java Implementations](#java-implementations)
      - [Two Pass Solution (Java)](#two-pass-solution-java)
      - [Peak and Valley Solution (Java)](#peak-and-valley-solution-java)
  - [Complexity Analysis](#complexity-analysis)
    - [Two Pass Solution](#two-pass-solution-1)
      - [Time Complexity](#time-complexity)
      - [Space Complexity](#space-complexity)
    - [Peak and Valley Solution](#peak-and-valley-solution-1)
      - [Time Complexity](#time-complexity-1)
      - [Space Complexity](#space-complexity-1)

---

## Introduction

This problem focuses on distributing candies among children based on their ratings with specific rules:

1. Each child must get at least one candy.
2. Children with higher ratings than their neighbors should get more candies.

The goal is to calculate the minimum candies required.

---

## Problem Description

### Examples

#### Example 1

**Input**:  
`ratings = [1,0,2]`  
**Output**:  
`5`  
**Explanation**:  
Candies distributed: `[2, 1, 2]`.

#### Example 2

**Input**:  
`ratings = [1,2,2]`  
**Output**:  
`4`  
**Explanation**:  
Candies distributed: `[1, 2, 1]`.

---

### Constraints

- \( n == \text{ratings.length} \)
- \( 1 \leq n \leq 2 \times 10^4 \)
- \( 0 \leq \text{ratings[i]} \leq 2 \times 10^4 \)

---

## Approach

### Greedy Approach with Two Passes

This approach uses two passes to compute the candy distribution:

1. **Left-to-right pass**: Ensures children with higher ratings than their left neighbors get more candies.
2. **Right-to-left pass**: Ensures children with higher ratings than their right neighbors get more candies.

### Greedy Peak and Valley Approach

This approach uses local peaks and valleys:

1. Traverse the array and count candies for increasing sequences.
2. Traverse for decreasing sequences, updating candies, and handle overlapping peaks.

---

## Detailed Explanation of Code

### C++ Implementations

#### Two Pass Solution

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);

        // Left-to-right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Right-to-left pass
        int right = 1, sum = left[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            sum += max(left[i], right);
        }

        return sum;
    }
};
```

#### Peak and Valley Solution

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, i = 1, n = ratings.size();

        while (i < n) {
            // Case of equal ratings
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            // Handle increasing sequence
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            // Handle decreasing sequence
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }

            // Adjust peak if valley count exceeds it
            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};
```

---

### Java Implementations

#### Two Pass Solution (Java)

```java
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] left = new int[n];
        Arrays.fill(left, 1);

        // Left-to-right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Right-to-left pass
        int right = 1, sum = left[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            sum += Math.max(left[i], right);
        }

        return sum;
    }
}
```

#### Peak and Valley Solution (Java)

```java
class Solution {
    public int candy(int[] ratings) {
        int sum = 1, i = 1, n = ratings.length;

        while (i < n) {
            // Case of equal ratings
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            // Handle increasing sequence
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            // Handle decreasing sequence
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }

            // Adjust peak if valley count exceeds it
            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
}
```

---

## Complexity Analysis

### Two Pass Solution

#### Time Complexity

- \( O(n) \): Two linear passes are required.

#### Space Complexity

- \( O(n) \): For the `left` array.

### Peak and Valley Solution

#### Time Complexity

- \( O(n) \): Single linear traversal of the array.

#### Space Complexity

- \( O(1) \): No extra space beyond a few variables.
