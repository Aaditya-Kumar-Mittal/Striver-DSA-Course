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
    // Function to reverse a linked list recursively
    Node *reverse(Node *head)
    {
        // Base cases: if the list is empty or contains only one node, return the head
        if (head == nullptr || head->next == nullptr)
            return head;

        // Recursively reverse the rest of the list
        Node *newHead = reverse(head->next);

        // Adjust the pointers to reverse the current node's link
        Node *front = head->next;
        front->next = head;

        // Set the current node's next pointer to NULL
        head->next = nullptr;

        // Return the new head of the reversed list
        return newHead;
    }

    // Function to add one to the number represented by the linked list
    Node *addOne(Node *head)
    {
        // Step 1: Reverse the linked list to facilitate addition from the least significant digit
        head = reverse(head);

        Node *temp = head;
        int carry = 1; // Initialize carry as 1 since we need to add one

        // Step 2: Traverse the reversed list and add the carry to each node
        while (temp != nullptr)
        {
            temp->data = temp->data + carry; // Add carry to the current node's data

            if (temp->data < 10)
            {
                // If the sum is less than 10, no further carry is needed
                carry = 0;
                break; // Exit the loop
            }
            else
            {
                // If the sum is 10 or more, set the node's data to 0 and keep carry as 1
                temp->data = 0;
                carry = 1;
            }

            temp = temp->next; // Move to the next node
        }

        // Step 3: If carry is still 1 after the loop, it means we need to add a new node
        if (carry == 1)
        {
            Node *newNode = new Node(1); // Create a new node with data 1
            head = reverse(head);        // Reverse the list back to its original order
            newNode->next = head;        // Add the new node at the beginning of the list
            return newNode;
        }

        // Step 4: Reverse the list back to its original order if no new node was added
        head = reverse(head);

        return head;
    }
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
- The function `addOne` has a time complexity of O(3N), where N is the number of nodes in the linked list.
  - The reversal of the list takes O(N) time.
  - The traversal of the list to add one also takes O(N) time.
  - Reversing the list back to its original order takes another O(N) time.

  Therefore, the overall time complexity is O(3N).

Space Complexity:
- The space complexity is O(1) because the operations are performed in place, and only a constant amount of extra space is used.
*/
