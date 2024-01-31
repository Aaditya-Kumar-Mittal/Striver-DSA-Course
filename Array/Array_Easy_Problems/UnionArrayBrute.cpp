/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> UnionArrayBrute(vector<int> &a, vector<int> &b, int n1, int n2)
{
    // Using Set

    set<int> unionSet;
    for (int i = 0; i < n1; i++)
    {
        unionSet.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        unionSet.insert(b[i]);
    }

    int n = unionSet.size();

    vector<int> ans(n);

    int i = 0;
    for (auto it : unionSet)
    {
        ans[i++] = it;
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

    vector<int> unionArr = UnionArrayBrute(a, b, n1, n2);

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

Analysis of Problem

Name: Union of Two Arrays (Brute Force)

Time Complexity: Let ( n1) and ( n2) be the sizes of arrays ( a) and ( b ), respectively. In the brute force approach, the time complexity is ( O(n1 + n2 + (n1 + n2) log(n1 + n2))). 

Explanation: 
- Constructing the set involves iterating over both arrays, \( a \) and \( b \), which takes \( O(n_1 + n_2) \) time.
- Converting the set to a vector involves iterating over the set, which takes \( O(n_1 + n_2) \) time.
- Sorting the vector (if needed) takes \( O((n_1 + n_2) \log(n_1 + n_2)) \) time.

Space Complexity: The space complexity is \( O(n_1 + n_2) \) due to the set used to store the union of the arrays.

The provided code implements a brute force approach to find the union of two arrays \( a \) and \( b \). It uses a set to store unique elements and then converts the set to a vector to return the union array.

Comments:
- The code is straightforward and correctly computes the union of the two arrays.
- However, if the order of elements in the union array does not matter, using a set directly might be sufficient and could save the conversion to a vector and the associated sorting.
- The commented-out main function seems to be unrelated to the union of arrays and can be removed from the code.

Overall, the implementation is functional, but depending on the requirements, there might be room for optimizations or different approaches.

*/