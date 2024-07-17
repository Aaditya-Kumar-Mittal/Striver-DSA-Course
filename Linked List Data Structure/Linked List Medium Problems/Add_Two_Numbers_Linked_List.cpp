#include <iostream>
#include <vector>

using namespace std;

// Definition of Node class for linked list
class Node
{
public:
  int data;
  Node *next;

  // Constructor to initialize node
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
  Node *mover = head;            // Mover node to traverse and build the list

  // Iterate over the array starting from the second element
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]); // Create a new node for each element
    mover->next = temp;            // Link the new node to the list
    mover = temp;                  // Move to the new node
  }

  return head; // Return the head of the linked list
}

// Function to print the linked list
void printLinkedList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Function to add two numbers represented by linked lists
Node *addTwoNumbers(Node *head1, Node *head2)
{
  Node *t1 = head1, *t2 = head2;
  Node *dummyNode = new Node(-1); // Dummy node to handle result list
  Node *currentNode = dummyNode;  // Pointer to build the result list
  int carry = 0;                  // Initialize carry

  // Traverse both linked lists
  while (t1 != nullptr || t2 != nullptr)
  {
    int sum = carry;

    if (t1)
      sum += t1->data;

    if (t2)
      sum += t2->data;

    Node *newNode = new Node(sum % 10); // Create a new node with the digit
    carry = sum / 10;                   // Update carry

    currentNode->next = newNode; // Link the new node to the result list
    currentNode = newNode;       // Move to the new node

    if (t1)
      t1 = t1->next;

    if (t2)
      t2 = t2->next;
  }

  // If there is a carry left, add a new node with carry value
  if (carry)
  {
    Node *newNode = new Node(carry);
    currentNode->next = newNode;
  }

  return dummyNode->next; // Return the result list head
}

int main()
{
  int n, m;

  cin >> n >> m;

  vector<int> arr1(n), arr2(m);

  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    arr1[i] = ele;
  }

  for (int i = 0; i < m; i++)
  {
    int ele;
    cin >> ele;
    arr2[i] = ele;
  }

  Node *head1 = convertArraytoLinkedList(arr1);
  cout << "Linked list after conversion from array-1: ";
  printLinkedList(head1);

  Node *head2 = convertArraytoLinkedList(arr2);
  cout << "Linked list after conversion from array-2: ";
  printLinkedList(head2);

  Node *sumList = addTwoNumbers(head1, head2);
  cout << "Addition of Two Numbers using Linked List yields a sum: ";
  printLinkedList(sumList);

  return 0;
}

/**
 * Analysis:
 *
 * Convert Array to Linked List (`convertArraytoLinkedList`):
 * - Time Complexity: O(n) - where n is the size of the array. Each element is visited once to create a linked list node.
 * - Space Complexity: O(n) - for storing n nodes in the linked list.
 *
 * Print Linked List (`printLinkedList`):
 * - Time Complexity: O(n) - where n is the number of nodes in the linked list. Each node is visited once.
 * - Space Complexity: O(1) - only a few pointers are used for traversal.
 *
 * Add Two Numbers (`addTwoNumbers`):
 * - Time Complexity: O(max(n, m)) - where n and m are the lengths of the two linked lists. Each node from both lists is visited once.
 * - Space Complexity: O(max(n, m)) - for storing the result linked list, which can be as long as the longer input list plus one additional node for carry.
 */
