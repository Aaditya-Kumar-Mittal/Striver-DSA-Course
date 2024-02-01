/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int NumberOccurringOnce(vector<int> a, int n)
{
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ a[i];
    }
    return xorr;
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

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Element Appearing Once in a Twice Element Array is: " << NumberOccurringOnce(arr, n)
         << endl;

    return 0;
}

/*
Analysis of Problem

Time Complexity: O(N), where N = size of the array.
Reason: We are iterating the array only once.

Space Complexity: O(1) as we are not using any extra space.


#include<vector>

 

int getSingleElement(vector<int> &arr){

    int n=arr.size();

    for(int i=0;i<n;i=i+2){

        if(arr[i]==arr[i+1]){

            continue;

        }

        else{

            return arr[i];

        }

    } //Takes O(log n)

}

*/