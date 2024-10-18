# Top K Frequent Elements

## Table of Contents

- [Top K Frequent Elements](#top-k-frequent-elements)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Input/Output](#inputoutput)
    - [Constraints](#constraints)
    - [Follow-Up](#follow-up)
  - [Solution Overview](#solution-overview)
    - [Approach](#approach)
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
  - [Other Soltions](#other-soltions)
    - [Solution - 1](#solution---1)

---

## Problem Description

**Problem**: Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. The order of the returned elements does not matter.

### Input/Output

- **Input**:
  - `nums`: A vector of integers.
  - `k`: An integer representing the number of most frequent elements to return.
- **Output**: A vector of integers containing `k` most frequent elements from `nums`.

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, the number of unique elements in the array]`.
- The answer is guaranteed to be unique.

### Follow-Up

Your algorithm's time complexity must be better than `O(n log n)`, where `n` is the array's size.

---

## Solution Overview

### Approach

1. **Using a Min-Heap (Priority Queue)**:
   - Use a hash map (`unordered_map`) to store the frequency of each element in the array.
   - Use a min-heap (priority queue) to keep track of the `k` most frequent elements.
   - For each element in the frequency map:
     - Push a pair of the frequency and the element into the min-heap.
     - If the size of the heap exceeds `k`, pop the least frequent element.
   - After processing all elements, the heap will contain the `k` most frequent elements.
   - Extract these elements from the heap to form the final result.

---

## Code Explanation

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

#define pii pair<int, int>  // Defines a pair with first as frequency and second as the element.

/**
 * @class Solution
 * @brief A class to find the top K frequent elements from an array.
 */
class Solution {
public:
    /**
     * @brief Finds the top K frequent elements from the given array.
     * @param nums The input array of integers.
     * @param k The number of most frequent elements to return.
     * @return A vector of integers containing the K most frequent elements.
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;  // Stores the frequency of each element.

        // Count the frequency of each element.
        for (auto x : nums) {
            mpp[x]++;
        }

        // Min-heap to store pairs of frequency and element.
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // Iterate through the frequency map and maintain a heap of size k.
        for (auto x : mpp) {
            pq.push({x.second, x.first});  // Push frequency as the first element for comparison.
            if (pq.size() > k) {
                pq.pop();  // Pop the least frequent element if size exceeds k.
            }
        }

        vector<int> ans;  // Stores the result.

        // Extract elements from the heap.
        while (!pq.empty()) {
            pii temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);  // Add the element (second of the pair) to the result.
        }

        return ans;
    }
};
```

### Explanation

1. **Frequency Count**:
   - `unordered_map<int, int> mpp` is used to count the frequency of each element in `nums`.
2. **Min-Heap**:
   - A priority queue `pq` is used as a min-heap to store pairs of frequency and element.
   - The min-heap helps maintain the `k` elements with the highest frequencies.
3. **Heap Maintenance**:
   - Iterate through the map and push each element's frequency and value into the heap.
   - If the size of the heap exceeds `k`, pop the element with the lowest frequency.
4. **Result Extraction**:
   - After all elements are processed, extract the elements from the heap to get the `k` most frequent elements.

---

## Example

### Example 1

**Input**:

- `nums = [1, 1, 1, 2, 2, 3]`
- `k = 2`

**Output**: `[1, 2]`

**Explanation**:

- Element `1` appears `3` times, and element `2` appears `2` times.
- The `2` most frequent elements are `1` and `2`.

### Example 2

**Input**:

- `nums = [1]`
- `k = 1`

**Output**: `[1]`

**Explanation**:

- The only element `1` is the most frequent with `1` occurrence.

---

## Usage

```cpp
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### Output

```bash
Top 2 frequent elements: 1 2
```

---

## Time and Space Complexity

### Time Complexity

- **Building Frequency Map**: `O(n)`, where `n` is the size of the input array `nums`.
- **Building Min-Heap**: `O(m log k)`, where `m` is the number of unique elements in `nums` and `k` is the size of the heap.
- **Extracting Results**: `O(k log k)` for retrieving elements from the heap.
- **Overall Complexity**: `O(n + m log k)`, which is more efficient than `O(n log n)` for large inputs when `k` is much smaller than `n`.

### Space Complexity

- **Frequency Map**: `O(m)`, where `m` is the number of unique elements in `nums`.
- **Min-Heap**: `O(k)` to store the `k` most frequent elements.
- **Overall Space Complexity**: `O(m + k)`.

## Other Soltions

### Solution - 1

```cpp
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int &num : nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1);
        for(auto &it : mp){
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
       }
       vector<int> result;
       for(int i = n; i>=0; i--){
        if(bucket[i].size() == 0)
            continue;
        while(bucket[i].size() > 0 && k > 0){
            result.push_back(bucket[i].back());
            bucket[i].pop_back();
            k--;
        }
       }
       return result;
    }
};
```
