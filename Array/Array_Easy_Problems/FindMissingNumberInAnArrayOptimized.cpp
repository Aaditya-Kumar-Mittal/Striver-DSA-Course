/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int MissingNumberInArrayOptimized1(vector<int> &a, int n, int N)
{
    int Sum = N * (N + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return Sum - sum;
}

int MissingNumberInArrayOptimized2(vector<int> &a, int n, int N)
{
    int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < n; i++)
    {
        XOR1 = XOR1 ^ a[i];
        XOR2 = XOR2 ^ (i + 1);
    }
    XOR2 = XOR2 ^ N;
    return XOR1 ^ XOR2;
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

    cout << "The missing number in the array is: " << MissingNumberInArrayOptimized1(arr, n, N)
         << endl;
    cout << "The missing number in the array is: " << MissingNumberInArrayOptimized2(arr, n, N)
         << endl;

    return 0;
}

/*
Analysis of Problem

Name: Missing Number in an Array (Optimized)

The problem remains the same: finding the missing number in an array of integers from 1 to N , where N is the maximum number in the array.

Approach 1 (Optimized 1):
- Calculate the sum of integers from 1 to  N  using the formula Sum = N * (N + 1)/2.
- Compute the sum of elements in the array.
- The difference between the calculated sum and the actual sum of elements in the array will give the missing number.

Approach 2 (Optimized 2):
- Use XOR operations to find the missing number.
- Initialize two variables, XOR1 and XOR2, to 0.
- Iterate through the array and perform XOR operations on the elements and the indices (1 to N ).
- Perform an additional XOR operation with N  to handle the case where the missing number is N.
- XOR the results of XOR1 and XOR2 to find the missing number.

Comments:
- Both approaches provide optimized solutions for finding the missing number.
- Approach 1 is efficient for smaller values of N as it has a time complexity of O(n) and a space complexity of O(1).
- Approach 2, using XOR operations, is also efficient with a time complexity of  O(n) and a space complexity of O(1) .
- Approach 2, especially using XOR, is preferred for larger values of  N  as it performs better in terms of both time and space complexity.
- Among the optimal approaches, the XOR approach is slightly better than the summation one because the term (N * (N+1))/2 used in the summation method cannot be stored in an integer if the value of N is big (like 105). In that case, we have to use some bigger data types. But we will face no issues like this while using the XOR approach.

Overall, both approaches are valid and optimized for finding the missing number in the array. The choice between them depends on the specific requirements of the problem and the range of possible values for  N .
*/