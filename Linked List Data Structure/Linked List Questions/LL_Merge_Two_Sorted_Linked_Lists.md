# Linked List -  Merge Two Sorted Linked List

```cpp
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to merge two sorted linked lists.
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Initialize pointers for traversing both lists
        Node *t1 = head1, *t2 = head2;
        
        // Dummy node to help with merging
        Node *dummyNode = new Node(-1);
        Node *temp = dummyNode; // Pointer to build the merged list
        
        // Traverse both lists until one of them is exhausted
        while(t1 != nullptr && t2 != nullptr) {
            // Compare nodes and add the smaller one to the merged list
            if(t1->data < t2->data) {
                temp->next = t1; // Add t1 to merged list
                temp = t1;       // Move temp to the last node of merged list
                t1 = t1->next;   // Move t1 to the next node in the list
            } else {
                temp->next = t2; // Add t2 to merged list
                temp = t2;       // Move temp to the last node of merged list
                t2 = t2->next;   // Move t2 to the next node in the list
            }
        }
        
        // Append the remaining nodes from either list
        if(t1) temp->next = t1;
        else temp->next = t2;
        
        // Return the merged list starting from the next of dummy node
        return dummyNode->next;
    } 
};
```

## Analysis Section

### Problem Name: Merge Two Sorted Linked Lists

### Description

This function takes two sorted linked lists and merges them into one sorted linked list. It traverses both input lists, comparing the nodes, and appends the smaller node to the resulting merged list. If one list is exhausted before the other, the remaining nodes from the non-exhausted list are directly appended to the merged list.

### Time Complexity

- Since each node from both linked lists is processed exactly once, the time complexity is `O(n + m)` where `n` is the length of the first list and `m` is the length of the second list.

### Space Complexity

- The space complexity is `O(1)` because we only use a few extra pointers for the merge operation.
- However, the space required for the result itself is `O(n + m)` due to the nodes of the linked lists being combined.

### Edge Cases

1. Either `head1` or `head2` is `NULL`. The function handles this by simply returning the non-NULL list.
2. Both input lists are empty, returning `NULL`.
