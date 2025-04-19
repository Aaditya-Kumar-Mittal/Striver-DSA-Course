# 1331 - Rank Transform of an Array

## Problem Description

Given an array of integers `arr`, we need to replace each element with its **rank** based on its value. The rank is assigned according to the following rules:

1. Rank is an integer starting from 1.
2. The larger the element, the larger the rank.
3. If two elements are equal, their rank must be the same.
4. The rank must be as small as possible.

### Example 1

- **Input:** `arr = [40, 10, 20, 30]`
- **Output:** `[4, 1, 2, 3]`
- **Explanation:**
  - 40 is the largest element, so its rank is 4.
  - 10 is the smallest element, so its rank is 1.
  - 20 is the second smallest, so its rank is 2.
  - 30 is the third smallest, so its rank is 3.

### Example 2

- **Input:** `arr = [100, 100, 100]`
- **Output:** `[1, 1, 1]`
- **Explanation:** Since all the elements are the same, they share the same rank of 1.

### Example 3

- **Input:** `arr = [37, 12, 28, 9, 100, 56, 80, 5, 12]`
- **Output:** `[5, 3, 4, 2, 8, 6, 7, 1, 3]`
- **Explanation:** The rank of the elements is based on their sorted order.

## Constraints

- `0 <= arr.length <= 10^5`
- `-10^9 <= arr[i] <= 10^9`

---

## Approach

The solution can be broken down into the following steps:

1. **Sort and Rank:**

   - Create a sorted copy of the input array.
   - Traverse the sorted array and assign ranks to each unique element.
   - Store the ranks in a hash map (`unordered_map`) to ensure that equal elements get the same rank.

2. **Result Array:**

   - Using the original array, we can replace each element with its corresponding rank from the hash map.

3. **Complexity Consideration:**
   - Sorting the array takes `O(n log n)` time.
   - Storing and retrieving ranks from the hash map takes `O(1)` on average, making the overall time complexity `O(n log n)`.

---

## Code Implementation with Detailed Comments

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Transforms the input array by replacing each element with its rank.
     *
     * The rank is determined by sorting the elements of the array in increasing order.
     * Larger elements get higher ranks, starting from 1. Equal elements share the same rank.
     *
     * @param arr A reference to the input vector of integers.
     * @return A vector of integers where each element is replaced by its rank.
     */
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Create a sorted copy of the array to determine the ranks
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Step 2: Create a map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        int rank = 1;

        // Step 3: Assign ranks to each element in the sorted array
        for (int i = 0; i < n; i++) {
            // If the element hasn't been assigned a rank yet, assign the current rank
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank;
                rank++;
            }
        }

        // Step 4: Create the result array where each element is replaced by its rank
        vector<int> rankArr(n);
        for (int i = 0; i < n; i++) {
            rankArr[i] = rankMap[arr[i]];
        }

        return rankArr;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {40, 10, 20, 30};
    vector<int> result1 = sol.arrayRankTransform(arr1);
    // Expected output: [4, 1, 2, 3]
    for (int x : result1) {
        cout << x << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {100, 100, 100};
    vector<int> result2 = sol.arrayRankTransform(arr2);
    // Expected output: [1, 1, 1]
    for (int x : result2) {
        cout << x << " ";
    }
    cout << endl;

    // Test Case 3
    vector<int> arr3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> result3 = sol.arrayRankTransform(arr3);
    // Expected output: [5, 3, 4, 2, 8, 6, 7, 1, 3]
    for (int x : result3) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

---

## Analysis

### Time Complexity

- **Sorting:** Sorting the array takes `O(n log n)`, where `n` is the number of elements in the array.
- **Rank Assignment:** Traversing the sorted array and assigning ranks takes `O(n)`.
- **Result Construction:** Constructing the result array also takes `O(n)`.

Thus, the overall time complexity is **O(n log n)** due to the sorting step.

### Space Complexity

- **Rank Map:** We use an unordered map to store the ranks of each unique element, which requires `O(n)` space.
- **Sorted Array:** A copy of the input array is made and sorted, which also requires `O(n)` space.

Hence, the overall space complexity is **O(n)**.

---

## Additional Information

- **Edge Case Handling:**
  - If the input array has all the same elements, they will all receive the same rank.
  - If the array is empty (`arr.length == 0`), the result will also be an empty array.
- **Optimality:** This approach is optimal as sorting the array is necessary to determine the correct rank for each element. The use of an unordered map ensures that equal elements are given the same rank in constant time.

---

## Conclusion

This solution efficiently transforms an array by assigning ranks based on the sorted order of its elements. It handles duplicates gracefully and ensures the ranks are as small as possible. The implementation is optimal in terms of time and space complexity for the given problem constraints.

---

## Other Methods

### Using Pairs

```cpp
class Solution {
public:
    using int2=pair<int, int>;
    static vector<int> arrayRankTransform(vector<int>& arr) {
        const int n=arr.size();
        vector<int2> arrIdx(n);
        for(int i=0; int x: arr){
            arrIdx[i]={x, i};
            i++;
        }
        sort(arrIdx.begin(), arrIdx.end());
        vector<int> ans(n);
        int prev=INT_MIN, curr=0;
        for(auto& [x, i]: arrIdx){
            if (x>prev) curr++;
            ans[i]=curr;
            prev=x;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
```

### Using Radix Sort - 18ms Beats 100%

```cpp
class Solution {
public:
    using int2 = pair<int, int>;
    vector<int2> bucket[64];
    void radix_sort(vector<int2>& nums, int xmin, int xmax) {
        unsigned xrange = xmax - xmin + 1;
        int round = max(1, int(32 - countl_zero(xrange) + 5) / 6);

        // 0th round
        for (auto& [x, idx] : nums) {
            x -= xmin; // Adjust x by xmin
            bucket[x & 63].emplace_back(x+=(round==1)?xmin:0, idx);
        }

        int i = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] = v;
            B.clear(); // Clear bucket after usage
        }
        //    print(nums);

        // Rounds from 1st to (round-2)th round
        for (int rd = 1; rd < round - 1; rd++) {
            int shift =
                rd * 6; // Bit shifting to extract the next set of 6 bits
            for (auto& [x, idx] : nums)
                bucket[(x >> shift) & 63].emplace_back(x, idx);

            i = 0;
            for (auto& B : bucket) {
                for (auto& v : B)
                    nums[i++] = v;
                B.clear(); // Clear bucket after usage
            }
            //    print(nums);
        }

        // Last round
        if (round > 1) {
            int shift = 6 * (round - 1); // Bit shifting for the last round
            for (auto& [x, idx] : nums)
                bucket[x >> shift].emplace_back(x, idx);

            i = 0;
            for (auto& B : bucket) {
                for (auto& [x, idx] : B)
                    nums[i++] = {x + xmin, idx}; // Adjust x back by adding xmin
                B.clear();                       // Clear bucket after usage
            }
            //    print(nums);
        }
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();
        // Initialize arrIdx with values and original indices
        if (n==0) return {};

        vector<int2> arrIdx(n);
        for (int i = 0; i < n; i++)
            arrIdx[i] = {arr[i], i}; // Store value and original index

        // Find the minimum and maximum
        auto [xmin, xmax] = minmax_element(arr.begin(), arr.end());
        radix_sort(arrIdx, int(*xmin), int(*xmax)); // Perform radix sort

        // Rank transformation with handling duplicates
        vector<int> ans(n);
        int prev = INT_MIN, curr = 0;
        for (auto& [x, i] : arrIdx) {
            if (x > prev)
                curr++;
            ans[i] = curr;
            prev = x;
        }
        return ans;
    }
};
```
