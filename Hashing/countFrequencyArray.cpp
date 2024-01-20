#include <bits/stdc++.h>
using namespace std;

int freqArray[1000000] = {0};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &i : arr)
    {
        cin >> i;
    }

    // preComputation
    for (int i = 0; i < n; i++)
    {
        freqArray[arr[i]] += 1;
    }

    // fetching;

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        cout << number << " " << freqArray[number] << endl;
    }

    return 0;
}
