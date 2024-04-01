#include "wildcard_matching.h"
#include <vector>

#include <iostream>
#include <vector>

template <typename T>
void print2DVector(const std::vector<std::vector<T>> &vec) {
  for (const auto &row : vec) {
    for (const auto &element : row) {
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

using namespace std;

bool isMatch(string s, string p) {
  vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
  dp[0][0] = true;
  for (int j = 1; j <= p.size(); j++) {
    dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
  }
  print2DVector(dp);
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= p.size(); j++) {
      char pc = p[j - 1];
      switch (pc) {
      case '?':
        dp[i][j] = dp[i - 1][j - 1];
        break;
      case '*':
        dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
        break;
      default:
        dp[i][j] = (pc == s[i - 1]) && dp[i - 1][j - 1];
        break;
      }
    }
  }
  return dp[s.size()][p.size()];
}
