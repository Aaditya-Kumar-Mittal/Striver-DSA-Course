# Notes - 1

## General Summary of What Kind of Problems can be solved and cannot be solved by using Two Pointers

- Link: [General summary of what kind of problem can/ cannot solved by Two Pointers](https://leetcode.com/problems/subarray-sum-equals-k/solutions/301242/general-summary-of-what-kind-of-problem-3py46)
- A problem can be solved by two pointers when two pointers come into place to help us reduce the total cases we need to consider, such that the corresponding time complexity will reduce too.
- Generalizing the characteristics of the problems that can be solved by two pointers. The summary is simple:
  - If the **narrow scope of your window is valid**, then the wider scope is valid. By definition of the narrow window being a sub problem of the wider problem.
  - If the **wider scope of the window is invalid**, then the narrow scope is also invalid. By definition of the wider window being a full problem of the given sub problem (narrow window -> sub problem).
  - If the narrow scope of your window is invalid, it doesn't always mean the wider scope is invalid. You need to increment the pointers to find out (this is why the 2 pointer solution works, after all). In a given narrow window, you cannot guarantee that this window means the solution cannot be found, because the narrow window is just a slice of a given string, array chunk, whatever. Then, if all sub problems are solved and the wider problem is also invalid, then we can say that all sub problems or sub strings cannot be formed to solve the problem.
  - With 2 rules above hold, we are able to optimize the brute-force solution to two pointers solution.
  - The real key here is the relationship of the sub problems to the greater whole.
- [Important Problems - 1](https://leetcode.com/discuss/post/1094290/custom-comparator-function-cpp-by-rohanp-8u47/)
