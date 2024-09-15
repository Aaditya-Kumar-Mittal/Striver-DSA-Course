# Sieve of Eratosthenes

## Analysis

- Problem: Count the number of prime numbers less than n using the Sieve of Eratosthenes.
- Difficulty: Medium

### **Concept**

- A prime number is a number greater than 1 that has no divisors other than 1 and itself.
- The Sieve of Eratosthenes is an efficient algorithm to find all primes less than a given number `n` by marking the multiples of each prime starting from 2.
- We only need to iterate up to `sqrt(n)` because, for every composite number `n = a * b`, at least one of the factors must be less than or equal to `sqrt(n)`.

### **Approach**

- Create a boolean array where each element represents whether the corresponding number is prime.
- Start with the assumption that all numbers are prime, then eliminate the multiples of each number starting from 2.
- After processing, the remaining numbers marked as prime are the prime numbers below `n`.

### **Time Complexity**

- `O(n log log n)` where `n` is the input value. This is the time complexity of the Sieve of Eratosthenes.

### **Space Complexity**

- `O(n)` for the boolean array that stores the primality of numbers up to `n`.

### **Example**

- Input: n = 10
- Output: 4
- Explanation: There are 4 prime numbers less than 10: 2, 3, 5, 7.

## Code

```cpp
class Solution {
public:
    /*
        Function to count the number of prime numbers less than n.
        
        Parameters:
        - n: The upper bound number to count primes below.
        
        Returns:
        - The count of prime numbers less than n.
        
        Approach:
        - We use the Sieve of Eratosthenes to mark non-prime numbers in a boolean array.
        - The sieve starts by assuming all numbers are prime, then iteratively marks the multiples of each prime as non-prime.
        - The use of fast I/O (ios_base::sync_with_stdio, cin.tie, cout.tie) improves the execution time.
    */
    int countPrimes(int n) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        // Edge cases: if n is 0 or 1, there are no primes
        if (n <= 1) return 0;

        // Create a boolean array to mark prime numbers, initialize all as true (prime)
        vector<int> primes(n, 1);  // primes[i] = 1 means i is prime
        primes[0] = 0;  // 0 is not a prime
        primes[1] = 0;  // 1 is not a prime

        // Apply the Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            // If i is a prime (i.e., primes[i] == 1), mark all multiples of i as non-prime
            if (primes[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = 0;  // Mark multiples of i as non-prime
                }
            }
        }

        // Count the number of primes
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (primes[i] == 1) count++;
        }

        return count;
    }
};
```

### Key Fixes

1. The code now correctly marks the multiples of `i` as non-prime in the inner loop with `primes[j] = 0;`.
2. Removed the unnecessary check for `n == 0 || n == 1` in favor of a simpler boundary check (`if (n <= 1)`).
3. Used `n` as the size of the `primes` vector rather than `n+1`, which is sufficient since we're counting primes less than `n`.

### Summary

- **Fast I/O** is used to optimize input/output operations, making the solution faster in competitive programming settings.
- **Sieve of Eratosthenes** efficiently marks non-prime numbers and counts the primes less than `n` with `O(n log log n)` time complexity.
