# Merge k Sorted Lists

## Problem Overview

**Problem:**  
You are given an array of `k` linked-lists, where each linked-list is sorted in ascending order. The task is to merge all the linked-lists into one sorted linked-list and return it.

### Example

**Example 1:**

- **Input:** `lists = [[1,4,5], [1,3,4], [2,6]]`
- **Output:** `[1,1,2,3,4,4,5,6]`
- **Explanation:** The linked-lists are:
  - `1 -> 4 -> 5`
  - `1 -> 3 -> 4`
  - `2 -> 6`
  - Merging them results in: `1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6`

**Example 2:**

- **Input:** `lists = []`
- **Output:** `[]`

**Example 3:**

- **Input:** `lists = [[]]`
- **Output:** `[]`

### Constraints

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- Each `lists[i]` is sorted in ascending order.
- The sum of `lists[i].length` will not exceed `10^4`.

---

### Approach

To solve this problem, we use a **min-heap (priority queue)** to efficiently merge `k` sorted linked-lists.

#### Why a Priority Queue?

- A priority queue (min-heap) helps keep track of the smallest elements from each of the linked-lists.
- By always pulling the smallest element and adding the next element from the corresponding list, we ensure that the merged linked-list is sorted.
- The priority queue is structured to store nodes of the linked-lists such that the smallest node is always at the top.

#### Data Structure Used

- **Min-Heap**: To store nodes of the linked lists.
  - We use a custom comparator `MyComparator` to ensure that the node with the smallest value is at the top of the priority queue.

#### Algorithm

1. **Initialize a Min-Heap (`priority_queue`)**:
   - Create a priority queue that uses the custom comparator `MyComparator` to store pointers to `ListNode`.
2. **Add First Nodes**:
   - Traverse through each linked list and push the first node of each non-empty list into the priority queue.
3. **Create a Dummy Node**:
   - Create a dummy node (`dummyNode`) to serve as the head of the merged linked-list.
   - Maintain a `temp` pointer to build the merged linked-list.
4. **Merge Lists**:
   - While the priority queue is not empty:
     - Extract the smallest element from the queue (`ele = pq.top()`).
     - Append `ele` to the merged list by setting `temp->next = ele`.
     - Move `temp` to `temp->next`.
     - If `ele` has a next node, push `ele->next` into the priority queue.
5. **Return the Merged List**:
   - Return `dummyNode->next` as the head of the merged linked-list.

---

### Code with Documentation

```cpp
#include <queue>
using namespace std;

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

/**
 * Custom comparator to maintain a min-heap based on ListNode values.
 */
struct MyComparator {
    bool operator()(ListNode* nodeA, ListNode* nodeB) {
        return nodeA->val > nodeB->val;  // Min-heap property: smallest element at the top
    }
};

class Solution {
public:
    /**
     * Merges k sorted linked-lists into a single sorted linked-list.
     * @param lists - A vector of ListNode pointers representing the heads of k sorted linked-lists.
     * @return ListNode* - The head of the merged sorted linked-list.
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a dummy node to act as the head of the merged list.
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Create a min-heap (priority queue) to hold the list nodes.
        priority_queue<ListNode*, vector<ListNode*>, MyComparator> pq;

        // Add the first node of each list to the priority queue.
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        // Merge all nodes into a single sorted list.
        while (!pq.empty()) {
            // Get the smallest node.
            auto ele = pq.top();
            pq.pop();

            // Add the smallest node to the merged list.
            temp->next = ele;
            temp = temp->next;

            // If there is a next node in the list, push it into the priority queue.
            if (ele->next) {
                pq.push(ele->next);
            }
        }

        // Return the head of the merged list (next of dummyNode).
        return dummyNode->next;
    }
};

// Optimizations for faster input-output operations in competitive programming.
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
```

---

### Analysis

```plaintext
Time Complexity:
- Building the initial heap takes O(k log k), where k is the number of linked-lists.
- Extracting the smallest element and inserting the next element from a list takes O(log k) for each of the n elements.
- Overall time complexity: O(n log k), where n is the total number of nodes in all lists combined.

Space Complexity:
- O(k) for the priority queue, as it holds at most k elements at any given time.
- O(1) additional space for the merged list pointers.
```

### How to Use

1. **Create Linked-Lists**: Convert input arrays to linked-lists.
2. **Instantiate Solution Object**:

   ```cpp
   Solution obj;
   ```

3. **Merge Lists**:

   ```cpp
   vector<ListNode*> lists = { /* initialize linked-lists here */ };
   ListNode* mergedHead = obj.mergeKLists(lists);
   ```

4. **Print/Use the Merged List**: Traverse `mergedHead` to access the sorted merged list.

---

### Summary

The `mergeKLists` function provides an efficient solution for merging multiple sorted linked-lists using a min-heap. By keeping track of the smallest elements at each step, it builds a merged sorted linked-list in an optimal manner. This approach ensures that the overall time complexity remains manageable even when dealing with a large number of linked-lists.

## Other Solutions

### Solution - 1 (Using MultiSet)

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
class Solution
{

  struct comparator
  {
    bool operator()(const ListNode *a, const ListNode *b) const
    {
      return a->val < b->val;
    }
  };

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    multiset<ListNode *, comparator> S;
    for (const auto &list : lists)
    {
      auto node = list;
      while (node)
      {
        S.insert(node);
        node = node->next;
      }
    }
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (const auto &node : S)
    {
      if (!head)
      {
        head = node;
        tail = node;
      }
      else
      {
        tail->next = node;
        tail = tail->next;
      }
    }
    return head;
  }
};
```

### Solution - 2 (Using the concept of Merging 2 Sorted LinkedList)

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
class Solution
{
public:
  ListNode *merge(ListNode *head1, ListNode *head2)
  {
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    while (head1 != NULL && head2 != NULL)
    {
      if (head1->val <= head2->val)
      {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;
        tail->next = NULL;
      }
      else
      {
        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
        tail->next = NULL;
      }
    }
    while (head1)
    {
      tail->next = head1;
      head1 = head1->next;
      tail = tail->next;
    }
    while (head2)
    {
      tail->next = head2;
      head2 = head2->next;
      tail = tail->next;
    }
    tail = head;
    head = head->next;
    delete tail;
    return head;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.empty())
    {
      return NULL;
    }
    ListNode *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
      head = merge(head, lists[i]);
    }
    return head;
  }
};
```
