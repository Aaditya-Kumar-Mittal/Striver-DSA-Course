# Task Scheduler Problem (LeetCode 621)

## Problem Statement

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number `n`. Each CPU interval can either be idle or execute one task. Tasks can be completed in any order, but there is a constraint: **there must be a gap of at least `n` intervals between two tasks with the same label**.

### Objective

Return the **minimum number of CPU intervals** required to complete all tasks.

### Example 1

**Input**:

```bash
tasks = ["A", "A", "A", "B", "B", "B"], n = 2
```

**Output**:

```bash
8
```

**Explanation**: A possible sequence is:

```bash
A -> B -> idle -> A -> B -> idle -> A -> B
```

After completing task A, we must wait 2 intervals before doing A again. The same applies to task B. Therefore, we add idle intervals between repetitions of A and B.

### Example 2

**Input**:

```bash
tasks = ["A", "C", "A", "B", "D", "B"], n = 1
```

**Output**:

```bash
6
```

**Explanation**: A possible sequence is:

```bash
A -> B -> C -> D -> A -> B
```

With a cooling interval of 1, each task can be repeated after just one other task.

### Example 3

**Input**:

```bash
tasks = ["A", "A", "A", "B", "B", "B"], n = 3
```

**Output**:

```bash
10
```

**Explanation**: A possible sequence is:

```bash
A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B
```

Since there are only two types of tasks, A and B, which need to be separated by 3 intervals, we add idle intervals.

### Constraints

- `1 <= tasks.length <= 10^4`
- `tasks[i]` is an uppercase English letter.
- `0 <= n <= 100`

---

## Solution Explanation

### Approach

1. **Frequency Count**:

   - Use an array `freqArr` of size 26 to store the frequency of each task.
   - Iterate over the `tasks` array and count occurrences of each task.

2. **Use a Max-Heap**:

   - Use a priority queue (`pq`) to always process the most frequent remaining task.
   - Push all non-zero frequencies into the priority queue.

3. **Process Tasks with Cooling Intervals**:

   - Use a loop to process tasks in batches of `n + 1` intervals (to account for the cooling period).
   - Store temporarily processed tasks in a `temp` vector.
   - After processing, push tasks back into the priority queue if they still have a positive frequency.

4. **Calculate Time**:
   - If the priority queue becomes empty after a batch, add the size of the `temp` vector to `time`.
   - Otherwise, add `n + 1` to `time` to account for idle intervals.

### Time Complexity

- **Time Complexity**: `O(N * log K)` where `N` is the number of tasks, and `K` is the number of unique tasks (up to 26).
- **Space Complexity**: `O(1)` for `freqArr` and `O(K)` for the priority queue.

---

## Code

```cpp
class Solution {
public:
    /**
     * @brief Calculates the minimum number of intervals required to complete all tasks with cooling period 'n'.
     *
     * @param tasks Vector of characters representing tasks labeled from 'A' to 'Z'.
     * @param n The cooling interval between two identical tasks.
     * @return int Minimum number of intervals required.
     */
    int leastInterval(vector<char>& tasks, int n) {
        // Optimization for faster input-output operations.
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // Step 1: Create a frequency array for tasks.
        vector<int> freqArr(26, 0);
        for (char c : tasks) {
            freqArr[c - 'A']++;
        }

        // Step 2: Use a max heap (priority queue) to store frequencies.
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freqArr[i] > 0) {
                pq.push(freqArr[i]);
            }
        }

        int time = 0;

        // Step 3: Process tasks in groups of 'n + 1' intervals.
        while (!pq.empty()) {
            vector<int> temp;

            // Process up to 'n + 1' intervals.
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq); // Store processed task with decremented frequency.
                }
            }

            // Step 4: Push remaining tasks back into the queue.
            for (int f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            // Step 5: Calculate total time based on remaining tasks.
            if (pq.empty()) {
                time += temp.size(); // No more tasks left, add the size of processed tasks.
            } else {
                time += n + 1; // Add 'n + 1' to account for idle intervals.
            }
        }

        return time;
    }
};
```

---

Here’s the detailed analysis in Markdown format:

---

## Analysis

### Time Complexity: `O(N * log K)`

1. **Building the Frequency Array: `O(N)`**

   - The frequency array `freqArr` has 26 slots, each representing a letter from 'A' to 'Z'.
   - As we iterate over the `tasks` vector (of length `N`) to count the frequency of each task, it takes `O(N)` time.
   - Example: For `tasks = ["A", "A", "B", "B", "C"]`, we record the frequencies of 'A', 'B', and 'C' in `freqArr`.

2. **Inserting into the Priority Queue: `O(K * log K)`**

   - After building the frequency array, we add each non-zero frequency into a max heap (priority queue).
   - Here, `K` is the number of unique tasks, which can be up to 26 (from 'A' to 'Z').
   - Inserting each of the `K` elements into the heap takes `O(log K)` time, so this step is `O(K * log K)`.

3. **Processing Tasks with Priority Queue: `O(N * log K)`**

   - During each iteration, we extract the most frequent task from the priority queue.
   - For every task processed, we decrement its frequency and reinsert it into the queue if it is still positive.
   - Extracting from and reinserting into the heap takes `O(log K)` time.
   - Since the number of tasks is `N`, this step takes `O(N * log K)` time.

4. **Overall Time Complexity: O(N \* log K)**
   - The dominant factor in this problem is processing the tasks using the priority queue, which results in a time complexity of `O(N * log K)`.
   - Even though `K` is at most 26 (fixed for uppercase English letters), it is still considered for completeness.

### Space Complexity: `O(1) + O(K) = O(K)`

1. **Frequency Array: O(1)**

   - The frequency array `freqArr` of size 26 is used to store the count of each task.
   - Since the size is fixed (26 for uppercase English letters), it is considered `O(1)` space.

2. **Priority Queue: `O(K)`**

   - The priority queue holds up to `K` elements (the unique tasks with non-zero frequency).
   - In the worst case, when all tasks are different, `K` can be 26.
   - Therefore, the space used by the priority queue is `O(K)`.

3. **Temporary Storage for Processing: `O(K)`**

   - During each round of processing, we use a temporary vector to store tasks being processed before reinserting them.
   - The size of this temporary vector can be up to `K` (in the worst case, all unique tasks).
   - Thus, this also contributes to `O(K)` space complexity.

4. **Overall Space Complexity: `O(K)`**
   - Even though the frequency array is `O(1)`, the main space-consuming structure is the priority queue, making the overall space complexity `O(K)`.

## Other Soluitons

### Solution - 1

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(begin(freq) , end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;

        for(int i=24; i>=0; i--){
            idel -= min(chunk,freq[i]);
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};
```

### Solution - 2

```cpp
class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    unordered_map<char, int> freqMap;

    for (char task : tasks)
    {
      freqMap[task]++;
    }

    priority_queue<int> maxHeap;
    for (auto it : freqMap)
    {
      maxHeap.push(it.second);
    }

    int maxFreq = maxHeap.top();
    int maxCount = 0;

    while (!maxHeap.empty() && maxHeap.top() == maxFreq)
    {
      maxCount++;
      maxHeap.pop();
    }

    int result = (maxFreq - 1) * (n + 1) + maxCount;

    return max(result, (int)tasks.size());
  }
};
```

### Solution - 3

```cpp
class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    int cnt = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < tasks.size(); i++)
    {
      mp[tasks[i]]++;
      cnt = max(cnt, mp[tasks[i]]);
    }
    int ans = (cnt - 1) * (n + 1);
    for (auto it : mp)
      if (it.second == cnt)
        ans++;
    return max(ans, (int)tasks.size());
  }
};
```
