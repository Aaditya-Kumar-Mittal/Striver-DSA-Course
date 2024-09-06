//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// Structure representing a node in a linked list
struct Node
{
  int data;
  struct Node *next;

  // Constructor to initialize a node with a value
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
    cout << node->data << " "; // Print the data of the current node
    node = node->next;         // Move to the next node
  }
  cout << "\n"; // New line after printing the list
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
  // Function to rotate a linked list by k positions.
  Node *rotate(Node *head, int k)
  {

    // Base case: if list is empty or no rotation is required, return the head
    if (head == nullptr || k == 0)
      return head;

    Node *tail = head;

    int len = 1; // Initialize the length of the list

    // Traverse the list to find the last node (tail) and calculate length
    while (tail->next != nullptr)
    {
      len++;
      tail = tail->next;
    }

    // If k is a multiple of the list length, no rotation is needed
    if (k % len == 0)
      return head;

    k = k % len; // Handle cases where k > len by reducing k modulo len

    // Form a circular linked list by connecting the last node to the head
    tail->next = head;

    // Move both tail and head k positions forward
    int count = 0;
    while (count < k)
    {
      tail = tail->next;
      head = head->next;
      count++;
    }

    // Break the circular connection by setting the next of tail to nullptr
    tail->next = nullptr;

    return head; // Return the new head of the rotated list
  }
};

//{ Driver Code Starts.

int main()
{
  int t; // Number of test cases
  cin >> t;
  cin.ignore(); // Ignore the newline character after reading t

  while (t--)
  {
    vector<int> arr;
    string input;
    getline(cin, input); // Read the entire line of input
    stringstream ss(input);
    int number;

    // Read numbers from the input line
    while (ss >> number)
    {
      arr.push_back(number);
    }

    Node *head = nullptr;

    // Check if the array is empty
    if (!arr.empty())
    {
      head = new Node(arr[0]); // Create the head node
      Node *tail = head;
      for (size_t i = 1; i < arr.size(); ++i)
      {
        tail->next = new Node(arr[i]); // Add new nodes to the list
        tail = tail->next;
      }
    }
    int k;
    cin >> k;     // Read the number of positions to rotate
    cin.ignore(); // Ignore the newline character

    Solution ob;
    head = ob.rotate(head, k); // Rotate the list
    printList(head);           // Print the rotated list
  }
  return 1;
}

// } Driver Code Ends

/*
Problem Name: Rotate a Linked List

Time Complexity:
- Traversing the list to find the length and tail: O(N)
- Rotating the list by k positions: O(N)
- Overall: O(N), where N is the number of nodes in the list.

Space Complexity:
- The algorithm uses constant space, so the space complexity is O(1).

Explanation:
1. Finding the Length and Tail:
   First, we traverse the linked list to determine its length and find the tail node.
   This is important for handling cases where the rotation count k is greater than the length of the list.

2. Handling k > length:
   If k is greater than the length of the list, we reduce it to k % length.
   This prevents unnecessary rotations since rotating by the length of the list results in the same list.

3. Making the List Circular:
   We temporarily convert the linked list into a circular linked list by connecting the tail to the head.
   This helps in rotating the list without having to traverse it again.

4. Breaking the Loop:
   After rotating by k positions, we break the loop by setting the next pointer of the tail to nullptr,
   thus restoring the list structure. The node that becomes the new head is returned.

This approach ensures that the list is rotated efficiently without the need for additional data structures.
*/
