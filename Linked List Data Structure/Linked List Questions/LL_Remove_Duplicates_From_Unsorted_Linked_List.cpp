//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of Node structure used in the linked list
struct Node {
    int data;          // Data field to store the value of the node
    Node *next;        // Pointer to the next node in the list

    // Constructor to initialize the node with data and next pointer
    Node(int x)
        : data(x), next(nullptr) {}
};

// Utility function to print the linked list
void printList(Node *head) {
    Node *temp = head;
    // Traverse the linked list and print each node's data
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the data of current node
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Newline after printing the list
}

// } Driver Code Ends
/*
The structure of linked list is as follows:

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
    // Function to remove duplicate elements from a sorted linked list
    Node *removeDuplicates(Node *head) {
        
        // Variable to store the maximum value found in the linked list
        int maxVal = INT_MIN;
        
        Node *temp = head;
        
        // First loop to find the maximum value in the linked list
        while(temp != nullptr)
        {
            // Update maxVal if current node's data is greater
            maxVal = temp->data > maxVal ? temp->data : maxVal;
            temp = temp->next;
        }
        
        // Create a boolean array (hash array) to mark visited elements, initialized to false
        vector<bool> hashArr(maxVal + 1, false);
        
        Node *prev = nullptr; // Pointer to track the previous node
        temp = head;          // Reset temp to the head
        
        // Traverse the linked list and remove duplicates
        while(temp != nullptr){
            
            // If the current node's data has been seen before, remove it
            if(hashArr[temp->data])
            {
                Node *toDelete = temp; // Temporary pointer to store the node to be deleted
                prev->next = temp->next; // Bypass the duplicate node
                temp = temp->next;       // Move to the next node
                delete toDelete;         // Free the memory of the duplicate node
            }
            else {
                // Mark the current node's data as seen
                hashArr[temp->data] = true;
                prev = temp;    // Update the previous pointer
                temp = temp->next; // Move to the next node
            }
        }
        
        return head; // Return the updated linked list without duplicates
    }
};

//{ Driver Code Starts.
int main() {
    int t; // Number of test cases
    cin >> t; // Read the number of test cases
    cin.ignore(); // Ignore the newline character
    
    // Loop over each test case
    while (t--) {
        vector<int> arr; // Vector to store the input data
        string input;    // String to store the input line
        getline(cin, input); // Read the entire line of input
        stringstream ss(input); // String stream to parse the input
        int number;
        
        // Extract numbers from the input string and store in the vector
        while (ss >> number) {
            arr.push_back(number);
        }
        
        // If the array is empty, print "empty" and continue
        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        // Create the linked list from the input data
        Node *head = new Node(arr[0]); // Initialize the head of the list
        Node *tail = head;             // Tail pointer to track the end of the list
        
        // Add each element to the linked list
        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]); // Add new node to the end
            tail = tail->next;             // Move the tail pointer
        }

        Solution ob; // Create an object of Solution class
        Node *result = ob.removeDuplicates(head); // Remove duplicates from the list
        printList(result); // Print the updated list
    }

    return 0;
}

// } Driver Code Ends

/*
ANALYSIS:

Problem:
The task is to remove duplicate nodes from a sorted linked list.

Approach:
1. **Find Maximum Value**: Traverse the list to find the maximum value so we can size the hash array (for tracking visited nodes).
2. **Use a Hash Array**: A boolean array of size `maxVal + 1` is used to keep track of which values have already been seen.
3. **Traversal and Removal**: We traverse the linked list again, and for each node:
   - If the value has already been marked in the hash array, we delete the node.
   - Otherwise, we mark it and move to the next node.

Time Complexity:
- **O(N)** where N is the number of nodes in the list.
   - First pass to find the maximum value takes O(N).
   - Second pass to remove duplicates also takes O(N).
   - Operations on the hash array are O(1).

Space Complexity:
- **O(M)** where M is the maximum value in the linked list (`maxVal`), because we create a hash array of size `maxVal + 1`.
- **O(1)** additional space, aside from the hash array.

Edge Cases:
1. **Empty List**: If the linked list is empty, we handle it by skipping the process.
2. **Single Element List**: A list with one element is already free of duplicates.
3. **All Elements Unique**: If all elements are unique, the original list is returned as is.
*/