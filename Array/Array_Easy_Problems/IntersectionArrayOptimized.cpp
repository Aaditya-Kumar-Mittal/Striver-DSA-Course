/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> IntersectionArrayOptimized(vector<int> &a, vector<int> &b, int n1, int n2)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
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

    vector<int> intersectionArr = IntersectionArrayOptimized(a, b, n1, n2);

    cout << "Printing Intersection of A and B Elements: " << endl;
    for (int i = 0; i < intersectionArr.size(); i++)
    {
        cout << intersectionArr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Name: Intersection of Two Arrays (Optimized)

Time Complexity: Let n1 and n2 be the sizes of arrays a and b, respectively. In the brute force approach, the time complexity is O(n1 + n2).This is because you iterate through both arrays simultaneously using two pointers, and the maximum number of iterations is the sum of the sizes of the arrays.

Space Complexity: The space complexity of the intersection array is O(min(n1,n2)) since the intersection cannot exceed the size of the smaller array.
*/