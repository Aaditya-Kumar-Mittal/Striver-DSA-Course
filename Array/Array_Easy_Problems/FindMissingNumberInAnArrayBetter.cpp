/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int MissingNumberInArrayBetter(vector<int> &a, int n, int N)
{

    // Using hash array
    vector<int> hashArr(N++);

    for (int i = 0; i < n; i++)
    {
        hashArr[a[i]]++;
    }

    for (int j = 1; j < N; j++)
    {
        if (hashArr[j] == 0)
        {
            return j;
        }
    }
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

    int N;
    cin >> N;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The missing number in the array is: " << MissingNumberInArrayBetter(arr, n, N)
         << endl;
}

/*
Analysis of Problem

Name: Missing Number in an Array (Improved)

The problem remains the same: finding the missing number in an array of integers from 1 to \( N \), where \( N \) is the maximum number in the array.

Approach:
- Use a hash array to store the count of occurrences of each number in the array.
- Iterate through the input array and update the hash array accordingly.
- Traverse the hash array to find the number with zero occurrences, which represents the missing number.

The provided code implements an improved approach to find the missing number in the array:
- It uses a hash array to count the occurrences of each number in the input array.
- Then, it traverses the hash array to find the missing number by identifying the number with zero occurrences.

Comments:
- The code works correctly and efficiently finds the missing number.
- However, there's a small issue in the implementation. In the second for loop, the loop should iterate from 1 to \( N \), not from 1 to \( n \). This is because \( N \) represents the maximum possible number in the array, while \( n \) is the size of the input array.
- The time complexity of the current implementation is \( O(N) \), where \( N \) is the maximum number in the array, and the space complexity is also \( O(N) \) due to the hash array.

Improvements:
- Fix the loop condition in the second for loop to iterate from 1 to \( N \) instead of 1 to \( n \).
- Consider optimizing the space complexity by using a boolean array instead of an integer array since we only need to store presence/absence information for each number.

Overall, the approach is sound, but a minor correction and potential optimization can enhance the implementation.

*/