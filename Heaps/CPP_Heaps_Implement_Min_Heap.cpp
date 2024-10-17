#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/**
 * @class MinHeap
 * @brief A class for a MinHeap data structure.
 *
 * This class implements a MinHeap using an array. It provides operations for
 * insertion, deletion, extraction of the minimum element, and key updates.
 */
class MinHeap
{
  int *myHeap;  // Pointer to the array storing the heap elements.
  int capacity; // Maximum number of elements that can be stored.
  int heapSize; // Current number of elements in the heap.

public:
  /**
   * @brief Constructor to initialize a MinHeap with a given capacity.
   * @param capacity The maximum size of the heap.
   */
  MinHeap(int capacity)
  {
    heapSize = 0;
    this->capacity = capacity;
    myHeap = new int[capacity];
  }

  /**
   * @brief Get the parent index of a given node index.
   * @param i The index of the current node.
   * @return The index of the parent node.
   */
  int parent(int i)
  {
    return (i - 1) / 2;
  }

  /**
   * @brief Get the left child index of a given node index.
   * @param i The index of the current node.
   * @return The index of the left child node.
   */
  int leftChild(int i)
  {
    return (2 * i) + 1;
  }

  /**
   * @brief Get the right child index of a given node index.
   * @param i The index of the current node.
   * @return The index of the right child node.
   */
  int rightChild(int i)
  {
    return (2 * i) + 2;
  }

  /**
   * @brief Inserts a new value into the heap.
   * @param value The value to be inserted.
   *
   * This function inserts the value at the end of the heap and then adjusts the heap
   * to maintain the min-heap property by comparing the new element with its parent.
   *
   * Time Complexity: O(log n) - Insertion requires at most O(log n) swaps to adjust the heap.
   */
  void insert(int value)
  {
    if (heapSize == capacity)
    {
      std::cout << "\nOverflow: Could not insert element." << std::endl;
      return;
    }

    heapSize++;
    myHeap[heapSize - 1] = value;

    for (int i = heapSize - 1; i != 0 && myHeap[parent(i)] > myHeap[i]; i = parent(i))
    {
      swap(myHeap[parent(i)], myHeap[i]);
    }
  }

  /**
   * @brief Maintains the min-heap property for the heap.
   * @param i The index of the node to heapify.
   *
   * This function checks the node at index `i` and its children. It swaps the node with
   * the smallest of its children and then recursively heapifies the affected subtree.
   *
   * Time Complexity: O(log n) - Each recursive call goes down one level of the heap.
   */
  void MinHeapify(int i)
  {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    if (left < heapSize && myHeap[left] < myHeap[smallest])
    {
      smallest = left;
    }

    if (right < heapSize && myHeap[right] < myHeap[smallest])
    {
      smallest = right;
    }

    if (smallest != i)
    {
      swap(myHeap[i], myHeap[smallest]);
      MinHeapify(smallest);
    }
  }

  /**
   * @brief Gets the minimum element from the heap.
   * @return The minimum element in the heap.
   *
   * Time Complexity: O(1) - The minimum element is at the root of the heap.
   */
  int getMin()
  {
    return myHeap[0];
  }

  /**
   * @brief Extracts the minimum element from the heap.
   * @return The minimum element extracted.
   *
   * This function removes the root of the heap (the minimum element), replaces it
   * with the last element in the heap, decreases the heap size, and calls `MinHeapify`
   * to adjust the heap.
   *
   * Time Complexity: O(log n) - `MinHeapify` is called to maintain the heap property.
   */
  int extractMin()
  {
    if (heapSize <= 0)
    {
      return INT_MAX;
    }

    if (heapSize == 1)
    {
      heapSize--;
      return myHeap[0];
    }

    int root = myHeap[0];
    swap(myHeap[0], myHeap[heapSize - 1]);
    heapSize--;
    MinHeapify(0);

    return root;
  }

  /**
   * @brief Decreases the value of a key at a given index.
   * @param i The index of the element to decrease.
   * @param new_value The new value to set.
   *
   * This function decreases the value at index `i` and then adjusts the heap to maintain
   * the min-heap property by moving the element upwards if necessary.
   *
   * Time Complexity: O(log n) - Adjustment may involve moving up the tree.
   */
  void decreaseKey(int i, int new_value)
  {
    myHeap[i] = new_value;

    while (i != 0 && myHeap[parent(i)] > myHeap[i])
    {
      swap(myHeap[parent(i)], myHeap[i]);
      i = parent(i);
    }
  }

  /**
   * @brief Deletes a key at a given index.
   * @param i The index of the element to delete.
   *
   * This function decreases the key value at index `i` to `INT_MIN`, then extracts the
   * minimum to remove the element from the heap.
   *
   * Time Complexity: O(log n) - `decreaseKey` and `extractMin` both operate in O(log n) time.
   */
  void deleteKey(int i)
  {
    decreaseKey(i, INT_MIN);
    extractMin();
  }

  /**
   * @brief Displays the array representation of the heap.
   *
   * This function prints the current state of the heap array.
   *
   * Time Complexity: O(n) - Displays all elements of the heap.
   */
  void displayHeapArr()
  {
    std::cout << "Displaying Array Representation of Heap: " << std::endl;
    for (int i = 0; i < heapSize; i++)
    {
      std::cout << myHeap[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  MinHeap h(11);
  h.insert(3);
  h.displayHeapArr();
  h.insert(2);
  h.displayHeapArr();
  h.deleteKey(1);
  h.displayHeapArr();
  h.insert(15);
  h.displayHeapArr();
  h.insert(5);
  h.displayHeapArr();
  h.insert(4);
  h.displayHeapArr();
  h.insert(45);
  h.displayHeapArr();
  cout << h.extractMin() << " ";
  h.displayHeapArr();
  cout << h.getMin() << endl;
  h.displayHeapArr();
  h.decreaseKey(2, 1);
  h.displayHeapArr();
  cout << h.getMin() << endl;
  h.displayHeapArr();
  return 0;
}
