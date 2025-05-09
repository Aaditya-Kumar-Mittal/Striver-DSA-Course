/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Function to count the minimum number of students required to allocate books such that no student reads more than 'pages' pages.
 *
 * @param arr: A vector of integers representing the number of pages in each book.
 * @param n: The total number of books.
 * @param pages: The maximum number of pages a student is allowed to read.
 * @return The number of students required.
 */
int countStudents(vector<int> &arr, int n, int pages)
{
    int students = 1;         // Initialize the number of students required
    long long pageStudents = 0; // To keep track of the pages allocated to the current student

    for (int i = 0; i < n; i++)
    {
        if (pageStudents + arr[i] <= pages)
        {
            // If adding the current book to the current student's load does not exceed the limit
            pageStudents += arr[i];
        }
        else
        {
            // Allocate the current book to a new student
            students++;
            pageStudents = arr[i];
        }
    }
    return students;
}

/**
 * Brute force approach to find the minimum number of pages each student should read so that all books are allocated.
 *
 * @param arr: A vector of integers representing the number of pages in each book.
 * @param n: The total number of books.
 * @param m: The number of students.
 * @return The minimum number of pages.
 */
int bookAllocationBruteForce(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        // If there are more students than books, it is impossible to allocate books
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end()); // Minimum possible pages (largest single book)
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible pages (sum of all books)

    // Brute force search from the largest single book to the sum of all books
    for (int pages = low; pages <= high; pages++)
    {
        if (countStudents(arr, n, pages) == m)
        {
            return pages;
        }
    }

    return low; // Default return value in case of failure
}

/**
 * Optimized approach using binary search to find the minimum number of pages each student should read so that all books are allocated.
 *
 * @param arr: A vector of integers representing the number of pages in each book.
 * @param n: The total number of books.
 * @param m: The number of students.
 * @return The minimum number of pages.
 */
int bookAllocationBinarySearch(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        // If there are more students than books, it is impossible to allocate books
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end()); // Minimum possible pages (largest single book)
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible pages (sum of all books)

    // Binary search to find the minimum pages
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Middle point of the current range

        int students = countStudents(arr, n, mid);

        if (students > m)
        {
            // If more students are needed, increase the lower bound
            low = mid + 1;
        }
        else
        {
            // Otherwise, decrease the upper bound
            high = mid - 1;
        }
    }
    return low; // The point where low meets high is the minimum pages required
}

int main()
{
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    int bruteAns = bookAllocationBruteForce(array, n, numberOfStudents);
    cout << "The minimum pages for which we can allocate all the books to " << numberOfStudents << " students are (Brute Force Solution): " << bruteAns << endl;

    int binarySearchAns = bookAllocationBinarySearch(array, n, numberOfStudents);
    cout << "The minimum pages for which we can allocate all the books to " << numberOfStudents << " students are (Binary Search Solution): " << binarySearchAns << endl;

    return 0;
}

/*
Analysis of Problem

Name: Book Allocation Problem

Brute Force Solution:
Time Complexity: O(N * (sum(arr[])-max(arr[])+1))
    - Where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    - We are using a loop from max(arr[]) to sum(arr[]) to check all possible numbers of pages. Inside the loop, we are calling the countStudents() function for each number. The countStudents() function has a time complexity of O(N).

Space Complexity: O(1)
    - We are not using any extra space to solve this problem.

Binary Search Solution:
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))
    - Where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    - We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. The countStudents() function has a time complexity of O(N).

Space Complexity: O(1)
    - We are not using any extra space to solve this problem.
*/
