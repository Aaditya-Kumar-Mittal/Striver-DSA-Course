#include <bits/stdc++.h>
using namespace std;

/*
    Function to find the next greater element for each element of the array.
    The approach uses a stack to maintain the elements for which we haven't yet found the next greater element.
    We traverse the array from right to left, ensuring that at each element, we know the next greater element if it exists.
*/
class Solution
{
public:
  // Function to find the next greater element for each element of the array.
  vector<long long> nextLargerElement(vector<long long> nums, int n)
  {
    vector<long long> NGE(n); // Vector to store the next greater elements
    stack<long long> st;      // Stack to store elements for which we are finding the NGE

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
      // Pop elements from the stack that are smaller or equal to the current element
      while (!st.empty() && st.top() <= nums[i])
      {
        st.pop();
      }

      // If the stack is empty, no greater element exists, set NGE[i] to -1
      if (st.empty())
      {
        NGE[i] = -1;
      }
      else
      {
        // The top element of the stack is the next greater element
        NGE[i] = st.top();
      }

      // Push the current element to the stack for future comparisons
      st.push(nums[i]);
    }

    return NGE; // Return the vector containing the next greater elements
  }
};

/****************************************************************

Problem Name: Next Greater Element

Time Complexity:
- O(n), where n is the number of elements in the input array.
  Each element is pushed and popped from the stack at most once, so the overall time complexity is linear.

Space Complexity:
- O(n), where n is the number of elements in the input array.
  This is due to the use of the stack and the result vector, both of which may store up to n elements.

Approach:
1. **Stack-Based Approach**:
   - As we traverse the array from right to left, the stack helps us efficiently find the next greater element for each item.
   - For each element, we remove all smaller elements from the stack because they can't be the next greater element for any subsequent elements.
   - The first element left in the stack that is greater than the current element becomes its next greater element.

2. **Edge Cases**:
   - The last element in the array will always have a next greater element of `-1`, as there are no elements to its right.

****************************************************************/

// Driver function to test the solution
int main()
{
  // Number of test cases
  int t;
  cin >> t;

  // Loop over each test case
  while (t--)
  {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    // Creating an instance of the Solution class
    Solution obj;
    vector<long long> res = obj.nextLargerElement(arr, n);

    // Output the next greater elements
    for (long long i : res)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Problem Name: Next Greater Element

Time Complexity:
- O(n), where n is the number of elements in the input array.
  Each element is pushed and popped from the stack at most once, so the overall time complexity is linear.

Space Complexity:
- O(n), where n is the number of elements in the input array.
  This is due to the use of the stack and the result vector, both of which may store up to n elements.

Approach:
1. **Stack-Based Approach**:
   - As we traverse the array from right to left, the stack helps us efficiently find the next greater element for each item.
   - For each element, we remove all smaller elements from the stack because they can't be the next greater element for any subsequent elements.
   - The first element left in the stack that is greater than the current element becomes its next greater element.

2. **Edge Cases**:
   - The last element in the array will always have a next greater element of `-1`, as there are no elements to its right.

*/
  