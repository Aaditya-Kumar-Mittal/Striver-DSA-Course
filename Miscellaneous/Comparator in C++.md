# Comparator in C++

## Table of Contents

- [Comparator in C++](#comparator-in-c)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [1. Comparator Using Function Pointer](#1-comparator-using-function-pointer)
      - [2. Comparator Using Lambda Expression](#2-comparator-using-lambda-expression)
      - [3. Comparator Using Functor (Function Object)](#3-comparator-using-functor-function-object)
      - [4. Comparator Using Functor with State](#4-comparator-using-functor-with-state)
  - [Applications of Comparator](#applications-of-comparator)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In C++, a **comparator** is a function or a functional object that defines custom rules for comparing two elements. It is widely used with STL algorithms like `std::sort`, `std::priority_queue`, and more. A comparator generally accepts two values and returns a boolean based on their comparison — it is also called a **binary predicate**. Comparators allow programmers to customize the sorting or ordering of elements according to specific needs.

---

## Problem Description

Comparators enable sorting and ordering elements based on custom logic rather than the default `<` operator.  
They can be created in multiple ways:

- Using Function Pointers
- Using Lambda Expressions
- Using Functors (Function Objects)
- Using Functors with State

Comparators can also be applied to solve real-world sorting challenges based on:

- Frequency
- Number of set bits
- Segregating even and odd numbers
- Lexicographic or complex ordering

---

### Examples

**Sorting an array:**

```cpp
Input: {7, 5, 2, 1, 4, 3}
Output: {1, 2, 3, 4, 5, 7}
```

**Sorting characters by frequency:**

```cpp
Input: "Heellloooo"
Output: "oooollleeH"
```

**Sorting numbers by set bit count:**

```cpp
Input: {1, 5, 8, 13, 2, 17}
Output: {1, 8, 2, 5, 17, 13}
```

---

### Constraints

- Data elements must be comparable based on custom rules.
- Comparators must return a **boolean value**.
- Comparators must not cause **side-effects** in sorting (i.e., should be pure functions).
- Sorting should maintain **stability** if required.

---

## Approach

In C++, comparators are built in four major ways:

1. **Function Pointer**:  
   Write a standalone function and pass it by reference to the sorting function.

2. **Lambda Expression**:  
   Write inline comparator functions directly inside the sorting function call.

3. **Functor (Function Object)**:  
   Create a struct/class with overloaded `operator()` to behave like a comparator.

4. **Functor with State**:  
   Use class members to hold additional data to influence comparisons dynamically.

Each method has its own use case based on flexibility and performance requirements.

---

## Detailed Explanation of Code

### C++ Implementation

---

#### 1. Comparator Using Function Pointer

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Custom comparison function
bool customComparison(int a, int b) {
    return a < b; // Ascending order
}

int main() {
    vector<int> myVec = {7, 5, 2, 1, 4, 3};
    sort(myVec.begin(), myVec.end(), customComparison);

    cout << "Sorted Vector: ";
    for (int num : myVec) cout << num << " ";
    cout << endl;
    return 0;
}
```

✅ Output:

```bash
Sorted Vector: 1 2 3 4 5 7
```

---

#### 2. Comparator Using Lambda Expression

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVec = {4, 3, 8, 1, 7, 2};

    sort(myVec.begin(), myVec.end(), [](int a, int b) {
        return a < b;
    });

    cout << "Sorted Vector: ";
    for (int i : myVec) cout << i << " ";
    cout << endl;
    return 0;
}
```

✅ Output:

```bash
Sorted Vector: 1 2 3 4 7 8
```

---

#### 3. Comparator Using Functor (Function Object)

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Functor
struct Comparator {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

int main() {
    vector<int> myVec = {9, 2, 4, 1, 6, 3};

    sort(myVec.begin(), myVec.end(), Comparator());

    cout << "Sorted Vector: ";
    for (int i : myVec) cout << i << " ";
    cout << endl;
    return 0;
}
```

✅ Output:

```bash
Sorted Vector: 1 2 3 4 6 9
```

---

#### 4. Comparator Using Functor with State

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Functor with State
class CustomComparator {
public:
    CustomComparator(int baseValue) : baseValue_(baseValue) {}
    bool operator()(int a, int b) const {
        return (a % baseValue_) < (b % baseValue_);
    }

private:
    int baseValue_;
};

int main() {
    vector<int> myVector = {12, 24, 8, 13, 27, 40};
    sort(myVector.begin(), myVector.end(), CustomComparator(5));

    cout << "Sorted Vector: ";
    for (int num : myVector) cout << num << " ";
    cout << endl;
    return 0;
}
```

✅ Output:

```bash
Sorted Vector: 40 12 27 8 13 24
```

---

## Applications of Comparator

| Application                             | Description                                                         | Example                              |
| :-------------------------------------- | :------------------------------------------------------------------ | :----------------------------------- |
| **Sort characters by frequency**        | Sort characters in string by their frequency                        | `"Heellloooo" ➔ "oooollleeH"`        |
| **Sort by frequency and then alphabet** | Sort by increasing frequency and alphabetically descending for ties | `"hellloooo geek" ➔ "oooollleeekhg"` |
| **Sort numbers by set bit count**       | Numbers with fewer 1s in binary representation come first           | `{1,5,8,13,2,17} ➔ {1,8,2,5,17,13}`  |
| **Segregate even-odd**                  | Place even numbers before odd numbers                               | `{1,2,3,4,5,6,7} ➔ {2,4,6,1,3,5,7}`  |

---

## Complexity Analysis

| Method              | Time Complexity | Space Complexity |
| :------------------ | :-------------- | :--------------- |
| Function Pointer    | O(N log N)      | O(1)             |
| Lambda Expression   | O(N log N)      | O(1)             |
| Functor (Stateless) | O(N log N)      | O(1)             |
| Functor with State  | O(N log N)      | O(1)             |

- `N` = number of elements being sorted.
- Sorting internally uses variations of **QuickSort**, **HeapSort**, or **Insertion Sort** depending on the container and standard library implementation.

---

## How to Run the Code

### For C++

1. **Save the code** into a file named `main.cpp`.
2. **Compile** using:

   ```bash
   g++ main.cpp -o main
   ```

3. **Run** the executable:

   ```bash
   ./main
   ```

---
