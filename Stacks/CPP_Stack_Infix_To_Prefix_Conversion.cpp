#include <bits/stdc++.h>

using namespace std;

// Function to get the priority of operators
int getPriority(char C)
{
  if (C == '-' || C == '+')
    return 1;
  else if (C == '*' || C == '/')
    return 2;
  else if (C == '^')
    return 3;
  return 0;
}

string infixToPostfix(string infix)
{
  infix = '(' + infix + ')';

  int len = infix.size();

  stack<char> stk;

  string postfix = "";

  for (int i = 0; i < len; i++)
  {
    if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
    {
      postfix += infix[i];
    }
    else if (infix[i] == '(')
    {
      stk.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (!stk.empty() && stk.top() != '(')
      {
        postfix += stk.top();

        stk.pop();
      }

      stk.pop();
    }
    else
    {
      if (infix[i] == '^')
      {
        while (!stk.empty() && getPriority(infix[i]) <= getPriority(stk.top()))
        {
          postfix += stk.top();

          stk.pop();
        }
      }
      else
      {
        while (!stk.empty() && getPriority(infix[i]) < getPriority(stk.top()))
        {
          postfix += stk.top();

          stk.pop();
        }
      }
      stk.push(infix[i]);
    }
  }

  while (!stk.empty())
  {
    postfix += stk.top();

    stk.pop();
  }

  return postfix;
}

string infixToPrefix(string infix)
{
  int len = infix.size();

  reverse(infix.begin(), infix.end());

  for (int i = 0; i < len; i++)
  {
    if (infix[i] == '(')
      infix[i] = ')';

    else if (infix[i] == ')')
      infix[i] = '(';
  }

  string prefix = infixToPostfix(infix);

  reverse(prefix.begin(), prefix.end());

  return prefix;
}

int main()
{

  string s = ("x+y*z/w+u");

  std::cout << infixToPrefix(s) << std::endl;

  return 0;
}