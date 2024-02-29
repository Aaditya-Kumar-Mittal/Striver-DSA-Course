# Counting Reverse Pairs in an Array

This code implements a solution to count reverse pairs in an array using the merge sort algorithm.

## Algorithm / Intuition

Let's understand the algorithm and intuition behind the solution:

1. **Merge Sort Approach**: We use the merge sort algorithm to efficiently count reverse pairs in the array.

2. **Counting Pairs**: Within the merge sort process, we count the number of reverse pairs. We achieve this by checking for each element `arr[i]` in the left half of the array how many elements in the right half satisfy the condition `arr[i] > 2 * arr[j]`, where `j` ranges from `mid + 1` to `high`.

3. **Merge Operation**: While merging the sorted halves, we count the number of reverse pairs as we merge the two halves together.

## Time Complexity

The time complexity of the algorithm is O(2N\*logN), where N is the size of the given array.

- The merge sort process has a time complexity of O(N\*logN).
- During the merge operation, the countPairs function runs in O(N) time complexity.

## Space Complexity

The space complexity of the algorithm is O(N).

- We use a temporary array to store elements in sorted order during the merge operation.
- Apart from this temporary array, the space complexity remains constant.

## Code Explanation

The provided code consists of functions to perform merge sort, count reverse pairs, and merge sorted halves.

- The merge function merges two sorted halves while counting reverse pairs.
- The countPairs function counts reverse pairs between two sorted halves.
- The mergeSort function recursively divides the array into halves, sorts them, and counts reverse pairs.
- The reversePairs function initializes the merge sort process and returns the count of reverse pairs.
- In the main function, the array elements are inputted, and the count of reverse pairs is printed.

## C++ Implementation

```cpp
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);        // left half
    cnt += mergeSort(arr, mid + 1, high);   // right half
    cnt += countPairs(arr, low, mid, high); // Modification
    merge(arr, low, mid, high);             // merging sorted halves
    return cnt;
}

int reversePairs(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n - 1);
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

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    std::cout << "Printing the count of reverse pair in the array: " << reversePairs(arr, n) << std::endl;
    cout << endl;

    return 0;
}
```

## Java Implementation

```java
import java.util.*;

public class ReversePairs {

    static int merge(int[] arr, int low, int mid, int high) {
        int[] temp = new int[high - low + 1];
        int left = low;
        int right = mid + 1;
        int count = 0;
        int index = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
                count += mid - left + 1;
            }
        }

        while (left <= mid) {
            temp[index++] = arr[left++];
        }
        while (right <= high) {
            temp[index++] = arr[right++];
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }

    static int mergeSort(int[] arr, int low, int high) {
        int count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            count += mergeSort(arr, low, mid);
            count += mergeSort(arr, mid + 1, high);
            count += merge(arr, low, mid, high);
        }
        return count;
    }

    static int reversePairs(int[] arr) {
        return mergeSort(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println("Printing Array Elements:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Printing the count of reverse pairs in the array: " + reversePairs(arr));
    }
}

```

## Python Implementation

```python
def merge(arr, low, mid, high):
    temp = []
    left = low
    right = mid + 1
    count = 0

    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1
            count += mid - left + 1

    while left <= mid:
        temp.append(arr[left])
        left += 1
    while right <= high:
        temp.append(arr[right])
        right += 1

    for i in range(low, high + 1):
        arr[i] = temp[i - low]

    return count

def merge_sort(arr, low, high):
    count = 0
    if low < high:
        mid = (low + high) // 2
        count += merge_sort(arr, low, mid)
        count += merge_sort(arr, mid + 1, high)
        count += merge(arr, low, mid, high)
    return count

def reverse_pairs(arr):
    return merge_sort(arr, 0, len(arr) - 1)

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    print("Printing Array Elements:")
    print(*arr)

    print("Printing the count of reverse pairs in the array:", reverse_pairs(arr))

```

## JavaScript Implementation

```javascript
function merge(arr, low, mid, high) {
  let left = low;
  let right = mid + 1;
  let count = 0;
  let temp = [];

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push(arr[left++]);
    } else {
      temp.push(arr[right++]);
      count += mid - left + 1;
    }
  }

  while (left <= mid) {
    temp.push(arr[left++]);
  }
  while (right <= high) {
    temp.push(arr[right++]);
  }

  for (let i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }

  return count;
}

function mergeSort(arr, low, high) {
  let count = 0;
  if (low < high) {
    let mid = Math.floor((low + high) / 2);
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
  }
  return count;
}

function reversePairs(arr) {
  return mergeSort(arr, 0, arr.length - 1);
}

let n = prompt("Enter the size of the array: ");
let arr = [];
for (let i = 0; i < n; i++) {
  arr.push(parseInt(prompt("Enter element " + (i + 1))));
}

console.log("Printing Array Elements:");
console.log(arr.join(" "));

console.log(
  "Printing the count of reverse pairs in the array: " + reversePairs(arr)
);
```
