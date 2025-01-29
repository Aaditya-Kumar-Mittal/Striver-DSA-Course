# Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int recursive_solution(int index, int target, vector<int> &arr)
{
  if (target == 0)
    return 1;
  if (index == 0)
    return arr[0] == target;

  int not_picked = recursive_solution(index - 1, target, arr);
  int picked = (target >= arr[index]) ? recursive_solution(index - 1, target - arr[index], arr) : 0;

  return not_picked + picked;
}

int memoization(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (target == 0)
    return 1;
  if (index == 0)
    return arr[0] == target;

  if (dp[index][target] != -1)
    return dp[index][target];

  int not_picked = memoization(index - 1, target, arr, dp);
  int picked = (target >= arr[index]) ? memoization(index - 1, target - arr[index], arr, dp) : 0;

  return dp[index][target] = not_picked + picked;
}

int tabulation(int n, int k, vector<int> &arr)
{
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));

  // Base case: there is always one way to make target 0 (by picking nothing)
  for (int i = 0; i < n; i++)
    dp[i][0] = 1;

  // If the first element is within bounds, mark it
  if (arr[0] <= k)
    dp[0][arr[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int sum = 0; sum <= k; sum++)
    {
      int not_picked = dp[i - 1][sum];
      int picked = (sum >= arr[i]) ? dp[i - 1][sum - arr[i]] : 0;
      dp[i][sum] = not_picked + picked;
    }
  }

  return dp[n - 1][k];
}

int tabulation_optimized(int n, int k, vector<int> &arr)
{
  vector<int> dp(k + 1, 0), current(k + 1, 0);

  // Base case: there is always one way to make target 0 (by picking nothing)
  dp[0] = current[0] = 1;

  // If the first element is within bounds, mark it
  if (arr[0] <= k)
    dp[arr[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int sum = 0; sum <= k; sum++)
    {
      int not_picked = dp[sum];
      int picked = (sum >= arr[i]) ? dp[sum - arr[i]] : 0;
      current[sum] = not_picked + picked;
    }
    dp = current
  }

  return dp[k];
}

int findWays(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));

  // Uncomment to use memoization
  // return memoization(n - 1, k, arr, dp);

  return tabulation(n, k, arr);
}
```
