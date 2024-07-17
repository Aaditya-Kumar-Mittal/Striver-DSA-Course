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

// Brute-force approach to sort linked list of 0s, 1s, and 2s
Node *sortZeroOneTwoBrute(Node *head)
{
  Node *temp = head;
  int count0 = 0, count1 = 0, count2 = 0;

  // Count occurrences of 0s, 1s, and 2s
  while (temp != nullptr)
  {
    if (temp->data == 0)
      count0++;
    else if (temp->data == 1)
      count1++;
    else
      count2++;
    temp = temp->next;
  }

  temp = head;

  // Reassign values in the linked list based on counts
  while (temp != nullptr)
  {
    if (count0)
    {
      temp->data = 0;
      count0--;
    }
    else if (count1)
    {
      temp->data = 1;
      count1--;
    }
    else if (count2)
    {
      temp->data = 2;
      count2--;
    }
    temp = temp->next;
  }

  return head;
}

// Optimized approach to sort linked list of 0s, 1s, and 2s
Node *sortZeroOneTwoOptimized(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  // Dummy nodes to represent the start of three linked lists
  Node *zeroHead = new Node(-1);
  Node *oneHead = new Node(-1);
  Node *twoHead = new Node(-1);

  // Pointers to traverse and build the three lists
  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;

  Node *temp = head;

  // Traverse the original list and distribute nodes into three lists
  while (temp != nullptr)
  {
    if (temp->data == 0)
    {
      zero->next = temp;
      zero = temp;
    }
    else if (temp->data == 1)
    {
      one->next = temp;
      one = temp;
    }
    else if (temp->data == 2)
    {
      two->next = temp;
      two = temp;
    }
    temp = temp->next;
  }

  // Combine the three lists
  zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
  one->next = twoHead->next;
  two->next = nullptr;

  Node *newHead = zeroHead->next;

  // Free dummy nodes
  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return newHead;
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

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    arr[i] = ele;
  }

  Node *head = convertArraytoLinkedList(arr);
  cout << "Linked list after conversion from array: ";
  printLinkedList(head);

  Node *newHead = sortZeroOneTwoOptimized(head);
  printLinkedList(newHead);

  return 0;
}

/**
 * Analysis:
 *
 * Convert Array to Linked List (`convertArraytoLinkedList`):
 * - Time Complexity: O(n) - where n is the size of the array. Each element is visited once to create a linked list node.
 * - Space Complexity: O(n) - for storing n nodes in the linked list.
 *
 * Brute-force Sort (`sortZeroOneTwoBrute`):
 * - Time Complexity: O(2n) - Two passes through the list. One for counting and one for assigning values.
 * - Space Complexity: O(1) - No extra space except for counters.
 *
 * Optimized Sort (`sortZeroOneTwoOptimized`):
 * - Time Complexity: O(n) - One pass to distribute nodes into three lists and another to combine them.
 * - Space Complexity: O(1) - No extra space except for a few pointers and dummy nodes.
 */