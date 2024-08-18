#include <iostream>
#include <vector>

using namespace std;

// Node class represents a single node in a doubly linked list
class Node
{
public:
  int data;   // Value stored in the node
  Node *next; // Pointer to the next node in the list
  Node *back; // Pointer to the previous node in the list

  // Constructor to initialize a new node with given data, next, and back pointers
  Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
  {
    data = data1;
    next = next1;
    back = back1;
  }
};

// Function to convert an array to a doubly linked list
Node *convertArraytoLinkedList(vector<int> &arr)
{
  if (arr.empty())
    return nullptr; // Return null if the array is empty

  // Initialize the head of the linked list
  Node *head = new Node(arr[0]);

  // Pointer to keep track of the previous node
  Node *prev = head;

  // Iterate over the array and create linked list nodes
  for (int i = 1; i < arr.size(); i++)
  {
    // Create a new node with a pointer to the previous node
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp; // Link the previous node to the current node
    prev = temp;       // Update the previous node pointer
  }

  return head; // Return the head of the linked list
}

// Function to print the doubly linked list
void printLinkedList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << "<->"; // Print the value of each node and the link
    temp = temp->next;           // Move to the next node
  }
  cout << "X"; // Indicate the end of the list
  cout << endl;
}

// Function to delete the head of the doubly linked list
Node *deleteHeadOfDLL(Node *head)
{
  // If the list is empty or has only one element, return null
  if (head == nullptr || head->next == nullptr)
  {
    return nullptr;
  }

  Node *prev = head;    // Store the current head
  head = head->next;    // Move the head to the next node
  head->back = nullptr; // Update the back pointer of the new head
  prev->next = nullptr; // Detach the old head from the list

  delete prev; // Delete the old head to free memory

  return head; // Return the new head
}

// Function to delete the tail of the doubly linked list
Node *deleteTailofDLL(Node *head)
{
  // If the list is empty or has only one element, return null
  if (head == nullptr || head->next == nullptr)
  {
    return nullptr;
  }

  Node *tail = head;

  // Traverse to the last node (tail)
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }

  Node *newTail = tail->back; // Get the previous node (new tail)
  newTail->next = nullptr;    // Update the next pointer of the new tail

  tail->back = nullptr; // Detach the old tail from the list

  delete tail; // Delete the old tail to free memory

  return head; // Return the head of the list
}

// Function to delete the Kth element in the doubly linked list
Node *deleteKthElementofDLL(Node *head, int K)
{
  if (head == nullptr)
  {
    return nullptr; // Return null if the list is empty
  }

  int count = 0;

  Node *KThNode = head;

  // Traverse to the Kth node
  while (KThNode != nullptr)
  {
    count++;

    if (K == count)
    {
      break; // Stop when the Kth node is found
    }

    KThNode = KThNode->next;
  }

  Node *prev = KThNode->back;
  Node *front = KThNode->next;

  // Case 1: Single node in the list
  if (prev == nullptr && front == nullptr)
  {
    return nullptr; // Return null if the list has only one node
  }
  // Case 2: Deleting the head (K == 1)
  else if (prev == nullptr)
  {
    return deleteHeadOfDLL(head); // Call the function to delete the head
  }
  // Case 3: Deleting the tail (K == last element)
  else if (front == nullptr)
  {
    return deleteTailofDLL(head); // Call the function to delete the tail
  }
  else
  {
    // General case: Deleting a node in the middle
    prev->next = front;
    front->back = prev;

    KThNode->next = nullptr;
    KThNode->back = nullptr;

    delete KThNode; // Delete the Kth node to free memory

    return head; // Return the head of the list
  }
}

int main()
{
  int n;

  cin >> n;

  vector<int> arr(n);

  // Input array elements from the user
  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    arr[i] = ele;
  }

  // Convert array to linked list
  Node *head = convertArraytoLinkedList(arr);
  cout << "Linked list after conversion from array: ";
  printLinkedList(head); // Print the resulting linked list

  /*
  Node *deletionHead = deleteHeadOfDLL(head);
  cout << "Linked list after deletion of its head: ";
  printLinkedList(deletionHead);
  */

  /*
  Node *deleteTail = deleteTailofDLL(deletionHead);
  std::cout << "Linked List after deletion of its tail : ";
  printLinkedList(deleteTail);
  */

  Node *deleteKth = deleteKthElementofDLL(head, 5);
  std::cout << "Linked List after deletion of Kth Element : ";
  printLinkedList(deleteKth); // Print the list after deleting the Kth element

  return 0;
}

/*
 * Problem Name: Doubly Linked List Operations (Deletion)
 *
 * Analysis:
 * - This code demonstrates the creation of a doubly linked list from an array and various deletion operations on the list.
 * - Deletion operations include deleting the head, tail, and a specific Kth node.
 *
 * Time Complexity:
 * - Conversion from array to linked list: O(n), where n is the number of elements in the array.
 * - Deletion of the head node: O(1).
 * - Deletion of the tail node: O(n) due to the need to traverse to the last node.
 * - Deletion of the Kth node: O(n), where n is the position of the node to be deleted.
 *
 * Space Complexity:
 * - O(1) for operations, except for the space required for the nodes of the doubly linked list.
 */
