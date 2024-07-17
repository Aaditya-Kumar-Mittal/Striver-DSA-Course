
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

// Brute-force approach to segregate odd and even indexed nodes
Node *segregateOddEvenBrute(Node *head)
{
  vector<int> arr; // Vector to store node values

  Node *odd = head;

  // Traverse the list and collect odd indexed nodes
  while (odd != nullptr && odd->next != nullptr)
  {
    arr.push_back(odd->data);
    odd = odd->next->next;
  }

  if (odd)
    arr.push_back(odd->data);

  Node *even = head->next;

  // Traverse the list and collect even indexed nodes
  while (even != nullptr && even->next != nullptr)
  {
    arr.push_back(even->data);
    even = even->next->next;
  }

  if (even)
    arr.push_back(even->data);

  int i = 0;
  Node *temp = head;

  // Reassign values in the linked list based on the collected values
  while (temp != nullptr)
  {
    temp->data = arr[i];
    i++;
    temp = temp->next;
  }

  return head;
}

// Optimized approach to segregate odd and even indexed nodes
Node *segregateOddEvenOptimized(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *odd = head, *even = head->next;
  Node *evenHead = even; // Memoization of even head

  // Traverse the list and rearrange nodes
  while (even != nullptr && even->next != nullptr)
  {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }

  odd->next = evenHead; // Link odd list to even list

  return head;
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

  Node *newHead = segregateOddEvenOptimized(head);
  cout << "Linked List after segregating odd and even nodes: ";
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
 * Brute-force Segregation (`segregateOddEvenBrute`):
 * - Time Complexity: O(n) - Two passes through the list. One for collecting odd/even nodes and another for assigning values.
 * - Space Complexity: O(n) - for storing node values in the vector.
 *
 * Optimized Segregation (`segregateOddEvenOptimized`):
 * - Time Complexity: O(n) - One pass to rearrange nodes.
 * - Space Complexity: O(1) - No extra space except for a few pointers.
 */