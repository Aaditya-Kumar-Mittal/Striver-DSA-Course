/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

double medianofTwoSortedArrysBruteForce(vector<int> &a, vector<int> &b, int m, int n)
{

    int size = m + n;

    vector<int> merged;

    int i = 0, j = 0;

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

    while (i < m)
    {
        merged.push_back(a[i++]);
    }

    while (j < n)
    {
        merged.push_back(b[j++]);
    }

    if (size % 2 == 1)
    {
        return (double)merged[size / 2];
    }
    else
    {
        return (double)((double)(merged[size / 2] + merged[size / 2 - 1]) / 2.0);
    }
}

double medianofTwoSortedArrysOptimizedApproach(vector<int> &a, vector<int> &b, int m, int n)
{
    int i = 0, j = 0, count = 0, ind1el = -1, ind2el = -1;

    int size = m + n;

    int ind2 = size / 2;

    int ind1 = ind2 - 1;

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

    while (i < m)
    {
        if (count == ind1)
            ind1el = a[i];
        if (count == ind2)
            ind2el = a[i];
        count++;
        i++;
    }

    while (j < n)
    {
        if (count == ind1)
            ind1el = b[j];
        if (count == ind2)
            ind2el = b[j];
        count++;
        j++;
    }

    if (size % 2 == 1)
    {
        return (double)ind2el;
    }

    else
    {
        return (double)((double)(ind1el + ind2el) / 2.0);
    }
}

double medianofTwoSortedArrysBinarySearchApproach(vector<int> &a, vector<int> &b, int m, int n)
{
    if (m > n)
        return medianofTwoSortedArrysBinarySearchApproach(b, a, n, m);

    int low = 0, high = m;

    int size = m + n;

    int left = size + 1 / 2;

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;

        int mid2 = left - mid1;

        int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n) ? b[mid2] : INT_MAX;
        int l1 = (mid1 - 1 >= 0) ? a[mid1 - 1] : INT_MIN;
        int l2 = (mid2 - 1 >= 0) ? b[mid2 - 1] : INT_MIN;

        if (l1 <= r2 && l2 <= r1)
        {
            if (size % 2 == 1)
            {
                return max(l1, l2);
            }
            else
            {
                return (double)((double)((max(l1, l2) + min(r1, r2)) / 2.0));
            }
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }

    return high;
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

Name:

Time Complexity:

Space Complexity:


*/