# Count Inversions in an Array

## Algorithm / Intuition

Let's build the intuition for this approach using a modified version of the given question.

Assume two sorted arrays are given i.e. `a1[] = {2, 3, 5, 6}` and `a2[] = {2, 2, 4, 4, 8}`. Now, we have to count the pairs i.e. `a1[i]` and `a2[j]` such that `a1[i] > a2[j]`.

In order to solve this, we will keep two pointers `i` and `j`, where `i` will point to the first index of `a1[]` and `j` will point to the first index of `a2[]`. Now in each iteration, we will do the following:

- If `a1[i] <= a2[j]`: These two elements cannot be a pair and so we will move the pointer `i` to the next position.
- If `a1[i] > a2[j]`: These two elements can be a pair and so we will update the count of pairs. Now, here, we should observe that as `a1[i]` is greater than `a2[j]`, all the elements after `a1[i]` will also be greater than `a2[j]` and so, those elements will also make a pair with `a2[j]`. So, the number of pairs added will be `n1-i` (where `n1 = size of a1[]`). Now, we will move the `j` pointer to the next position.

The above process will continue until at least one of the pointers reaches the end.

Until now, we have figured out how to count the number of pairs in one go if two sorted arrays are given. But in our actual question, only a single unsorted array is given. So, how to break it into two sorted halves so that we can apply the above observation?

We can think of the merge sort algorithm that works in a similar way we want. In the merge sort algorithm, at every step, we divide the given array into two halves and then sort them, and while doing that we can actually count the number of pairs.

Basically, we will use the merge sort algorithm to use the observation in the correct way.

## Observation

The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just a one-line addition inside the `merge()` function. Inside the `merge()`, we need to add the number of pairs to the count when `a[left] > a[right]`.

The steps of the `merge()` function were the following:

1. In the merge function, we will use a `temp` array to store the elements of the two sorted arrays after merging. Here, the range of the left array is `low` to `mid` and the range for the right half is `mid+1` to `high`.
2. Now we will take two pointers `left` and `right`, where `left` starts from `low` and `right` starts from `mid+1`.
3. Using a while loop (`while(left <= mid && right <= high)`), we will select two elements, one from each half, and will consider the smallest one among the two. Then, we will insert the smallest element in the `temp` array.
4. After that, the left-out elements in both halves will be copied as it is into the `temp` array.
5. Now, we will just transfer the elements of the `temp` array to the range `low` to `high` in the original array.

### Modifications in merge() and mergeSort()

In order to count the number of pairs, we will keep a count variable, `cnt`, initialized to 0 beforehand inside the `merge()`.
While comparing `a[left]` and `a[right]` in the 3rd step of `merge()`, if `a[left] > a[right]`, we will simply add this line:

```cpp
cnt += mid-left+1 (mid+1 = size of the left half)
```

Now, we will return this `cnt` from `merge()` to `mergeSort()`.
Inside `mergeSort()`, we will keep another counter variable that will store the final answer. With this `cnt`, we will add the answer returned from `mergeSort()` of the left half, `mergeSort()` of the right half, and `merge()`.
Finally, we will return this `cnt`, as our answer from `mergeSort()`.

## C++ Implementation

```cpp
#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // Temporary array to store merged subarrays
    int left = low;      // Pointer for the left subarray
    int right = mid + 1; // Pointer for the right subarray

    // Modification 1: Count variable to count the inversions
    int count = 0;

    // Merge the two subarrays while counting inversions
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]); // Append element from left subarray to temp
            left++;
        }
        else
        {
            temp.push_back(arr[right]); // Append element from right subarray to temp
            count += (mid - left + 1);  // Count inversions
            right++;
        }
    }

    // Copy remaining elements from left subarray to temp
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // Copy remaining elements from right subarray to temp
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements from temp back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count; // Return inversion count
}

// Recursive function to perform merge sort and count inversions
// Parameters:
// arr: The input array
// low: Starting index of the array/subarray
// high: Ending index of the array/subarray
// Returns: Number of inversions in the array/subarray
int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0; // Initialize inversion count
    if (low < high)
    {
        int mid = low + (high - low) / 2; // Calculate the midpoint of the array/subarray
        count += mergeSort(arr, low, mid); // Recursively sort and count inversions in the left subarray
        count += mergeSort(arr, mid + 1, high); // Recursively sort and count inversions in the right subarray
        count += merge(arr, low, mid, high); // Merge the sorted subarrays and count inversions
    }
    return count; // Return inversion count
}

// Function to count inversions in the array using merge sort
// Parameters:
// arr: The input array
// n: Size of the array
// Returns: Number of inversions in the array
int countInversions(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1); // Call merge sort function to count inversions
}

int main()
{
    int n;
    cin >> n; // Input size of the array

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print array elements
    }
    cout << endl;

    // Output the count of inversions in the array
    cout << "Printing the count of inversions in the array: " << countInversions(arr, n) << endl;
    cout << endl;

    return 0;
}
```

## Python Implementation

```python
def merge(arr, low, mid, high):
    temp = []    # Temporary array to store merged subarrays
    left = low   # Pointer for the left subarray
    right = mid + 1  # Pointer for the right subarray

    # Modification 1: Count variable to count the inversions
    count = 0

    # Merge the two subarrays while counting inversions
    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])  # Append element from left subarray to temp
            left += 1
        else:
            temp.append(arr[right])  # Append element from right subarray to temp
            count += (mid - left + 1)  # Count inversions
            right += 1

    # Copy remaining elements from left subarray to temp
    while left <= mid:
        temp.append(arr[left])
        left += 1
    # Copy remaining elements from right subarray to temp
    while right <= high:
        temp.append(arr[right])
        right += 1

    # Copy merged elements from temp back to original array
    for i in range(low, high + 1):
        arr[i] = temp[i - low]

    return count  # Return inversion count


def mergeSort(arr, low, high):
    count = 0  # Initialize inversion count
    if low < high:
        mid = low + (high - low) // 2  # Calculate the midpoint of the array/subarray
        count += mergeSort(arr, low, mid)  # Recursively sort and count inversions in the left subarray
        count += mergeSort(arr, mid + 1, high)  # Recursively sort and count inversions in the right subarray
        count += merge(arr, low, mid, high)  # Merge the sorted subarrays and count inversions
    return count  # Return inversion count


def countInversions(arr):
    n = len(arr)
    return mergeSort(arr, 0, n - 1)  # Call merge sort function to count inversions


if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))  # Input size of the array
    arr = list(map(int, input("Enter the array elements separated by space: ").split()))  # Input array elements

    print("Printing Array Elements:")
    print(*arr)  # Print array elements

    # Output the count of inversions in the array
    print("Printing the count of inversions in the array:", countInversions(arr))

```

## Java Implementation

```java
import java.util.Scanner;

public class CountInversions {

    public static int merge(int[] arr, int low, int mid, int high) {
        int[] temp = new int[high - low + 1];  // Temporary array to store merged subarrays
        int left = low;  // Pointer for the left subarray
        int right = mid + 1;  // Pointer for the right subarray

        // Modification 1: Count variable to count the inversions
        int count = 0;

        int k = 0;
        // Merge the two subarrays while counting inversions
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];  // Append element from left subarray to temp
            } else {
                temp[k++] = arr[right++];  // Append element from right subarray to temp
                count += (mid - left + 1);  // Count inversions
            }
        }

        // Copy remaining elements from left subarray to temp
        while (left <= mid) {
            temp[k++] = arr[left++];
        }
        // Copy remaining elements from right subarray to temp
        while (right <= high) {
            temp[k++] = arr[right++];
        }

        // Copy merged elements from temp back to original array
        for (int i = 0; i < temp.length; i++) {
            arr[low + i] = temp[i];
        }

        return count;  // Return inversion count
    }

    // Recursive function to perform merge sort and count inversions
    public static int mergeSort(int[] arr, int low, int high) {
        int count = 0;  // Initialize inversion count
        if (low < high) {
            int mid = low + (high - low) / 2;  // Calculate the midpoint of the array/subarray
            count += mergeSort(arr, low, mid);  // Recursively sort and count inversions in the left subarray
            count += mergeSort(arr, mid + 1, high);  // Recursively sort and count inversions in the right subarray
            count += merge(arr, low, mid, high);  // Merge the sorted subarrays and count inversions
        }
        return count;  // Return inversion count
    }

    // Function to count inversions in the array using merge sort
    public static int countInversions(int[] arr) {
        return mergeSort(arr, 0, arr.length - 1);  // Call merge sort function to count inversions
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();  // Input size of the array
        int[] arr = new int[n];
        System.out.print("Enter the array elements separated by space: ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();  // Input array elements
        }

        System.out.println("Printing Array Elements:");
        for (int num : arr) {
            System.out.print(num + " ");  // Print array elements
        }
        System.out.println();

        // Output the count of inversions in the array
        System.out.println("Printing the count of inversions in the array: " + countInversions(arr));
    }
}

```

## JavaScript Implementation

```javascript
function merge(arr, low, mid, high) {
  let temp = []; // Temporary array to store merged subarrays
  let left = low; // Pointer for the left subarray
  let right = mid + 1; // Pointer for the right subarray

  // Modification 1: Count variable to count the inversions
  let count = 0;

  // Merge the two subarrays while counting inversions
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push(arr[left]); // Append element from left subarray to temp
      left++;
    } else {
      temp.push(arr[right]); // Append element from right subarray to temp
      count += mid - left + 1; // Count inversions
      right++;
    }
  }

  // Copy remaining elements from left subarray to temp
  while (left <= mid) {
    temp.push(arr[left]);
    left++;
  }
  // Copy remaining elements from right subarray to temp
  while (right <= high) {
    temp.push(arr[right]);
    right++;
  }

  // Copy merged elements from temp back to original array
  for (let i = 0; i < temp.length; i++) {
    arr[low + i] = temp[i];
  }

  return count; // Return inversion count
}

// Recursive function to perform merge sort and count inversions
function mergeSort(arr, low, high) {
  let count = 0; // Initialize inversion count
  if (low < high) {
    let mid = Math.floor(low + (high - low) / 2); // Calculate the midpoint of the array/subarray
    count += mergeSort(arr, low, mid); // Recursively sort and count inversions in the left subarray
    count += mergeSort(arr, mid + 1, high); // Recursively sort and count inversions in the right subarray
    count += merge(arr, low, mid, high); // Merge the sorted subarrays and count inversions
  }
  return count; // Return inversion count
}

// Function to count inversions in the array using merge sort
function countInversions(arr) {
  return mergeSort(arr, 0, arr.length - 1); // Call merge sort function to count inversions
}

// Main function to take input and output the result
function main() {
  const readline = require("readline");
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  rl.question("Enter the size of the array: ", (n) => {
    let arr = [];
    rl.question("Enter the array elements separated by space: ", (input) => {
      arr = input.split(" ").map(Number);
      console.log("Printing Array Elements:");
      console.log(...arr); // Print array elements

      // Output the count of inversions in the array
      console.log(
        "Printing the count of inversions in the array:",
        countInversions(arr)
      );
      rl.close();
    });
  });
}

main();
```
