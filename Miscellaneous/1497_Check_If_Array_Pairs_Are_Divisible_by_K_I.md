# Problem : Check If Array Pairs Are Divisible by k

Given an array of integers `arr` of even length `n` and an integer `k`, the task is to divide the array into exactly `n / 2` pairs such that the sum of each pair is divisible by `k`. The function should return `true` if such a division is possible, otherwise `false`.

## Approach

- **Step 1:** Check if the array has an odd number of elements. If so, return `false` because it's impossible to form pairs.
- **Step 2:** Create a frequency array to store the remainder counts when each element is divided by `k`.

- **Step 3:** Count the remainders:

  - For each element in the array, calculate its remainder when divided by `k`.
  - Adjust negative remainders to fit within the range `[0, k-1]`.

- **Step 4:** Check for valid pairs:
  - For remainder `0`, the frequency must be even (because elements with remainder `0` can only pair with each other).
  - For each remainder `i`, the frequency of remainder `i` should match the frequency of remainder `k - i`, ensuring valid pairs.

### Complexity

- **Time Complexity:** `O(n)` where `n` is the length of the array. We iterate through the array once to calculate the remainder frequencies, and then iterate over half of the remainder array to check conditions.
- **Space Complexity:** `O(k)` where `k` is the divisor. We use a frequency array of size `k` to store the counts of remainders.

### Examples

#### Example 1

- **Input:**

  ```text
  arr = [1,2,3,4,5,10,6,7,8,9], k = 5
  ```

- **Output:** `true`
- **Explanation:**
  - The pairs are: `(1,9), (2,8), (3,7), (4,6), (5,10)`.
  - All pairs sum to a multiple of `k`.

#### Example 2

- **Input:**

  ```text
  arr = [1,2,3,4,5,6], k = 7
  ```

- **Output:** `true`
- **Explanation:**
  - The pairs are: `(1,6), (2,5), (3,4)`.
  - All pairs sum to a multiple of `k`.

#### Example 3

- **Input:**

  ```text
  arr = [1,2,3,4,5,6], k = 10
  ```

- **Output:** `false`
- **Explanation:**
  - No valid pairs can be formed such that the sum is divisible by `k`.

### Constraints

- `arr.length == n`
- `1 <= n <= 10^5`
- `n` is even.
- `-10^9 <= arr[i] <= 10^9`
- `1 <= k <= 10^5`

This solution ensures that the array can be divided into pairs where the sum of each pair is divisible by `k`. The use of remainders and frequency counting ensures an efficient solution with a time complexity of `O(n)` and space complexity of `O(k)`.

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Function to check if array can be divided into pairs where the sum of each pair is divisible by k.
     *
     * @param arr - a vector of integers representing the input array.
     * @param k - an integer representing the divisor.
     * @return true if the array can be divided into pairs such that the sum of each pair is divisible by k, false otherwise.
     *
     * The approach uses the concept of remainder frequency.
     * We count the remainder of each element when divided by k.
     * To form valid pairs, the frequency of remainders must satisfy certain conditions:
     * - For elements divisible by k (remainder = 0), their frequency must be even.
     * - For other elements, the frequency of remainder i must match the frequency of remainder (k - i).
     * The algorithm runs in O(n), where n is the size of the array, and uses O(k) extra space.
     */
    bool canArrange(vector<int>& arr, int k) {
        // Step 1: If the array size is odd, return false (we cannot form pairs)
        if (arr.size() % 2 != 0)
            return false;

        // Step 2: Create a frequency array to count remainders when divided by k
        vector<int> freq(k, 0);

        // Step 3: Count the frequency of each remainder
        for (int num : arr) {
            // Calculate the remainder of the current number modulo k
            int rem = num % k;

            // Adjust remainder for negative values to bring it within the range [0, k-1]
            if (rem < 0) {
                rem += k;
            }

            // Increment the frequency of the remainder
            freq[rem]++;
        }

        // Step 4: Check if the conditions for forming pairs are met

        // 4.1: For remainder 0, the count must be even (pairs of elements divisible by k)
        if (freq[0] % 2 != 0)
            return false;

        // 4.2: For other remainders, check if freq[i] matches freq[k - i]
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i])
                return false;
        }

        // If all conditions are met, return true
        return true;
    }
};

/**
 * Analysis:
 *
 * Problem: Check If Array Pairs Are Divisible by k
 * Time Complexity: O(n)
 * - We iterate through the array once to calculate the remainder frequencies (O(n)).
 * - Then, we iterate through half of the remainder values to check for pair conditions (O(k)).
 *   Since k is much smaller than n in most cases, this results in O(n) time complexity.
 *
 * Space Complexity: O(k)
 * - We use a frequency array of size k to store the counts of remainders.
 *   This results in O(k) auxiliary space complexity.
 *
 * Approach:
 * - Use a frequency array to count the number of occurrences of each remainder when the array elements are divided by k.
 * - Ensure the number of elements with remainder 0 is even, as these must pair with each other.
 * - For each remainder i, ensure that the frequency of remainder i matches the frequency of remainder (k - i),
 *   as these remainders will pair together to form sums divisible by k.
 *
 * Example:
 * Consider arr = [1, 2, 3, 4, 5, 10, 6, 7, 8, 9] and k = 5.
 * - The remainders when the elements are divided by 5 are:
 *   [1, 2, 3, 4, 0, 0, 1, 2, 3, 4]
 * - We can form pairs: (1, 9), (2, 8), (3, 7), (4, 6), and (5, 10), all of which are divisible by 5.
 */
```
