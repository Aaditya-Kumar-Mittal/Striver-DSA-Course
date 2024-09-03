//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  // Function to insert an element at the bottom of a stack
  void insertAtBottom(stack<int> &s, int num)
  {

    // Base case: If the stack is empty, push the element to the bottom
    if (s.empty())
    {
      s.push(num);
      return;
    }

    // Pop the top element and recurse to reach the bottom
    int x = s.top();
    s.pop();

    // Recursive call to insert num at the bottom
    insertAtBottom(s, num);

    // Push the popped element back into the stack
    s.push(x);
  }

  // Function to reverse the stack using recursion
  void Reverse(stack<int> &St)
  {

    // Base case: If the stack is empty, return
    if (St.empty())
      return;

    // Pop the top element
    int num = St.top();
    St.pop();

    // Recur to reverse the remaining stack
    Reverse(St);

    // Insert the popped element at the bottom of the reversed stack
    insertAtBottom(St, num);
  }
};

//{ Driver Code Starts.

int main()
{
  int T;
  cin >> T; // Read the number of test cases
  while (T--)
  {
    int N;
    cin >> N; // Read the number of elements in the stack
    stack<int> St;
    for (int i = 0; i < N; i++)
    {
      int x;
      cin >> x;   // Read each element
      St.push(x); // Push element into the stack
    }
    Solution ob;
    ob.Reverse(St); // Reverse the stack using the Reverse function
    vector<int> res;
    while (St.size())
    {
      res.push_back(St.top()); // Collect the reversed elements
      St.pop();                // Remove the top element
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
      cout << res[i] << " "; // Print the reversed stack
    }
    cout << endl;
  }
}
// } Driver Code Ends

/**
 * Analysis:
 *
 * Problem: Reverse the elements of a stack using recursion without using any extra data structures.
 *
 * Approach:
 * - The solution uses two recursive functions: `Reverse` and `insertAtBottom`.
 * - The `Reverse` function pops elements from the stack until it is empty,
 *   then uses the `insertAtBottom` function to insert each element back at the bottom,
 *   effectively reversing the stack.
 *
 * Time Complexity:
 * - The time complexity is O(N^2) where N is the number of elements in the stack.
 *   This is because for each element, we might need to insert it at the bottom
 *   of the stack, which takes O(N) time.
 *
 * Space Complexity:
 * - The space complexity is O(N) due to the recursive function calls using the
 *   call stack. No additional data structure is used, but the recursion stack
 *   requires space proportional to the number of elements in the stack.
 *
 * Note: Recursion provides an elegant way to reverse the stack, but it consumes
 * stack memory for recursive calls. In practical scenarios with large stacks,
 * an iterative approach could be more space-efficient.
 */
