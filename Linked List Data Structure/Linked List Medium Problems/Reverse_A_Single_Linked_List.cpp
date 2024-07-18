#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;   // Data to be stored in the node
  Node *next; // Pointer to the next node in the linked list

  // Constructor to initialize the node with data and optional next pointer
  Node(int data1, Node *next1 = nullptr)
  {
    data = data1;
    next = next1;
  }
};

// Function to convert a vector to a linked list
Node *convertArraytoLinkedList(vector<int> &arr)
{
  if (arr.empty()) // If the array is empty, return null pointer
    return nullptr;

  Node *head = new Node(arr[0]); // Create the head node with the first element
  Node *mover = head;            // Pointer to traverse the linked list

  // Iterate over the array starting from the second element
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]); // Create a new node for each element
    mover->next = temp;            // Link the previous node to the new node
    mover = temp;                  // Move the pointer to the new node
  }

  return head; // Return the head of the linked list
}

// Function to print the linked list
void printLinkedList(Node *head)
{
  Node *temp = head; // Pointer to traverse the linked list
  while (temp)
  {                            // Traverse until the end of the linked list
    cout << temp->data << " "; // Print the data of the current node
    temp = temp->next;         // Move to the next node
  }
  cout << endl; // Print a new line at the end
}

// Function to reverse the linked list iteratively
Node *reverseLinkedListIteratively(Node *head)
{
  if (head == nullptr || head->next == nullptr) // If the list is empty or has one node, return head
    return head;

  Node *prev = nullptr, *temp = head; // Initialize pointers

  // Iterate over the linked list
  while (temp != nullptr)
  {
    Node *front = temp->next; // Store the next node
    temp->next = prev;        // Reverse the current node's pointer
    prev = temp;              // Move prev to the current node
    temp = front;             // Move temp to the next node
  }
  delete temp;
  return prev; // Return the new head of the reversed linked list
}

// Function to reverse the linked list recursively
Node *reverseLinkedListRecursively(Node *head)
{
  if (head == nullptr || head->next == nullptr) // If the list is empty or has one node, return head
    return head;

  Node *newHead = reverseLinkedListRecursively(head->next); // Recursively reverse the rest of the list

  Node *front = head->next; // Store the next node
  front->next = head;       // Reverse the current node's pointer
  head->next = nullptr;     // Set the current node's next pointer to null

  return newHead; // Return the new head of the reversed linked list
}

// Function to reverse the linked list using a stack
Node *reverseLinkedListUsingStack(Node *head)
{
  if (head == nullptr || head->next == nullptr) // If the list is empty or has one node, return head
    return head;

  stack<int> stk; // Stack to store the node data

  Node *temp = head; // Pointer to traverse the linked list

  // Push the data of each node onto the stack
  while (temp != nullptr)
  {
    stk.push(temp->data);
    temp = temp->next;
  }

  temp = head; // Reset the temp pointer to the head

  // Pop the data from the stack and update the nodes
  while (temp != nullptr)
  {
    temp->data = stk.top();
    stk.pop();
    temp = temp->next;
  }

  return head; // Return the head of the linked list
}

int main()
{
  int n, m;
  cin >> n >> m; // Input the sizes of two arrays

  vector<int> arr1(n), arr2(m); // Declare two vectors

  // Input the elements of the first array
  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    arr1[i] = ele;
  }

  // Input the elements of the second array
  for (int i = 0; i < m; i++)
  {
    int ele;
    cin >> ele;
    arr2[i] = ele;
  }

  // Convert the first array to a linked list and print it
  Node *head1 = convertArraytoLinkedList(arr1);
  cout << "Linked list after conversion from array-1: ";
  printLinkedList(head1);

  // Convert the second array to a linked list and print it
  Node *head2 = convertArraytoLinkedList(arr2);
  cout << "Linked list after conversion from array-2: ";
  printLinkedList(head2);

  // Convert the second array to another linked list and print it (to be used for stack reversal)
  Node *head3 = convertArraytoLinkedList(arr2);
  cout << "Linked list after conversion from array-3: ";
  printLinkedList(head3);

  // Reverse the first linked list iteratively and print it
  Node *newHead1 = reverseLinkedListIteratively(head1);
  cout << "Reversing the Linked List Iteratively: " << endl;
  printLinkedList(newHead1);

  // Reverse the second linked list recursively and print it
  Node *newHead2 = reverseLinkedListRecursively(head2);
  cout << "Reversing the Linked List Recursively: " << endl;
  printLinkedList(newHead2);

  // Reverse the third linked list using a stack and print it
  Node *newHead3 = reverseLinkedListUsingStack(head3);
  cout << "Reversing the Linked List Using Stack: " << endl;
  printLinkedList(newHead3);

  return 0;
}

/**
 * Analysis:
 *
 * 1. `convertArraytoLinkedList`:
 *    - Time Complexity: O(n) where n is the number of elements in the array.
 *    - Space Complexity: O(n) for the linked list nodes.
 *
 * 2. `printLinkedList`:
 *    - Time Complexity: O(n) where n is the number of nodes in the linked list.
 *    - Space Complexity: O(1).
 *
 * 3. `reverseLinkedListIteratively`:
 *    - Time Complexity: O(n) where n is the number of nodes in the linked list.
 *    - Space Complexity: O(1).
 *
 * 4. `reverseLinkedListRecursively`:
 *    - Time Complexity: O(n) where n is the number of nodes in the linked list.
 *    - Space Complexity: O(n) due to the recursion stack.
 *
 * 5. `reverseLinkedListUsingStack`:
 *    - Time Complexity: O(n) where n is the number of nodes in the linked list.
 *    - Space Complexity: O(n) for the stack.
 *
 * The main function demonstrates the creation of linked lists from arrays, printing them, and reversing them using different methods. Each method's performance in terms of time and space complexity is also outlined for better understanding and comparison.
 */