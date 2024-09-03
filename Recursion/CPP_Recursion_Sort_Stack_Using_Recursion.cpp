//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Class to represent a stack and provide a sort function
class SortedStack
{
public:
  stack<int> s; // Stack to hold integers
  void sort();  // Function to sort the stack
};

// Function to print the elements of the stack
void printStack(stack<int> s)
{
  while (!s.empty())
  {
    printf("%d ", s.top()); // Print the top element of the stack
    s.pop();                // Remove the top element
  }
  printf("\n");
}

// Main function to drive the program
int main()
{
  int t;
  cin >> t; // Read the number of test cases
  while (t--)
  {
    SortedStack *ss = new SortedStack();
    int n;
    cin >> n; // Read the number of elements in the stack
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;      // Read each element
      ss->s.push(k); // Push element into the stack
    }
    ss->sort();        // Sort the stack
    printStack(ss->s); // Print the sorted stack
  }
}
// } Driver Code Ends

/* The structure of the class is
class SortedStack {
public:
    stack<int> s;  // Stack to hold integers
    void sort();   // Function to sort the stack
};
*/

/* The below method sorts the stack s
   You are required to complete the below method */

// Function to insert an element into the stack in sorted order
void sortInsertedOrder(stack<int> &s, int num)
{

  // Base case: If stack is empty or the top element is smaller than num, push num
  if (s.empty() || (!s.empty() && s.top() < num))
  {
    s.push(num);
    return;
  }

  // If the top element is greater than num, pop the top and recurse
  int n = s.top();
  s.pop();

  // Recur to insert num in the correct position
  sortInsertedOrder(s, num);

  // Push the popped element back into the stack
  s.push(n);
}

// Recursive function to sort the stack
void sortStack(stack<int> &s)
{

  // Base case: If stack is empty, return
  if (s.empty())
    return;

  // Pop the top element
  int num = s.top();
  s.pop();

  // Recur to sort the remaining stack
  sortStack(s);

  // Insert the popped element back into the sorted stack
  sortInsertedOrder(s, num);
}

// Function to be called by the driver code to sort the stack
void SortedStack::sort()
{
  sortStack(s); // Call the recursive sort function
}

/**
 * Analysis:
 *
 * Problem: Sorting a stack using recursion without using any other data structure.
 *
 * Approach:
 * - The algorithm uses a recursive approach to sort the stack.
 * - The `sortStack` function recursively pops elements from the stack and sorts
 *   the remaining elements. After the stack is sorted, the popped element is
 *   inserted back into the stack in the correct position using the
 *   `sortInsertedOrder` function.
 *
 * Time Complexity:
 * - The time complexity is O(N^2) where N is the number of elements in the stack.
 *   This is because for each element, we might need to perform N insertions in
 *   the sorted order.
 *
 * Space Complexity:
 * - The space complexity is O(N) due to the recursive function calls using the
 *   call stack. No extra data structure is used except for recursion.
 *
 * Note: Although recursion provides a neat way to solve this problem, iterative
 * approaches might be more space-efficient as they do not require stack space for
 * recursive calls.
 */
