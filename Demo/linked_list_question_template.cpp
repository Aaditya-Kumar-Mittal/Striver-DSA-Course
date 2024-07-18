#include <bits/stdc++.h>

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

Node *removeNthFromEndTwoPointers(Node *head, int k)
{
  Node *fast = head, *slow = head;

  for (int i = 0; i < k; i++)
    fast = fast->next;

  if (fast == nullptr)
    return head->next;

  while (fast->next != nullptr)
  {
    fast = fast->next;
    slow = slow->next;
  }

  Node *deleteNode = slow->next;

  slow->next = deleteNode->next;

  delete deleteNode;

  return head;
}

Node *removeNthFromEndBruteForce(Node *head, int k)
{

  Node *temp = head;

  int count = 0;

  while (temp != nullptr)
  {
    count++;

    temp = temp->next;
  }

  if (count == k)
    return head->next;

  int resultant = count - k;

  temp = head;

  while (temp != nullptr)
  {

    resultant--;

    if (resultant == 0)
      break;

    temp = temp->next;
  }

  Node *deleteNode = temp->next;

  temp->next = deleteNode->next;

  delete deleteNode;

  return head;
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

  Node *newHead1 = removeNthFromEndBruteForce(head1, 5);
  std::cout << "Linked After Removing Kth Element From End: ";
  printLinkedList(newHead1);

  Node *newHead2 = removeNthFromEndBruteForce(head2, 5);
  std::cout << "Linked After Removing Kth Element From End: ";
  printLinkedList(newHead2);

  return 0;
}
