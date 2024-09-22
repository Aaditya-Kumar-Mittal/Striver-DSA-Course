//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
  int data;
  QueueNode *next;

  /**
   * Constructor to create a new node.
   *
   * @param a The data to be stored in the node.
   */
  QueueNode(int a)
  {
    data = a;
    next = NULL;
  }
};

struct MyQueue
{
  QueueNode *front;
  QueueNode *rear;

  /**
   * Constructor to initialize an empty queue.
   */
  MyQueue()
  {
    front = rear = NULL;
  }

  /**
   * Function to push an element into the queue.
   *
   * @param x The element to be added to the queue.
   */
  void push(int x);

  /**
   * Function to pop the front element from the queue.
   *
   * @return The value of the front element after removal, or -1 if the queue is empty.
   */
  int pop();
};

int main()
{
  int T;
  cin >> T; // Number of test cases
  while (T--)
  {
    MyQueue *sq = new MyQueue(); // Create a new queue instance

    int Q;
    cin >> Q; // Number of operations to be performed
    while (Q--)
    {
      int QueryType = 0;
      cin >> QueryType;
      if (QueryType == 1)
      {
        int a;
        cin >> a;
        sq->push(a); // Push element into the queue
      }
      else if (QueryType == 2)
      {
        cout << sq->pop() << " "; // Pop element from the queue and print it
      }
    }
    cout << endl;
  }
}
// } Driver Code Ends

/**
 * Structure of a node in the Queue:
 *
 * struct QueueNode {
 *     int data;
 *     QueueNode *next;
 *
 *     // Constructor to initialize the node
 *     QueueNode(int a) {
 *         data = a;
 *         next = NULL;
 *     }
 * };
 *
 * Structure of the Queue:
 *
 * struct MyQueue {
 *     QueueNode *front;
 *     QueueNode *rear;
 *
 *     // Constructor to initialize the queue
 *     MyQueue() {
 *         front = rear = NULL;
 *     }
 *
 *     // Function to push an element into the queue
 *     void push(int);
 *
 *     // Function to pop the front element from the queue
 *     int pop();
 * };
 */

/**
 * Function to push an element into the queue.
 *
 * @param x The element to be added to the queue.
 */
void MyQueue::push(int x)
{
  // Create a new node
  QueueNode *temp = new QueueNode(x);

  // If the queue is empty, set both front and rear to the new node
  if (front == nullptr)
  {
    front = rear = temp;
  }
  else
  {
    // Link the new node at the end of the queue and update rear
    rear->next = temp;
    rear = temp;
  }
}

/**
 * Function to pop the front element from the queue.
 *
 * @return The value of the front element after removal, or -1 if the queue is empty.
 */
int MyQueue::pop()
{
  // If the queue is empty, return -1
  if (front == nullptr)
    return -1;

  // Store the front node's data to return
  QueueNode *temp = front;
  int element = temp->data;

  // Move the front pointer to the next node
  front = front->next;

  // Free memory for the removed node
  delete temp;

  return element;
}

/**
 * Problem Name: Queue Implementation Using Linked List
 *
 * Time Complexity:
 * - `push`: O(1), because we always insert an element at the rear (end) of the queue in constant time.
 * - `pop`: O(1), because we always remove the front element in constant time.
 *
 * Space Complexity:
 * - O(N), where N is the number of elements in the queue, as each element is stored in a node of the linked list.
 *
 * Explanation:
 * 1. Push Operation:
 *    - A new node is created for the incoming element. If the queue is empty, both `front` and `rear` point to this node. Otherwise, the new node is linked to the `rear`, and the `rear` pointer is updated.
 *
 * 2. Pop Operation:
 *    - The front node of the queue is removed, and the `front` pointer is updated to the next node. If the queue becomes empty, the `front` pointer will be set to `nullptr`.
 *
 * 3. Edge Cases:
 *    - When the queue is empty and a `pop` operation is performed, it returns `-1` as there is no element to remove.
 */
