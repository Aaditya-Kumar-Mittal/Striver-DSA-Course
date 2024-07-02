#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data;   // The data stored in the node
  Node *next; // Pointer to the next node

  // Constructor to initialize a node with data and optionally a next pointer
  Node(int data1, Node *next1 = nullptr)
  {
    data = data1;
    next = next1;
  }
};

// Function to convert an array to a linked list
Node *convertArraytoLinkedList(vector<int> &arr)
{
  if (arr.empty()) // If the array is empty, return nullptr
    return nullptr;

  Node *head = new Node(arr[0]); // Create the head node
  Node *mover = head;            // Pointer to traverse the list

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]); // Create a new node for each array element
    mover->next = temp;            // Link the new node to the list
    mover = temp;                  // Move to the next node
  }

  return head; // Return the head of the linked list
}

// Function to print the linked list
void printLinkedList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " "; // Print the data of each node
    temp = temp->next;         // Move to the next node
  }
  cout << endl;
}

// Function to remove the head node
Node *removesHead(Node *head)
{
  if (head == nullptr) // If the list is empty, return nullptr
    return nullptr;

  Node *temp = head; // Temporary pointer to the head node
  head = head->next; // Move the head pointer to the next node
  delete temp;       // Delete the old head node

  return head; // Return the new head of the list
}

// Function to remove the tail node
Node *removesTail(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;    // If the list is empty or has one node, delete it
    return nullptr; // Return nullptr for an empty list
  }

  Node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next; // Move to the second last node
  }

  delete temp->next;    // Delete the last node
  temp->next = nullptr; // Set the next of the second last node to nullptr

  return head; // Return the head of the list
}

// Function to remove the node at the kth position (1-based index)
Node *removeKthPosition(Node *head, int k)
{
  if (head == nullptr) // If the list is empty, return nullptr
    return head;

  if (k == 1)
  {
    Node *temp = head; // Temporary pointer to the head node
    head = head->next; // Move the head pointer to the next node
    delete temp;       // Delete the old head node
    return head;       // Return the new head of the list
  }

  int count = 0;
  Node *temp = head;
  Node *prev = nullptr;

  while (temp != nullptr)
  {
    count++;
    if (count == k)
    {
      prev->next = prev->next->next; // Remove the kth node
      delete temp;                   // Delete the kth node
      break;
    }
    prev = temp;
    temp = temp->next;
  }

  return head; // Return the head of the list
}

// Function to remove the first node with the specified value
Node *removeElement(Node *head, int value)
{
  if (head == nullptr) // If the list is empty, return nullptr
    return head;

  if (head->data == value)
  {
    Node *temp = head; // Temporary pointer to the head node
    head = head->next; // Move the head pointer to the next node
    delete temp;       // Delete the old head node
    return head;       // Return the new head of the list
  }

  Node *temp = head;
  Node *prev = nullptr;

  while (temp != nullptr)
  {
    if (temp->data == value)
    {
      prev->next = prev->next->next; // Remove the node with the specified value
      delete temp;                   // Delete the node with the specified value
      break;
    }
    prev = temp;
    temp = temp->next;
  }

  return head; // Return the head of the list
}

int main()
{
  // Convert an array to a linked list and perform various operations
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13};

  Node *head = convertArraytoLinkedList(arr);
  cout << "Linked list after conversion from array: ";
  printLinkedList(head);

  head = removesHead(head);
  cout << "Linked list after removing head: ";
  printLinkedList(head);

  head = removesTail(head);
  cout << "Linked list after removing tail: ";
  printLinkedList(head);

  head = removeKthPosition(head, 5);
  cout << "Linked list after removing 5th position element: ";
  printLinkedList(head);

  head = removeKthPosition(head, 1);
  cout << "Linked list after removing 1st position element: ";
  printLinkedList(head);

  head = removeKthPosition(head, 8);
  cout << "Linked list after removing 8th position element: ";
  printLinkedList(head);

  head = removeElement(head, 10);
  cout << "Linked list after removing element with value 10: ";
  printLinkedList(head);

  return 0;
}

/*
Analysis Section:

Convert Array to Linked List: This function initializes a linked list from an array. It handles the case where the array is empty and ensures the linked list is correctly formed by iterating through the array and linking nodes sequentially.
Print Linked List: This function traverses the linked list and prints each node's data. It ensures all nodes are printed correctly, ending with a newline for better readability.
Remove Head: This function removes the head node of the linked list. It checks if the list is empty and deletes the head node, updating the head pointer to the next node.
Remove Tail: This function removes the tail node of the linked list. It handles the case where the list is empty or contains only one node, updating the second last node's next pointer to null.
Remove Kth Position: This function removes the node at the kth position in the linked list. It handles the case where the list is empty, updates pointers, and ensures the node at the kth position is removed.
Remove Element: This function removes the first node with the specified value from the linked list. It checks if the list is empty, updates pointers, and deletes the node with the specified value.
Improvements:
Memory Management: Ensure proper deletion of nodes to avoid memory leaks.
Edge Case Handling: Properly handle edge cases like an empty list or single-node list.
Output Clarity: Print clear and concise messages to indicate the operations performed on the linked list.

*/