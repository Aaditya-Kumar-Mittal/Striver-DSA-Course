# Custom Sorting Techniques in C++

## Table of Contents

- [Custom Sorting Techniques in C++](#custom-sorting-techniques-in-c)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Example 1: Sorting integers](#example-1-sorting-integers)
    - [Example 2: Sorting students](#example-2-sorting-students)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Level 1: Basic Custom Sort (Increasing/Decreasing)](#level-1-basic-custom-sort-increasingdecreasing)
    - [Level 2: Custom Sort on Pairs](#level-2-custom-sort-on-pairs)
    - [Level 3: Min Heap and Max Heap using Custom Comparator](#level-3-min-heap-and-max-heap-using-custom-comparator)
    - [Level 4: Ordering in Sets and PriorityQueue for User-Defined Data Types](#level-4-ordering-in-sets-and-priorityqueue-for-user-defined-data-types)
      - [Comparator for sorting](#comparator-for-sorting)
      - [Sort using vector](#sort-using-vector)
      - [Sort using priority queue](#sort-using-priority-queue)
      - [Sort using set](#sort-using-set)
    - [Level 5: Complex Sorting Conditions](#level-5-complex-sorting-conditions)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

When solving problems like Dijkstra's Algorithm, or when working with user-defined data types, efficient ordering and custom sorting are often needed. This document explains **Custom Sorting** at different levels — from basic to complex — using **C++ Lambda functions**, **Priority Queues**, and **Sets**.

Learning how to define custom comparators gives you immense power to control how your data is ordered!

---

## Problem Description

We aim to learn:

- Sorting integers in increasing and decreasing order.
- Sorting pairs based on first and/or second elements.
- Implementing custom **Min-Heap** and **Max-Heap** using `priority_queue`.
- Sorting **User-defined types** (like `Student`) based on multiple attributes.
- Using **Set** and **PriorityQueue** with user-defined types.

---

### Examples

### Example 1: Sorting integers

```cpp
Input: [7,8,9,1,2,6,4,3]
Output (Increasing): [1,2,3,4,6,7,8,9]
Output (Decreasing): [9,8,7,6,4,3,2,1]
```

### Example 2: Sorting students

| Name   | Marks | Roll No | Enrollment No |
| ------ | ----- | ------- | ------------- |
| Chandu | 94    | 15      | 4             |
| John   | 87    | 11      | 2             |
| Daman  | 81    | 19      | 5             |
| Daman  | 81    | 19      | 7             |
| Rohan  | 33    | 2       | 1             |
| Basu   | 24    | 12      | 3             |
| Seema  | 24    | 15      | 6             |

---

### Constraints

- Enrollment number will always be unique.
- Name, rollNumber, and marks **may not** be unique.
- Sorting is multilevel and must respect all tie-breaking rules.
- Heap and Set operations must use proper custom comparators.

---

## Approach

- **Level 1:** Sort integers using simple comparators (`a < b` or `a > b`).
- **Level 2:** Sort pairs by `first`, then `second`, or a mix of both.
- **Level 3:** Customize Min-Heap and Max-Heap behavior via comparator.
- **Level 4:** Build Sets and Priority Queues for user-defined types like `Student`.
- **Level 5:** Implement layered sorting based on multiple attributes with fallback comparisons.

---

## Detailed Explanation of Code

### Level 1: Basic Custom Sort (Increasing/Decreasing)

```cpp
vector<int> arr = {7,8,9,1,2,6,4,3};

auto cmpInc = [](int a, int b) { return a < b; };
auto cmpDec = [](int a, int b) { return a > b; };

sort(arr.begin(), arr.end(), cmpInc); // Increasing
sort(arr.begin(), arr.end(), cmpDec); // Decreasing
```

- **cmpInc:** Sorts in ascending order.
- **cmpDec:** Sorts in descending order.

---

### Level 2: Custom Sort on Pairs

```cpp
vector<pair<int,int>> arr = {{1,2},{2,2},{8,6},{1,4},{8,2},{3,7},{8,4}};

auto cmpFirst = [](pair<int,int> a, pair<int,int> b) { return a.first < b.first; };
auto cmpSecond = [](pair<int,int> a, pair<int,int> b) { return a.second < b.second; };
auto cmp_FirstInc_SecDec = [](pair<int,int> a, pair<int,int> b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
};

sort(arr.begin(), arr.end(), cmpFirst);       // Sorts by first
sort(arr.begin(), arr.end(), cmpSecond);       // Sorts by second
sort(arr.begin(), arr.end(), cmp_FirstInc_SecDec); // Sorts by first (asc) then second (desc)
```

---

### Level 3: Min Heap and Max Heap using Custom Comparator

```cpp
auto cmpForMaxHeap = [](int a, int b) { return a < b; };
auto cmpForMinHeap = [](int a, int b) { return a > b; };

priority_queue<int, vector<int>, decltype(cmpForMaxHeap)> maxHeap(cmpForMaxHeap);
priority_queue<int, vector<int>, decltype(cmpForMinHeap)> minHeap(cmpForMinHeap);

for(auto i : a) minHeap.push(i), maxHeap.push(i);
```

- **Min Heap:** Root has the smallest element.
- **Max Heap:** Root has the largest element.

---

### Level 4: Ordering in Sets and PriorityQueue for User-Defined Data Types

We define a `Student` struct:

```cpp
struct Student {
    string name;
    int marks, rollNumber, enrollmentNumber;
    Student(string _name, int _marks, int _rollNumber)
        : name(_name), marks(_marks), rollNumber(_rollNumber), enrollmentNumber(++_ct) {}
    void printStudent() {
        cout<<"Name "<<name<<"\t";
        printf("rollNumber: %d \t marks: %d \t enrollmentNumber: %d \n", rollNumber, marks, enrollmentNumber);
    }
};
```

#### Comparator for sorting

```cpp
auto cmp1 = [](const Student &a, const Student &b) {
    if (a.marks != b.marks) return a.marks > b.marks;
    if (a.rollNumber != b.rollNumber) return a.rollNumber < b.rollNumber;
    if (a.name != b.name) return a.name < b.name;
    return a.enrollmentNumber < b.enrollmentNumber;
};
```

- Sorts by Marks (desc), RollNumber (asc), Name (lexicographical), Enrollment (asc).

#### Sort using vector

```cpp
sort(studentList1.begin(), studentList1.end(), cmp1);
```

#### Sort using priority queue

```cpp
auto cmp2 = [](const Student &a, const Student &b) {
    if (a.marks != b.marks) return a.marks < b.marks;
    if (a.rollNumber != b.rollNumber) return a.rollNumber > b.rollNumber;
    if (a.name != b.name) return a.name > b.name;
    return a.enrollmentNumber > b.enrollmentNumber;
};

priority_queue<Student, vector<Student>, decltype(cmp2)> pq(cmp2);
for(auto i : studentList2) pq.push(i);

while(!pq.empty()) {
    auto top = pq.top(); pq.pop();
    top.printStudent();
}
```

#### Sort using set

```cpp
set<Student, decltype(cmp1)> Set(cmp1);
for(auto i : studentList3) Set.insert(i);

for(auto i : Set) i.printStudent();
```

- **Set:** Automatically keeps elements sorted.

---

### Level 5: Complex Sorting Conditions

This involves combining multiple comparators logically for user-defined types, as shown above.

---

## Complexity Analysis

| Operation                       | Time Complexity        |
| ------------------------------- | ---------------------- |
| Sorting with `sort()`           | O(N log N)             |
| Inserting into `priority_queue` | O(log N) per insertion |
| Inserting into `set`            | O(log N) per insertion |
| Traversing Heap or Set          | O(N)                   |

- **Space Complexity**: O(N) for arrays, heaps, and sets.

---

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file, say `custom_sorting.cpp`.
2. Make sure you have a C++ compiler (like `g++`).
3. Compile the code:

   ```bash
   g++ -std=c++17 custom_sorting.cpp -o custom_sorting
   ```

4. Run the executable:

   ```bash
   ./custom_sorting
   ```

---
