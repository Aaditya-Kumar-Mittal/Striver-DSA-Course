#include <bits/stdc++.h>

using namespace std;

// Class definition for a Node in a linked list
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

// Function to remove the nth node from the end using two pointers
Node *removeNthFromEndTwoPointers(Node *head, int k)
{
  Node *fast = head, *slow = head; // Initialize two pointers

  // Move the fast pointer k steps ahead
  for (int i = 0; i < k; i++)
    fast = fast->next;

  // If fast reached the end, remove the head
  if (fast == nullptr)
    return head->next;

  // Move both pointers until fast reaches the end
  while (fast->next != nullptr)
  {
    fast = fast->next;
    slow = slow->next;
  }

  // Remove the target node
  Node *deleteNode = slow->next;
  slow->next = deleteNode->next;
  delete deleteNode;

  return head; // Return the head of the modified list
}

// Function to remove the nth node from the end using brute force
Node *removeNthFromEndBruteForce(Node *head, int k)
{
  Node *temp = head; // Pointer to traverse the linked list

  int count = 0; // Counter to determine the length of the list

  // Count the total number of nodes
  while (temp != nullptr)
  {
    count++;
    temp = temp->next;
  }

  // If the target node is the head
  if (count == k)
    return head->next;

  int resultant = count - k; // Calculate the position to remove

  temp = head; // Reset the temp pointer to the head

  // Traverse to the node just before the target node
  while (temp != nullptr)
  {
    resultant--;
    if (resultant == 0)
      break;
    temp = temp->next;
  }

  // Remove the target node
  Node *deleteNode = temp->next;
  temp->next = deleteNode->next;
  delete deleteNode;

  return head; // Return the head of the modified list
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

  // Remove the 5th node from the end using brute force and print the result
  Node *newHead1 = removeNthFromEndBruteForce(head1, 5);
  cout << "Linked list after removing 5th element from end using brute force: ";
  printLinkedList(newHead1);

  // Remove the 5th node from the end using brute force and print the result
  Node *newHead2 = removeNthFromEndBruteForce(head2, 5);
  cout << "Linked list after removing 5th element from end using brute force: ";
  printLinkedList(newHead2);

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
 * 3. `removeNthFromEndTwoPointers`:
 *    - Time Complexity: O(n) where n is the number of nodes in the linked list.
 *    - Space Complexity: O(1).
 *
 * 4. `removeNthFromEndBruteForce`:
 *    - Time Complexity: O(n) where n is the number of nodes in the linked list.
 *    - Space Complexity: O(1).
 *
 * The main function demonstrates the creation of linked lists from arrays, printing them, and removing the nth node from the end using different methods. Each method's performance in terms of time and space complexity is also outlined for better understanding and comparison.
 */
