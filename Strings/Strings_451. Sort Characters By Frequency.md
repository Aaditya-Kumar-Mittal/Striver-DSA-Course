# Sort Characters by Frequency

## Table of Contents

- [Sort Characters by Frequency](#sort-characters-by-frequency)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [1️⃣ Frequency Count Using a Vector](#1️⃣-frequency-count-using-a-vector)
    - [2️⃣ Sorting by Frequency](#2️⃣-sorting-by-frequency)
    - [3️⃣ Constructing the Result String](#3️⃣-constructing-the-result-string)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2 (Java Bucket Sort)](#solution---2-java-bucket-sort)
  - [Alternative Approaches](#alternative-approaches)
  - [Summary](#summary)

---

## Introduction

The goal is to sort the characters of a given string in decreasing order based on their frequency of appearance.

✅ If multiple answers are possible, any valid sorted output is acceptable.  
✅ Uppercase and lowercase letters are considered different.

---

## Problem Description

### Examples

#### Example 1

🔹 Input: `s = "tree"`  
🔹 Output: `"eert"`  
🔹 Explanation: `'e' appears twice`, so it must appear before `'r'` and `'t'`. `"eetr"` is also valid.

#### Example 2

🔹 Input: `s = "cccaaa"`  
🔹 Output: `"aaaccc"` or `"cccaaa"`  
🔹 Explanation: Both `'c'` and `'a'` appear three times, so they can appear in any order together.

#### Example 3

🔹 Input: `s = "Aabb"`  
🔹 Output: `"bbAa"` or `"bbaA"`  
🔹 Explanation: `'A'` and `'a'` are treated as different characters. `"Aabb"` is incorrect because it is not sorted by frequency.

---

## Constraints

- `1 <= s.length <= 5 * 10^5`
- `s` consists of uppercase and lowercase English letters and digits.

---

## Approach

### 1️⃣ Frequency Count Using a Vector

✅ Use a vector of pairs to store characters and their frequencies.  
✅ Traverse the string and update the frequency count for each character.

### 2️⃣ Sorting by Frequency

✅ Sort the vector in descending order based on frequency using a lambda function in `sort()`.

### 3️⃣ Constructing the Result String

✅ Build the output string by appending characters frequency times.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<char, int> P;

    string frequencySort(string s) {
        vector<P> vec(123);  // Vector of pairs to store character frequency

        // Count character frequencies
        for (char& ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq + 1};
        }

        // Lambda function to sort by frequency in descending order
        auto lambda = [&](P& p1, P& p2) { return p1.second > p2.second; };
        sort(vec.begin(), vec.end(), lambda);

        string result = "";

        // Construct the result string
        for (int i = 0; i <= 122; i++) {
            if (vec[i].second > 0) {
                char ch = vec[i].first;
                int freq = vec[i].second;
                string temp(freq, ch);
                result += temp;
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.frequencySort("tree") << endl;   // Output: "eert" or "eetr"
    cout << sol.frequencySort("cccaaa") << endl; // Output: "aaaccc" or "cccaaa"
    cout << sol.frequencySort("Aabb") << endl;   // Output: "bbAa" or "bbaA"
    return 0;
}
```

---

## Complexity Analysis

| Operation           | Time Complexity | Space Complexity | Explanation                                  |
| ------------------- | --------------- | ---------------- | -------------------------------------------- |
| Counting Frequency  | `O(n)`          | `O(1)`           | Single traversal of `s` storing frequency    |
| Sorting             | `O(σ log σ)`    | `O(σ)`           | Sorting `σ` (unique) characters by frequency |
| Constructing Output | `O(n)`          | `O(n)`           | Appending characters to result string        |
| Total Complexity    | `O(n log σ)`    | `O(n)`           | Efficient for large `s`                      |

---

## How to Run the Code

### For C++

1️⃣ Compile the code:

```bash
g++ -o frequency_sort frequency_sort.cpp
```

2️⃣ Run the executable:

```bash
./frequency_sort
```

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    typedef pair<char,int> P;
    struct lambda{
        bool operator()(P &p1, P &p2){
            return p1.second < p2.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<P, vector<P>, lambda> pq;
        unordered_map<char,int> mp;

        for(auto &ch:s){
            mp[ch]++;
        }

        string res = "";

        for(auto &it:mp){
            pq.push({it.first, it.second});
        }

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            res += string(temp.second, temp.first);
        }
        return res;
    }
};
```

### Solution - 2 (Java Bucket Sort)

```java
public class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray())
            map.put(c, map.getOrDefault(c, 0) + 1);

        List<Character> [] bucket = new List[s.length() + 1];
        for (char key : map.keySet()) {
            int frequency = map.get(key);
            if (bucket[frequency] == null) bucket[frequency] = new ArrayList<>();
            bucket[frequency].add(key);
        }

        StringBuilder sb = new StringBuilder();
        for (int pos = bucket.length - 1; pos >= 0; pos--)
            if (bucket[pos] != null)
                for (char c : bucket[pos])
                    for (int i = 0; i < pos; i++)
                        sb.append(c);

        return sb.toString();
    }
}
```

## Alternative Approaches

| Approach                            | Time Complexity | Space Complexity | Notes                     |
| ----------------------------------- | --------------- | ---------------- | ------------------------- |
| Priority Queue (Heap)               | `O(n log σ)`    | `O(σ)`           | Uses max heap for sorting |
| Bucket Sort (Efficient for small σ) | `O(n)`          | `O(n)`           | Uses frequency as index   |

✅ Current approach (Sorting + Vector) is simple and efficient for most cases.  
✅ Bucket Sort is better if `σ` (unique chars) is much smaller than `n`.

---

## Summary

✔ Used a vector to count character frequencies.  
✔ Sorted characters based on frequency using `sort()`.  
✔ Built the result string efficiently.  
✔ Achieved optimal time complexity O(n log σ).
