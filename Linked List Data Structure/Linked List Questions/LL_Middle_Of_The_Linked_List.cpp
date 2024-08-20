//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Initial template for C++

// Definition of the Node structure for the linked list
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
    cout << node->data << " "; // Print each node's data
    node = node->next;         // Move to the next node
  }
  cout << "\n";
}

// } Driver Code Ends

/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution
{
public:
  /* Should return data of middle node. If linked list is empty, then -1 */
  int getMiddle(Node *head)
  {
    Node *slow = head; // Initialize slow pointer
    Node *fast = head; // Initialize fast pointer

    // Traverse the list with two pointers
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;       // Move slow pointer by one step
      fast = fast->next->next; // Move fast pointer by two steps
    }

    // When fast pointer reaches the end, slow pointer will be at the middle
    return slow->data;
  }
};

//{ Driver Code Starts.

int main()
{

  int t;
  cin >> t;
  cin.ignore(); // Ignore the newline character after reading t

  while (t--)
  {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
      arr.push_back(number); // Parse each number and add to the vector
    }

    if (arr.empty())
    {
      cout << -1 << endl; // If the list is empty, print -1
      continue;
    }

    int data = arr[0];
    struct Node *head = new Node(data); // Create the head node
    struct Node *tail = head;

    // Create the linked list from the input array
    for (int i = 1; i < arr.size(); ++i)
    {
      data = arr[i];
      tail->next = new Node(data); // Add new nodes to the list
      tail = tail->next;
    }

    Solution ob;
    cout << ob.getMiddle(head) << endl; // Print the data of the middle node
  }

  return 0;
}

// } Driver Code Ends

/*
Analysis of the Code

Time Complexity:
- The `getMiddle` function runs in O(N) time, where N is the length of the linked list.
  - This is because each pointer (slow and fast) traverses the list, but effectively the list is only traversed once.

Space Complexity:
- The space complexity is O(1), as no extra space is used beyond a few pointers.

This approach is efficient for finding the middle of a linked list. The use of two pointers ensures that the solution is both time and space optimal.
*/
