# LRU (Least Recently Used) Cache Implementation Problem

## Description

The **LRUCache** (Least Recently Used Cache) is a data structure that stores a limited number of key-value pairs. It is designed to efficiently manage the cache of a fixed capacity by evicting the least recently used items when the capacity is reached. This allows frequently accessed items to stay in the cache, while older and less frequently used items are removed.

## Problem Statement

Design a class `LRUCache` that simulates the behavior of a least recently used (LRU) cache. The class should support the following operations:

- **`LRUCache(int capacity)`**: Initializes the LRU cache with a positive integer `capacity`.
- **`int get(int key)`**: Returns the value of the key if it exists in the cache. Otherwise, returns `-1`.
- **`void put(int key, int value)`**: Inserts or updates the key-value pair in the cache. If the number of keys exceeds the `capacity`, it evicts the least recently used (LRU) key to make room for the new key-value pair.

## Requirements

- Both `get` and `put` operations must have an average time complexity of **O(1)**.
- Use a **doubly linked list** and a **hash map** for optimal performance:
  - The **hash map** (`unordered_map`) maps keys to their corresponding nodes in the doubly linked list for O(1) access.
  - The **doubly linked list** keeps track of the usage order of nodes, with the head being the most recently used and the tail being the least recently used.

## Constraints

- `1 <= capacity <= 3000`
- `0 <= key <= 10^4`
- `0 <= value <= 10^5`
- At most `2 * 10^5` calls will be made to `get` and `put`.

### Example

```cpp
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

## Implementation

The LRUCache is implemented using a doubly linked list to store nodes representing cache entries, and an unordered map to provide quick access to nodes. The doubly linked list allows us to efficiently manage the order of nodes based on their usage.

```cpp
class Node {
public:
    int key, value;
    Node *next, *prev;

    Node() : next(nullptr), prev(nullptr), key(-1), value(-1) {}

    Node(int _key, int _value)
        : next(nullptr), prev(nullptr), key(_key), value(_value) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> mpp;
    Node *head, *tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* node) {
        Node* headNext = head->next;
        head->next = node;
        node->next = headNext;
        node->prev = head;
        headNext->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* temp = mpp[key];
        int res = temp->value;

        // Move the accessed node to the front (most recently used)
        deleteNode(temp);
        insertAfterHead(temp);

        return res;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            // Update the value of the existing node and move it to the front
            Node* findNode = mpp[key];
            findNode->value = value;
            deleteNode(findNode);
            insertAfterHead(findNode);
        } else {
            if (mpp.size() == capacity) {
                // Remove the least recently used (LRU) node
                Node* tailPrev = tail->prev;
                mpp.erase(tailPrev->key);
                deleteNode(tailPrev);
                delete tailPrev;
            }

            // Insert the new node at the front
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;
        }
    }
};
```

### How It Works

- **`get` operation**:
  - Checks if the key exists in the cache. If not, returns `-1`.
  - If the key exists, retrieves the corresponding node, moves it to the front (most recently used), and returns its value.
- **`put` operation**:
  - If the key already exists, updates the node's value and moves it to the front.
  - If the key does not exist, checks if the cache is full.
    - If the cache is at capacity, evicts the least recently used item (the node just before the `tail`).
    - Inserts the new node at the front (most recently used) and updates the map.

### Complexity Analysis

- **Time Complexity**:
  - `get`: O(1) - Hash map lookup and doubly linked list operations are constant time.
  - `put`: O(1) - Same as `get`, with an additional map insertion or deletion.
- **Space Complexity**:
  - O(capacity) - Space required for storing nodes in the linked list and keys in the hash map.

### Optimization

To further optimize input/output handling in competitive programming:

```cpp
inline const auto optimize = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
```

### Usage

```cpp
LRUCache lRUCache(2);
lRUCache.put(1, 1);
lRUCache.put(2, 2);
int val1 = lRUCache.get(1); // Returns 1
lRUCache.put(3, 3);         // Evicts key 2
int val2 = lRUCache.get(2); // Returns -1 (not found)
lRUCache.put(4, 4);         // Evicts key 1
int val3 = lRUCache.get(1); // Returns -1 (not found)
int val4 = lRUCache.get(3); // Returns 3
int val5 = lRUCache.get(4); // Returns 4
```

This `LRUCache` implementation effectively balances memory usage and speed, making it suitable for scenarios where quick access to recently used data is needed, such as caching in web servers or managing recent user actions.
