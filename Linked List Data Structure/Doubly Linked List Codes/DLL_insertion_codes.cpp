#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Node
 * @brief Represents a node in a doubly linked list.
 */
class Node
{
public:
  int data;   ///< Value stored in the node.
  Node *next; ///< Pointer to the next node in the list.
  Node *back; ///< Pointer to the previous node in the list.

  /**
   * @brief Constructor to initialize a new node.
   * @param data1 Value to be stored in the node.
   * @param next1 Pointer to the next node (default is nullptr).
   * @param back1 Pointer to the previous node (default is nullptr).
   */
  Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
  {
    data = data1;
    next = next1;
    back = back1;
  }
};

/**
 * @brief Converts an array to a doubly linked list.
 * @param arr Vector of integers to be converted into the linked list.
 * @return Pointer to the head of the newly created doubly linked list.
 */
Node *convertArraytoDoublyLinkedList(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node *head = new Node(arr[0]);
  Node *prev = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }

  return head;
}

/**
 * @brief Prints the elements of a doubly linked list.
 * @param head Pointer to the head of the linked list.
 */
void printDoublyLinkedList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << "<->";
    temp = temp->next;
  }
  cout << "X" << endl;
}

/**
 * @brief Inserts a new node before the head of the doubly linked list.
 * @param head Pointer to the head of the linked list.
 * @param val Value to be inserted.
 * @return Pointer to the new head of the linked list.
 */
Node *insertionBeforeHeadDLL(Node *head, int val)
{
  Node *newNode = new Node(val, head, nullptr);
  head->back = newNode;
  return newNode;
}

/**
 * @brief Inserts a new node after the head of the doubly linked list.
 * @param head Pointer to the head of the linked list.
 * @param val Value to be inserted.
 * @return Pointer to the head of the linked list.
 */
Node *insertionAfterHeadDLL(Node *head, int val)
{
  Node *newNode = new Node(val, head->next, head);
  head->next = newNode;
  return head;
}

/**
 * @brief Inserts a new node before the tail of the doubly linked list.
 * @param head Pointer to the head of the linked list.
 * @param val Value to be inserted.
 * @return Pointer to the head of the linked list.
 */
Node *insertionBeforeTailDLL(Node *head, int val)
{
  if (head == nullptr)
  {
    return new Node(val, nullptr, nullptr);
  }
  else if (head->next == nullptr)
  {
    Node *newNode = new Node(val, head, nullptr);
    head->back = newNode;
    return newNode;
  }
  else
  {
    Node *temp = head;

    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    Node *previous = temp->back;
    Node *newNode = new Node(val, temp, previous);
    previous->next = newNode;
    temp->back = newNode;

    return head;
  }
}

/**
 * @brief Inserts a new node before the Kth element of the doubly linked list.
 * @param head Pointer to the head of the linked list.
 * @param val Value to be inserted.
 * @param K Position before which the new node should be inserted.
 * @return Pointer to the head of the linked list.
 */
Node *insertionBeforeKthelementDLL(Node *head, int val, int K)
{
  if (K == 1)
  {
    return insertionBeforeHeadDLL(head, val);
  }

  Node *temp = head;
  int cnt = 0;

  while (temp != nullptr)
  {
    cnt++;
    if (cnt == K)
    {
      break;
    }
    temp = temp->next;
  }

  Node *prev = temp->back;
  Node *newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;

  return head;
}

/**
 * @brief Main function to demonstrate the operations on a doubly linked list.
 * @return int Exit status of the program.
 */
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

  Node *head = convertArraytoDoublyLinkedList(arr);
  cout << "Doubly Linked list after conversion from array: ";
  printDoublyLinkedList(head);

  /*
  Node *iBH = insertionBeforeHeadDLL(head, 11);
  cout << "Doubly Linked list after insertion Before Head: ";
  printDoublyLinkedList(iBH);
  */

  /*
  Node *iAH = insertionAfterHeadDLL(head, 11);
  cout << "Doubly Linked list after insertion After Head: ";
  printDoublyLinkedList(iAH);
  */

  /*
  Node *iBT = insertionBeforeTailDLL(head, 11);
  cout << "Doubly Linked list after insertion Before Tail: ";
  printDoublyLinkedList(iBT);
  */

  Node *iKT = insertionBeforeKthelementDLL(head, 11, 5);
  cout << "Doubly Linked list after insertion Before Kth element: ";
  printDoublyLinkedList(iKT);

  return 0;
}

/**
 * @brief Problem Name: Doubly Linked List Operations (Insertion)
 *
 * @details This code demonstrates the creation of a doubly linked list from an array and various insertion operations on the list.
 *          The insertion operations include inserting a node before the head, after the head, before the tail, and before a specified Kth element.
 *
 * @complexity Time Complexity:
 *             - Conversion from array to linked list: O(n), where n is the number of elements in the array.
 *             - Insertion before head or after head: O(1).
 *             - Insertion before tail: O(n) due to the need to traverse to the last node.
 *             - Insertion before Kth element: O(K), where K is the position of the node before which the new node is inserted.
 *
 * @complexity Space Complexity:
 *             - O(1) for operations, except for the space required for the nodes of the doubly linked list.
 */
