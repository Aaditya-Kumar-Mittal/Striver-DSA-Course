# Greedy Problem: Shortest Job First (SJF) Average Waiting Time

## Problem Statement

In the Shortest Job First (SJF) scheduling algorithm, the process with the smallest burst time (execution time) is selected to execute next. All processes are considered available at time 0. The task is to calculate the **average waiting time** of all the processes following this scheduling policy.

Given:

- `n`: the number of processes.
- `bt[]`: an array of integers representing the burst time for each process.

The function should return the **average waiting time** of all processes, rounded down to the nearest integer.

### Examples

**Example 1:**

- **Input:** `n = 5`, `bt = [4, 3, 7, 1, 2]`
- **Output:** `4`
- **Explanation:** After sorting burst times by the shortest job policy, the calculated average waiting time is 4.

**Example 2:**

- **Input:** `n = 4`, `bt = [1, 2, 3, 4]`
- **Output:** `2`
- **Explanation:** Sorted burst times yield an average waiting time of 2.

### Constraints

- \(1 \leq n \leq 10^5\)
- \(1 \leq bt[i] \leq 10^5\)

### Approach

1. **Sort the Burst Times**:
   - Sort the `bt` array in ascending order to follow the shortest job first scheduling policy.
2. **Calculate Waiting Times**:
   - Initialize `timer` to keep track of elapsed time as jobs complete.
   - Initialize `waitTimer` to accumulate the waiting times for each process.
   - For each job, add the current `timer` value to `waitTimer`, then increment `timer` by the job’s burst time.
3. **Return Average Waiting Time**:
   - Divide `waitTimer` by the number of processes and return the floored result.

### Code with Detailed Comments

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Calculates the average waiting time following SJF scheduling.
     *
     * @param bt Vector of integers representing burst times for each process.
     * @return long long The floor of the average waiting time of all processes.
     */
    long long solve(vector<int>& bt) {
        int n = bt.size();

        // Sort burst times to follow Shortest Job First scheduling policy
        sort(bt.begin(), bt.end());

        int timer = 0;       // Tracks the total time elapsed as processes complete
        int waitTimer = 0;   // Accumulates total waiting time for all processes

        // Iterate over each burst time
        for (int i = 0; i < n; i++) {
            waitTimer += timer;  // Each process's waiting time is the current timer
            timer += bt[i];      // Add burst time of current process to the timer
        }

        return waitTimer / n;  // Calculate and return the floored average waiting time
    }
};

/**
 * Problem: Shortest Job First (SJF) Average Waiting Time
 *
 * Analysis:
 * - The algorithm follows the SJF scheduling by sorting burst times and accumulating waiting times.
 * - Each process waits until all previous processes with shorter burst times have finished.
 *
 * Time Complexity: O(n log n)
 * - Sorting the burst times is O(n log n), and iterating over the burst times is O(n).
 *
 * Space Complexity: O(1)
 * - Only a fixed amount of additional space is used, regardless of input size.
 *
 * Edge Cases:
 * - Single process: The waiting time is zero.
 * - Identical burst times: Results in linear increase of waiting time with each process in sequence.
 */
```

### Explanation of Code

- **Sorting**: By sorting `bt`, we ensure the shortest job is selected first, following the SJF policy.
- **Calculating Waiting Times**: Each process’s waiting time is equal to the total burst times of all previous processes. The total waiting time for each process is accumulated in `waitTimer`.
- **Average Calculation**: Dividing `waitTimer` by `n` yields the average waiting time.

### Complexity Analysis

- **Time Complexity**: \(O(n \log n)\)
  - Sorting the `bt` array is \(O(n \log n)\), and calculating waiting times is \(O(n)\).
- **Space Complexity**: \(O(1)\)
  - Only a few integer variables are used to store values, which do not depend on `n`.

### Edge Cases

1. **Single Process**: The waiting time is zero, as there are no other processes to wait for.
2. **Identical Burst Times**: Each subsequent process’s waiting time increases linearly due to the identical burst times.
3. **Already Sorted Burst Times**: The function should still calculate the average waiting time correctly.
