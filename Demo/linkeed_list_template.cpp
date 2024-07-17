#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data1, Node *next1 = nullptr)
  {
    data = data1;
    next = next1;
  }
};

Node *convertArraytoLinkedList(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node *head = new Node(arr[0]);
  Node *mover = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }

  return head;
}

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

  return 0;
}
