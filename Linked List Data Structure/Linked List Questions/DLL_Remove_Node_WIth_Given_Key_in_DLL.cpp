//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// Structure definition for a Node in the doubly linked list
struct Node {
    int data;       // Data stored in the node
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

// Function to push a new node to the front of the list
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign the new data to the new node
    new_node->data = new_data;

    // Make the new node's previous pointer NULL since it will be the new head
    new_node->prev = NULL;

    // Point the new node's next pointer to the current head of the list
    new_node->next = (*head_ref);

    // If the list is not empty, update the previous head's prev pointer to the new node
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    // Move the head pointer to the new node, making it the new head
    (*head_ref) = new_node;
}

// Function to print the elements of the list
void printList(struct Node* head) {
    // If the list is empty, print -1
    if (head == NULL) cout << -1;

    // Traverse the list and print each node's data
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// } Driver Code Ends

// User function Template for C++

// Class containing the function to delete all occurrences of a given value in the doubly linked list
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node *temp = *head_ref;  // Start from the head of the list
        
        // Traverse the entire list
        while(temp != nullptr)
        {
            Node *nextNode = temp->next;  // Store the next node before potentially deleting the current node
            
            // Check if the current node's data matches the value to be deleted
            if(temp->data == x)
            {
                // If the node to be deleted is the head node
                if(temp == *head_ref)
                {
                    *head_ref = nextNode;  // Update the head to the next node
                    
                    // If the list has more nodes, update the new head's previous pointer
                    if(nextNode != nullptr)
                    {
                        nextNode->prev = nullptr;
                    }
                }
                else
                {
                    // If the node to be deleted is not the head, update the links
                    Node *prevNode = temp->prev;
                    
                    // Update the previous node's next pointer to skip the deleted node
                    if(prevNode)
                    {
                        prevNode->next = nextNode;
                    }
                    
                    // If there's a next node, update its previous pointer
                    if(nextNode)
                    {
                        nextNode->prev = prevNode;
                    }
                }
                
                // Delete the current node
                delete temp;
                
                // Move to the next node
                temp = nextNode;
            }
            else {
                // Move to the next node if the current node is not deleted
                temp = temp->next;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // Test cases loop
    while (t--) {
        // Initialize the head of the list
        Node* head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        // Input values for the list
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            inp[i] = val;
        }

        // Build the list by pushing each value onto the front of the list
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }

        int key;
        cin >> key;

        // Create an instance of the solution class
        Solution obj;

        // Delete all occurrences of the specified value
        obj.deleteAllOccurOfX(&head, key);

        // Print the modified list
        printList(head);
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
