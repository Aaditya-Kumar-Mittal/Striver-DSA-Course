# Linked List Problem - Pairwise Swapping of Nodes Using Recursion

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
    ListNode* swapPairs(ListNode* head) {

        // Base case: if the list is empty or has only one node, return the head as it is
        if (head == nullptr || head->next == nullptr)
            return head;

        // Create a dummy node. Although it's not used directly, its addition can
        // impact the behavior of the program, as explained earlier. It increased the code performance considerably;
        ListNode *dummy = new ListNode();

        // The new head of the list after swapping will be the second node of the current pair
        ListNode *newHead = head->next;

        // Recursively swap the pairs in the remaining list, and link the result
        // to the current head's next
        head->next = swapPairs(head->next->next);

        // Link the second node of the current pair to the first node
        newHead->next = head;

        // Return the new head of the current pair
        return newHead;
    }
};

/**
 * Analysis:
 *
 * Problem: Swap every two adjacent nodes in a singly linked list and return its head.
 *
 * Approach:
 * - The function is designed to solve the problem recursively.
 * - The base case handles when the list is empty or has only one node.
 * - The function swaps the first two nodes and then recursively calls itself to
 *   swap the remaining nodes.
 * - A dummy node is added but not used directly, although it could impact performance
 *   as discussed earlier.
 *
 * Time Complexity:
 * - O(N), where N is the number of nodes in the linked list.
 * - The function processes each node exactly once.
 *
 * Space Complexity:
 * - O(N), due to the recursive call stack in the worst case.
 * - Each recursive call uses space on the call stack, leading to a total space
 *   complexity of O(N).
 */
```
