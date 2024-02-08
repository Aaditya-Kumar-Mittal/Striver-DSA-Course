#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit from buying and selling stocks
int BestTimeToBuyAndSellStock(vector<int> a, int n)
{
    int minPrice = a[0]; // Initialize minimum price to the first day's price
    int profit = 0;      // Initialize maximum profit to zero

    // Iterate through each day's price
    for (int i = 1; i < n; i++)
    {
        int cost = a[i] - minPrice;     // Calculate the potential profit by selling on the current day
        profit = max(profit, cost);     // Update the maximum profit if the potential profit is greater
        minPrice = min(minPrice, a[i]); // Update the minimum price seen so far
    }

    return profit; // Return the maximum profit
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
Time Complexity: O(n), where n is the size of the input array. The algorithm iterates through the array once.
Space Complexity: O(1). The algorithm uses only a constant amount of extra space, independent of the input size.
*/
