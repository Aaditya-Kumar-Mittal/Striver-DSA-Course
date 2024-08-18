#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *back;

  Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
  {
    data = data1;
    next = next1;
    back = back1;
  }
};

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

  return 0;
}
