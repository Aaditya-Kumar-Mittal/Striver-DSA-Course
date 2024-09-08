//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* Linked list Node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Min-heap to store {data, Node*} pairs sorted by data
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        
        // Insert the head node of each linked list into the min-heap
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]) {
                pq.push({arr[i]->data, arr[i]});
            }
        }
        
        // Create a dummy node for the merged linked list
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        
        // While there are elements in the priority queue
        while(!pq.empty()){
            // Extract the smallest node from the heap
            auto it = pq.top();
            pq.pop();
            
            // Add the smallest node to the merged list
            temp->next = it.second;
            temp = temp->next;
            
            // If the extracted node has a next node, insert it into the heap
            if(it.second->next){
                pq.push({it.second->next->data, it.second->next});
            }
        }
        
        // Return the merged linked list
        return dummyNode->next;
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        
        while (ss >> number) {
            nums.push_back(number);
        }

        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    
    return 0;
}
// } Driver Code Ends

/*
Problem Name: Merge K Sorted Linked Lists
Time Complexity: O(N K log K)
    - N is the total number of nodes across all K linked lists.
    - K is the number of linked lists.
    - Insertion and deletion operations from the priority queue (min-heap) take O(K log K) time. Since each of the N nodes is processed exactly once, the overall time complexity is O(N log K).

Space Complexity: O(K)
    - The priority queue stores at most K elements at any given time, which corresponds to the head of each linked list.
    - Additional space is used for the merged linked list (O(N)), but this is not counted as extra space since it is the result of the operation.
*/
