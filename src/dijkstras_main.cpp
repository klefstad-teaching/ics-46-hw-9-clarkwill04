#include "dijkstras.h"
int main() {
  Graph g;
  file_to_graph("src/small.txt", g);
  vector<int> previous;
  vector<int> dijk = dijkstra_shortest_path(g, 0, previous);
  print_path(dijk, dijk.size());

}