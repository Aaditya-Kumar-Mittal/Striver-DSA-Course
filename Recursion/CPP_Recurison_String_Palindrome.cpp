
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
	int palindrome(string s, int i)
	{
		if (i >= s.size() / 2)
			return 1;

		if (s[i] != s[s.size() - i - 1])
			return 0;

		return palindrome(s, i + 1);
	}

	int isPalindrome(string S)
	{
		return palindrome(S, 0);
	}
};

//{ Driver Code Starts.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		Solution ob;

		cout << ob.isPalindrome(s) << "\n";
	}

	return 0;
}
