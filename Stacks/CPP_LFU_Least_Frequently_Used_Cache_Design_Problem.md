# LFU (Least Frequently Used Cache) Design and Implementation

## Description

The **LFUCache** (Least Frequently Used Cache) is a data structure that efficiently manages a cache with a fixed capacity. It stores key-value pairs and ensures that, when the cache reaches its capacity, it evicts the least frequently used key. If there is a tie between keys with the same frequency, the least recently used key among them is evicted. This allows for optimized cache management, favoring keys that are accessed more frequently.

## Problem Statement

Design a class `LFUCache` that follows the constraints of a Least Frequently Used (LFU) cache. The class should support the following operations:

- **`LFUCache(int capacity)`**: Initializes the cache with a positive integer `capacity`.
- **`int get(int key)`**: Returns the value of the given `key` if it exists in the cache. Otherwise, returns `-1`.
- **`void put(int key, int value)`**: Updates the value of the given `key` if it exists. Otherwise, adds the `key-value` pair to the cache. If the number of keys exceeds `capacity`, it should invalidate and remove the least frequently used key. In the case of a tie in frequency, the least recently used key should be invalidated.

### Requirements

- Both `get` and `put` operations should have an average time complexity of **O(1)**.
- Utilize a combination of **hash maps** and **doubly linked lists** to ensure efficient operations:
  - **`mapNodes`** (`map<int, Node*>`): Maps keys to their corresponding nodes for O(1) access.
  - **`mapLists`** (`map<int, FrequencyList*>`): Maps frequencies to doubly linked lists (`FrequencyList`) containing nodes with the same frequency.
  - The **`FrequencyList`** class maintains the order of nodes with the same frequency, supporting efficient addition and deletion of nodes.
- A counter `minFreq` is used to track the minimum frequency among all nodes to quickly find the list of least frequently used nodes.

### Constraints

- `1 <= capacity <= 10^4`
- `0 <= key <= 10^5`
- `0 <= value <= 10^9`
- At most `2 * 10^5` calls will be made to `get` and `put`.

### Example

```cpp
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]

Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = use counter for key x
// cache=[] shows the last used order for tiebreakers (leftmost element is most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key with cnt(2)=1, evicts key 2
                // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have cnt=2, but 1 is LRU, evicts key 1
                // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                // cache=[4,3], cnt(4)=2, cnt(3)=3
```

### Implementation

The `LFUCache` is implemented using a combination of maps and doubly linked lists for managing cache entries and their frequencies.

```cpp
/**
 * Class representing a Node in the doubly linked list.
 * Each node stores the key, value, and its current access count.
 */
class Node {
public:
    int key, value, count;
    Node *next, *prev;

    Node(int _key, int _value) : key(_key), value(_value), count(1) {}
};

/**
 * Class representing a doubly linked list for nodes with the same frequency.
 * Provides methods to add a node to the front and delete a given node.
 */
class FrequencyList {
public:
    int listSize;
    Node *head, *tail;

    FrequencyList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        listSize = 0;
    }

    void addFront(Node* node) {
        Node* headNext = head->next;
        node->next = headNext;
        node->prev = head;
        head->next = node;
        headNext->prev = node;
        listSize++;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        listSize--;
    }
};

/**
 * LFUCache class handles the caching operations using two maps:
 * - mapLists: Maps frequencies to FrequencyLists containing nodes.
 * - mapNodes: Maps keys to their corresponding Node pointers.
 */
class LFUCache {
    map<int, FrequencyList*> mapLists;
    map<int, Node*> mapNodes;
    int capacity, minFreq, currSize;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFrequencyList(Node* node) {
        mapNodes.erase(node->key);

        // Remove the node from its current frequency list
        mapLists[node->count]->deleteNode(node);

        // If node's count was the minimum frequency and the list is now empty, increment minFreq
        if (node->count == minFreq && mapLists[node->count]->listSize == 0) {
            minFreq++;
        }

        // Update to the next higher frequency list
        FrequencyList* nextHigherFrequencyList = new FrequencyList();
        if (mapLists.find(node->count + 1) != mapLists.end()) {
            nextHigherFrequencyList = mapLists[node->count + 1];
        }

        node->count += 1;
        nextHigherFrequencyList->addFront(node);
        mapLists[node->count] = nextHigherFrequencyList;
        mapNodes[node->key] = node;
    }

    int get(int key) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        if (mapNodes.find(key) == mapNodes.end())
            return -1;

        Node* temp = mapNodes[key];
        int val = temp->value;
        updateFrequencyList(temp);
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mapNodes.find(key) != mapNodes.end()) {
            Node* node = mapNodes[key];
            node->value = value;
            updateFrequencyList(node);
        } else {
            if (currSize == capacity) {
                // Remove the least frequently used node from the cache
                FrequencyList* list = mapLists[minFreq];
                mapNodes.erase(list->tail->prev->key);
                mapLists[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }

            currSize++;
            minFreq = 1;

            FrequencyList* list = new FrequencyList();
            if (mapLists.find(minFreq) != mapLists.end()) {
                list = mapLists[minFreq];
            }

            Node* node = new Node(key, value);
            list->addFront(node);
            mapNodes[key] = node;
            mapLists[minFreq] = list;
        }
    }
};
```

### How It Works

- **`get` operation**:
  - Checks if the key exists in the `mapNodes`. If not, returns `-1`.
  - If the key exists, retrieves the node, updates its frequency, and returns its value.
- **`put` operation**:
  - If the key already exists, updates the value and increases its frequency.
  - If the key is new:
    - Checks if the cache is full. If full, removes the least frequently used node from `mapLists[minFreq]`.
    - Inserts the new node into the frequency list with a count of `1`.
- **`updateFrequencyList` function**:
  - Removes a node from its current frequency list.
  - Adds the node to the next higher frequency list.
  - Adjusts `minFreq` when necessary

.

### Complexity Analysis

```plaintext
Time Complexity:
- `get`: O(1) on average due to the map and doubly linked list operations.
- `put`: O(1) on average for updates and insertion.

Space Complexity:
- O(capacity + distinct keys) for storing nodes and frequency lists.
```

### Usage

```cpp
LFUCache* obj = new LFUCache(capacity);
int value = obj->get(key);
obj->put(key, value);
```

The above code creates an instance of the LFUCache with the specified capacity, allows for insertion of key-value pairs, and retrieves values using the `get` function.

### GeeksForGeeks Implementation

```cpp
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/**
 * Class representing a Node in the doubly linked list.
 * Each node stores the key, value, and its current access count.
 */
class Node {
public:
    int key, value, count;
    Node *next, *prev;

    Node(int _key, int _value) : key(_key), value(_value), count(1) {}
};

/**
 * Class representing a doubly linked list for nodes with the same frequency.
 * Provides methods to add a node to the front and delete a given node.
 */
class FrequencyList {
public:
    int listSize;
    Node *head, *tail;

    FrequencyList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        listSize = 0;
    }

    void addFront(Node* node) {
        Node* headNext = head->next;
        node->next = headNext;
        node->prev = head;
        head->next = node;
        headNext->prev = node;
        listSize++;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        listSize--;
    }
};

/**
 * LFUCache class handles the caching operations using two maps:
 * - mapLists: Maps frequencies to FrequencyLists containing nodes.
 * - mapNodes: Maps keys to their corresponding Node pointers.
 */
class LFUCache {
    map<int, FrequencyList*> mapLists;
    map<int, Node*> mapNodes;
    int capacity, minFreq, currSize;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFrequencyList(Node* node) {
        int currentFreq = node->count;
        mapLists[currentFreq]->deleteNode(node);

        // If the current frequency list is empty and it was the minimum frequency, increment minFreq
        if (currentFreq == minFreq && mapLists[currentFreq]->listSize == 0) {
            minFreq++;
        }

        // Move the node to the next higher frequency list
        node->count++;
        FrequencyList* nextList;
        if (mapLists.find(node->count) != mapLists.end()) {
            nextList = mapLists[node->count];
        } else {
            nextList = new FrequencyList();
            mapLists[node->count] = nextList;
        }
        nextList->addFront(node);

        // Update mapNodes with the new frequency
        mapNodes[node->key] = node;
    }

    int get(int key) {
        if (mapNodes.find(key) == mapNodes.end()) return -1;
        Node* node = mapNodes[key];
        int value = node->value;
        updateFrequencyList(node);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mapNodes.find(key) != mapNodes.end()) {
            // Update the value of the existing node
            Node* node = mapNodes[key];
            node->value = value;
            updateFrequencyList(node);
        } else {
            // If the cache is full, evict the least frequently used node
            if (currSize == capacity) {
                FrequencyList* list = mapLists[minFreq];
                Node* nodeToEvict = list->tail->prev;
                mapNodes.erase(nodeToEvict->key);
                list->deleteNode(nodeToEvict);
                currSize--;
            }

            // Add the new node with frequency 1
            currSize++;
            minFreq = 1;
            FrequencyList* list;
            if (mapLists.find(minFreq) != mapLists.end()) {
                list = mapLists[minFreq];
            } else {
                list = new FrequencyList();
                mapLists[minFreq] = list;
            }
            Node* newNode = new Node(key, value);
            list->addFront(newNode);
            mapNodes[key] = newNode;
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        int capacity; cin >> capacity;
        LFUCache* obj = new LFUCache(capacity);

        int runs; cin >> runs;
        for(int i = 0;i<runs;i++){
            int s; cin >> s;
            if(s==1){
                int key; cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }else{
                int key,value;
                cin >> key >> value;
                obj->put(key,value);
            }



        }



    }
}

// } Driver Code Ends
```

## Using Heap

```cpp
// C++ program for LFU cache implementation
#include <bits/stdc++.h>
using namespace std;

// Generic function to swap two pairs
void swap(pair<int, int> &a, pair<int, int> &b)
{
  pair<int, int> temp = a;
  a = b;
  b = temp;
}

// Returns the index of the parent node
inline int parent(int i)
{
  return (i - 1) / 2;
}

// Returns the index of the left child node
inline int left(int i)
{
  return 2 * i + 1;
}

// Returns the index of the right child node
inline int right(int i)
{
  return 2 * i + 2;
}

// Self made heap to Rearranges
// the nodes in order to maintain the heap property
void heapify(vector<pair<int, int>> &v,
             unordered_map<int, int> &m, int i, int n)
{
  int l = left(i), r = right(i), minim;
  if (l < n)
    minim = ((v[i].second < v[l].second) ? i : l);
  else
    minim = i;
  if (r < n)
    minim = ((v[minim].second < v[r].second) ? minim : r);
  if (minim != i)
  {
    m[v[minim].first] = i;
    m[v[i].first] = minim;
    swap(v[minim], v[i]);
    heapify(v, m, minim, n);
  }
}

// Function to Increment the frequency
// of a node and rearranges the heap
void increment(vector<pair<int, int>> &v,
               unordered_map<int, int> &m, int i, int n)
{
  ++v[i].second;
  heapify(v, m, i, n);
}

// Function to Insert a new node in the heap
void insert(vector<pair<int, int>> &v,
            unordered_map<int, int> &m, int value, int &n)
{

  if (n == v.size())
  {
    m.erase(v[0].first);
    cout << "Cache block " << v[0].first
         << " removed.\n";
    v[0] = v[--n];
    heapify(v, m, 0, n);
  }
  v[n++] = make_pair(value, 1);
  m.insert(make_pair(value, n - 1));
  int i = n - 1;

  // Insert a node in the heap by swapping elements
  while (i && v[parent(i)].second > v[i].second)
  {
    m[v[i].first] = parent(i);
    m[v[parent(i)].first] = i;
    swap(v[i], v[parent(i)]);
    i = parent(i);
  }
  cout << "Cache block " << value << " inserted.\n";
}

// Function to refer to the block value in the cache
void refer(vector<pair<int, int>> &cache, unordered_map<int, int> &indices, int value, int &cache_size)
{
  if (indices.find(value) == indices.end())
    insert(cache, indices, value, cache_size);
  else
    increment(cache, indices, indices[value], cache_size);
}

// Driver Code
int main()
{
  int cache_max_size = 4, cache_size = 0;
  vector<pair<int, int>> cache(cache_max_size);
  unordered_map<int, int> indices;
  refer(cache, indices, 1, cache_size);
  refer(cache, indices, 2, cache_size);
  refer(cache, indices, 1, cache_size);
  refer(cache, indices, 3, cache_size);
  refer(cache, indices, 2, cache_size);
  refer(cache, indices, 4, cache_size);
  refer(cache, indices, 5, cache_size);
  return 0;
}
```
