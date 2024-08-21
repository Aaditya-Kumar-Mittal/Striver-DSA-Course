//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// Function to print the linked list
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

// Function to create a loop in the linked list at a given position
void loopHere(Node *head, Node *tail, int position)
{
  if (position == 0)
    return;

  Node *walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
  // Function to find the length of a loop in the linked list.

  int findLength(Node *s, Node *f)
  {
    int len = 1;
    f = f->next;
    while (s != f)
    {
      len++;
      f = f->next;
    }
    return len;
  }

  int countNodesinLoop(struct Node *head)
  {
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        return findLength(slow, fast);
      }
    }
    return 0; // No loop found
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
      arr.push_back(number);
    }
    int k;
    cin >> k;
    cin.ignore();
    struct Node *head = new Node(arr[0]);
    struct Node *tail = head;
    for (int i = 1; i < arr.size(); ++i)
    {
      tail->next = new Node(arr[i]);
      tail = tail->next;
    }
    loopHere(head, tail, k);

    Solution ob;
    cout << ob.countNodesinLoop(head) << endl;
  }
  return 0;
}

// } Driver Code Ends

/*
### Analysis

**Problem Name:** Find the Length of Loop in Linked List

**Approach:**
- The code uses Floyd’s Cycle Detection Algorithm (Tortoise and Hare approach) to detect if there is a loop in the linked list.
- Once a loop is detected by the meeting point of slow and fast pointers, the length of the loop is calculated by traversing the loop until the pointers meet again.

**Time Complexity:**
- The time complexity is `O(N)` where `N` is the number of nodes in the linked list. The worst case occurs when there is no loop, requiring a complete traversal of the list.

**Space Complexity:**
- The space complexity is `O(1)` since no extra space or data structures are used beyond a few pointers.

**Edge Cases Considered:**
- No loop present in the list.
- A loop starting at the head.
- A loop with only one node.

This approach efficiently handles the problem of detecting and measuring the length of a loop in a linked list with minimal time and space complexity.
*/
