#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v)
{
    vector<int> ans;
    map<int, int> mpp;

    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }

    int maxFreq = 0, minFreq = v.size();
    int maxEle = 0, minEle = 0;
    // Traverse through map to find the elements.

    for (auto it : mpp)
    {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq)
        {
            maxEle = element;
            maxFreq = count;
        }

        if (count < minFreq)
        {
            minEle = element;
            minFreq = count;
        }
    }
    ans.push_back(maxEle);
    ans.push_back(minEle);
    return ans;
}

int main()
{
    vector<int> a = {10, 5, 10, 15, 10, 5};

    vector<int> ans = getFrequencies(a);

    cout << "The highest frequency element is: " << ans[0] << endl;
    cout << "The lowest frequency element is: " << ans[1] << endl;

    return 0;
}

/*
Sample Input 1 :
6
1 2 3 1 1 4
Sample Output 1 :
1 2
Sample Explanation 1:
Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

Output: 1 2

Explanation: The element having the highest frequency is '1', and the frequency is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we need to pick the smallest element, we pick '2'. Hence we return [1, 2].
Sample Input 2 :
6
10 10 10 3 3 3
Sample Output 2 :
3 3
Sample Explanation 2:
Input: ‘n' = 6, 'v' = [10, 10, 10, 3, 3, 3]

Output: 3 3

Explanation: Since the frequency of '3' and '10' is 3. Therefore, the element with the maximum and minimum frequency is '3'.
Expected Time Complexity :
The expected time complexity is O(n), where n is the size of the array.
Expected Space Complexity :
The expected time complexity is O(n), where n is the size of the array.
Constraints :
2 <=  n <= 10^4
1 <= v[i] <= 10^9
There are at least two distinct elements in the array.
Time Limit: 1 sec
*/