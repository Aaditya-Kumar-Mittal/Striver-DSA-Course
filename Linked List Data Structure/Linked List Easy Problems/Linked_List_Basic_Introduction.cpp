/*

Aaditya Kumar Mittal - We often suffer more in imagination than in reality.

*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

Node *convertArraytoLinkedList(vector<int> &arr)
{

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
}

int lengthofLinkedList(Node *head)
{

  Node *temp = head;

  int count = 0;

  while (temp)
  {

    count++;
    temp = temp->next;
  }

  return count;
}

bool searchInALinkedList(Node *head, int searchEle)
{

  Node *temp = head;

  while (temp)
  {
    if (temp->data == searchEle)
      return true;
    temp = temp->next;
  }

  return false;
}
int main()
{

  vector<int> arr = {1, 2, 3, 4, 5};

  Node *head = convertArraytoLinkedList(arr);

  std::cout << "Head of converted array: " << head << std::endl;

  printLinkedList(head);

  std::cout << std::endl;

  std::cout << "Length of the linked list is: " << lengthofLinkedList(head) << std::endl;

  std::cout << "Enter an element to search: " << std::endl;

  int search;

  cin >> search;

  bool found = searchInALinkedList(head, search);

  if (found)
  {
    std::cout << search << " found in the Linked List." << std::endl;
  }
  else
  {
    std::cout << search << " not found in the Linked List." << std::endl;
  }

  return 0;
}