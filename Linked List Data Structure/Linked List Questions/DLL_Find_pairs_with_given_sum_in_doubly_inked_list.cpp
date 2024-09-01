//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Class representing a Node in a doubly linked list
class Node
{
public:
  int data;          // Data stored in the node
  Node *next, *prev; // Pointers to the next and previous nodes

  // Constructor to initialize a node with a given value
  Node(int val) : data(val), next(NULL), prev(NULL)
  {
  }
};

// } Driver Code Ends
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
  // Function to find the tail (last node) of the doubly linked list
  Node *findTail(Node *head)
  {
    // If the list is empty or has only one node, return the head
    if (head == nullptr || head->next == nullptr)
      return head;

    Node *temp = head;

    // Traverse to the end of the list to find the tail
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    return temp; // Return the last node
  }

  // Function to find all pairs with a given sum in the doubly linked list
  vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
  {
    vector<pair<int, int>> dataStr; // Vector to store the pairs that sum to the target

    Node *left = head; // Pointer to the beginning of the list

    Node *right = findTail(head); // Pointer to the end of the list

    // Loop until the two pointers meet
    while (left->data < right->data)
    {
      int sum = left->data + right->data; // Calculate the sum of the two nodes

      if (sum == target) // If the sum matches the target
      {
        dataStr.push_back({left->data, right->data}); // Add the pair to the result

        left = left->next; // Move the left pointer forward

        right = right->prev; // Move the right pointer backward
      }
      else if (sum < target) // If the sum is less than the target, move the left pointer forward
      {
        left = left->next;
      }
      else
      { // If the sum is greater than the target, move the right pointer backward
        right = right->prev;
      }
    }

    return dataStr; // Return the list of pairs that sum to the target
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, target;
    cin >> target >> n;
    int a;
    cin >> a;
    Node *head = new Node(a);
    Node *tail = head;
    for (int i = 0; i < n - 1; i++)
    {
      cin >> a;
      tail->next = new Node(a);
      tail->next->prev = tail;
      tail = tail->next;
    }
    Solution ob;
    auto ans = ob.findPairsWithGivenSum(head, target);
    if (ans.size() == 0)
      cout << "-1";
    else
    {
      for (int i = 0; i < ans.size(); i++)
      {
        cout << "(" << ans[i].first << "," << ans[i].second << ")"
             << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
/*
### Problem Name:
Find Pairs with a Given Sum in a Doubly Linked List

### Problem Description:
Given a doubly linked list and an integer target, the task is to find all pairs of nodes whose sum equals the target value.
Each pair should be printed as `(first, second)`, where `first` and `second` are the node values. The list should be traversed
from the beginning (`head`) and end (`tail`) simultaneously to find the pairs.

### Approach:
1. **Two-Pointer Technique**:
   - The solution employs the two-pointer technique, where one pointer (`left`) starts at the head of the doubly linked list
     and another pointer (`right`) starts at the tail of the list.
   - The algorithm iteratively checks the sum of the values at the two pointers:
     - If the sum equals the target, the pair is added to the result list, and both pointers are moved inward.
     - If the sum is less than the target, the `left` pointer is moved to the next node.
     - If the sum is greater than the target, the `right` pointer is moved to the previous node.
   - The process continues until the `left` pointer meets or crosses the `right` pointer.

2. **Handling Edge Cases**:
   - The algorithm properly handles cases where the list is empty or contains only one node.
   - It also ensures that no invalid pairs (e.g., duplicates) are added to the result by adjusting the pointers correctly.

3. **Helper Function (`findTail`)**:
   - A helper function `findTail` is used to find the last node (tail) of the doubly linked list, which helps in setting
     up the initial `right` pointer.

### Time Complexity:
- **O(n)**:
  - The algorithm traverses the doubly linked list using the two-pointer technique, which requires a single pass from the
    head and tail toward the center. This results in a linear time complexity.
  - The helper function `findTail` also runs in O(n) time, as it traverses the list to find the tail node.

### Space Complexity:
- **O(1)**:
  - The algorithm uses a constant amount of extra space for the pointers and variables. The only additional space used
    is for storing the result pairs, which depends on the number of pairs but is not considered in the space complexity
    since it is an output requirement.

### Edge Cases Considered:
1. **Empty List**:
   - The algorithm returns no pairs (or a specific indicator like `-1`) when the list is empty.

2. **Single Node List**:
   - No pairs can be formed if the list contains only one node.

3. **No Valid Pairs**:
   - If no pairs match the target sum, the algorithm returns a specific indicator (e.g., `-1`).

### Example:
Consider a doubly linked list: `1 <-> 2 <-> 3 <-> 4 <-> 5` and a target sum of `6`.

- Initial positions: `left` at `1` and `right` at `5`.
- Check sum: `1 + 5 = 6` (valid pair), so move inward: `left` to `2`, `right` to `4`.
- Check sum: `2 + 4 = 6` (valid pair), so move inward: `left` to `3`, `right` to `3`.
- The process stops as `left` is not less than `right`.

Output: `(1, 5), (2, 4)`

This approach ensures that all valid pairs are found efficiently without needing to use additional data structures
like hash maps, thus optimizing both time and space.
*/