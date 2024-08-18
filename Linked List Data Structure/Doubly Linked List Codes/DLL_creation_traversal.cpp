#include <iostream>
#include <vector>

using namespace std;

// Node class represents a single node in a doubly linked list
class Node
{
public:
  int data;    // Value stored in the node
  Node *next;  // Pointer to the next node in the list
  Node *back;  // Pointer to the previous node in the list

  // Constructor to initialize a new node with given data, next, and back pointers
  Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
  {
    data = data1;
    next = next1;
    back = back1;
  }
};

// Function to convert an array to a doubly linked list
Node *convertArraytoDoublyLinkedList(vector<int> &arr)
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
void printDoublyLinkedList(Node *head)
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
  Node *head = convertArraytoDoublyLinkedList(arr);
  cout << "Linked list after conversion from array: ";
  printDoublyLinkedList(head); // Print the resulting linked list

  return 0;
}

/*
 * Problem Name: Doubly Linked List Conversion and Printing
 *
 * Analysis:
 * - The code implements the conversion of an array into a doubly linked list and prints the list.
 * - Each node in the list has a reference to both the next and the previous node, allowing traversal in both directions.
 *
 * Time Complexity:
 * - Conversion from array to linked list: O(n), where n is the number of elements in the array.
 * - Printing the linked list: O(n), as it requires traversal of all nodes in the list.
 *
 * Space Complexity:
 * - O(1) for operations, except the space required for the new nodes being created in the linked list.
 */
