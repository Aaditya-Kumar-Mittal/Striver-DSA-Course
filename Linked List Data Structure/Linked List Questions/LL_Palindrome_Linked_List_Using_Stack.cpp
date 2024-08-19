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
struct Node {
    int data;     // Data stored in the Node
    struct Node *next;  // Pointer to the next Node

    Node(int x) {   // Constructor to initialize Node with data
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

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // If the list is empty or contains a single node, it's a palindrome
        if(head == nullptr || head->next == nullptr) return true;
        
        Node *temp = head; // Temporary pointer to traverse the list
        
        stack<int> stk; // Stack to store the values of the list
        
        // Traverse the list and push all values onto the stack
        while(temp != nullptr){
            stk.push(temp->data);
            temp = temp->next;
        }
        
        temp = head; // Reset temp to the head of the list
        
        // Traverse the list again and compare each value with the top of the stack
        while(temp != nullptr){
            if(temp->data != stk.top()) return false; // If values don't match, it's not a palindrome
            stk.pop();
            temp = temp->next;
        }
        
        return true; // If all values matched, the list is a palindrome
    }
};

//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;  // Number of test cases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;  // Vector to store input numbers
        string input;  // String to read input line
        getline(cin, input);
        stringstream ss(input);  // Stringstream to parse the input
        int number;
        while (ss >> number) {
            arr.push_back(number);  // Push each number to the vector
        }

        if (arr.empty()) {  // If the input is empty, print "empty" and continue
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);  // Create the head of the list
        struct Node *tail = head;  // Tail pointer to add new nodes at the end
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);  // Create a new node and link it
            tail = tail->next;
        }
        
        Solution ob;  // Create an object of the Solution class
        if (ob.isPalindrome(head))  // Check if the list is a palindrome
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
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
- The function `isPalindrome` has a time complexity of O(2N), where N is the number of nodes in the linked list.
  - The first traversal of the list takes O(N) time to push all elements into the stack.
  - The second traversal takes O(N) time to compare the stack elements with the list elements.

Space Complexity:
- The space complexity is O(N) because of the stack used to store the list's values.
  - The stack will hold all N values of the linked list, resulting in O(N) additional space usage.
*/
