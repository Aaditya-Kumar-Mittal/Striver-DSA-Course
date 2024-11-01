# Hand of Straights

## Problem Description

Alice has a set of cards with numbers written on them, represented by an integer array `hand`. Alice wants to rearrange these cards into groups of consecutive cards, where each group has a fixed size `groupSize`.

The rules are:

1. Each group must contain exactly `groupSize` consecutive cards.
2. Each group must be formed from unique values without missing elements.

If Alice can arrange her cards into such groups, return `true`; otherwise, return `false`.

### Example

1. **Input**: `hand = [1, 2, 3, 6, 2, 3, 4, 7, 8]`, `groupSize = 3`

   - **Output**: `true`
   - **Explanation**: Alice can form the groups `[1,2,3]`, `[2,3,4]`, and `[6,7,8]`.

2. **Input**: `hand = [1, 2, 3, 4, 5]`, `groupSize = 4`
   - **Output**: `false`
   - **Explanation**: Alice cannot rearrange her cards into groups of size `4` with consecutive values.

### Constraints

- \( 1 \leq \text{hand.length} \leq 10^4 \)
- \( 0 \leq \text{hand}[i] \leq 10^9 \)
- \( 1 \leq \text{groupSize} \leq \text{hand.length} \)

## Solution Approach

To solve this problem, we can use a frequency count and a priority queue (min-heap) to ensure that we can process each group starting from the smallest card value.

### Solution Steps

1. **Input Size Check**: If the size of `hand` is not divisible by `groupSize`, we can immediately return `false` as it’s impossible to form groups of equal size.
2. **Frequency Map**: Create an unordered map `count` to store the frequency of each card value.

3. **Priority Queue**: Insert each unique card value into a priority queue (`min-heap`) to process values in ascending order.

4. **Form Groups**:

   - For each smallest element in the heap (which represents the start of a group), attempt to form a consecutive sequence of `groupSize` elements by checking and decrementing the count of each consecutive card.
   - If any card in the sequence is missing (count of the card is zero), return `false`.
   - If a card's count reduces to zero after being used, remove it from the heap.

5. **Return Result**: If all elements can be grouped successfully, return `true`; otherwise, return `false`.

### Code Implementation

```cpp
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        // Frequency map to count occurrences of each card
        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Min-heap to store unique card values in ascending order
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto& [card, _] : count) {
            pq.push(card);
        }

        // Try to form consecutive groups
        while (!pq.empty()) {
            int start = pq.top();  // Start of the current group
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;  // Consecutive card in the group

                // If the card is missing from the count map, return false
                if (count[card] == 0)
                    return false;

                // Decrement the count of the current card
                count[card]--;

                // If count of this card becomes zero, remove it from the min-heap
                if (count[card] == 0 && pq.top() == card) {
                    pq.pop();
                }
            }
        }
        return true;
    }
};
```

### Inline Optimization

The following lines are added for I/O optimization:

```cpp
inline const auto optimize = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
```

This disables synchronization between C and C++ I/O streams, improving execution speed for competitive programming.

### Explanation of Code Components

1. **Frequency Map**: The `count` map is initialized to store the number of times each card appears in `hand`. This helps in quickly checking the availability of a card while forming groups.
2. **Priority Queue**: The priority queue `pq` (min-heap) ensures that we process the smallest available card first, which is essential to form consecutive groups starting from the smallest elements.

3. **Group Formation Logic**: For each smallest element in `pq`, we attempt to form a group of size `groupSize`. If any card needed for a consecutive group is missing (count is zero), we return `false`. Cards are removed from the priority queue only when their count reaches zero to maintain proper order in the heap.

### Complexity Analysis

- **Time Complexity**: \(O(N \log N)\), where \(N\) is the number of cards in `hand`.
  - Sorting elements in ascending order using a priority queue takes \(O(N \log N)\).
  - Processing each card once to form groups takes \(O(N)\).
- **Space Complexity**: \(O(N)\) for the frequency map and priority queue to store the unique elements of `hand`.

### Edge Cases

1. **Single Element Group**: If `groupSize` is 1, we only need to check that all cards in `hand` have non-zero frequency.
2. **Invalid Group Size**: If `hand.size()` is not divisible by `groupSize`, return `false` immediately.
3. **Non-Consecutive Elements**: If there are gaps between values in `hand` such that consecutive groups cannot be formed, the function should return `false`.

## Conclusion

This solution efficiently checks if `hand` can be rearranged into consecutive groups of size `groupSize` using a combination of a frequency map and a min-heap, ensuring that the elements are processed in ascending order. The approach is optimal in terms of both time and space complexity for the given problem constraints.

## Other Solutions

### Solution - 1

```cpp
class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();
    sort(hand.begin(), hand.end());
    vector<bool> v(n, false);
    int count = 0, groups = 0, i = 0, j = 0, prev;
    bool start = true;

    while (i < n && j < n)
    {
      if (start && i < n)
      {
        if (v[i] == false)
        {
          count++;
          prev = hand[i];
          start = false;
          v[i] = true;
        }
        if (count == groupSize)
        {
          groups++;
          start = true;
          count = 0;
        }
        i++;
      }
      else if (!start && j < n)
      {
        if (hand[j] - prev == 1 && v[j] == false)
        {
          count++;
          prev = hand[j];
          v[j] = true;
        }
        if (count == groupSize)
        {
          groups++;
          start = true;
          count = 0;
          j = i;
        }
        j++;
      }
    }
    if ((count == 0) || (groupSize == 1 && count == 1))
    {
      return true;
    }
    return false;
  }
};
```

### Solution - 2

```cpp
class Solution
{
public:
  bool findSuccessors(vector<int> &hand, int groupSize, int i, int n)
  {
    int next = hand[i] + 1;
    hand[i] = -1; // Mark as used
    int count = 1;
    i += 1;
    while (i < n && count < groupSize)
    {
      if (hand[i] == next)
      {
        next = hand[i] + 1;
        hand[i] = -1;
        count++;
      }
      i++;
    }
    return count == groupSize;
  }

  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();
    if (n % groupSize != 0)
      return false;
    std::sort(hand.begin(), hand.end());
    for (int i = 0; i < n; i++)
    {
      if (hand[i] >= 0)
      {
        if (!findSuccessors(hand, groupSize, i, n))
          return false;
      }
    }
    return true;
  }
};
```
