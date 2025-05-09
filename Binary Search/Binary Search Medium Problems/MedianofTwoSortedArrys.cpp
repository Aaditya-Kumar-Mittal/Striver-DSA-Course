/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Function to find the median of two sorted arrays using a brute force approach.
 *
 * @param a: A vector of integers representing the first sorted array.
 * @param b: A vector of integers representing the second sorted array.
 * @param m: An integer representing the size of the first array.
 * @param n: An integer representing the size of the second array.
 * @return The median of the two sorted arrays.
 */
double medianofTwoSortedArrysBruteForce(vector<int> &a, vector<int> &b, int m, int n)
{
  // Total size of the merged array
  int size = m + n;

  // Vector to store the merged sorted array
  vector<int> merged;

  // Indices to traverse both arrays
  int i = 0, j = 0;

  // Merge both arrays into the merged vector
  while (i < m && j < n)
  {
    if (a[i] < b[j])
    {
      merged.push_back(a[i++]);
    }
    else
    {
      merged.push_back(b[j++]);
    }
  }

  // Append remaining elements of array a, if any
  while (i < m)
  {
    merged.push_back(a[i++]);
  }

  // Append remaining elements of array b, if any
  while (j < n)
  {
    merged.push_back(b[j++]);
  }

  // If the total size is odd, return the middle element
  if (size % 2 == 1)
  {
    return (double)merged[size / 2];
  }
  // If the total size is even, return the average of the two middle elements
  else
  {
    return (double)((double)(merged[size / 2] + merged[size / 2 - 1]) / 2.0);
  }
}

/**
 * Function to find the median of two sorted arrays using an optimized approach.
 *
 * @param a: A vector of integers representing the first sorted array.
 * @param b: A vector of integers representing the second sorted array.
 * @param m: An integer representing the size of the first array.
 * @param n: An integer representing the size of the second array.
 * @return The median of the two sorted arrays.
 */
double medianofTwoSortedArrysOptimizedApproach(vector<int> &a, vector<int> &b, int m, int n)
{
  // Indices to traverse both arrays
  int i = 0, j = 0, count = 0;

  // Variables to store the median elements
  int ind1el = -1, ind2el = -1;

  // Total size of the merged array
  int size = m + n;

  // Indices of the median elements
  int ind2 = size / 2;
  int ind1 = ind2 - 1;

  // Traverse both arrays to find the median elements
  while (i < m && j < n)
  {
    if (a[i] < b[j])
    {
      if (count == ind1)
        ind1el = a[i];
      if (count == ind2)
        ind2el = a[i];
      count++;
      i++;
    }
    else
    {
      if (count == ind1)
        ind1el = b[j];
      if (count == ind2)
        ind2el = b[j];
      count++;
      j++;
    }
  }

  // Append remaining elements of array a, if any
  while (i < m)
  {
    if (count == ind1)
      ind1el = a[i];
    if (count == ind2)
      ind2el = a[i];
    count++;
    i++;
  }

  // Append remaining elements of array b, if any
  while (j < n)
  {
    if (count == ind1)
      ind1el = b[j];
    if (count == ind2)
      ind2el = b[j];
    count++;
    j++;
  }

  // If the total size is odd, return the second median element
  if (size % 2 == 1)
  {
    return (double)ind2el;
  }
  // If the total size is even, return the average of the two median elements
  else
  {
    return (double)((double)(ind1el + ind2el) / 2.0);
  }
}

/**
 * Function to find the median of two sorted arrays using a binary search approach.
 *
 * @param a: A vector of integers representing the first sorted array.
 * @param b: A vector of integers representing the second sorted array.
 * @param m: An integer representing the size of the first array.
 * @param n: An integer representing the size of the second array.
 * @return The median of the two sorted arrays.
 */
double medianofTwoSortedArrysBinarySearchApproach(vector<int> &a, vector<int> &b, int m, int n)
{
  // Ensure that array a is the smaller array
  if (m > n)
    return medianofTwoSortedArrysBinarySearchApproach(b, a, n, m);

  // Initialize the binary search bounds
  int low = 0, high = m;

  // Total size of the merged array
  int size = m + n;

  // Midpoint for partitioning the arrays
  int left = (size + 1) / 2;

  while (low <= high)
  {
    int mid1 = (low + high) >> 1;

    int mid2 = left - mid1;

    // Right elements of the partitions
    int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
    int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

    // Left elements of the partitions
    int l1 = (mid1 - 1 >= 0) ? a[mid1 - 1] : INT_MIN;
    int l2 = (mid2 - 1 >= 0) ? b[mid2 - 1] : INT_MIN;

    // Check if the partitions are correct
    if (l1 <= r2 && l2 <= r1)
    {
      // If the total size is odd, return the maximum of the left elements
      if (size % 2 == 1)
      {
        return max(l1, l2);
      }
      // If the total size is even, return the average of the maximum left element and the minimum right element
      else
      {
        return (double)((double)((max(l1, l2) + min(r1, r2)) / 2.0));
      }
    }
    // Adjust the binary search bounds
    else if (l1 > r2)
    {
      high = mid1 - 1;
    }
    else
    {
      low = mid1 + 1;
    }
  }

  return high; // This line should never be reached
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> array1(n), array2(m);
  for (int i = 0; i < n; i++)
  {
    cin >> array1[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> array2[i];
  }

  cout << "Printing Array1 Elements: ";
  for (int i = 0; i < n; i++)
  {
    cout << array1[i] << " ";
  }
  cout << endl;

  cout << "Printing Array2 Elements: ";
  for (int i = 0; i < m; i++)
  {
    cout << array2[i] << " ";
  }
  cout << endl;

  double medianBrute = medianofTwoSortedArrysBruteForce(array1, array2, n, m);
  std::cout << "Median of 2 sorted arrays using Brute Force Approach: " << medianBrute << std::endl;

  double medianOptimized = medianofTwoSortedArrysOptimizedApproach(array1, array2, n, m);
  std::cout << "Median of 2 sorted arrays using Optimized Approach: " << medianOptimized << std::endl;

  double medianBinary = medianofTwoSortedArrysBinarySearchApproach(array1, array2, n, m);
  std::cout << "Median of 2 sorted arrays using Binary Search Approach: " << medianBinary << std::endl;

  return 0;
}

/*
Analysis of Problem

Name: Median of Two Sorted Arrays

Time Complexity:
1. Brute Force: O(m + n)
   - Merging the two arrays takes linear time.
   - Finding the median from the merged array is a constant time operation.

2. Optimized Approach: O(m + n)
   - Traversing both arrays once to find the median elements takes linear time.

3. Binary Search Approach: O(log(min(m, n)))
   - Binary search on the smaller array to partition the arrays correctly.

Space Complexity:
1. Brute Force: O(m + n)
   - Storing the merged array requires linear space.

2. Optimized Approach: O(1)
   - No extra space required, except for a few variables.

3. Binary Search Approach: O(1)
  */