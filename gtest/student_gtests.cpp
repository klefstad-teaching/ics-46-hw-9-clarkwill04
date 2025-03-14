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


