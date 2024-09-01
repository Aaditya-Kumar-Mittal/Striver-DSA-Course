//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}

void displayList(Node *head)
{
    // Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
}

int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}

bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{
public:

    Node *removeDuplicates(struct Node *head)
    {
        Node *temp = head;
        
        while(temp != nullptr && temp->next != nullptr){
            
            Node *nextNode = temp->next;
            
            while(nextNode != nullptr && nextNode->data == temp->data){
                
                Node *duplicate = nextNode;
                
                nextNode = nextNode->next;
                
                delete duplicate;
            }
            
            temp->next = nextNode;
            
            if(nextNode) nextNode->prev = temp;
            
            temp = temp->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Node *head=NULL, *tail=NULL;
        int x;
        cin>>x;
        head = newNode(x);
        tail = head;
        
        for(int i=0;i<n - 1;i++)
        {
            cin>>x;
            Node* temp=newNode(x);
            tail->next=temp;
            temp->prev= tail;
            tail = temp;
        }
        Solution obj;
        head=obj.removeDuplicates(head);
        
        if(verify(head))
            displayList(head);
        else
            cout<<"Your pointers are not correctly connected";
    
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*
### Problem Name:
Remove Duplicates from a Sorted Doubly Linked List

### Problem Description:
Given a sorted doubly linked list, the task is to remove all duplicate nodes so that each element appears only once.

### Approach:
1. **Iterative Removal of Duplicates**:
   - The algorithm iterates through the list, comparing each node with its next node.
   - If the current node and the next node have the same data, the next node is considered a duplicate and is removed.
   - The links between the previous node, current node, and the next node after the duplicate are adjusted to maintain the doubly linked list structure.
   - The process continues until all nodes are checked.

2. **Pointer Adjustments**:
   - The next pointer of the current node is updated to skip over the duplicate nodes.
   - The previous pointer of the non-duplicate next node is also adjusted to point back to the current node.

### Time Complexity:
- **O(n)**: The algorithm traverses the list once, comparing adjacent nodes, leading to a linear time complexity.

### Space Complexity:
- **O(1)**: No extra space is used other than pointers for traversal and deletion, making it an in-place algorithm.

### Edge Cases Considered:
1. **Empty List**:
   - If the list is empty, no action is needed.
   
2. **Single Node List**:
   - A list with only one node has no duplicates, so no changes are made.
   
3. **All Elements Are the Same**:
   - If all nodes in the list have the same data, the algorithm reduces the list to a single node.

### Example:
Consider a sorted doubly linked list: `1 <-> 1 <-> 2 <-> 3 <-> 3`.

- Initial node: `1`. The next node is also `1`, so the duplicate `1` is removed.
- Next comparison: `1` and `2` (no duplicates).
- Moving to `2` and `3` (no duplicates).
- Finally, `3` and `3`. The duplicate `3` is removed.

Output: `1 <-> 2 <-> 3`

This approach ensures that the list remains sorted and free of duplicates, adhering to the problem's constraints efficiently.
*/