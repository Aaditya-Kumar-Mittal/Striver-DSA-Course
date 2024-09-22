//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
  /**
   * Function to determine if a graph can be colored with at most M colors such that
   * no two adjacent vertices of the graph are colored with the same color.
   *
   * @param graph A 2D adjacency matrix representing the graph.
   * @param m The number of colors available.
   * @param N The number of vertices in the graph.
   * @return A boolean indicating whether the graph can be colored with M colors.
   */
  bool graphColoring(bool graph[101][101], int m, int N)
  {
    // Array to store the color assigned to each vertex
    int color[N] = {0};

    // Call the helper function to check if coloring is possible
    if (colorGraph(0, color, m, N, graph))
      return true;

    // If no valid coloring is found, return false
    return false;
  }

  /**
   * Helper function for coloring the graph using backtracking.
   *
   * @param vertex The current vertex being colored.
   * @param color An array storing the colors assigned to vertices.
   * @param m The number of available colors.
   * @param n The total number of vertices.
   * @param graph A 2D adjacency matrix representing the graph.
   * @return A boolean indicating whether the graph can be colored from the current state.
   */
  bool colorGraph(int vertex, int color[], int m, int n, bool graph[101][101])
  {
    // If all vertices are successfully colored, return true
    if (vertex == n)
      return true;

    // Try coloring the current vertex with one of the m colors
    for (int i = 1; i <= m; i++)
    {
      // Check if it is safe to color the current vertex with color i
      if (isSafe(vertex, color, graph, n, i))
      {
        // Assign color i to the current vertex
        color[vertex] = i;

        // Recur to color the rest of the vertices
        if (colorGraph(vertex + 1, color, m, n, graph))
          return true;

        // If no valid coloring is possible, backtrack and reset the color
        color[vertex] = 0;
      }
    }

    // Return false if no valid color can be assigned
    return false;
  }

  /**
   * Function to check if it is safe to assign the given color to the current vertex.
   *
   * @param node The current vertex being checked.
   * @param color An array storing the colors assigned to vertices.
   * @param graph A 2D adjacency matrix representing the graph.
   * @param n The total number of vertices.
   * @param col The color being assigned to the vertex.
   * @return A boolean indicating whether it is safe to assign the color to the vertex.
   */
  bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
  {
    // Check the adjacent vertices of the current vertex
    for (int k = 0; k < n; k++)
    {
      // If there is an edge between node and k, and k has the same color, return false
      if (k != node && graph[k][node] == 1 && color[k] == col)
        return false;
    }

    // If no conflict is found, it is safe to assign the color
    return true;
  }
};

//{ Driver Code Starts.
int main()
{
  int t; // Number of test cases
  cin >> t;

  while (t--)
  {
    int n, m, e; // n: number of vertices, m: number of colors, e: number of edges
    cin >> n >> m >> e;
    int i;

    // Initialize the adjacency matrix for the graph
    bool graph[101][101];
    for (i = 0; i < n; i++)
    {
      memset(graph[i], 0, sizeof(graph[i]));
    }

    // Input the edges of the graph
    for (i = 0; i < e; i++)
    {
      int a, b;
      cin >> a >> b;
      graph[a - 1][b - 1] = 1;
      graph[b - 1][a - 1] = 1;
    }

    // Create an instance of the Solution class and call the graphColoring function
    Solution ob;
    cout << ob.graphColoring(graph, m, n) << endl;
  }

  return 0;
}
// } Driver Code Ends

/**
 * Problem Name: M-Coloring Problem (Graph Coloring)
 *
 * Time Complexity:
 * - The time complexity is O(M^N), where N is the number of vertices and M is the number of colors.
 *   This is because for each vertex, we try M colors, and we do this for all N vertices.
 *
 * Space Complexity:
 * - The space complexity is O(N), where N is the number of vertices. This space is used to store
 *   the color of each vertex.
 *
 * Explanation:
 * 1. Backtracking Approach:
 *    - The algorithm solves the M-coloring problem using a backtracking approach. It tries to assign
 *      colors to the vertices one by one, ensuring that no two adjacent vertices have the same color.
 *
 * 2. Safety Check:
 *    - The `isSafe` function checks if it is safe to assign a particular color to a vertex. This means
 *      that none of its adjacent vertices should have the same color.
 *
 * 3. Recursion and Backtracking:
 *    - The algorithm recursively assigns colors to the vertices. If it finds that a valid coloring is
 *      not possible for a certain vertex, it backtracks by resetting the color of the vertex and tries
 *      another color.
 *
 * 4. Practical Use:
 *    - This problem has practical applications in areas such as map coloring, scheduling problems, and
 *      register allocation in compilers.
 */
