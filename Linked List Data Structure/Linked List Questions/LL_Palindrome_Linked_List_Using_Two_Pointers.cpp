//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Structure representing a Node in a singly linked list
struct Node
{
  int data;          // Data stored in the Node
  struct Node *next; // Pointer to the next Node

  Node(int x)
  { // Constructor to initialize Node with data
    data = x;
    next = NULL;
  }
};

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
  // Function to reverse a linked list starting from a given head node
  Node *reverse(Node *head)
  {
    Node *temp = head;    // Temporary pointer to traverse the list
    Node *prev = nullptr; // Pointer to store the previous node during reversal

    while (temp != nullptr)
    {
      Node *front = temp->next; // Store the next node
      temp->next = prev;        // Reverse the current node's pointer
      prev = temp;              // Move prev to the current node
      temp = front;             // Move to the next node
    }

    return prev; // Return the new head of the reversed list
  }

  // Function to check whether the linked list is a palindrome
  bool isPalindrome(Node *head)
  {
    // Base cases: empty list or single node is always a palindrome
    if (head == nullptr || head->next == nullptr)
      return true;

    Node *slow = head, *fast = head; // Two pointers for finding the middle of the list

    // Move slow to the middle of the list, fast moves twice as fast
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    Node *newHead = reverse(slow->next); // Reverse the second half of the list

    Node *first = head;     // Pointer to traverse the first half
    Node *second = newHead; // Pointer to traverse the reversed second half

    // Compare both halves of the list
    while (second != nullptr)
    {
      if (first->data != second->data)
      {
        reverse(newHead); // Restore the original order before returning
        return false;     // Not a palindrome
      }
      first = first->next;
      second = second->next;
    }

    reverse(newHead); // Restore the original order
    return true;      // List is a palindrome
  }
};

//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

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
    { // If the input is empty, print "empty" and continue
      cout << "empty" << endl;
      continue;
    }

    struct Node *head = new Node(arr[0]); // Create the head of the list
    struct Node *tail = head;             // Tail pointer to add new nodes at the end
    for (int i = 1; i < arr.size(); ++i)
    {
      tail->next = new Node(arr[i]); // Create a new node and link it
      tail = tail->next;
    }

    Solution ob;               // Create an object of the Solution class
    if (ob.isPalindrome(head)) // Check if the list is a palindrome
      cout << "true" << endl;
    else
      cout << "false" << endl;

    // Clean up the remaining nodes to avoid memory leaks
    while (head != NULL)
    {
      struct Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  return 0;
}

// } Driver Code Ends

/*
Analysis of the Code

Time Complexity:
- The function `isPalindrome` has a time complexity of O(N), where N is the number of nodes in the linked list.
  - The first traversal of the list takes O(N) time to find the middle of the list.
  - The reversal of the second half of the list takes O(N/2) time.
  - The comparison of both halves takes O(N/2) time.
  - Finally, restoring the list back to its original order takes O(N/2) time.

Space Complexity:
- The space complexity is O(1) because the reversal and comparison are done in place, using a constant amount of extra space.
*/
