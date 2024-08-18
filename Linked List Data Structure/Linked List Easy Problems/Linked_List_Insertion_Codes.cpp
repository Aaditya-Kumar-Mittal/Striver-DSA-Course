#include <bits/stdc++.h>

using namespace std;

// Node class represents a single node in a linked list
class Node
{
public:
  int data;   // Value stored in the node
  Node *next; // Pointer to the next node in the list

  // Constructor to initialize a new node
  Node(int data1, Node *next1 = nullptr)
  {
    data = data1;
    next = next1;
  }
};

// Function to convert an array to a linked list
Node *convertArraytoLinkedList(vector<int> &arr)
{
  if (arr.empty())
    return nullptr; // Return null if the array is empty

  // Initialize the head of the linked list
  Node *head = new Node(arr[0]);
  Node *mover = head;

  // Iterate over the array and create linked list nodes
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }

  return head; // Return the head of the linked list
}

// Function to print the linked list
void printLinkedList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " "; // Print the value of each node
    temp = temp->next;
  }
  cout << endl; // Print a newline at the end
}

// Function to insert a node at the head of the linked list
Node *insertionatHead(Node *head, int value)
{
  Node *temp = new Node(value, head); // Create a new node pointing to the current head

  return temp; // Return the new head
}

// Function to insert a node at the tail of the linked list
Node *insertionAtTail(Node *head, int value)
{
  if (head == nullptr)
  {
    return new Node(value); // If the list is empty, return the new node as the head
  }

  Node *temp = head;
  Node *newNode = new Node(value); // Create the new node

  // Traverse to the end of the list
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }

  temp->next = newNode; // Link the last node to the new node

  return head; // Return the head of the list
}

// Function to insert a node at the Kth position in the linked list
Node *insertionatKthPosition(Node *head, int value, int K)
{
  // If the linked list is empty and K is 1, insert at head
  if (head == nullptr)
  {
    if (K == 1)
    {
      return new Node(value);
    }
    else
    {
      return nullptr; // Invalid position if K is greater than 1
    }
  }

  if (K == 1)
  {
    Node *temp = new Node(value, head); // Insert at head
    return temp;
  }

  int count = 0;
  Node *temp = head;

  // Traverse to the K-1 position
  while (temp != nullptr)
  {
    count++;

    if (count == K - 1)
    {
      Node *newNode = new Node(value);
      newNode->next = temp->next;
      temp->next = newNode; // Insert the new node at the Kth position
      break;
    }

    temp = temp->next;
  }

  return head; // Return the head of the list
}

// Function to insert a node before a given value in the linked list
Node *insertionBeforeAGivenValue(Node *head, int value, int eleVal)
{
  if (head == nullptr)
  {
    return nullptr; // Return null if the list is empty
  }

  if (head->data == eleVal)
  {
    Node *temp = new Node(value, head); // Insert before the head if the value matches
    return temp;
  }

  Node *temp = head;

  // Traverse to find the node before the target value
  while (temp != nullptr)
  {
    if (temp->next != nullptr && temp->next->data == eleVal)
    {
      Node *newNode = new Node(value, temp->next);
      temp->next = newNode; // Insert the new node before the target value
      break;
    }

    temp = temp->next;
  }

  return head; // Return the head of the list
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

  Node *head3 = insertionatHead(head1, 25);
  cout << "Linked List after insertion at head: " << endl;
  printLinkedList(head3);

  Node *head4 = insertionAtTail(head2, 289);
  cout << "Linked List after insertion at tail: " << endl;
  printLinkedList(head4);

  Node *head5 = insertionatKthPosition(head2, 25, 5);
  cout << "Linked List after insertion at Kth Position: " << endl;
  printLinkedList(head5);

  Node *head6 = insertionatKthPosition(head2, 25, 18);
  cout << "Linked List after insertion at Kth Position: " << endl;
  printLinkedList(head6);

  Node *head7 = insertionBeforeAGivenValue(head2, 26, 1);
  cout << "Linked List after insertion before Given Value: " << endl;
  printLinkedList(head7);

  Node *head8 = insertionBeforeAGivenValue(head2, 256, 10);
  cout << "Linked List after insertion before Given Value: " << endl;
  printLinkedList(head8);

  return 0;
}

/*
 * Problem Name: Linked List Operations (Insertion)
 *
 * Analysis:
 * - The code implements basic operations on a singly linked list such as insertion at the head,
 *   tail, Kth position, and before a given value. It also includes a utility to convert an array
 *   into a linked list.
 *
 * Time Complexity:
 * - Conversion from array to linked list: O(n), where n is the number of elements in the array.
 * - Insertion at the head: O(1), as it only involves creating a new node and pointing it to the current head.
 * - Insertion at the tail: O(n), where n is the number of nodes in the linked list, as it requires traversal to the end.
 * - Insertion at the Kth position: O(K), where K is the position, as it requires traversal to the K-1 node.
 * - Insertion before a given value: O(n), where n is the number of nodes, as it may require traversal of the entire list.
 *
 * Space Complexity:
 * - O(1) for all operations, except the space required for the new nodes being inserted.
 */
