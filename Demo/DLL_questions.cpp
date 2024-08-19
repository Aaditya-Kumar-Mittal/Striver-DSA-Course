#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data1, Node *next1 = nullptr, Node *prev1 = nullptr)
  {
    data = data1;
    next = next1;
    prev = prev1;
  }
};

Node *convertArraytoDoublyLinkedList(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node *head = new Node(arr[0]);

  Node *back = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, back);
    back->next = temp;
    back = temp;
  }

  return head;
}

void printDoublyLinkedList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << "<->";
    temp = temp->next;
  }
  cout << "X";
  cout << endl;
}

Node *reverseDoublyLinkedListNaive(Node *head)
{

  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  stack<int> store;

  Node *temp = head;

  while (temp != nullptr)
  {
    store.push(temp->data);

    temp = temp->next;
  }

  temp = head;

  while (temp != nullptr)
  {

    temp->data = store.top();

    store.pop();

    temp = temp->next;
  }

  return head;
}
Node *reverseDoublyLinkedListOptimized(Node *head)
{

  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *last = nullptr;

  Node *current = head;

  while (current != nullptr)
  {
    last = current->prev;

    current->prev = current->next;

    current->next = last;

    current = current->prev;
  }

  return last->prev;
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

  Node *head = convertArraytoDoublyLinkedList(arr);
  cout << "Doubly Linked list after conversion from array: ";
  printDoublyLinkedList(head);

  Node *reverseDLLNaive = reverseDoublyLinkedListNaive(head);
  cout << "Doubly Linked list after reversal : ";
  printDoublyLinkedList(reverseDLLNaive);

  Node *reverseDLLOptmized = reverseDoublyLinkedListOptimized(reverseDLLNaive);
  cout << "Doubly Linked list after reversal : ";
  printDoublyLinkedList(reverseDLLOptmized);

  return 0;
}

/*
Anaylsis of the Code

Time Complexity : O(2N) During the first traversal, each node's value is pushed into the stack once, which requires O(N) time. Then, during the second iteration, the values are popped from the stack and used to update the nodes. Space Complexity : O(N) This is because we are using an external stack data structure. At the end of the first iteration, the stack will hold all N values of the doubly linked list therefore the space required for stack is directly proportional to the size of the input doubly linked list.

Time Complexity : O(N) We only have to traverse the doubly linked list once, hence our time complexity is O(N).

Space Complexity : O(1), as the reversal is done in place.


*/