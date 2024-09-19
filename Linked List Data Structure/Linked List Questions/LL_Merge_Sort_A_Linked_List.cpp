//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Structure for linked list node
struct Node
{
  int data;
  struct Node *next;

  // Constructor to initialize the node
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// Function to print the linked list
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

// } Driver Code Ends

/*
The structure of linked list is as follows:

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
  // Function to sort the linked list using merge sort
  Node *mergeSort(Node *head)
  {
    // Base case: if the list is empty or has only one element
    if (head == nullptr || head->next == nullptr)
      return head;

    // Find the middle node to split the list
    Node *middle = findMiddle(head);
    Node *right = middle->next;
    middle->next = nullptr; // Split the list into two halves

    // Recursively sort both halves
    Node *left = mergeSort(head);
    right = mergeSort(right);

    // Merge the sorted halves
    return mergeTwoLists(left, right);
  }

  // Function to find the middle node of the linked list
  Node *findMiddle(Node *head)
  {
    Node *slow = head, *fast = head->next;

    // Move slow by 1 and fast by 2 steps until fast reaches the end
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Slow will be at the middle of the list
    return slow;
  }

  // Function to merge two sorted linked lists
  Node *mergeTwoLists(Node *l1, Node *l2)
  {
    Node *dummy = new Node(-1); // Dummy node to simplify merging process
    Node *temp = dummy;

    // Merge the two lists in sorted order
    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->data < l2->data)
      {
        temp->next = l1;
        temp = l1;
        l1 = l1->next;
      }
      else
      {
        temp->next = l2;
        temp = l2;
        l2 = l2->next;
      }
    }

    // Attach remaining nodes, if any
    if (l1)
      temp->next = l1;
    else
      temp->next = l2;

    // Return the merged list (skipping the dummy node)
    return dummy->next;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  cin.ignore(); // Ignore the newline character

  while (t--)
  {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;

    // Read numbers from the input line
    while (ss >> number)
    {
      arr.push_back(number);
    }

    Node *head = nullptr;
    // If the array is not empty, construct the linked list
    if (!arr.empty())
    {
      head = new Node(arr[0]);
      Node *tail = head;
      for (size_t i = 1; i < arr.size(); ++i)
      {
        tail->next = new Node(arr[i]);
        tail = tail->next;
      }
    }

    // Create an instance of Solution and sort the list
    Solution obj;
    Node *ans = obj.mergeSort(head);

    // Print the sorted linked list
    printList(ans);
  }
  return 0;
}
// } Driver Code Ends

/*

### Explanation:

1. **`mergeSort` Function**:
   - The main function that implements the merge sort algorithm for a linked list.
   - It recursively splits the list into two halves using the `findMiddle` function, sorts both halves, and then merges them using the `mergeTwoLists` function.

2. **`findMiddle` Function**:
   - Finds the middle node of the linked list using the slow and fast pointer technique.
   - The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps. When `fast` reaches the end, `slow` will be at the middle.

3. **`mergeTwoLists` Function**:
   - Merges two sorted linked lists into one sorted list.
   - A dummy node is used to simplify the merging process, avoiding edge cases where the merged list starts with `nullptr`.

4. **Driver Code**:
   - The driver code reads multiple test cases.
   - It constructs a linked list from the input numbers and then calls the `mergeSort` function to sort it.
   - The sorted list is then printed using the `printList` function.

### Time Complexity:
- **Time complexity**: \(O(n \log n)\), where \(n\) is the number of nodes in the linked list. This is due to recursively dividing the list into halves and merging them back.

### Space Complexity:
- **Space complexity**: \(O(\log n)\) due to the recursion depth of merge sort.

This solution effectively sorts a linked list using the divide-and-conquer strategy of merge sort.
*/