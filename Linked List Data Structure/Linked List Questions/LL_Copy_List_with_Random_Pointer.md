# Linked List - Copy List with Random Pointer

## Problem Description

You are given a linked list where each node contains an additional random pointer, which could point to any node in the list or null. The task is to create a deep copy of the list.

### Solution Overview

The solution consists of three main steps:

1. **Inserting Copies of Nodes in Between**:

   - For each original node, we insert a new copy node right after it.

2. **Connecting the Random Pointers**:

   - The random pointer of each copied node is connected to the corresponding random node of the original list.

3. **Separating the Copied List from the Original**:
   - Finally, we extract the copied nodes to form the new deep copy of the list, restoring the original list in the process.

```cpp
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
```

### Algorithm Implementation Code

```cpp
class Solution {
public:
    // Main function to return a deep copy of the linked list with random pointers
    Node* copyRandomList(Node* head) {

        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        // Step 1: Insert copies of nodes in between original nodes
        insertCopiesInBetween(head);

        // Step 2: Connect the random pointers of the newly created nodes
        connectRandomPointers(head);

        // Step 3: Separate the original and copied lists and return the copied list
        return duplicateList(head);
    }

    // Step 1: Function to insert copies of nodes in between original nodes
    void insertCopiesInBetween(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {
            Node *nextElement = temp->next;
            Node* copy = new Node(temp->val); // Create a new copy node
            copy->next = nextElement;
            temp->next = copy; // Insert copy between original nodes
            temp = nextElement;
        }
    }

    // Step 2: Function to connect the random pointers of the copied nodes
    void connectRandomPointers(Node *head) {
        Node *temp = head;

        while (temp != nullptr) {
            Node *copyNode = temp->next; // Access the copy node

            if (temp->random) {
                copyNode->random = temp->random->next; // Set the random pointer of copy node
            } else {
                copyNode->random = nullptr;
            }

            temp = temp->next->next; // Move to the next original node
        }
    }

    // Step 3: Function to separate the copied list from the original list
    Node *duplicateList(Node* head) {
        Node* temp = head;

        Node* dummy = new Node(-1); // Dummy node to help build the new list
        Node* res = dummy;

        while (temp != nullptr) {
            res->next = temp->next; // Append copy node to the result list
            res = res->next;
            temp->next = temp->next->next; // Restore the original list
            temp = temp->next;
        }

        return dummy->next; // Return the copied list
    }
};
```

## Detailed Explanation

#### 1. **Inserting Copies In-Between**

- In this step, we traverse through the original list. For each node, a new node (the copy) is created and inserted directly after the original node. This allows us to later set the random pointers of the copied nodes by using the already set pointers of the original list.

#### 2. **Connecting the Random Pointers**

- Once the copy nodes are inserted, we traverse the list again to connect the `random` pointers. Since the copied nodes are placed directly after their originals, we can set the `random` pointer of each copied node by referring to its corresponding original node's `random` pointer.

#### 3. **Separating the Lists**

- In this final step, we separate the copied nodes from the original list and form the new deep copied list. The original list is restored to its original form by fixing the `next` pointers.

---

### Time Complexity

- **O(n)**, where `n` is the number of nodes in the list. Each step (inserting copies, connecting random pointers, and separating lists) requires a single traversal of the list.

### Space Complexity

- **O(1)**, since we are not using any additional space apart from the nodes already present in the list (aside from the newly created copy nodes, which are essential).
