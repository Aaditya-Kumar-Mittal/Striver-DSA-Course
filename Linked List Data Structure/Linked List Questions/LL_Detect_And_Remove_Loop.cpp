//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {  // Constructor to initialize a node
        data = val;
        next = NULL;
    }
};

// Function to create a loop in the linked list at the given position
void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)  // No loop to be created
        return;

    Node* walk = head;  // Start from the head
    for (int i = 1; i < position; i++)  // Move to the position
        walk = walk->next;
    tail->next = walk;  // Create a loop by connecting the tail to the position node
}

// Function to detect if a loop is present in the linked list
bool isLoop(Node* head) {
    if (!head)
        return false;

    Node* fast = head->next;
    Node* slow = head;

    // Move fast and slow pointers, fast moves two steps and slow moves one step
    while (fast != slow) {
        if (!fast || !fast->next)  // If fast reaches the end, no loop is present
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;  // If fast and slow meet, there is a loop
}

// Function to calculate the length of the linked list
int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

// Function to verify if the linked list has been modified from its original state
bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {

    while (head) {
        if (myMap.find(head) == myMap.end())
            return true;  // Node not found in the map, indicating a modification
        if (myMap[head] != (head->data))
            return true;  // Data mismatch, indicating a modification

        head = head->next;
    }
    return false;  // No modification detected
}

// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        if(head == nullptr || head->next == nullptr) return;
        
        Node *slow = head, *fast = head;
        
        slow = slow->next;  // Move slow pointer one step
        fast = fast->next->next;  // Move fast pointer two steps
        
        // Detect loop using Floyd’s Cycle Detection Algorithm
        while(fast != nullptr && fast->next != nullptr){
            
            if(slow == fast) // If both meet, loop detected
            {
                break;
            }
            
            slow = slow->next;  // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps
        }
        
        if(slow == fast){
            
            slow = head;
            
            // Special case when loop starts at the head
            if(slow == fast){
                
                while(fast->next != slow) fast = fast->next;  // Move fast pointer to the last node in the loop
            }
            else{
                
                while(slow->next != fast->next){
                    
                    slow = slow->next;  // Move slow pointer one step
                    fast = fast->next;  // Move fast pointer one step
                }
            }
            
            fast->next = nullptr;  // Remove the loop by setting the last node's next to nullptr
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        unordered_map<Node*, int> myMap;

        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
    }
    return 0;
}

// } Driver Code Ends

/*
### Analysis

**Problem Name:** Remove Loop in Linked List

**Approach:**
- The code uses Floyd’s Cycle Detection Algorithm (also known as the Tortoise and Hare Algorithm) to detect and remove a loop in a linked list.
- If a loop is detected, the code finds the start of the loop and breaks it by setting the `next` pointer of the last node in the loop to `nullptr`.

**Time Complexity:**
- The time complexity of this algorithm is `O(N)`, where `N` is the number of nodes in the linked list. This is because in the worst case, every node is visited twice (once by the slow pointer and once by the fast pointer).

**Space Complexity:**
- The space complexity is `O(1)` since no extra space is required, other than a few pointers.

**Edge Cases Considered:**
- Empty list or a list with only one node.
- List where the loop starts at the head.

This approach efficiently handles detecting and removing loops in a linked list with minimal additional space and time complexity.
*/
