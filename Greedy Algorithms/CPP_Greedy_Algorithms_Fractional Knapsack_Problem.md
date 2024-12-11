# Fractional Knapsack

## Table of Contents

- [Fractional Knapsack](#fractional-knapsack)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Introduction

The Fractional Knapsack problem is a classic greedy algorithm problem where you are tasked with maximizing the total value of items placed in a knapsack, allowing items to be split into fractions.

---

## Problem Description

Given arrays `val[]` (values of items) and `wt[]` (weights of items), along with a maximum knapsack capacity `capacity`, the objective is to maximize the total value in the knapsack. Items can be taken fully or partially based on their value-to-weight ratio.

---

### Examples

#### Example 1

**Input**:  
`val[] = [60, 100, 120]`, `wt[] = [10, 20, 30]`, `capacity = 50`  
**Output**:  
`240.000000`  
**Explanation**:

- Take items with value 60 (weight 10) and 100 (weight 20) fully.
- Take \( \frac{120}{30} \times 20 = 80 \).  
  Total value = \( 60 + 100 + 80 = 240 \).

#### Example 2

**Input**:  
`val[] = [60, 100]`, `wt[] = [10, 20]`, `capacity = 50`  
**Output**:  
`160.000000`  
**Explanation**:  
Take all items completely. Total value = \( 60 + 100 = 160 \).

#### Example 3

**Input**:  
`val[] = [10, 20, 30]`, `wt[] = [5, 10, 15]`, `capacity = 100`  
**Output**:  
`60.000000`  
**Explanation**:  
All items fit completely into the knapsack. Total value = \( 10 + 20 + 30 = 60 \).

---

### Constraints

- \( 1 \leq \text{val.size} = \text{wt.size} \leq 10^5 \)
- \( 1 \leq \text{capacity} \leq 10^9 \)
- \( 1 \leq \text{val[i]}, \text{wt[i]} \leq 10^4 \)

---

## Approach

1. **Sort Items by Value-to-Weight Ratio**:

   - Compute the ratio \( \text{val[i]} / \text{wt[i]} \) for each item.
   - Sort items in descending order of this ratio.

2. **Greedily Fill Knapsack**:

   - Add items to the knapsack until it reaches its capacity.
   - If an item cannot fit completely, add the fraction that fits.

3. **Stop When Capacity is Full**:
   - Exit the loop when the knapsack is full.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

class Solution {
public:
    // Comparator function to sort items by value-to-weight ratio
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);

        // Create an array of items
        for (int i = 0; i < n; i++) {
            items[i].value = val[i];
            items[i].weight = wt[i];
        }

        // Sort items by value-to-weight ratio
        sort(items.begin(), items.end(), comp);

        double totalValue = 0.0;
        int currentWeight = 0;

        for (int i = 0; i < n; i++) {
            if (currentWeight + items[i].weight <= capacity) {
                currentWeight += items[i].weight;
                totalValue += items[i].value;
            } else {
                int remaining = capacity - currentWeight;
                totalValue += (double)items[i].value / (double)items[i].weight * remaining;
                break;
            }
        }

        return totalValue;
    }
};

// Driver Code
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution obj;
    cout << fixed << setprecision(6) << obj.fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Item {
    int value, weight;

    Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }
}

class Solution {
    // Comparator function to sort items by value-to-weight ratio
    static Comparator<Item> comp = (a, b) -> Double.compare(
        (double)b.value / b.weight, (double)a.value / a.weight
    );

    public double fractionalKnapsack(int[] val, int[] wt, int capacity) {
        int n = val.length;
        Item[] items = new Item[n];

        // Create an array of items
        for (int i = 0; i < n; i++) {
            items[i] = new Item(val[i], wt[i]);
        }

        // Sort items by value-to-weight ratio
        Arrays.sort(items, comp);

        double totalValue = 0.0;
        int currentWeight = 0;

        for (Item item : items) {
            if (currentWeight + item.weight <= capacity) {
                currentWeight += item.weight;
                totalValue += item.value;
            } else {
                int remaining = capacity - currentWeight;
                totalValue += (double)item.value / item.weight * remaining;
                break;
            }
        }

        return totalValue;
    }

    // Driver Code
    public static void main(String[] args) {
        int[] val = {60, 100, 120};
        int[] wt = {10, 20, 30};
        int capacity = 50;

        Solution obj = new Solution();
        System.out.printf("%.6f\n", obj.fractionalKnapsack(val, wt, capacity));
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Sorting**: \( O(n \log n) \) for sorting items by value-to-weight ratio.
- **Traversal**: \( O(n) \) for iterating through items.
- **Total**: \( O(n \log n) \).

### Space Complexity

- **C++**: \( O(n) \) for the `items` array.
- **Java**: \( O(n) \) for the `items` array.
