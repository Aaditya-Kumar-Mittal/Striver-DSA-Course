#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  /*
      Function to calculate how much water can be trapped between the heights.
      This approach uses two pointers to scan from both ends of the array towards the center.
      For each element, the algorithm calculates how much water can be trapped above it
      based on the minimum of the maximum heights to its left and right.

      Parameters:
      - vector<int>& height: Reference to the input array representing heights of walls.

      Returns:
      - int: Total units of water that can be trapped between the walls.
  */
  int trap(vector<int> &height)
  {
    // Initialize variables
    int lMax = 0, rMax = 0;           // Track the left and right maximum heights
    int total = 0;                    // Total water trapped
    int l = 0, r = height.size() - 1; // Left and right pointers

    // Use a two-pointer approach to traverse the array from both ends
    while (l <= r)
    {
      // If the left height is less than or equal to the right height
      if (height[l] <= height[r])
      {
        // If the current left height is greater than or equal to the left maximum, update it
        if (height[l] >= lMax)
        {
          lMax = height[l];
        }
        // Otherwise, calculate water trapped and add to the total
        else
        {
          total += lMax - height[l];
        }
        l++; // Move the left pointer to the right
      }
      else
      {
        // If the current right height is greater than or equal to the right maximum, update it
        if (height[r] >= rMax)
        {
          rMax = height[r];
        }
        // Otherwise, calculate water trapped and add to the total
        else
        {
          total += rMax - height[r];
        }
        r--; // Move the right pointer to the left
      }
    }

    return total; // Return the total trapped water
  }
};

/****************************************************************

Problem Name: Trapping Rain Water

Time Complexity:
- O(n), where n is the size of the height array.
  The algorithm uses two pointers and traverses the entire array once, processing each element exactly once.

Space Complexity:
- O(1), since the algorithm uses a constant amount of extra space regardless of the input size.
  The space used by the left and right pointers, and the left and right maximum height trackers, is fixed.

Explanation:
1. **Two-pointer Approach**:
   - The idea is to maintain two pointers (`l` and `r`) starting from the leftmost and rightmost ends of the array, respectively.
   - As long as `height[l]` is less than or equal to `height[r]`, we update the left maximum (`lMax`) and calculate the trapped water.
   - If `height[l] > height[r]`, we do the same for the right pointer and right maximum (`rMax`).
   - This ensures that water can only be trapped if there is a higher wall on either side of the current position, and we move the pointers inward to find the next possible trapping points.

2. **Water Calculation**:
   - For every index, the amount of water trapped above it is determined by the difference between the maximum height seen so far and the current height at that index.

3. **Edge Cases**:
   - Arrays of size less than 3 cannot trap any water, so no special handling is needed for those cases.
   - Flat areas or monotonically increasing or decreasing arrays will result in no trapped water.

*****************************************************************/
