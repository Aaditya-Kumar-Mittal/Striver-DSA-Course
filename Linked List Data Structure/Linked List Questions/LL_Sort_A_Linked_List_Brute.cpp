//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

void freeList(struct Node *head)
{
  struct Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution
{
public:
  Node *sort(Node *head)
  {

    vector<int> arr;

    Node *temp = head;

    while (temp != nullptr)
    {
      arr.push_back(temp->data);

      temp = temp->next;
    }

    std::sort(arr.begin(), arr.end());

    int i = 0;

    temp = head;

    while (temp != nullptr)
    {

      temp->data = arr[i++];

      temp = temp->next;
    }

    return head;
  }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
  int t;
  cin >> t;
  cin.ignore(); // Ignore the newline character after t

  while (t--)
  {
    string input;
    getline(cin, input); // Read the entire line for the array elements

    stringstream ss(input);
    Node *head = nullptr, *tail = nullptr;
    int x;

    if (ss >> x)
    {
      head = new Node(x);
      tail = head;

      while (ss >> x)
      {
        tail->next = new Node(x);
        tail = tail->next;
      }
    }

    Solution ob;
    Node *newHead = ob.sort(head);
    printList(newHead);
    freeList(newHead);
  }

  return 0;
}
// } Driver Code Ends

/*
Analysis:
-----------
Problem: Sort the given linked list by storing its elements in a vector, sorting them, and putting them back into the linked list.

Time Complexity: O(N log N)
- N is the number of nodes in the linked list.
- The time complexity is dominated by the sorting step using `std::sort`, which takes O(N log N).
- Traversing the linked list to store values: O(n), where n is the number of nodes.
- Sorting the array: O(n log n), using std::sort().
- Re-assigning values to the linked list: O(n).
- Total Time Complexity: O(n log n).

Space Complexity: O(N)
- The additional space is used to store the elements of the linked list in a vector.
*/
