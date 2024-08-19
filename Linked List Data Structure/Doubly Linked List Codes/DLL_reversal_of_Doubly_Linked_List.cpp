#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Class representing a node in a doubly linked list.
 */
class Node
{
public:
  int data;   // Data stored in the node
  Node *next; // Pointer to the next node
  Node *prev; // Pointer to the previous node

  /**
   * @brief Constructor to initialize a node.
   *
   * @param data1 Data to be stored in the node.
   * @param next1 Pointer to the next node (default is nullptr).
   * @param prev1 Pointer to the previous node (default is nullptr).
   */
  Node(int data1, Node *next1 = nullptr, Node *prev1 = nullptr)
  {
    data = data1;
    next = next1;
    prev = prev1;
  }
};

/**
 * @brief Converts an array to a doubly linked list.
 *
 * @param arr Reference to the input array.
 * @return Node* Pointer to the head of the doubly linked list.
 */
Node *convertArraytoDoublyLinkedList(vector<int> &arr)
{
  // If the array is empty, return a nullptr.
  if (arr.empty())
    return nullptr;

  // Create the head node.
  Node *head = new Node(arr[0]);

  // Pointer to keep track of the previous node.
  Node *back = head;

  // Loop through the array to create and link the nodes.
  for (int i = 1; i < arr.size(); i++)
  {
    // Create a new node with the current element.
    Node *temp = new Node(arr[i], nullptr, back);
    back->next = temp; // Link the previous node to the current node.
    back = temp;       // Move the 'back' pointer to the current node.
  }

  // Return the head of the doubly linked list.
  return head;
}

/**
 * @brief Prints the doubly linked list.
 *
 * @param head Pointer to the head of the doubly linked list.
 */
void printDoublyLinkedList(Node *head)
{
  Node *temp = head;

  // Traverse through the list and print the data.
  while (temp)
  {
    cout << temp->data << "<->";
    temp = temp->next;
  }
  cout << "X";
  cout << endl;
}

/**
 * @brief Reverses a doubly linked list using a naive approach (by using a stack).
 *
 * @param head Pointer to the head of the doubly linked list.
 * @return Node* Pointer to the head of the reversed doubly linked list.
 */
Node *reverseDoublyLinkedListNaive(Node *head)
{
  // Handle cases where the list is empty or has only one node.
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  stack<int> store; // Stack to store the node values.

  Node *temp = head;

  // Traverse through the list and push each node's data onto the stack.
  while (temp != nullptr)
  {
    store.push(temp->data);
    temp = temp->next;
  }

  temp = head;

  // Pop the data from the stack and overwrite the original data in the list.
  while (temp != nullptr)
  {
    temp->data = store.top();
    store.pop();
    temp = temp->next;
  }

  return head; // Return the head of the reversed list.
}

/**
 * @brief Reverses a doubly linked list using an optimized approach (by swapping pointers).
 *
 * @param head Pointer to the head of the doubly linked list.
 * @return Node* Pointer to the head of the reversed doubly linked list.
 */
Node *reverseDoublyLinkedListOptimized(Node *head)
{
  // Handle cases where the list is empty or has only one node.
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *last = nullptr; // Pointer to keep track of the last node visited.
  Node *current = head; // Pointer to traverse the list.

  // Traverse through the list and swap the next and prev pointers.
  while (current != nullptr)
  {
    last = current->prev;          // Store the previous node.
    current->prev = current->next; // Swap the next and prev pointers.
    current->next = last;          // Swap the next and prev pointers.
    current = current->prev;       // Move to the next node (which is the previous node due to the swap).
  }

  // The last node visited will be the new head after reversal.
  return last->prev;
}

/**
 * @brief Main function to drive the program.
 *
 * @return int Exit status of the program.
 */
int main()
{
  int n;
  cin >> n; // Input the size of the array.

  vector<int> arr(n); // Vector to store the input array.

  // Input the array elements.
  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    arr[i] = ele;
  }

  // Convert the array to a doubly linked list.
  Node *head = convertArraytoDoublyLinkedList(arr);
  cout << "Doubly Linked list after conversion from array: ";
  printDoublyLinkedList(head);

  // Reverse the doubly linked list using the naive approach.
  Node *reverseDLLNaive = reverseDoublyLinkedListNaive(head);
  cout << "Doubly Linked list after reversal (Naive): ";
  printDoublyLinkedList(reverseDLLNaive);

  // Reverse the doubly linked list using the optimized approach.
  Node *reverseDLLOptmized = reverseDoublyLinkedListOptimized(reverseDLLNaive);
  cout << "Doubly Linked list after reversal (Optimized): ";
  printDoublyLinkedList(reverseDLLOptmized);

  return 0;
}

/*
 * Analysis of the Code:
 *
 * Problem Name: Reverse a Doubly Linked List
 *
 * Description:
 * - The code demonstrates two approaches to reverse a doubly linked list.
 *   The first approach (naive) uses a stack to store the values of the nodes,
 *   and then overwrites the original list with these values.
 *   The second approach (optimized) swaps the `next` and `prev` pointers of each
 *   node to reverse the list in place.
 *
 * Naive Approach:
 * - Time Complexity: O(2N)
 *   - First traversal: Each node's value is pushed into the stack, which takes O(N) time.
 *   - Second traversal: The values are popped from the stack and used to update the nodes.
 * - Space Complexity: O(N)
 *   - The space complexity is proportional to the number of nodes because of the stack used
 *     to store the node values.
 *
 * Optimized Approach:
 * - Time Complexity: O(N)
 *   - The list is traversed only once to swap the pointers, so the time complexity is linear
 *     with respect to the number of nodes.
 * - Space Complexity: O(1)
 *   - The reversal is done in place, so no extra space is used apart from a few pointers.
 *
 * This analysis helps in understanding the trade-offs between the two methods in terms of time
 * and space efficiency.
 */