/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int MissingNumberInArrayBrute(vector<int> &a, int n, int N)
{

    for (int i = 1; i <= N; i++)
    {
        int flag = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            return i;
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

    cout << "The missing number in the array is: " << MissingNumberInArrayBrute(arr, n, N)
         << endl;
}

/*
Analysis of Problem

Analysis of Problem

Name: Missing Number in an Array (Brute Force)

The problem aims to find the missing number in an array of integers from 1 to \( N \), where \( N \) is the maximum number in the array.

Approach:
- Iterate from 1 to \( N \).
- For each number, check if it exists in the array.
- If a number is not found in the array, return it as the missing number.

The provided code implements a brute force approach to find the missing number in the array.
- It iterates through numbers from 1 to \( N \) and for each number, it iterates through the array to check its presence.
- If a number is not found in the array, it is returned as the missing number.

Comments:
- The code works correctly but it has a high time complexity, making it inefficient for large arrays.
- The time complexity is \( O(N^2) \), where \( N \) is the maximum number in the array. This is because for each number from 1 to \( N \), it iterates through the entire array to check its presence.
- The space complexity is \( O(1) \) as the algorithm uses a constant amount of extra space.

Improvements:
- To improve the time complexity, consider using a more efficient algorithm such as sorting the array and then finding the missing number or using mathematical formulas to find the missing number.
- Additionally, you can use a set or hash table to store the elements of the array and then check for the missing number in constant time.
- These approaches would significantly reduce the time complexity to \( O(N \log N) \) or \( O(N) \), depending on the chosen method.

Overall, while the brute force approach works, it is not the most efficient solution for large arrays.

*/