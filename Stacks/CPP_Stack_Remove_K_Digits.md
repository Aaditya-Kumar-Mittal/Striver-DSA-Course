# Stack - Remove K Digits

## Problem Statement

Given a string `num` representing a non-negative integer and an integer `k`, the task is to return the smallest possible integer after removing `k` digits from `num`.

### Constraints

- `1 <= k <= num.length <= 10^5`
- `num` consists of only digits.
- `num` does not have any leading zeros except for the zero itself.

### Examples

#### Example 1

- **Input**: `num = "1432219"`, `k = 3`
- **Output**: `"1219"`
- **Explanation**: Remove the digits `4`, `3`, and `2` to form the new number `1219`, which is the smallest.

#### Example 2

- **Input**: `num = "10200"`, `k = 1`
- **Output**: `"200"`
- **Explanation**: Remove the leading `1` and the number becomes `200`. Note that the output must not contain leading zeros.

#### Example 3

- **Input**: `num = "10"`, `k = 2`
- **Output**: `"0"`
- **Explanation**: Remove all the digits, and the result is `0`.

## Approach

This problem can be efficiently solved using a **stack**. We aim to remove the largest digits as early as possible, because larger digits in the beginning of the number would result in a higher number. We keep removing digits until we get the smallest possible number after removing exactly `k` digits.

### Detailed Explanation

1. **Stack for Monotonic Decrease**: We use a stack to keep track of digits in the smallest possible order. While iterating through the number, if we encounter a digit smaller than the one at the top of the stack, we pop from the stack and decrease `k`. This ensures that larger digits are removed to form a smaller number.
2. **Post-Iteration Removal**: After iterating through the number, if there are still remaining digits to remove (`k > 0`), we pop the remaining top digits from the stack.

3. **Remove Leading Zeros**: After constructing the result from the stack, we need to remove any leading zeros from the result.

4. **Edge Case**: If the result becomes empty (i.e., all digits are removed), we return `"0"`.

---

## Code -1 Implementation

```cpp
class Solution {
public:
    /**
     * @brief Removes k digits from the given string num to form the smallest possible number.
     *
     * This function uses a stack to greedily remove digits and ensure that
     * the remaining number is the smallest possible. We remove larger digits
     * first while iterating through the string num, and then handle any remaining
     * removal of digits by popping the stack if necessary.
     *
     * @param num A string representing a non-negative integer.
     * @param k An integer representing the number of digits to remove.
     * @return The smallest possible number after removing k digits.
     */
    string removeKdigits(string num, int k) {
        stack<char> st;  // Stack to store the digits in increasing order

        int n = num.size();  // Size of the input number

        // Iterate through each digit in the number
        for (int i = 0; i < n; i++) {
            // While the stack is not empty, k > 0, and the top of the stack is greater
            // than the current digit, we pop the top of the stack (remove larger digits).
            while (!st.empty() && k > 0 && (st.top() > num[i])) {
                st.pop();
                k--;  // Decrease k as we've removed a digit
            }
            st.push(num[i]);  // Push the current digit onto the stack
        }

        // If there are still digits left to remove, pop them from the stack
        while (k > 0) {
            st.pop();
            k--;  // Decrease k for each removed digit
        }

        // Handle the case where the stack is empty
        if (st.empty()) {
            return "0";  // If no digits are left, return "0"
        }

        vector<char> res;  // Vector to store the resulting digits

        // Pop all digits from the stack and store them in the result vector
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        // Remove any leading zeros from the result vector
        while (res.size() > 0 && res.back() == '0') {
            res.pop_back();
        }

        // Reverse the result vector to get the correct number order
        reverse(res.begin(), res.end());

        // If all digits are removed and no result is left, return "0"
        if (res.empty()) {
            return "0";
        }

        // Convert the result vector to a string
        string ans = "";
        for (char c : res) {
            ans += c;
        }

        return ans;  // Return the final result
    }
};

// Optimization block for faster input/output
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
```

## Explanation of Key Sections

1. **Main Logic**:
   - We iterate through the digits of the number, and if we encounter a digit smaller than the one on top of the stack, we remove the top element from the stack. This ensures that we always keep the smallest possible digits in the stack.
2. **Handling Leading Zeros**:
   - After popping all digits from the stack, we check for leading zeros in the result. This ensures that the result does not have unnecessary zeros at the front.
3. **Edge Case Handling**:
   - If after removing digits the stack becomes empty, or if the entire result is made of zeros, we return `"0"`.
4. **Optimization**:
   - To optimize input/output operations for large test cases, `ios::sync_with_stdio(false)` and `cin.tie(nullptr)` are used to disable synchronization between C++ and C I/O streams.

## Complexity Analysis

- **Time Complexity**: `O(n)`

  - We process each digit once as we push and pop them from the stack. In the worst case, all digits are pushed and popped once, making the time complexity linear.

- **Space Complexity**: `O(n)`
  - In the worst case, we store all digits in the stack or the result vector, making the space complexity linear in the size of the input string `num`.

## Code - 2 Implementation (Without Reversal)

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        int n = num.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k > 0 && (st.top() > num[i])) {
                st.pop();

                k--;
            }

            st.push(num[i]);
        }

        while (k > 0) {
            st.pop();

            k--;
        }

        if (st.empty()) {
            return "0";
        }

        int idx = st.size();
        string ans(idx, '%'); // Prevents reversing the string

        while (!st.empty()) {
            ans[--idx] = st.top();
            st.pop();
        }
        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        // The erase function removes i characters
        // from given index (0 here)
        ans.erase(0, i);

        // If are using reversal
        // while(ans.size() > 0 && ans.back() == '0')
        //     ans.pop_back();

        if (ans.empty())
            return "0";
        return ans;
    }
};

inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
```

## Code - 3 Implementation

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto s: num)
        {
            while(!st.empty() && k>0 && s<st.top())
            {
                st.pop();
                k--;
            }
            st.push(s);
        }

        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        while(!ans.empty() && ans.back()=='0')
            ans.pop_back();
        if(ans.empty())
            return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
