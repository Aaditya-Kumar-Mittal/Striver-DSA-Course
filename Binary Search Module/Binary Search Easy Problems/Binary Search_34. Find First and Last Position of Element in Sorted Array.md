# Find First and Last Position of Element in Sorted Array

## Table of Contents

- [Find First and Last Position of Element in Sorted Array](#find-first-and-last-position-of-element-in-sorted-array)
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
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Other Solutions](#other-solutions)
      - [1. Linear Search (Brute Force)](#1-linear-search-brute-force)
      - [2. Binary Search (Two Separate Searches)](#2-binary-search-two-separate-searches)
      - [3. Modified Binary Search (Optimized)](#3-modified-binary-search-optimized)
      - [4. Two-Pointer Approach](#4-two-pointer-approach)

---

## Introduction

This document provides a detailed explanation and implementation of the problem **"Find First and Last Position of Element in Sorted Array"** using binary search. The task is to locate the start and end indices of a given target value in a sorted array, ensuring a time complexity of `O(log n)`.

---

## Problem Description

You are given an array of integers `nums` sorted in non-decreasing order. Your task is to find the starting and ending position of a given `target` value.

If the target is **not present**, return `[-1, -1]`.

You **must** implement a solution with **O(log n)** runtime complexity.

### Examples

#### Example 1

```plaintext
Input:  nums = [5,7,7,8,8,10], target = 8
Output: [3, 4]
```

#### Example 2

```plaintext
Input:  nums = [5,7,7,8,8,10], target = 6
Output: [-1, -1]
```

#### Example 3

```plaintext
Input:  nums = [], target = 0
Output: [-1, -1]
```

---

### Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is a non-decreasing array.
- `-10^9 <= target <= 10^9`

---

## Approach

The solution requires two binary searches:

1. **First Binary Search:** To find the **first occurrence** of the target value.
2. **Second Binary Search:** To find the **last occurrence** of the target value.

Both searches modify the search range based on comparison with the target and update the respective indices when the target is found.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int first = -1, last = -1;

        // First binary search to find the first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // continue to search on left side
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Reset boundaries for second search
        low = 0;
        high = n - 1;

        // Second binary search to find the last occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // continue to search on right side
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(log n)`  
  Each binary search runs in logarithmic time, making the overall time complexity `O(log n)`.

- **Space Complexity:** `O(1)`  
  The algorithm uses constant extra space for tracking indices and loop variables.

---

## How to Run the Code

### For C++

1. Save the code in a file named `search_range.cpp`.
2. Compile the code using a C++ compiler:

   ```bash
   g++ search_range.cpp -o search_range
   ```

3. Create a `main()` function to test the implementation:

   ```cpp
   int main() {
       Solution sol;
       vector<int> nums = {5, 7, 7, 8, 8, 10};
       int target = 8;
       vector<int> result = sol.searchRange(nums, target);
       cout << "[" << result[0] << ", " << result[1] << "]" << endl;
       return 0;
   }
   ```

4. Run the program:

   ```bash
   ./search_range
   ```

Expected Output:

```bash
[3, 4]
```

### Other Solutions

In addition to the optimal binary search approach, several alternative methods exist to solve the "Find First and Last Position of Element in Sorted Array" problem. Each comes with its own trade-offs in terms of time and space complexity. Below are the detailed explanations and implementations of the most common strategies:

#### 1. Linear Search (Brute Force)

**Approach:**

- Initialize two variables, `first` and `last`, to `-1`.
- Iterate through the array:
  - Set `first` when the target is first encountered.
  - Continue traversing and update `last` for every matching occurrence.
- Return `[first, last]`.

**Complexity:**

- ⏱️ **Time:** `O(n)` — Scans the entire array.
- 🚀 **Space:** `O(1)` — No additional space used.

**C++ Implementation:**

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return {first, last};
    }
};
```

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = -1, last = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return new int[]{first, last};
    }
}
```

---

#### 2. Binary Search (Two Separate Searches)

**Approach:**

- Use binary search twice:
  - First to find the leftmost (first) index.
  - Second to find the rightmost (last) index.

**Complexity:**

- ⏱️ **Time:** `O(log n)` — Two binary searches.
- 🚀 **Space:** `O(1)` — Constant space usage.

**Python Implementation:**

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findFirst(nums, target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    if mid == 0 or nums[mid - 1] != target:
                        return mid
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1

        def findLast(nums, target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    if mid == len(nums) - 1 or nums[mid + 1] != target:
                        return mid
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1

        return [findFirst(nums, target), findLast(nums, target)]
```

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return new int[]{first, last};
    }

    private int findFirst(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    first = mid;
                    break;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }

    private int findLast(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == nums.length - 1 || nums[mid + 1] != target) {
                    last = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last;
    }
}
```

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    first = mid;
                    break;
                }
                else {
                    right = mid - 1;
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    last = mid;
                    break;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return last;
    }
};
```

---

#### 3. Modified Binary Search (Optimized)

**Approach:**

- Integrate `first` and `last` index tracking directly into each binary search.
- On encountering the target:
  - Continue to search left to find the first occurrence.
  - Similarly, search right to find the last occurrence.

**Complexity:**

- ⏱️ **Time:** `O(log n)` — Two modified binary searches.
- 🚀 **Space:** `O(1)` — Constant space usage.

**Python Implementation:**

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findFirst(nums, target):
            left, right = 0, len(nums) - 1
            first = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    first = mid
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return first

        def findLast(nums, target):
            left, right = 0, len(nums) - 1
            last = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    last = mid
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return last

        return [findFirst(nums, target), findLast(nums, target)]
```

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return new int[]{first, last};
    }

    private int findFirst(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }

    private int findLast(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last;
    }
}
```

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return last;
    }
};
```

---

#### 4. Two-Pointer Approach

**Approach:**

- Initialize two pointers: `left` and `right`.
- Use a `while` loop with binary logic and additional linear scanning for borders.
- Once the target is found:
  - Move leftward to find the first index.
  - Move rightward to find the last index.

**Complexity:**

- ⏱️ **Time:** `O(n)` — Additional traversal after binary match.
- 🚀 **Space:** `O(1)` — No extra space needed.

**Python Implementation:**

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums) - 1
        first, last = -1, -1

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                first = mid
                last = mid
                while first > 0 and nums[first - 1] == target:
                    first -= 1
                while last < len(nums) - 1 and nums[last + 1] == target:
                    last += 1
                return [first, last]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return [first, last]
```

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int first = -1, last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                last = mid;
                while (first > 0 && nums[first - 1] == target) {
                    first--;
                }
                while (last < nums.length - 1 && nums[last + 1] == target) {
                    last++;
                }
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return new int[]{first, last};
    }
}
```

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1, last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                last = mid;
                while (first > 0 && nums[first - 1] == target) {
                    first--;
                }
                while (last < nums.size() - 1 && nums[last + 1] == target) {
                    last++;
                }
                break;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return {first, last};
    }
};
```

---

These solutions offer varied performance based on the context of use. For small arrays, linear and two-pointer methods may suffice. For large datasets, binary search–based methods are significantly more efficient.
