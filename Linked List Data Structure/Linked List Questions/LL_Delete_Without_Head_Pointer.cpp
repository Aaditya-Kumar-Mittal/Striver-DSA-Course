//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list node structure */
struct Node
{
  int data;
  Node *next;

  // Constructor to initialize a node with data and set next to NULL
  Node(int x)
  {
    data = x;
    next = NULL;
  }
} *head;

/* Function to find a node in the list */
Node *findNode(Node *head, int search_for)
{
  Node *current = head;
  while (current != NULL)
  {
    if (current->data == search_for)
      return current; // Node with the desired data found
    current = current->next;
  }
  return NULL; // Node with the desired data not found
}

/* Function to insert nodes from input */
void insert()
{
  Node *temp;
  vector<int> arr;
  string input;
  getline(cin, input); // Read the entire input line
  stringstream ss(input);
  int number;
  while (ss >> number)
  {
    arr.push_back(number); // Store input numbers in a vector
  }

  int n = arr.size();
  if (n == 0)
    return; // No elements to insert

  // Create the head of the linked list
  head = new Node(arr[0]);
  temp = head;
  for (int i = 1; i < n; i++)
  {
    temp->next = new Node(arr[i]); // Link new nodes to the list
    temp = temp->next;
  }
}

/* Function to print linked list */
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " "; // Print the data of each node
    node = node->next;
  }
  cout << endl;
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
}*head;
*/

class Solution
{
public:
  /**
   * @brief Deletes a node in the linked list without any reference to the head.
   *
   * The function assumes that the node to be deleted is not the last node
   * and that it has a valid next node.
   *
   * @param del_node Pointer to the node to be deleted.
   */
  void deleteNode(Node *del_node)
  {

    // Make a pointer to the next node of the node to be deleted
    Node *temp = del_node->next;

    // Update the value in del_node with that of the temp node
    del_node->data = temp->data;

    // Make the delete node point to temp node's next
    del_node->next = temp->next;

    // Delete the temp node to free memory
    delete temp;
  }
};

//{ Driver Code Starts.

/* Driver program to test the above function */
int main()
{
  int t, k;

  cin >> t;
  cin.ignore(); // To handle the newline character after `cin >> t`

  Solution ob;

  while (t--)
  {
    insert(); // Insert the nodes from the input
    cin >> k;
    cin.ignore(); // To handle the newline character after `cin >> k`

    Node *del = findNode(head, k); // Find the node to be deleted

    // Check if the node exists and has a valid next node
    if (del != NULL && del->next != NULL)
    {
      ob.deleteNode(del); // Delete the node
      printList(head);    // Print the updated list
    }
    else if (del == NULL)
    {
      cout << "Node with value " << k << " not found." << endl;
    }
    else
    {
      cout << "Input does not follow the custom input conditions." << endl;
    }
  }

  return 0;
}

// } Driver Code Ends

/*
Analysis:

1. **Time Complexity**:
   - **O(n)** for `findNode` function to search for the node in the list, where `n` is the number of nodes in the list.
   - **O(1)** for `deleteNode` function as it only performs a constant number of operations once the node is found.

2. **Space Complexity**:
   - **O(1)** extra space for `deleteNode` function.
   - **O(n)** space required for storing the linked list in memory, where `n` is the number of nodes.

3. **Explanation**:
   - The `findNode` function iterates through the linked list to find the node with the specified value.
   - The `deleteNode` function deletes the given node by copying the data from the next node into it and then deleting the next node.
   - In the `main` function, the linked list is built from input, and the specified node is deleted, followed by printing the modified list.
   - If the node is not found or if it does not have a next node (i.e., the last node), the appropriate message is printed.
*/
