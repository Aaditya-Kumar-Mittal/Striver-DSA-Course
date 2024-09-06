//{ Driver Code Starts

#include <bits/stdc++.h>
#include <map>
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
};

/* Function to print the linked list */
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " "; // Print the data of each node
    node = node->next;
  }
  cout << "\n";
}

// } Driver Code Ends

/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

class Solution
{
public:
  /**
   * @brief Swaps the nodes of a linked list pairwise.
   *
   * Given a linked list, this function swaps every two adjacent nodes and returns its head.
   *
   * @param head Pointer to the head of the linked list.
   * @return Node* Pointer to the new head of the modified list.
   */
  Node *pairWiseSwap(Node *head)
  {

    // If the list is empty or has only one node, return the head
    if (head == nullptr || head->next == nullptr)
      return head;

    // Dummy node to simplify edge cases
    Node *dummyNode = new Node(-1);
    dummyNode->next = head;

    Node *current = dummyNode;
    Node *p = head;
    Node *q = head->next;

    while (p != nullptr && q != nullptr)
    {

      current->next = q; // Link current node to q (second node of the pair)

      p->next = q->next; // Link p (first node) to the node after q

      q->next = p; // Link q (second node) to p, effectively swapping them

      current = p; // Move current to the next pair

      p = current->next; // Move p to the next pair

      if (p != nullptr)
        q = p->next; // Move q to the next pair
    }

    // Return the new head of the list
    return dummyNode->next;
  }
};

//{ Driver Code Starts.
int main()
{

  int t;
  cin >> t;
  cin.ignore(); // Ignore the newline character after t input

  while (t--)
  {
    vector<int> arr;
    string input;

    // Read the array of linked list elements
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
      arr.push_back(number);
    }

    // Handle empty input case
    if (arr.empty())
    {
      cout << -1 << endl; // Print -1 for empty input
      continue;
    }

    // Create the linked list from the input array
    Node *head = new Node(arr[0]);
    Node *tail = head;
    map<Node *, int> mp;
    mp[head] = head->data;
    for (int i = 1; i < arr.size(); ++i)
    {
      tail->next = new Node(arr[i]);
      tail = tail->next;
      mp[tail] = tail->data;
    }

    Node *failure = new Node(-1); // Node used to indicate failure
    Solution ob;
    head = ob.pairWiseSwap(head); // Perform the pairwise swap

    int flag = 0;
    Node *temp = head;

    // Check if the list has been modified correctly
    while (temp)
    {
      if (mp[temp] != temp->data)
      {
        flag = 1;
        break;
      }
      temp = temp->next;
    }

    // Print the failure node if the list is not correct, otherwise print the swapped list
    if (flag)
      printList(failure);
    else
      printList(head);
  }
  return 0;
}

// } Driver Code Ends

/*
Analysis:

1. **Time Complexity**:
   - **O(n)** where `n` is the number of nodes in the linked list. This is because we traverse the entire list once to perform the swaps.

2. **Space Complexity**:
   - **O(1)** extra space, as the swapping is done in place without using any additional data structures (apart from the dummy node which is constant space).

3. **Explanation**:
   - The function `pairWiseSwap` swaps every two adjacent nodes in the list.
   - A dummy node is used to handle edge cases more easily, such as when the list has an even or odd number of nodes.
   - The `main` function reads input to create a linked list, applies the pairwise swap, and then checks if the operation was successful by comparing the node values with the original values.
   - If the list is modified correctly, it is printed; otherwise, an error is indicated by printing a node with `-1`.
*/
