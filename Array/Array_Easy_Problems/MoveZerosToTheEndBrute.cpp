/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void MoveZerosToTheEndBrute(vector<int> &a, int n)
{

    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }

    int nT = temp.size();
    for (int i = 0; i < nT; i++)
    {
        a[i] = temp[i];
    }

    for (int i = nT; i < n; i++)
    {
        a[i] = 0;
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

    int d;
    cin >> d;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    MoveZerosToTheEndBrute(arr, n);

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void MoveZerosToTheEndBrute(vector<int> &a, int n)
{

    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }

    int nT = temp.size();
    for (int i = 0; i < nT; i++)
    {
        a[i] = temp[i];
    }

    for (int i = nT; i < n; i++)
    {
        a[i] = 0;
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

    int d;
    cin >> d;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    MoveZerosToTheEndBrute(arr, n);

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Name: Move Zeros to the End (Brute Force)

Time Complexity: The time complexity of the brute force approach for moving zeros to the end of an array is O(n), where n is the number of elements in the array. In the worst case, the algorithm iterates through the array once to filter out non-zero elements and then again to fill in the zeros at the end.

Space Complexity: The space complexity of the brute force approach is O(n), where n is the number of elements in the array. This is because the algorithm uses an additional vector to store the non-zero elements temporarily before copying them back to the original array.

*/