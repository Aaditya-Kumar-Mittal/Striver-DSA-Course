/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> UnionArrayOptimized(vector<int> &a, vector<int> &b, int n1, int n2)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else if (a[i] > b[j])
        {
            if (ans.empty() || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
        else // When both elements are equal
        {
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    // Copy the remaining elements of a, if any
    while (i < n1)
    {
        if (ans.empty() || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }

    // Copy the remaining elements of b, if any
    while (j < n2)
    {
        if (ans.empty() || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

int main()
{

    int n1, n2;

    cin >> n1;

    cin >> n2;

    vector<int> a(n1);

    vector<int> b(n2);

    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    cout << "Printing Array A Elements: " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Printing Array B Elements: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    vector<int> unionArr = UnionArrayOptimized(a, b, n1, n2);

    cout << "Printing Union of A union B Elements: " << endl;
    for (int i = 0; i < unionArr.size(); i++)
    {
        cout << unionArr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Name: Union of Two Arrays (Optimized)

Time Complexity:
- In the optimized approach, the time complexity is O(n1 + n2), where n1 and n2 are the sizes of arrays a and b, respectively.
- The algorithm iterates through both arrays only once to merge them into a single sorted array while ensuring that duplicate elements are not added to the result.

Space Complexity:
- The space complexity is O(n1 + n2) because the size of the union array may be at most the sum of the sizes of arrays a and b.

The provided code implements an optimized approach to find the union of two arrays a and b. The algorithm uses two pointers to iterate through both arrays simultaneously and merges them into a single sorted array while ensuring that duplicate elements are not added to the result.

Comments:
- The code is straightforward and correctly computes the union of the two arrays.
- The algorithm efficiently handles the merging process and avoids adding duplicate elements to the union array.
- The commented-out main function seems to be unrelated to the union of arrays and can be removed from the code.

Overall, the implementation efficiently finds the union of two arrays in linear time while using additional space proportional to the sum of the sizes of the input arrays.

*/