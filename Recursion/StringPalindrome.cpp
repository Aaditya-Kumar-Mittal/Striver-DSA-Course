/*
Aaditya Mittal - My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of 'check' is a palindrome
bool checkPalindrome(string check, int i)
{
    int n = check.length();

    // Base case: if the current index 'i' is greater than or equal to half of the string length,
    // then the string is a palindrome
    if (i >= n / 2)
    {
        return true;
    }

    // Check if the characters at positions 'i' and 'n - i - 1' are equal
    if (check[i] != check[n - i - 1])
    {
        return false; // If not equal, the string is not a palindrome
    }

    // Recursively check the remaining characters
    return checkPalindrome(check, i + 1);
}

int main()
{
    // Input a string
    string text;
    getline(cin, text);

    // Check if the entered string is a palindrome using the recursive function
    if (checkPalindrome(text, 0))
    {
        std::cout << "String is a Palindrome." << std::endl;
    }
    else
    {
        std::cout << "String is not a Palindrome." << std::endl;
    }

    return 0;
}

/*
Analysis Portion and Comments:

- The main function reads a string from the user using getline.
- It then calls the 'checkPalindrome' function to determine if the string is a palindrome.
- The 'checkPalindrome' function uses recursion to compare characters from the beginning and end of the string.
- If the characters match for all positions, the function returns true, indicating a palindrome.
- Otherwise, it returns false.
- The main function prints whether the entered string is a palindrome or not.
*/