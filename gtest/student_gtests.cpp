#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(ladder, TestIfNeighbor) {

  string s1 = "cat", s2 = "dim", s3 = "dip", s4 = "dime";
  
  // cat is not one away from dim
  EXPECT_FALSE(is_adjacent(s1, s2));

  // dip --> dim
  EXPECT_TRUE(is_adjacent(s2, s3));

  // dim --> dime 
  EXPECT_TRUE(is_adjacent(s2, s4));

  // dip --> dim --> dime != 1
  EXPECT_FALSE(is_adjacent(s3, s4));

}


TEST(DijkstraTest, BasicGraphTest) {
    Graph G;
    G.numVertices = 5;
    G.resize(G.numVertices);
    
    // 0 -> 1 (10), 0 -> 4 (5)
    // 1 -> 2 (1), 1 -> 4 (2)
    // 2 -> 3 (4)
    // 3 -> 0 (7), 3 -> 2 (6)
    // 4 -> 1 (3), 4 -> 2 (9), 4 -> 3 (2)
    G[0].push_back(Edge(0, 1, 10));
    G[0].push_back(Edge(0, 4, 5));
    G[1].push_back(Edge(1, 2, 1));
    G[1].push_back(Edge(1, 4, 2));
    G[2].push_back(Edge(2, 3, 4));
    G[3].push_back(Edge(3, 0, 7));
    G[3].push_back(Edge(3, 2, 6));
    G[4].push_back(Edge(4, 1, 3));
    G[4].push_back(Edge(4, 2, 9));
    G[4].push_back(Edge(4, 3, 2));
    
    vector<int> previous;
    vector<int> dist = dijkstra_shortest_path(G, 0, previous);
    
    // Expected shortest distances from vertex 0:
    // 0: 0, 1: 8 (0 -> 4 -> 1), 2: 9 (0 -> 4 -> 1 -> 2),
    // 3: 7 (0 -> 4 -> 3), 4: 5 (0 -> 4)
    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 8);
    EXPECT_EQ(dist[2], 9);
    EXPECT_EQ(dist[3], 7);
    EXPECT_EQ(dist[4], 5);
    

    vector<int> path = extract_shortest_path(dist, previous, 3);
    vector<int> expected_path = {0, 4, 3};
    EXPECT_EQ(path, expected_path);


}

