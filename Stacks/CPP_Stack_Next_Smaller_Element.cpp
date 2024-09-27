#include <bits/stdc++.h>
using namespace std;

/*
    Function to find the previous smaller element for each element in the array.
    The approach is to use a stack to store elements in a way that for every element,
    the top of the stack contains the closest smaller element seen so far.

    Parameters:
    - vector<int> &A: Reference to the input array.

    Returns:
    - vector<int>: A new array where each element is the previous smaller element for
    the corresponding element in the input array. If no such element exists, return -1.
*/
vector<int> prevSmaller(vector<int> &A)
{
  int n = A.size();   // Get the size of the input array
  stack<int> st;      // Stack to store the previous smaller elements
  vector<int> NSE(n); // Resultant array to store the nearest smaller elements to the left

  // Loop through each element in the array
  for (int i = 0; i < n; i++)
  {
    // Pop elements from the stack while they are greater than or equal to the current element
    while (!st.empty() && st.top() >= A[i])
      st.pop();

    // If the stack is empty, there is no smaller element on the left, so store -1
    if (st.empty())
      NSE[i] = -1;
    else
      NSE[i] = st.top(); // Else, the top of the stack is the previous smaller element

    // Push the current element to the stack for future comparisons
    st.push(A[i]);
  }

  return NSE; // Return the array of nearest smaller elements
}

/****************************************************************

Problem Name: Previous Smaller Element (PSE)

Time Complexity:
- O(n), where n is the size of the input array.
  Each element is pushed and popped from the stack at most once,
  resulting in an overall linear time complexity.

Space Complexity:
- O(n), due to the use of a stack that can hold up to n elements
  in the worst case, and an array of size n to store the result.

Explanation:
1. **Previous Smaller Element Concept**:
   - For each element in the input array, the function finds the closest smaller element on its left side.
   - If no such element exists, the function returns -1 for that element.

2. **Stack-based Approach**:
   - The stack is used to store elements in a decreasing order.
   - While traversing the array, if the current element is smaller than the top of the stack,
     the stack is popped until a smaller element is found or the stack becomes empty.
   - The stack helps to efficiently track previous smaller elements.

3. **Edge Cases**:
   - Empty input arrays can return an empty result.
   - Proper handling of cases where all elements are in increasing order, resulting in all `-1` outputs.

*****************************************************************/
