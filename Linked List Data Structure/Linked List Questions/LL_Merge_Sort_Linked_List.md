# Linked List Problem - Merge Sort Linked List

## Explanation

1. **`findMiddle` Function**:

   - Uses the **slow and fast pointer technique** to find the middle of the list.
   - The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps.
   - When the `fast` pointer reaches the end, the `slow` pointer will be at the middle.

2. **`mergeTwoLists` Function**:

   - Merges two sorted linked lists.
   - A dummy node is used to simplify edge cases when merging.
   - The smaller element from the two lists is appended to the result list, and the pointers are updated accordingly.

3. **`mergeSortList` Function**:
   - Implements the merge sort algorithm.
   - The list is recursively split into two halves, sorted separately, and then merged back together using `mergeTwoLists`.

## Time Complexity

- **Time complexity**: \(O(n \log n)\), where \(n\) is the number of nodes in the linked list. This is due to recursively splitting the list into halves and merging them back.

## Space Complexity

- **Space complexity**: \(O(\log n)\) due to the recursive calls made by the merge sort.

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // Function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        // Initialize slow and fast pointers
        ListNode *slow = head, *fast = head->next;

        // Move slow by one step and fast by two steps to find the middle
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow pointer will now be at the middle
        return slow;
    }

    // Function to merge two sorted linked lists into one sorted list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify the merging process
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        // Traverse through both lists and merge them in sorted order
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }

        // Append any remaining nodes from either list
        if(l1) temp->next = l1;
        else temp->next = l2;

        // Return the merged list, skipping the dummy node
        return dummy->next;
    }

    // Function to perform merge sort on the linked list
    ListNode* mergeSortList(ListNode* head) {
        // Base case: If the list is empty or has only one element, it's already sorted
        if(head == nullptr || head->next == nullptr) return head;

        // Find the middle of the list
        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next;

        // Disconnect the left half from the right
        middle->next = nullptr;

        // Recursively sort the left and right halves
        ListNode *left = mergeSortList(head);
        right = mergeSortList(right);

        // Merge the sorted halves
        return mergeTwoLists(left, right);
    }
};
```
