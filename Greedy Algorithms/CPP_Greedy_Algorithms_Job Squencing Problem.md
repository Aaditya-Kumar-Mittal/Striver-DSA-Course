# Job Sequencing Problem

## Table of Contents

- [Job Sequencing Problem](#job-sequencing-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Algorithm Explanation](#algorithm-explanation)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [Other Solutions](#other-solutions)
    - [CPP DSU](#cpp-dsu)
    - [Using Disjoint Set](#using-disjoint-set)

---

## Introduction

The **Job Sequencing Problem** aims to schedule jobs in a way that maximizes profit. Each job has a deadline and a profit, and every job takes exactly one unit of time. Jobs can only be performed if they are completed within their respective deadlines.

---

## Problem Description

Given an array `jobs[]`, where each element is a tuple `(jobId, deadline, profit)`, find:

1. The **maximum profit** that can be earned.
2. The **number of jobs** that can be completed.

The jobs must be scheduled such that:

- Each job is completed within its deadline.
- Only one job is executed at any given time.

### Examples

#### Example 1

**Input:**  
`jobs[] = [(1,4,20), (2,1,1), (3,1,40), (4,1,30)]`  
**Output:**  
`[2, 60]`  
**Explanation:** Job 1 and Job 3 can be completed with a maximum profit of 60 (20 + 40).

#### Example 2

**Input:**  
`jobs[] = [(1,2,100), (2,1,19), (3,2,27), (4,1,25), (5,1,15)]`  
**Output:**  
`[2, 127]`  
**Explanation:** 2 jobs can be done with a maximum profit of 127 (100 + 27).

---

## Constraints

- `1 <= jobs.size <= 10^5`
- `1 <= deadline, jobId <= jobs.size`
- `1 <= profit <= 500`

---

## Approach

### Algorithm Explanation

1. **Sort Jobs by Profit**: Sort the jobs in descending order of profit to prioritize higher-profit jobs.
2. **Find Maximum Deadline**: Determine the latest deadline among all jobs.
3. **Allocate Slots**: Use a `slot` array of size `maxDeadline + 1` to keep track of free time slots. Each slot corresponds to a unit of time.
4. **Schedule Jobs**:
   - Iterate through the sorted jobs.
   - For each job, try to assign it to the latest available slot before its deadline.
   - If a slot is available, schedule the job and add its profit to the total.

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
};

class Solution {
public:
    static bool comparison(Job a, Job b) {
        return a.profit > b.profit; // Sort by profit in descending order
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        // Sort jobs by profit in descending order
        sort(jobs, jobs + n, comparison);

        // Find the maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }

        // Slot array to keep track of free slots
        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0, jobProfit = 0;

        // Assign jobs to slots
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (slot[j] == -1) { // If slot is free
                    slot[j] = i;
                    countJobs++;
                    jobProfit += jobs[i].profit;
                    break;
                }
            }
        }

        return {countJobs, jobProfit};
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Job {
    int id, deadline, profit;

    Job(int id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

class Solution {
    public static int[] JobScheduling(Job[] jobs, int n) {
        // Sort jobs by profit in descending order
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        // Find the maximum deadline
        int maxDeadline = 0;
        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }

        // Slot array to keep track of free slots
        int[] slot = new int[maxDeadline + 1];
        Arrays.fill(slot, -1);

        int countJobs = 0, jobProfit = 0;

        // Assign jobs to slots
        for (Job job : jobs) {
            for (int j = job.deadline; j > 0; j--) {
                if (slot[j] == -1) { // If slot is free
                    slot[j] = job.id;
                    countJobs++;
                    jobProfit += job.profit;
                    break;
                }
            }
        }

        return new int[] {countJobs, jobProfit};
    }
}
```

---

## Complexity Analysis

| Approach        | Time Complexity              | Space Complexity |
| --------------- | ---------------------------- | ---------------- |
| Sorting         | O(N log N)                   | O(1)             |
| Slot Allocation | O(N × maxDeadline)           | O(maxDeadline)   |
| **Overall**     | O(N log N + N × maxDeadline) | O(maxDeadline)   |

This algorithm is efficient for the problem constraints, as the sorting dominates the time complexity.

## Other Solutions

### CPP DSU

```cpp
class Solution {
  public:
    int par[1000000];

    int find(int u) {
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void merge(int u, int v) {
        u = par[u];
        v = par[v];
        if(u != v) {
            par[v] = u;
        }
    }

    static bool comp(Job job1, Job job2) {
        return job1.profit > job2.profit;
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        for(int i = 0; i < 1000000; i++) {
            par[i] = i;
        }
        sort(jobs, jobs + n, comp);
        int ans = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            int availableSlot = find(jobs[i].deadline);
            if (availableSlot > 0) {
                cnt++;
                ans += jobs[i].profit;
                merge(availableSlot - 1, availableSlot);
            }
        }
        return {cnt, ans};
    }
};
```

### Using Disjoint Set

```cpp
// C++ Program to find the maximum profit job sequence
// from a given array of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

// A structure to represent various attributes of a Job
struct Job
{
    // Each job has id, deadline and profit
    char id;
    int deadLine, profit;
};

// A Simple Disjoint Set Data Structure
struct DisjointSet
{
    int *parent;

    // Constructor
    DisjointSet(int n)
    {
        parent = new int[n+1];

        // Every node is a parent of itself
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Path Compression
    int find(int s)
    {
        /* Make the parent of the nodes in the path
           from u--> parent[u] point to parent[u] */
        if (s == parent[s])
            return s;
        return parent[s] = find(parent[s]);
    }

    // Makes u as parent of v.
    void merge(int u, int v)
    {
        //update the greatest available
        //free slot to u
        parent[v] = u;
    }
};

// Used to sort in descending order on the basis
// of profit for each job
bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}

// Functions returns the maximum deadline from the set
// of jobs
int findMaxDeadline(struct Job arr[], int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i].deadLine);
    return ans;
}

int printJobScheduling(Job arr[], int n)
{
    // Sort Jobs in descending order on the basis
    // of their profit
    sort(arr, arr + n, cmp);

    // Find the maximum deadline among all jobs and
    // create a disjoint set data structure with
    // maxDeadline disjoint sets initially.
    int maxDeadline = findMaxDeadline(arr, n);
    DisjointSet ds(maxDeadline);

    // Traverse through all the jobs
    for (int i = 0; i < n; i++)
    {
        // Find the maximum available free slot for
        // this job (corresponding to its deadline)
        int availableSlot = ds.find(arr[i].deadLine);

        // If maximum available free slot is greater
        // than 0, then free slot available
        if (availableSlot > 0)
        {
            // This slot is taken by this job 'i'
            // so we need to update the greatest
            // free slot. Note that, in merge, we
            // make first parameter as parent of
            // second parameter. So future queries
            // for availableSlot will return maximum
            // available slot in set of
            // "availableSlot - 1"
            ds.merge(ds.find(availableSlot - 1),
                             availableSlot);

            cout << arr[i].id << " ";
        }
    }
}

// Driver code
int main()
{
    Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },
                   { 'c', 2, 27 },  { 'd', 1, 25 },
                   { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following jobs need to be "
         << "executed for maximum profit\n";
    printJobScheduling(arr, n);
    return 0;
}
```
