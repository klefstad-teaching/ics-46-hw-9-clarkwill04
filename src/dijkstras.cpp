#include "dijkstras.h"
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
  int n = G.numVertices;
  vector<int> dist(n, INF);
  dist[source] = 0;

  previous.assign(n, -1);
  previous[source] = -1;

  // pq by (distance, vertex) using min heap
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  // source has distance 1
  pq.push({0, source});

  while (!pq.empty())
  {
    auto [currDistance, currVertex] = pq.top();
    pq.pop();

    if (currDistance != dist[currVertex]) continue;

    for (const auto& edge : G[currVertex])
    {
      int v = edge.dst;
      int weight = edge.weight;

      if ( dist[currVertex] != INF 
        && dist[currVertex] + weight 
        < dist[v] )
        {
          dist[v] = dist[currVertex] + weight;
          previous[v] = currVertex;
          pq.push({dist[v], v});
        }
    }
  }
  return dist;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    
    reverse(path.begin(), path.end());
    
    return path;
}

void print_path(const vector<int>& v, int total) 
{

  for (const auto & node : v)
    cout << node << ' ';
  cout << "\nTotal cost is " << total << endl;

}