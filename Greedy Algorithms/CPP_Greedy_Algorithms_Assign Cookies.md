# Greedy Problem: Assign Cookies (Leetcode 455)

## Problem Statement

Given two arrays:

- `g`: Represents the greed factor of each child, where `g[i]` is the minimum cookie size required to satisfy child `i`.
- `s`: Represents the sizes of cookies, where each `s[j]` is the size of cookie `j`.

You are a parent with a set of cookies, and each child can receive at most one cookie. To make a child content, the size of the cookie given must be greater than or equal to their greed factor. Your task is to maximize the number of content children and return this number.

### Examples

**Example 1:**

- **Input:** `g = [1,2,3]`, `s = [1,1]`
- **Output:** `1`
- **Explanation:** The greed factors of the children are 1, 2, and 3, but with only two cookies of size 1, only one child (with greed 1) can be content.

**Example 2:**

- **Input:** `g = [1,2]`, `s = [1,2,3]`
- **Output:** `2`
- **Explanation:** Both children can be content, as the cookies can meet both their requirements.

### Constraints

- \( 1 \leq g.length \leq 3 \times 10^4 \)
- \( 0 \leq s.length \leq 3 \times 10^4 \)
- \( 1 \leq g[i], s[j] \leq 2^{31} - 1 \)

#### Approach

1. **Sorting Arrays**: Sort both arrays, `g` (greed factors) and `s` (cookie sizes), in ascending order. This allows us to pair the smallest available cookie with each child's minimum requirement efficiently.
2. **Two-Pointer Method**: Use two pointers:
   - `left` for tracking the smallest unassigned cookie.
   - `right` for tracking the next unsatisfied child.
3. **Greedy Matching**: If the current cookie (`s[left]`) satisfies the current child's greed factor (`g[right]`), mark the child as content by incrementing `right`. Always increment `left` after each check to move to the next cookie.
4. **Result**: After iterating through, `right` holds the number of content children.

### Code with Detailed Comments

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the maximum number of children that can be content with given cookies.
     *
     * @param g Vector of integers representing children's greed factors.
     * @param s Vector of integers representing sizes of cookies.
     * @return int The maximum number of content children.
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        // Sort both arrays to allow pairing from smallest greed factor to smallest cookie size
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0;
        int gn = g.size();
        int sn = s.size();

        // Iterate through cookies and greed factors to maximize the number of content children
        while (left < sn && right < gn) {
            // If the current cookie can satisfy the current child
            if (g[right] <= s[left]) {
                right++; // Move to the next child
            }
            left++; // Move to the next cookie
        }

        return right; // Number of content children
    }
};

/**
 * Problem: Assign Cookies (Leetcode 455)
 *
 * Analysis:
 * - Given two arrays:
 *   - `g`: Greed factors for children, where `g[i]` is the minimum cookie size required to satisfy child `i`.
 *   - `s`: Sizes of cookies, where each `s[j]` represents the size of cookie `j`.
 * - Goal: Maximize the number of content children by giving each child at most one cookie.
 * - Solution uses a two-pointer approach on sorted arrays to match the smallest available cookie to each child's greed factor.
 *
 * Time Complexity: O(n log n + m log m)
 * - Sorting `g` and `s` takes O(n log n) and O(m log m) respectively, where n and m are the sizes of `g` and `s`.
 * - The main loop iterates through the sorted arrays, which is O(n + m).
 * - Overall complexity is dominated by sorting, hence O(n log n + m log m).
 *
 * Space Complexity: O(1)
 * - Sorting is done in place, and only constant space is used for pointer tracking.
 *
 * Edge Cases:
 * - `s` is empty: If there are no cookies, the function returns 0 immediately.
 * - `g` has larger values than any element in `s`: No child will be satisfied, and the function returns 0.
 * - Sufficient cookies to meet all children's requirements: The function will return the number of children (`g.size()`).
 */
```

---

### Explanation of Code

- **Sorting Step**: Enables a greedy approach, pairing the smallest cookie that can satisfy each child's minimum greed factor.
- **Two-Pointer Loop**: Traverses through cookies and children greed factors in a single pass, ensuring efficiency.
- **Return Value**: The pointer `right` reflects the number of satisfied children as it only increments when a child is content.

### Complexity Analysis

- **Time Complexity**: \( O(n \log n + m \log m) \)
  - Sorting both arrays dominates the complexity.
- **Space Complexity**: \( O(1) \)
  - Uses constant space for pointers and in-place operations on `g` and `s`.

### Edge Cases

1. If `s` is empty, the function immediately returns 0 as no children can be content.
2. If greed factors are all larger than cookie sizes, none of the children can be satisfied.
3. When all cookies are sufficient for all children, it outputs `g.size()`.

## Other Solution

### Solution - 1

```cpp
class Solution
{ // 7 mins
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int content = 0, j = 0, M = s.size();
    for (int i = 0; i < g.size(); i++)
    {
      while (j < M && g[i] > s[j])
        j++;
      if (j >= M)
        break;
      content++;
      j++;
    }
    return content;
  }
};
```
