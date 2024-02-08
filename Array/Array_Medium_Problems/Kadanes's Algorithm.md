# Kadane's Algorithm

## Intuition

Kadane's algorithm is used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers. The algorithm is efficient and works well even with negative numbers.

## Approach

1. Initialize two variables, `maxSum` and `sum`, to store the maximum sum found so far and the current sum of the subarray being processed, respectively. Set both to the smallest possible integer value.
2. Iterate through each element of the array.
3. For each element:
   - Add the current element to the `sum`.
   - If the `sum` becomes greater than the `maxSum`, update `maxSum` to the value of `sum`.
   - If the `sum` becomes negative, reset it to 0, as any negative sum would only decrease the maximum subarray sum.
4. After processing all elements, `maxSum` will contain the maximum sum of a contiguous subarray.

## Complexity Analysis

- **Time Complexity:** O(n), where n is the size of the input array. The algorithm iterates through the array once.
- **Space Complexity:** O(1). The algorithm uses only a constant amount of extra space, independent of the input size.

## Code Implementation

### C++

````cpp
#include <bits/stdc++.h>
using namespace std;

long long KadanesMaximumSubarraySum(vector<int> v, int n)
{
    long long sum = 0, maxSum = LONG_LONG_MIN;
    int ansStart = 0, ansEnd = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += v[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    std::cout << "The max sum for a subarray in the given array using Kadane's Algorithm is: " << KadanesMaximumSubarraySum(arr, n) << std::endl;

    return 0;
}
```

### JAVA

```Java
import java.util.Scanner;

public class KadanesAlgorithm {
    public static long kadanesMaximumSubarraySum(int[] arr) {
        long maxSum = Long.MIN_VALUE;
        long currentSum = 0;

        for (int num : arr) {
            currentSum += num;
            maxSum = Math.max(maxSum, currentSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("The max sum for a subarray in the given array using Kadane's Algorithm is: " + kadanesMaximumSubarraySum(arr));
    }
}
```

### JavaScript

```JavaScript
function kadanesMaximumSubarraySum(arr) {
    let maxSum = -Infinity;
    let currentSum = 0;

    for (let num of arr) {
        currentSum += num;
        maxSum = Math.max(maxSum, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (input) => {
    const arr = input.split(' ').map(Number);
    console.log("The max sum for a subarray in the given array using Kadane's Algorithm is:", kadanesMaximumSubarraySum(arr));
    rl.close();
});

```
