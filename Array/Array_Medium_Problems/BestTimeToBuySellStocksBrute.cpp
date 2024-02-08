#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit from buying and selling stocks
int BestTimeToBuyAndSellStock(vector<int> a, int n)
{
    int maxProfit = 0;

    // Iterate through each day
    for (int i = 0; i < n; i++)
    {
        // Check potential selling days after the current day
        for (int j = i + 1; j < n; j++)
        {
            // If the stock price on the selling day is higher than the buying day,
            // calculate the profit and update the maximum profit
            if (a[j] > a[i])
            {
                maxProfit = max(a[j] - a[i], maxProfit);
            }
        }
    }

    return maxProfit;
}

int main()
{
    int n;
    cin >> n;

    // Input array representing stock prices for each day
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print the input array
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Calculate and print the maximum profit
    cout << "The max Profit one can get from stocks is: " << BestTimeToBuyAndSellStock(arr, n) << endl;

    return 0;
}

/*
Analysis of Problem

Name: Best Time to Buy and Sell Stock
Time Complexity: O(n^2), where n is the size of the input array. The nested loops iterate through all possible pairs of buying and selling days.
Space Complexity: O(1). The algorithm uses only a constant amount of extra space, independent of the input size.
*/
