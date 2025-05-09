# std::lower_bound in C++

## Table of Contents

- [std::lower\_bound in C++](#stdlower_bound-in-c)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Syntax](#syntax)
  - [Parameters](#parameters)
  - [Return Value](#return-value)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Basic Usage](#basic-usage)
    - [Lower Bound in Arrays](#lower-bound-in-arrays)
    - [Custom Comparator with Strings](#custom-comparator-with-strings)
    - [Element Existence Check](#element-existence-check)
    - [Counting Smaller and Larger Elements](#counting-smaller-and-larger-elements)
    - [Inserting in Sorted Vector](#inserting-in-sorted-vector)
    - [Lower Bound in a Set](#lower-bound-in-a-set)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In C++, `std::lower_bound()` is a built-in algorithm that finds the first position in a **sorted range** where a specified value could be inserted without violating the order. It is part of the `<algorithm>` library.

It is particularly useful when:

- Searching for an element or determining the insertion point in a sorted collection.
- Performing binary search-based operations efficiently.

---

## Problem Description

Given a **sorted range** (like a vector or array) and a **target value**, find the **iterator** pointing to the first element that is **not less than** (`>=`) the given value.

### Examples

```cpp
vector<int> v = {10, 20, 30, 40, 50};
cout << *lower_bound(v.begin(), v.end(), 35); // Output: 40
```

```cpp
int arr[5] = {10, 20, 30, 40, 50};
cout << *lower_bound(arr, arr + 5, 35); // Output: 40
```

### Constraints

- The range must be **sorted**.
- If the element is **not found**, it returns an iterator to the position where the value could be inserted to maintain sorted order.
- Time complexity must be **O(log n)** for random-access containers (like vector, array).
- If used with a non-random access container (like set), complexity can be **O(n)**.

---

## Syntax

```cpp
std::lower_bound(first, last, val);
std::lower_bound(first, last, val, comp);
```

---

## Parameters

| Parameter         | Description                                                    |
| :---------------- | :------------------------------------------------------------- |
| `first`           | Iterator to the beginning of the range.                        |
| `last`            | Iterator to the end of the range.                              |
| `val`             | Value to compare to elements in the range.                     |
| `comp` (Optional) | A binary comparator function to customize comparison behavior. |

---

## Return Value

- Returns an **iterator** pointing to the first element **not less than** the given value.
- If all elements are smaller, returns `last`.
- If all elements are greater, returns `first`.

---

## Approach

`std::lower_bound()` internally uses a **binary search algorithm**:

- It repeatedly divides the range into halves.
- Checks if the middle element is less than the target.
- Narrows the search to the correct half until it finds the required position.

This ensures **O(log n)** performance for random access iterators.

---

## Detailed Explanation of Code

### Basic Usage

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    cout << *lower_bound(v.begin(), v.end(), 35);
    return 0;
}
```

**Output:**

```bash
40
```

Finds the smallest element greater than or equal to 35, which is 40.

---

### Lower Bound in Arrays

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    cout << *lower_bound(arr, arr + 5, 35);
    return 0;
}
```

**Output:**

```bash
40
```

---

### Custom Comparator with Strings

```cpp
#include <bits/stdc++.h>
using namespace std;

// Custom comparator for case-insensitive search
bool comp(const string &a, const string &b) {
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
                                   [](char c1, char c2) { return tolower(c1) < tolower(c2); });
}

int main() {
    vector<string> v = {"Apple", "banana", "Cherry", "date", "Elderberry"};
    auto lb = lower_bound(v.begin(), v.end(), "Avocado", comp);

    if (lb != v.end())
        cout << *lb;
    else
        cout << "Lower bound not found!";
    return 0;
}
```

**Output:**

```bash
banana
```

---

### Element Existence Check

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int val = 40;

    auto it = lower_bound(v.begin(), v.end(), val);
    if (it != v.end() && *it == val)
        cout << val << " is found.";
    else
        cout << val << " is NOT found.";

    return 0;
}
```

**Output:**

```bash
40 is found.
```

---

### Counting Smaller and Larger Elements

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int val = 35;

    auto lb = lower_bound(v.begin(), v.end(), val);

    cout << "No. of Smaller Elements: " << lb - v.begin() << endl;
    cout << "No. of Larger Elements: " << v.end() - lb << endl;

    return 0;
}
```

**Output:**

```bash
No. of Smaller Elements: 3
No. of Larger Elements: 2
```

---

### Inserting in Sorted Vector

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int val = 35;

    auto lb = lower_bound(v.begin(), v.end(), val);
    v.insert(lb, val);

    for (auto i : v)
        cout << i << " ";

    return 0;
}
```

**Output:**

```bash
10 20 30 35 40 50
```

---

### Lower Bound in a Set

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {10, 20, 30, 40, 50};

    cout << *lower_bound(s.begin(), s.end(), 35);

    return 0;
}
```

**Output:**

```bash
40
```

⚡ **Note**: Although you can use `lower_bound()` with `set` iterators, it is less efficient. Prefer using `set::lower_bound()` for `std::set`, which works in `O(log n)` time.

---

## Complexity Analysis

| Operation                               | Complexity |
| :-------------------------------------- | :--------- |
| Random-access iterators (vector, array) | O(log n)   |
| Forward iterators (set, list)           | O(n)       |
| Auxiliary Space                         | O(1)       |

---

## How to Run the Code

### For C++

1. Save the file as `main.cpp`.
2. Open terminal and compile:

   ```bash
   g++ main.cpp -o main
   ```

3. Run the executable:

   ```bash
   ./main
   ```

✔️ **Make sure** to include the necessary headers like `<algorithm>`, `<vector>`, `<set>`, and `<iostream>` as needed.

---
