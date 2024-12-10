# Minimum Platforms

## Table of Contents

- [Minimum Platforms](#minimum-platforms)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Key Points](#key-points)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps to Solve](#steps-to-solve)
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

The goal is to find the minimum number of platforms required at a railway station to accommodate all trains such that no train waits, given their arrival and departure times.

---

## Problem Description

You are given two arrays:

1. `arr[]`: Arrival times of trains.
2. `dep[]`: Departure times of trains.

Your task is to determine the minimum number of platforms required to ensure no train waits.

### Key Points

- Platforms are shared; one train can leave and another can arrive on the same platform.
- Additional platforms are required if a train arrives before another departs.

---

### Examples

#### Example 1

**Input**:  
`arr[] = [900, 940, 950, 1100, 1500, 1800]`  
`dep[] = [910, 1200, 1120, 1130, 1900, 2000]`  
**Output**:  
`3`  
**Explanation**: Between 9:40 and 12:00, three trains are present.

---

#### Example 2

**Input**:  
`arr[] = [900, 1235, 1100]`  
`dep[] = [1000, 1240, 1200]`  
**Output**:  
`1`  
**Explanation**: All train times are mutually exclusive, requiring only one platform.

---

#### Example 3

**Input**:  
`arr[] = [1000, 935, 1100]`  
`dep[] = [1200, 1240, 1130]`  
**Output**:  
`3`  
**Explanation**: All trains overlap between 11:00 and 11:30.

---

### Constraints

1. \( 1 \leq \text{number of trains} \leq 500000 \)
2. \( 0 \leq \text{arr[i]} \leq \text{dep[i]} \leq 2359 \)

---

## Approach

### Steps to Solve

1. **Sort the Arrays**:
   - Sort `arr[]` and `dep[]` independently.
2. **Use Two Pointers**:
   - Compare the earliest arrival and departure to decide if a new platform is required or if a platform can be freed.
3. **Count Platforms**:
   - Increment the count when a train arrives.
   - Decrement the count when a train departs.
   - Track the maximum count during this process.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Sort both arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0, count = 0, maxCount = 0, n = arr.size();

        // Use two pointers to simulate arrivals and departures
        while (i < n) {
            if (arr[i] <= dep[j]) {
                count++; // A new platform is needed
                i++;
            } else {
                count--; // A platform is freed
                j++;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read arrival times
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read departure times
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
        cout << "~\n";
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int findPlatform(int[] arr, int[] dep) {
        Arrays.sort(arr);
        Arrays.sort(dep);

        int n = arr.length;
        int i = 0, j = 0, count = 0, maxCount = 0;

        while (i < n) {
            if (arr[i] <= dep[j]) {
                count++; // Increment count for new platform
                i++;
            } else {
                count--; // Decrement count as a platform is freed
                j++;
            }
            maxCount = Math.max(maxCount, count);
        }

        return maxCount;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume newline character

        while (t-- > 0) {
            // Read arrival times
            String[] arrInput = sc.nextLine().split(" ");
            int[] arr = Arrays.stream(arrInput).mapToInt(Integer::parseInt).toArray();

            // Read departure times
            String[] depInput = sc.nextLine().split(" ");
            int[] dep = Arrays.stream(depInput).mapToInt(Integer::parseInt).toArray();

            Solution ob = new Solution();
            System.out.println(ob.findPlatform(arr, dep));
            System.out.println("~");
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Sorting**: \( O(n \log n) \)
- **Traversal**: \( O(n) \)

**Total**: \( O(n \log n) \)

### Space Complexity

- No extra space except input storage.

**Space**: \( O(1) \)

---

## How to Run the Code

### For C++

1. Save the code in a file named `main.cpp`.
2. Compile the code:

   ```bash
   g++ -o main main.cpp
   ```

3. Run the program:

   ```bash
   ./main
   ```

### For Java

1. Save the code in a file named `Solution.java`.
2. Compile the code:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
