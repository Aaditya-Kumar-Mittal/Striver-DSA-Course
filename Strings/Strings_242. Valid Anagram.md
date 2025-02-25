# Valid Anagram  

## Table of Contents  

- [Valid Anagram](#valid-anagram)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [1️⃣ Sorting-Based Approach (O(n log n))](#1️⃣-sorting-based-approach-on-log-n)
    - [2️⃣ Hash Table Approach (Optimized O(n))](#2️⃣-hash-table-approach-optimized-on)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Summary](#summary)

---

## Introduction  

An anagram of a string is another string that contains the same characters in a different order.  
For example:  
✅ `"anagram"` and `"nagaram"` are anagrams.  
❌ `"rat"` and `"car"` are not anagrams.  

Given two strings `s` and `t`, we need to determine if `t` is an anagram of `s`.  

---

## Problem Description  

### Examples  

#### Example 1  

🔹 Input: `s = "anagram", t = "nagaram"`  
🔹 Output: `true`  
🔹 Explanation: Both strings have the same characters in the same frequency.  

#### Example 2  

🔹 Input: `s = "rat", t = "car"`  
🔹 Output: `false`  
🔹 Explanation: `'r'`, `'a'`, and `'t'` are different from `'c'`, `'a'`, and `'r'`.  

---

## Constraints  

- `1 <= s.length, t.length <= 5 * 10^4`  
- `s` and `t` consist of lowercase English letters only.  

---

## Approach  

We will discuss two approaches:  

1. Sorting-Based Approach (Simple O(n log n))  
   - Sort both strings.
   - If they are equal, they are anagrams.  

2. Hash Table Approach (Optimized O(n))  
   - Use an array of size `26` (for lowercase English letters) to count character frequencies.
   - If frequencies match, they are anagrams.  

---

## Detailed Explanation of Code  

### 1️⃣ Sorting-Based Approach (O(n log n))  

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl; // Output: true
    cout << sol.isAnagram("rat", "car") << endl;         // Output: false
    return 0;
}
```

✅ Sorting ensures both strings are rearranged in the same order.  
❌ Time Complexity: `O(n log n)` due to sorting.  

---

### 2️⃣ Hash Table Approach (Optimized O(n))  

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> hashArr(26, 0);  // To store frequency of each letter
        
        // Count occurrences of each character in 's'
        for (char c : s) {
            hashArr[c - 'a']++;
        }
        
        // Subtract occurrences based on 't'
        for (char c : t) {
            hashArr[c - 'a']--;
        }
        
        // If all values are 0, strings are anagrams
        for (int i : hashArr) {
            if (i != 0) return false;
        }
        
        return true;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl; // Output: true
    cout << sol.isAnagram("rat", "car") << endl;         // Output: false
    return 0;
}
```

✅ Uses an array to store character counts efficiently.  
✅ Only two passes through the string (`O(n)`).  
✅ Space Complexity: `O(1)` since `26` elements are fixed.  

---

## Complexity Analysis  

| Approach | Time Complexity | Space Complexity | Explanation |  
|----------|---------------|-----------------|-------------|  
| Sorting-Based | `O(n log n)` | `O(1)` | Sorting takes `O(n log n)`, comparison is `O(n)`. |  
| Hash Table | `O(n)` | `O(1)` | Uses an array to track frequencies in `O(n)`. ✅ Best Approach |  

---

## How to Run the Code  

### For C++  

1️⃣ Compile the code:  

```bash
g++ -o valid_anagram valid_anagram.cpp
```  

2️⃣ Run the executable:  

```bash
./valid_anagram
```  

---

## Summary  

| Approach | Method | Time Complexity | Space Complexity | Best For |  
|----------|--------|---------------|-----------------|-----------|  
| Sorting-Based | Sorting strings | `O(n log n)` | `O(1)` | Easy to understand |  
| Hash Table | Using array | `O(n)` | `O(1)` | Optimal & Efficient ✅ |  

✅ The Hash Table approach is the most efficient for large inputs.  
🚀 This documentation provides a complete, optimized explanation.  

Would you like any modifications or additional optimizations? 😊
