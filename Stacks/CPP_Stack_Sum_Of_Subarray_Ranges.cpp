#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  long long subArrayRanges(vector<int> &nums)
  {
    // Optimize I/O performance
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = nums.size();                                            // Size of the input array
    stack<int> st;                                                  // Stack for calculating indices
    vector<long long> NLE(n, 0), PLEE(n, 0), NSE(n, 0), PSEE(n, 0); // Arrays to store indices

    // Run for NLE -> Next Larger Element
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && nums[st.top()] <= nums[i])
        st.pop();
      NLE[i] = st.empty() ? n : st.top(); // If stack is empty, set NLE[i] to n
      st.push(i);                         // Push the current index onto the stack
    }

    // Clear stack for the next calculation
    while (!st.empty())
      st.pop();

    // Run for PLEE -> Previous Larger or Equal Element
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && nums[st.top()] < nums[i])
        st.pop();
      PLEE[i] = st.empty() ? -1 : st.top(); // If stack is empty, set PLEE[i] to -1
      st.push(i);                           // Push the current index onto the stack
    }

    // Clear stack for the next calculation
    while (!st.empty())
      st.pop();

    // Run for NSE -> Next Smaller Element
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && nums[st.top()] >= nums[i])
        st.pop();
      NSE[i] = st.empty() ? n : st.top(); // If stack is empty, set NSE[i] to n
      st.push(i);                         // Push the current index onto the stack
    }

    // Clear stack for the next calculation
    while (!st.empty())
      st.pop();

    // Run for PSEE -> Previous Smaller Element
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && nums[st.top()] > nums[i])
        st.pop();
      PSEE[i] = st.empty() ? -1 : st.top(); // If stack is empty, set PSEE[i] to -1
      st.push(i);                           // Push the current index onto the stack
    }

    long long ans = 0; // Variable to store the final answer

    // Calculate the final answer based on contributions from max and min elements
    for (int i = 0; i < n; i++)
    {
      ans += (long)(nums[i] * (((i - PLEE[i]) * (NLE[i] - i)) -  // Contribution as max
                               ((i - PSEE[i]) * (NSE[i] - i)))); // Contribution as min
    }

    return ans; // Return the final answer
  }
};

// Example usage
int main()
{
  Solution sol;
  vector<int> nums = {1, 4, 6, 7, 3, 7, 8, 1};
  long long result = sol.subArrayRanges(nums);
  cout << "Sum of subarray ranges: " << result << endl;
  return 0;
}

/*
### Problem Name
Sum of Subarray Ranges

### Time Complexity
- The time complexity of this solution is O(n), where n is the number of elements in the input array. Each element is pushed and popped from the stack at most once during the four passes through the array.

### Space Complexity
- The space complexity is O(n), primarily due to the use of four additional vectors to store the indices of the next and previous larger and smaller elements.

### Explanation
1. **NLE (Next Larger Element)** and **PLEE (Previous Larger or Equal Element)** are calculated using a stack. NLE helps in finding the distance to the next larger element for each position, while PLEE helps find how many previous elements are larger or equal.

2. **NSE (Next Smaller Element)** and **PSEE (Previous Smaller Element)** are calculated in a similar manner.

3. The final answer is computed by considering each element's contribution to the total range sum based on how many subarrays it can serve as a maximum and a minimum.
*/

