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

Node *removesHead(Node *head)
{
  if (head == nullptr)
    return nullptr;

  Node *temp = head;
  head = head->next;
  delete temp;

  return head;
}

Node *removesTail(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;
    return nullptr;
  }

  Node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }

  delete temp->next;
  temp->next = nullptr;

  return head;
}

Node *removeKthPosition(Node *head, int k)
{

  if (head == nullptr)
  {
    return head;
  }

  if (k == 1)
  {
    Node *temp = head;

    head = head->next;

    delete temp;

    return head;
  }

  int count = 0;

  Node *temp = head;

  Node *prev = nullptr;

  while (temp != nullptr)
  {

    count++;

    if (count == k)
    {
      prev->next = prev->next->next;

      delete temp;

      break;
    }

    prev = temp;

    temp = temp->next;
  }

  return head;
}
Node *removeElement(Node *head, int value)
{

  if (head == nullptr)
  {
    return head;
  }

  if (head->data == value)
  {
    Node *temp = head;

    head = head->next;

    delete temp;

    return head;
  }

  Node *temp = head;

  Node *prev = nullptr;

  while (temp != nullptr)
  {

    if (temp->data == value)
    {
      prev->next = prev->next->next;

      delete temp;

      break;
    }

    prev = temp;

    temp = temp->next;
  }

  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13};

  Node *head = convertArraytoLinkedList(arr);
  cout << "Linked list after conversion from array: ";
  printLinkedList(head);

  head = removesHead(head);
  cout << "Linked list after removing head: ";
  printLinkedList(head);

  head = removesTail(head);
  cout << "Linked list after removing tail: ";
  printLinkedList(head);

  head = removeKthPosition(head, 5);
  std::cout << "Linked list after removing 5th position element" << std::endl;
  printLinkedList(head);

  head = removeKthPosition(head, 1);
  std::cout << "Linked list after removing 1st position element" << std::endl;
  printLinkedList(head);

  head = removeKthPosition(head, 8);
  std::cout << "Linked list after removing 8th position element" << std::endl;
  printLinkedList(head);

  head = removeElement(head, 10);
  printLinkedList(head);

  return 0;
}
