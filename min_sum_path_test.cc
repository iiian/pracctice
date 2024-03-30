#include "min_sum_path.h"
#include <gtest/gtest.h>

using namespace std;

TEST(MinSumPath, MainTest) {
  Solution s;
  vector<vector<int>> map = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  EXPECT_EQ(s.minPathSum(map), 7);

  map = {{1, 2, 3}, {4, 5, 6}};
  EXPECT_EQ(s.minPathSum(map), 12);

  map = {{9,1,4,8}};
  EXPECT_EQ(s.minPathSum(map), 22);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
