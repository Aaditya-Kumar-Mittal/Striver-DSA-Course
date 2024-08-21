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

// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution
{
public:
  Node *deleteMid(Node *head)
  {
    // If the list is empty or contains only one element, return nullptr
    if (head == nullptr || head->next == nullptr)
      return nullptr;

    Node *slow = head, *fast = head;

    // Move fast pointer two steps and slow pointer one step to find the middle
    fast = fast->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Delete the middle node
    Node *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
  }
};

//{ Driver Code Starts.

void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

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
    struct Node *head = new Node(arr[0]);
    struct Node *tail = head;
    for (int i = 1; i < arr.size(); ++i)
    {
      tail->next = new Node(arr[i]);
      tail = tail->next;
    }
    Solution obj;
    head = obj.deleteMid(head);
    printList(head);
  }
  return 0;
}

// } Driver Code Ends

/*
### Analysis

**Problem Name:** Delete the Middle of a Linked List

**Approach:**
- The code employs the two-pointer technique to locate the middle node of a linked list.
- The fast pointer moves two steps at a time while the slow pointer moves one step. When the fast pointer reaches the end, the slow pointer will be at the middle node.
- The middle node is then deleted by adjusting the pointers of the previous node.

**Time Complexity:**
- The time complexity is `O(N)` where `N` is the number of nodes in the linked list. The traversal of the list to find the middle and adjust the pointers occurs in linear time.

**Space Complexity:**
- The space complexity is `O(1)` as the algorithm only uses a constant amount of extra space, irrespective of the size of the linked list.

**Edge Cases Considered:**
- An empty list or a list with a single node, where the function returns `nullptr`.
- A list with an even number of nodes, where the function correctly identifies and deletes the first middle node.

This method efficiently deletes the middle node with minimal time and space complexity, handling edge cases effectively.
*/
