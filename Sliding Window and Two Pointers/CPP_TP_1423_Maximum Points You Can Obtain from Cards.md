# Sliding Window and Two Pointers - 1423. Maximum Points You Can Obtain from Cards

## Problem Description

You are given an array `cardPoints` of integers representing points associated with cards arranged in a row. In each step, you can take one card from either the beginning or the end of the row. You must take exactly `k` cards. Your goal is to maximize the sum of the points of the cards you take.

### Example Scenarios

1. **Example 1**:

   - **Input**: `cardPoints = [1,2,3,4,5,6,1]`, `k = 3`
   - **Output**: `12`
   - **Explanation**: The optimal choice is to take the three cards from the rightmost end: `[6, 5, 1]`, giving a total score of `12`.

2. **Example 2**:

   - **Input**: `cardPoints = [2,2,2]`, `k = 2`
   - **Output**: `4`
   - **Explanation**: Regardless of which two cards are taken, the sum will always be `4`.

3. **Example 3**:
   - **Input**: `cardPoints = [9,7,7,9,7,7,9]`, `k = 7`
   - **Output**: `55`
   - **Explanation**: All cards must be taken as `k` equals the length of `cardPoints`.

### Constraints

- `1 <= cardPoints.length <= 10^5`
- `1 <= cardPoints[i] <= 10^4`
- `1 <= k <= cardPoints.length`

---

### Approach

The problem can be visualized as selecting `k` cards either from the left or the right end. To solve this, we:

1. **Calculate Initial Sum**: Compute the sum of the first `k` elements (left sum).
2. **Sliding Window**: Use a sliding window approach by shifting the window to include cards from the right while removing cards from the left.
   - For each shift, decrease the left sum by the element that is left out and increase it by the element that is included from the right.
   - Update the `maxSum` at each step with the maximum value of `leftSum + rightSum`.

This solution efficiently calculates the maximum possible sum by leveraging a sliding window technique and avoids checking every possible combination, reducing time complexity.

### Complexity Analysis

- **Time Complexity**: `O(k)`, since we compute the initial left sum and then adjust it `k` times using a sliding window approach.
- **Space Complexity**: `O(1)`, as we are using a few variables for sum calculations and do not require extra data structures.

---

### Code Implementation

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    /**
     * @brief Computes the maximum score by selecting exactly `k` cards from the beginning or end.
     *
     * @param cardPoints A vector of integers representing the points of each card.
     * @param k An integer representing the number of cards to select.
     * @return int The maximum score achievable by selecting exactly `k` cards.
     */
    int maxScore(vector<int>& cardPoints, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        // Calculate the initial sum of the first `k` cards (left side).
        int leftSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        // Initialize rightSum as zero, and maxSum with the initial leftSum.
        int rightSum = 0, maxSum = leftSum;
        int rightIndex = cardPoints.size() - 1;

        // Slide the window by reducing elements from the left and adding from the right.
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];        // Remove the last element of the left window.
            rightSum += cardPoints[rightIndex]; // Add a new element from the right.
            rightIndex -= 1;

            // Update the maxSum with the maximum of the current and previous sums.
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cardPoints(n);
        for (int i = 0; i < n; ++i) {
            cin >> cardPoints[i];
        }
        Solution ob;
        cout << ob.maxScore(cardPoints, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
```

---

### Explanation of the Code

1. **Initial Sum Calculation**:

   - We calculate the sum of the first `k` elements, representing the sum when all cards are taken from the beginning of the array.
   - This sum is stored in `leftSum`.

2. **Sliding Window Update**:

   - A sliding window is used to shift from taking cards from the left to taking them from the right.
   - We iterate from `k-1` down to `0`, each time:
     - Subtracting the leftmost card that goes out of the window.
     - Adding a card from the right end of the array.
     - Updating `maxSum` with the maximum of the current window sum and the previously recorded `maxSum`.

3. **Return the Result**:
   - After sliding through all possibilities, `maxSum` contains the maximum sum of `k` cards.

---

### Example Walkthrough

For `cardPoints = [1,2,3,4,5,6,1]` and `k = 3`:

1. Initial `leftSum` for the first three cards `[1,2,3]` is `6`.
2. Start sliding the window:
   - Remove `3` from `leftSum` and add `1` from the right, new sum is `1+6=7`.
   - Update `maxSum` to `12` when the next right element `5` is added.
3. The optimal selection is the rightmost three cards: `[5,6,1]`, resulting in a sum of `12`.

---

### Edge Cases

1. **k equals the length of the array**: The function should return the sum of the entire array since all cards must be taken.
2. **Single card selection (`k=1`)**: The function should correctly pick the card with the highest points.
3. **All elements are equal**: The function should correctly return `k * cardPoints[0]`.

---

### Conclusion

This problem demonstrates the effective use of the sliding window technique for solving a seemingly complex problem efficiently. By maintaining a window of elements and adjusting the sum dynamically, the solution optimizes the process of finding the maximum score when choosing cards from both ends.

## Other Methods

### Solution - 1

```cpp
class Solution
{
public:
  int maxScore(vector<int> &card, int k)
  {
    int n = card.size();
    int sum = 0;
    int i;
    for (i = n - k; i < n; i++)
      sum += card[i];

    int ans = sum;
    while (i < k + n)
    {
      sum += (card[i % n]);
      sum -= (card[(i - k)]);

      ans = max(ans, sum);
      i++;
    }
    return ans;
  }
};

#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  return ios_base::sync_with_stdio(false);
}();
```

### Solution - 2 (Using Prefix Sum Method)

```cpp
class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Msum = 0, n = cardPoints.size();
    int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
    Msum = sum;
    for (int i = 0; i < k; i++)
    {
      int csum = sum - cardPoints[k - i - 1] + cardPoints[n - i - 1];
      sum = csum;
      Msum = max(Msum, csum);
    }
    return Msum;
  }
};
```

### Solution - 3 (Using Prefix Sum Method)

```cpp
#pragma GCC optimize("O3")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
#pragma GCC optimize("Ofast")
class Solution
{
    public:
    int maxScore(vector<int>& cardPoints, int k)
    {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
     int n=cardPoints.size();
     int leftsum=0;
     int rightsum=0;
     for(int i=0;i<k;i++)
     {
        leftsum=leftsum+cardPoints[i];
     }
     int maxsum=leftsum;
     for(int i=0;i<k;i++)
     {
        leftsum=leftsum-cardPoints[k-i-1];
        rightsum=rightsum+cardPoints[n-i-1];
        maxsum=max(maxsum ,rightsum+leftsum);
     }
     return maxsum;
    }
};
```
