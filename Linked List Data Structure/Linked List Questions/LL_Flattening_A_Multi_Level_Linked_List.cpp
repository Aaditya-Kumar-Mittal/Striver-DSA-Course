//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure used in the linked list
struct Node
{
  int data;            // Data field to store the value of the node
  struct Node *next;   // Pointer to the next node in the main linked list (rightward list)
  struct Node *bottom; // Pointer to the bottom node (downward list)

  // Constructor to initialize a new node
  Node(int x)
  {
    data = x;
    next = NULL;   // Initialize next pointer to NULL
    bottom = NULL; // Initialize bottom pointer to NULL
  }
};

// Function to print the linked list (used for validation)
void printList(Node *Node)
{
  while (Node != NULL)
  {                            // Traverse the bottom pointers to print the linked list
    printf("%d ", Node->data); // Print the data of the current node
    Node = Node->bottom;       // Move to the bottom node
  }
  printf("\n"); // Newline after printing the list
}

// } Driver Code Ends
/* Node structure  used in the program:

struct Node{
    int data;
    struct Node * next;   // Pointer to the next list
    struct Node * bottom; // Pointer to the bottom list

    Node(int x){   // Constructor
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution
{
public:
  // Helper function to merge two sorted linked lists with 'bottom' pointers
  Node *mergeTwoLinkedLists(Node *l1, Node *l2)
  {
    // Dummy node to act as the head of the merged list
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    // Merge two sorted linked lists
    while (l1 != nullptr && l2 != nullptr)
    {
      // If l1's data is smaller, append it to the result list
      if (l1->data < l2->data)
      {
        res->bottom = l1; // Append l1 to the result list
        res = l1;         // Move the result pointer to l1
        l1 = l1->bottom;  // Move l1 to the next node
      }
      else
      {
        // Otherwise, append l2 to the result list
        res->bottom = l2;
        res = l2;
        l2 = l2->bottom;
      }
      // Clear the 'next' pointer of the result node to prevent unexpected issues
      res->next = nullptr;
    }

    // Append the remaining nodes (if any) from l1 or l2
    if (l1)
      res->bottom = l1;
    else
      res->bottom = l2;

    return dummyNode->bottom; // Return the merged list, starting from dummyNode's next
  }

  // Function to flatten the multilevel linked list
  Node *flatten(Node *root)
  {
    // Base case: if root is NULL or there is only one list, return the root
    if (root == nullptr || root->next == nullptr)
      return root;

    // Recursively flatten the list on the right side
    Node *secondRoot = flatten(root->next);

    // Merge the current root list with the flattened list on the right
    return mergeTwoLinkedLists(root, secondRoot);
  }
};

//{ Driver Code Starts.
int main()
{
  int t;    // Number of test cases
  cin >> t; // Read the number of test cases
  while (t--)
  {
    int n; // Number of linked lists
    vector<int> work;

    // Read the entire line for the array elements
    string input;
    getline(cin, input);    // Consume leftover newline
    getline(cin, input);    // Read the actual array input
    stringstream ss(input); // String stream to parse the input
    int number;
    while (ss >> number)
    {                         // Read the integers from the input
      work.push_back(number); // Store them in the vector
    }
    n = work.size(); // Number of elements in the input array

    Node *head = NULL; // Pointer to the head of the list of lists
    Node *pre = NULL;  // Pointer to keep track of the previous list

    for (int i = 0; i < n; i++)
    {
      int m = work[i] - 1; // Number of bottom nodes
      int data;
      cin >> data; // Read the first data element for the current list

      // Create a new node and link it to the main list
      Node *temp = new Node(data);
      if (head == NULL)
      {
        head = temp;
        pre = temp;
      }
      else
      {
        pre->next = temp; // Link the previous node's next pointer to the new node
        pre = temp;
      }

      Node *preB = temp; // Pointer to keep track of the bottom nodes
      for (int j = 0; j < m; j++)
      {
        int temp_data;
        cin >> temp_data; // Read the data for the bottom node
        Node *tempB = new Node(temp_data);
        preB->bottom = tempB; // Link the current bottom node
        preB = tempB;         // Move to the next bottom node
      }
    }

    // Solution object to call the flatten function
    Solution ob;
    Node *root = ob.flatten(head); // Flatten the list of lists
    printList(root);               // Print the flattened list
  }
  return 0;
}
// } Driver Code Ends

/*
ANALYSIS:

Problem:
The problem is to flatten a multi-level linked list, where each node has a pointer to the next node and another pointer to the bottom node. The linked lists are sorted individually, and the final flattened list should be sorted as well.

Approach:
1. **Flattening Recursively**: We flatten the right-side linked list (`next` pointer) recursively.
2. **Merging Lists**: After flattening the right-side list, we merge it with the current linked list using the `bottom` pointer to maintain the sorted order.
3. **Merging Two Lists**: The merging is done using a two-pointer technique similar to merging two sorted arrays.

Time Complexity:
- **mergeTwoLinkedLists**: This function takes O(m + n) where m and n are the sizes of the two lists being merged.
- **flatten**: This function is called recursively, so the total time complexity is O(N), where N is the total number of nodes in all the lists combined.

Space Complexity:
- The space complexity is O(1) in terms of auxiliary space for merging (since we do it in-place).
- Recursion uses O(log K) space for function call stack, where K is the number of linked lists.

Edge Cases:
1. **Empty List**: If the root or its next pointer is `NULL`, we return the root immediately.
2. **Single Node Lists**: If there are no bottom nodes or only one node in a list, it is considered flattened.
3. **Unequal Lists**: Handles cases where the lists have different lengths.

This approach ensures that the final list is both flattened and sorted.
*/
