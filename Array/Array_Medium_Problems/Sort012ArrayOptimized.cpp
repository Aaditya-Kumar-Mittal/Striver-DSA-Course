#include <bits/stdc++.h>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s using the Dutch National Flag Algorithm
void SORT012ArrayOptimized(vector<int> &a, int n)
{
    // Initialize pointers for 0, 1, and 2 elements
    int low = 0, mid = 0, high = n - 1;

    // Traverse the array until mid pointer reaches the end
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            // If current element is 0, swap it with the element at low pointer
            swap(a[low], a[mid]);
            // Increment both low and mid pointers
            mid++;
            low++;
        }
        else if (a[mid] == 1)
        {
            // If current element is 1, move mid pointer forward
            mid++;
        }
        else if (a[mid] == 2)
        {
            // If current element is 2, swap it with the element at high pointer
            swap(a[high], a[mid]);
            // Decrement high pointer
            high--;
        }
    }
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print original array
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the sorting function
    SORT012ArrayOptimized(arr, n);

    // Print sorted array
    cout << "Printing Array Elements after 012 Sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem:

Name: Dutch National Flag Algorithm for sorting an array of 0s, 1s, and 2s
Time Complexity: O(n) - Single pass through the array
Space Complexity: O(1) - Only a constant amount of extra space is used for pointers

The Dutch National Flag Algorithm, also known as the Three-Way Partitioning Algorithm, is used to sort an array containing three distinct values (e.g., 0s, 1s, and 2s) in linear time without using any sorting algorithm like merge sort or quicksort. This algorithm was designed by Edsger W. Dijkstra, a Dutch computer scientist, and it is named after the flag of the Netherlands, which consists of three horizontal stripes in red, white, and blue.

Intuition:
The algorithm partitions the array into three sections:
1. Section for 0s: This section is maintained at the beginning of the array, starting from index 0.
2. Section for 1s: This section is maintained between the sections for 0s and 2s.
3. Section for 2s: This section is maintained at the end of the array, starting from the last index.

### Algorithm Steps:
1. Initialize three pointers: `low` for the section of 0s, `mid` for the section of 1s, and `high` for the section of 2s.
2. Traverse the array using the `mid` pointer until it reaches the `high` pointer.
3. If the current element is 0, swap it with the element at the `low` pointer, and increment both `low` and `mid` pointers.
4. If the current element is 1, just move the `mid` pointer forward.
5. If the current element is 2, swap it with the element at the `high` pointer, and decrement the `high` pointer.
6. Continue this process until the `mid` pointer crosses the `high` pointer.

### Analysis:
- Time Complexity: The algorithm performs a single pass through the array, so the time complexity is O(n), where n is the size of the array.
- Space Complexity: The algorithm uses only a constant amount of extra space for the pointers, so the space complexity is O(1).

### Implementation:

void sort012(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

This algorithm is particularly useful in scenarios where the array contains only a few distinct values, such as binary arrays (containing only 0s and 1s) or arrays containing a small range of integers.
*/
