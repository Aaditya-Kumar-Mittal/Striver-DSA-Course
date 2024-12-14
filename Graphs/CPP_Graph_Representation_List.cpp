#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m; // n = number of vertices, m = number of edges
  cin >> n >> m;

  // Initialize the adjacency list
  vector<int> adj[n + 1];

  // Read the edges and populate the adjacency list
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // Add edge from u to v
    adj[v].push_back(u); // Add edge from v to u (because it's undirected)
  }

  // Display the adjacency list
  cout << "Adjacency List:" << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << i << " -> ";
    for (int neighbor : adj[i])
    {
      cout << neighbor << " ";
    }
    cout << endl;
  }

  return 0;
}