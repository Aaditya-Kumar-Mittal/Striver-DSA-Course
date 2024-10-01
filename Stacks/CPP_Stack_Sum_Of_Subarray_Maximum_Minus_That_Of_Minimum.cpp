#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  vector<int> nextLargerElement(vector<int> &arr)
  {
    vector<int> NLE(arr.size());
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] <= arr[i])
        st.pop();
      NLE[i] = st.empty() ? arr.size() : st.top();
      st.push(i);
    }

    std::cout << "Print NGE: " << std::endl;
    for (auto &&i : NLE)
    {
      std::cout << i << " ";
    }
    cout << endl;

    return NLE;
  }

  vector<int> previousLargerEqualElement(vector<int> &arr)
  {
    vector<int> PLEE(arr.size());
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
      while (!st.empty() && arr[st.top()] < arr[i])
        st.pop();
      PLEE[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    std::cout << "Print PLEE: " << std::endl;
    for (auto &&i : PLEE)
    {
      std::cout << i << " ";
    }
    cout << endl;
    return PLEE;
  }

  vector<int> nextSmallerElement(vector<int> &arr)
  {
    vector<int> NSE(arr.size());
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      NSE[i] = st.empty() ? arr.size() : st.top();
      st.push(i);
    }

    std::cout << "Print NSE: " << std::endl;
    for (auto &&i : NSE)
    {
      std::cout << i << " ";
    }
    cout << endl;
    return NSE;
  }

  vector<int> previousSmallerEqualElement(vector<int> &arr)
  {
    vector<int> PSEE(arr.size());
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
      while (!st.empty() && arr[st.top()] > arr[i])
        st.pop();
      PSEE[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    std::cout << "Print PSEE: " << std::endl;
    for (auto &&i : PSEE)
    {
      std::cout << i << " ";
    }
    cout << endl;
    return PSEE;
  }

  int sumSubarrayMaxs(vector<int> &arr)
  {
    vector<int> nle = nextLargerElement(arr);
    vector<int> plee = previousLargerEqualElement(arr);
    long long total = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
      int left = i - plee[i];
      int right = nle[i] - i;
      total = (total + ((1LL * right * left % mod) * arr[i] % mod) % mod) % mod;
    }
    return (int)total;
  }

  int sumSubarrayMins(vector<int> &arr)
  {
    vector<int> nse = nextSmallerElement(arr);
    vector<int> psee = previousSmallerEqualElement(arr);
    long long total = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
      int left = i - psee[i];
      int right = nse[i] - i;
      total = (total + ((1LL * right * left % mod) * arr[i] % mod) % mod) % mod;
    }
    return (int)total;
  }

  int sumSubarrayMaxMinDifference(vector<int> &arr)
  {
    int sumMax = sumSubarrayMaxs(arr);
    int sumMin = sumSubarrayMins(arr);
    return (sumMax - sumMin + (int)(1e9 + 7)) % (int)(1e9 + 7);
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 4, 6, 7, 3, 7, 8, 1}; // Example array
  int result = sol.sumSubarrayMaxMinDifference(arr);
  cout << "Difference between sum of subarray maximums and minimums: " << result << endl;
  return 0;
}
