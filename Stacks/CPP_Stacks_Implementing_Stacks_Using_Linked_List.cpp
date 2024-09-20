#include <bits/stdc++.h>
using namespace std;

// Definition of StackNode
struct StackNode
{
  int data;        // Data stored in the node
  StackNode *next; // Pointer to the next node

  // Constructor to initialize a new node with data
  StackNode(int a)
  {
    data = a;
    next = NULL;
  }
};

// Stack class to implement push and pop operations using a linked list
class MyStack
{
private:
  StackNode *top; // Pointer to the top of the stack
  int size = 0;   // Variable to keep track of the size of the stack

public:
  // Constructor to initialize the stack with a NULL top
  MyStack()
  {
    top = NULL;
  }

  /**
   * @brief Push an element onto the stack.
   * @param x The element to be pushed onto the stack.
   *
   * Time Complexity: O(1)
   * Space Complexity: O(1)
   */
  void push(int x)
  {
    StackNode *temp = new StackNode(x); // Create a new node with the given value

    // Link the new node to the current top
    temp->next = top;
    top = temp; // Update the top pointer to the new node

    size += 1; // Increment the size of the stack
  }

  /**
   * @brief Pop an element from the stack and return it.
   * @return The popped element. If the stack is empty, return -1.
   *
   * Time Complexity: O(1)
   * Space Complexity: O(1)
   */
  int pop()
  {
    if (top == nullptr)
      return -1; // If the stack is empty, return -1

    // Get the top element and update the top pointer
    StackNode *temp = top;
    int ele = temp->data; // Store the top element
    top = top->next;      // Update the top pointer to the next node

    delete temp; // Free the memory of the old top node
    size -= 1;   // Decrement the size of the stack

    return ele; // Return the popped element
  }

  /**
   * @brief Get the current size of the stack.
   * @return The size of the stack.
   *
   * Time Complexity: O(1)
   * Space Complexity: O(1)
   */
  int Size()
  {
    return size;
  }
};

// Driver Code to handle multiple test cases and queries
int main()
{
  int T;
  cin >> T;     // Number of test cases
  cin.ignore(); // Ignore the newline character after T

  // For each test case
  while (T--)
  {
    MyStack *sq = new MyStack(); // Create a new stack instance
    string line;
    getline(cin, line); // Get the line of input for operations

    stringstream ss(line); // Use stringstream to parse the input line
    vector<int> nums;
    int num;

    // Parse the input queries
    while (ss >> num)
    {
      nums.push_back(num);
    }

    int n = nums.size();
    int i = 0;

    // Process each query in the input
    while (i < n)
    {
      int QueryType = nums[i++];

      // If the query is push
      if (QueryType == 1)
      {
        int a = nums[i++];
        sq->push(a); // Push the element onto the stack

        // If the query is pop
      }
      else if (QueryType == 2)
      {
        cout << sq->pop() << " "; // Pop the top element and print it
      }
    }
    cout << endl;
    delete sq; // Free the memory allocated for the stack
  }
  return 0;
}

/**
 * Key Points of the Implementation:
 *
 * Data Structure:
 * - StackNode is a structure representing each node in the linked list used to implement the stack.
 *   Each node contains an integer data and a pointer next to the next node.
 *
 * MyStack Class:
 * - The stack is represented by the MyStack class. It has:
 *   - A top pointer that refers to the top of the stack.
 *   - A size variable to keep track of the stack size.
 *
 * Operations:
 * - push(int x): Adds a new node with the value x at the top of the stack in O(1) time.
 * - pop(): Removes the top node and returns its value. If the stack is empty, returns -1.
 * - Size(): Returns the current size of the stack (used for debugging or additional queries if needed).
 *
 * Time Complexity:
 * - All operations (push and pop) run in constant time O(1), making this solution efficient.
 *
 * Space Complexity:
 * - Since no extra space is used apart from the linked list itself, the space complexity for each operation is O(1).
 *
 * Example:
 *
 * Input:
 * [[1,2], [1,3], [2], [1,4], [2]]
 *
 * Output:
 * 3 4
 *
 * Explanation:
 * - push(2): Stack = {2}
 * - push(3): Stack = {2, 3}
 * - pop(): Popped element = 3, Stack = {2}
 * - push(4): Stack = {2, 4}
 * - pop(): Popped element = 4, Stack = {2}
 */
