# Moore's Voting Algorithm

Moore's Voting Algorithm is used to find the majority element in an array with more than n/2 occurrences. This algorithm was proposed by Robert S. Moore in 1981 and is an efficient way to find the majority element in linear time and constant space.

## Intuition

The algorithm is based on the observation that if an element occurs more than n/2 times in an array, then it will cancel out all other elements. Hence, the majority element, if it exists, will remain after the cancellation process.

## Algorithm Steps

1. **Initialization**: Initialize two variables - `ele` to store the potential majority element and `count` to keep track of its occurrences. Initially, set `count` to 0.
2. **Finding Potential Majority Element**: Iterate through the array. If `count` becomes 0, update `ele` to the current element and set `count` to 1. If the current element is equal to `ele`, increment `count`; otherwise, decrement `count`.
3. **Verification**: After finding the potential majority element, verify if it is the actual majority element by counting its occurrences in the array.
4. **Return**: If the occurrences of the potential majority element are greater than n/2, return it as the majority element; otherwise, return -1 indicating no majority element exists.

## Analysis

- **Time Complexity**: The algorithm performs a single pass through the array, so the time complexity is O(n), where n is the size of the array.
- **Space Complexity**: The algorithm uses only a constant amount of extra space for variables `ele` and `count`, so the space complexity is O(1).

## Implementation

```cpp
int MajorityElementN2Optimized(vector<int> v, int n)
{
    int count = 0, ele;

    // Find potential majority element using Moore's Voting Algorithm
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            // If count becomes 0, update potential majority element
            ele = v[i];
            count = 1;
        }
        else if (v[i] == ele)
        {
            // If current element is equal to potential majority element, increment count
            count++;
        }
        else
        {
            // If current element is different from potential majority element, decrement count
            count--;
        }
    }

    // Verify if the potential majority element is the majority element by counting occurrences
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == ele)
        {
            count1++;
        }
    }

    // If occurrences of potential majority element is greater than n/2, return it as the majority element
    if (count1 > (n / 2))
    {
        return ele;
    }
    else
    {
        return -1; // If no majority element found, return -1
    }
}
```
