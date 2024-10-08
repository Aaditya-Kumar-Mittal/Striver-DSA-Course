/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> IntersectionArrayBrute(vector<int> &a, vector<int> &b, int n1, int n2)
{
    vector<int> visited(n2);
    for (int i = 0; i < n2; i++)
    {
        visited[i] = 0;
    }

    vector<int> ans;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j] && visited[j] == 0)
            {
                ans.push_back(a[i]);
                visited[j] = 1;
                break;
            }

            if (b[j] > a[i])
            {
                break;
            }
        }
    }

    return ans;
}

//Intersecction using unordered_set
int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here
    int count = 0;

    unordered_set<int> set_a(a, a + n);
    unordered_set<int> set_b(b, b + m);

    for (int element : set_a)
    {
        if (set_b.find(element) != set_b.end())
        {
            count++;
        }
    }

    return count;
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

    vector<int> intersectionArr = IntersectionArrayBrute(a, b, n1, n2);

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

Name: Intersection of Two Arrays (Brute Force)

Time Complexity: Let n1 and n2 be the sizes of arrays a and b, respectively. In the brute force approach, the time complexity is O(n1*n2). This is because for each element in array a, you iterate through all elements in array b to check for intersections.

Space Complexity: The space complexity is O(n2) for the visited array, where n2 is the size of array b. Additionally, the space complexity of the intersection array is O(min(n1,n2)) since the intersection cannot exceed the size of the smaller array.

*/