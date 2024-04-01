#include "min_sum_path.h"
#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

void printGrid(const vector<vector<int>> &);

int minPathSum(vector<vector<int>> &grid) {
  int bottom = grid.size() - 1;
  int right = grid[0].size() - 1;
  int edge = bottom; // moves up as we get closer to origin
  // construct dp matrix
  vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
  std::cout<<"\nnew\n";
  printGrid(grid);

  // initialize dest cost
  dp[bottom][right] = grid[bottom][right];

  auto q = queue<tuple<int, int>>();
  q.push(tuple<int, int>(bottom, right - 1));
  q.push(tuple<int, int>(bottom - 1, right));
  printGrid(dp);
  while (!q.empty()) {
    auto [i, j] = q.front();
    std::cout << "(x=" << i << ", y=" << j << ")\n";
    q.pop();
    if (i < 0 || j < 0) {
      if (j < 0) {
        edge -= 1;
      }
      continue;
    }

    if (i < bottom && j < right) {
      dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
    } else if (i < bottom) {
      dp[i][j] = dp[i + 1][j] + grid[i][j];
    } else {
      dp[i][j] = dp[i][j + 1] + grid[i][j];
    }

    if (i == edge) {
      q.push(tuple<int, int>(i, j - 1));
    }
    q.push(tuple<int, int>(i - 1, j));

    printGrid(dp);
  }
  std::cout << '\n';
  return dp[0][0];
}

void printGrid(const std::vector<std::vector<int>> &grid) {
  for (const auto &row : grid) {
    for (int num : row) {
      std::cout << std::setw(12)
                << num; // Assuming 3 digits + 1 space for padding
    }
    std::cout << '\n'; // Move to the next line after each row
  }
  std::cout << '\n';
}
