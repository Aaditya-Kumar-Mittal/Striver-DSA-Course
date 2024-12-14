#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m; // n = number of vertices, m = number of edges
  cin >> n >> m;

  // Initialize the adjacency matrix
  int adj[n + 1][n + 1] = {0}; // Use n+1 for 1-based indexing

  // Read the edges and populate the adjacency matrix
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1; // Edge from u to v
    adj[v][u] = 1; // Edge from v to u (because it's undirected)
  }

  // Display the adjacency matrix
  cout << "Adjacency Matrix:" << endl;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}