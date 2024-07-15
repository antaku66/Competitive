#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;

namespace {

/**
 * @brief  �S���_����e���_�ւ̍ŒZ�o�H�����߂�
 * @brief  dp[i][i] = 0, dp[s][t] = c, ���̑�INF �����͍ς݂ł��邱��
 * @return ���H�����݂���Ƃ�false �������true
 */
bool WarshallFloyd(std::vector<std::vector<ll>>& dp) {
  const size_t v = dp.size();
  for (size_t i = 0; i < v; ++i) {
    for (size_t from = 0; from < v; ++from) {
      for (size_t to = 0; to < v; ++to) {
        if ((dp[from][i] < INF) && (dp[i][to] < INF)) {
          dp[from][to] = std::min(dp[from][to], (dp[from][i] + dp[i][to]));
        }
      }
    }
  }
  for (size_t i = 0; i < v; ++i) {
    if (dp[i][i] < 0) {
      return false;
    }
  }
  return true;
}

}  // namespace