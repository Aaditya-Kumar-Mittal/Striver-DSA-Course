#include <bits/stdc++.h>
using namespace std;

/*
    Function to find the next greater element for each element in a circular array.
    The approach uses a stack to maintain the elements for which we haven't yet found the next greater element.
    The array is considered circular, so elements can "wrap around" and the last element may have the next greater element in the beginning of the array.
*/
class Solution
{
public:
  // Function to find the next greater element in a circular array.
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size(); // Size of the array
    vector<int> NGE(n);  // Vector to store the next greater elements

    stack<int> st; // Stack to store elements for which we are finding the NGE

    // First pass: Push elements (except the last one) onto the stack to process them in circular fashion
    for (int i = n - 2; i >= 0; i--)
    {
      st.push(nums[i]);
    }

    // Second pass: Process the array as a circular array
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

Problem Name: Next Greater Element in a Circular Array

Time Complexity:
- O(n), where n is the number of elements in the input array.
  Each element is pushed and popped from the stack at most once, so the overall time complexity is linear.

Space Complexity:
- O(n), where n is the number of elements in the input array.
  This is due to the use of the stack and the result vector, both of which may store up to n elements.

Explanation:
1. **Circular Array**:
   - In a circular array, after the last element, we consider that the first element follows.
   - This function handles the circular nature by pushing elements of the array onto the stack in two stages, and then processing the array normally.

2. **Stack-Based Approach**:
   - The stack is used to store elements that are waiting for a next greater element.
   - For each element, we remove all smaller elements from the stack because they can't be the next greater element for any subsequent elements.

3. **Edge Cases**:
   - Handling the circular aspect of the array is crucial, and this is managed by making a pass over the array while wrapping around using the stack.

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    // Creating an instance of the Solution class
    Solution obj;
    vector<int> res = obj.nextGreaterElements(arr);

    // Output the next greater elements
    for (int i : res)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}

/*

Problem Name: Next Greater Element in a Circular Array

Time Complexity:
- O(n), where n is the number of elements in the input array.
  Each element is pushed and popped from the stack at most once, so the overall time complexity is linear.

Space Complexity:
- O(n), where n is the number of elements in the input array.
  This is due to the use of the stack and the result vector, both of which may store up to n elements.

Explanation:
1. **Circular Array**:
   - In a circular array, after the last element, we consider that the first element follows.
   - This function handles the circular nature by pushing elements of the array onto the stack in two stages, and then processing the array normally.

2. **Stack-Based Approach**:
   - The stack is used to store elements that are waiting for a next greater element.
   - For each element, we remove all smaller elements from the stack because they can't be the next greater element for any subsequent elements.

3. **Edge Cases**:
   - Handling the circular aspect of the array is crucial, and this is managed by making a pass over the array while wrapping around using the stack.

*/
