//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure used for the linked list
struct Node
{
  int data;          // Data stored in the node
  struct Node *next; // Pointer to the next node in the list

  // Constructor to initialize a new node
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// Function to print the linked list, displaying only the last digit of each node's data
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data % 10; // Print the last digit of the data
    node = node->next;       // Move to the next node
  }
  cout << "\n";
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
  // Helper function to recursively add one to the linked list
  int helperFunction(Node *temp)
  {
    // Base case: If we reach the end of the list, return 1 (the carry to add)
    if (temp == nullptr)
      return 1;

    // Recursively call the helper function on the next node
    int carry = helperFunction(temp->next);

    // Add the carry to the current node's data
    temp->data = temp->data + carry;

    // If the sum is less than 10, no further carry is needed
    if (temp->data < 10)
    {
      return 0; // Return 0 to indicate no carry
    }
    else
    {
      // If the sum is 10 or more, set the node's data to 0 and return carry 1
      temp->data = 0;
      return 1; // Continue the carry
    }
  }

  // Function to add one to the number represented by the linked list
  Node *addOne(Node *head)
  {
    // Call the helper function starting from the head
    int carry = helperFunction(head);

    // If there is still a carry after processing the entire list, add a new node
    if (carry == 1)
    {
      Node *newNode = new Node(1); // Create a new node with data 1
      newNode->next = head;        // Make the new node the new head
      return newNode;
    }

    // Return the head if no new node was added
    return head;
  }

  /*
  // This is an alternative solution using list reversal. It's commented out but kept for reference.

  Node *reverse(Node *head) {
      if (head == nullptr || head->next == nullptr) return head;

      Node *newHead = reverse(head->next);

      Node *front = head->next;
      front->next = head;

      head->next = nullptr;

      return newHead;
  }

  Node* addOne(Node* head) {
      head = reverse(head);

      Node *temp = head;
      int carry = 1;

      while (temp != nullptr) {
          temp->data = temp->data + carry;

          if (temp->data < 10) {
              carry = 0;
              break;
          } else {
              temp->data = 0;
              carry = 1;
          }

          temp = temp->next;
      }

      if (carry == 1) {
          Node *newNode = new Node(1);
          head = reverse(head);
          newNode->next = head;
          return newNode;
      }

      head = reverse(head);
      return head;
  }
  */
};

//{ Driver Code Starts.

int main()
{
  int t; // Number of test cases
  cin >> t;
  cin.ignore();
  while (t--)
  {
    vector<int> arr; // Vector to store input numbers
    string input;    // String to read input line
    getline(cin, input);
    stringstream ss(input); // Stringstream to parse the input
    int number;
    while (ss >> number)
    {
      arr.push_back(number); // Push each number to the vector
    }

    if (arr.empty())
    { // If the input is empty, print -1 and continue
      cout << -1 << endl;
      continue;
    }

    // Create the head of the linked list from the first element
    int data = arr[0];
    struct Node *head = new Node(data);
    struct Node *tail = head; // Tail pointer to add new nodes at the end
    for (int i = 1; i < arr.size(); ++i)
    {
      data = arr[i];
      tail->next = new Node(data); // Create a new node and link it
      tail = tail->next;
    }

    Solution ob;            // Create an object of the Solution class
    head = ob.addOne(head); // Add one to the linked list
    printList(head);        // Print the resulting linked list
  }
  return 0;
}

// } Driver Code Ends

/*
Analysis of the Code

Time Complexity:
- The function `addOne` has a time complexity of O(N), where N is the number of nodes in the linked list.
  - The `helperFunction` traverses the entire list recursively, which takes O(N) time.

  Therefore, the overall time complexity is O(N).

Space Complexity:
- The space complexity is O(N) due to the recursive call stack in the `helperFunction`.
  - Each recursive call consumes stack space, and in the worst case, this can go up to N calls.

  Therefore, the space complexity is O(N).
*/