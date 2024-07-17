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

Node *addTwoNumbers(Node *head1, Node *head2)
{

  Node *t1 = head1, *t2 = head2;

  Node *dummyNode = new Node(-1);

  Node *currentNode = dummyNode;

  int carry = 0;

  while (t1 != nullptr || t2 != nullptr)
  {

    int sum = carry;

    if (t1)
      sum += t1->data;

    if (t2)
      sum += t2->data;

    Node *newNode = new Node(sum % 10);

    carry = sum / 10;

    currentNode->next = newNode;

    currentNode = newNode;

    if (t1)
      t1 = t1->next;

    if (t2)
      t2 = t2->next;
  }

  if (carry)
  {
    Node *newNode = new Node(carry);

    currentNode->next = newNode;
  }

  return dummyNode->next;
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
  std::cout << "Addition of Two Numbers using Linked List yields a sum: ";
  printLinkedList(sumList);

  return 0;
}
