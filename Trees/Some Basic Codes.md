# Some Basic Tree Concepts

## Given an integer i. Print the maximum number of nodes on level i of a binary tree

```cpp
class Solution
{
public:
  int countNodes(int i)
  {
    // your code here
    if (i == 0)
      return 0;
    int MaxNumOfNodes = pow(2, i - 1);
    return MaxNumOfNodes;
  }
};
```
