# Count Good Numbers Problem

## Exponentiation Basics

Exponentiation is a mathematical operation where you compute \( x^n \) as \( x \times x \times x \ldots \times x \) (n times).

There are two primary methods for calculating exponents:

1. **Recursive Approach**
2. **Iterative Approach** (left as homework)

## Recursive Approach

### Basic Method

The simplest recursive method to compute \( x^n \) is by breaking it down into \( x \times x^{n-1} \). This problem is similar to the original one, so it continues to break down into \( x \times x \times x^{n-2} \), and so on.

**Implementation**:

```cpp
int recursivePower(int x, int n) {
    if (n == 0) return 1;
    return x * recursivePower(x, n - 1);
}
```

**Time Complexity**:

- The time complexity of this approach is \( O(n) \), which is not efficient for large \( n \) (e.g., \( 10^{15} \)).

### Optimized Method

To improve efficiency, we can use the following strategies:

1. **If \( n \) is even**:
   \[ x^n = (x^2)^{n/2} \]

2. **If \( n \) is odd**:
   \[ x^n = x \times x^{n-1} \]
   - This converts \( n \) to an even number, allowing the even strategy to be applied next.

**Example**:
To find \( 5^{10} \):

- **Naive Approach**:
  \[ 5^{10} = 5 \times 5^9 = 5 \times 5 \times 5^8 = \ldots \text{(10 steps)} \]

- **Optimal Approach**:
  \[ 5^{10} = (5^2)^5 = 25^{5} = (25^2)^2 \times 25 = 625 \times 625 = 390625 \]
  - The process is reduced to about \( \log_2(10) \approx 4 \) steps.

**Time Complexity**:

- The time complexity of the optimized approach is \( O(\log n) \).

**Implementation**:

```cpp
int binaryExponentiation(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0)        
        return binaryExponentiation(x * x, n / 2);
    else                             
        return x * binaryExponentiation(x * x, (n - 1) / 2);
}
```

## Modular Exponentiation

When dealing with very large numbers, you need to compute results modulo \( M \) to prevent overflow and manage large values.

**Implementation**:

```cpp
int modularExponentiation(int x, int n, int M) {
    if (n == 0) return 1;
    if (n % 2 == 0)        
        return modularExponentiation((x * x) % M, n / 2, M);
    else                             
        return (x * modularExponentiation((x * x) % M, (n - 1) / 2, M)) % M;
}
```

**Time Complexity**:

- The time complexity remains \( O(\log n) \).
- The space complexity is \( O(\log n) \) due to the recursion stack.

## Solution for Counting Good Numbers

Given the problem of counting good numbers of length `n`, where:

- Evens = {0, 2, 4, 6, 8} (5 choices)
- Primes = {2, 3, 5, 7} (4 choices)

**Pattern**:

- At even indices: Can be any of the 5 evens.
- At odd indices: Can be one of 4 primes.

For a number of length `n`, the count of good numbers is:
\[ \text{ans} = 5^{\text{count\_even}} \times 4^{\text{count\_odd}} \]

**Implementation**:

```cpp
#define ll long long

class Solution {
public:
    int p = 1e9 + 7;  // Modulo value

    // Calculating x^y efficiently using modular exponentiation
    ll power(long long x, long long y) {
        long long res = 1;    
        x = x % p; // Update x if it is more than or equal to p
        if (x == 0) return 0; 

        while (y > 0) {
            if (y & 1) res = (res * x) % p;
            y = y >> 1; // Divide y by 2
            x = (x * x) % p;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        ll count_of_4s = n / 2;
        ll count_of_5s = n - count_of_4s;
        ll ans = ((power(4LL, count_of_4s) % p  * power(5LL, count_of_5s) % p) % p);
        return (int)ans;
    }
};
```

**Explanation**:

- **`power` Function**: Uses modular exponentiation to efficiently compute \( x^y \mod p \).
- **`countGoodNumbers` Function**: Computes the number of good numbers based on the counts of evens and primes.

**Time Complexity**: \( O(\log n) \)

**Space Complexity**: \( O(\log n) \) due to the recursion stack.

**Note**: Iterative methods are often preferred over recursive ones due to lower stack memory usage and can handle large values more effectively.

**Note**: `(A * B) % m = ((A % m) * (B % m)) % m` Modular Multiplication
