#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

namespace {

struct Edge {
  int from_, to_;
  ll cost_;
};

/**
 * @brief  �P��n�_����e���_�ւ̍ŒZ�o�H�����߂�
 * @brief  dists �̑S�v�f�� INF �ŏ��������Ă�������
 * @return ���H�����݂���Ƃ�false �������true
 */
bool BellmanFord(const std::vector<Edge>& edges, std::vector<ll>& dist,
                 int startIndex) {
  dist[startIndex] = 0;
  for (size_t i = 0; i < dist.size(); ++i) {
    bool changed = false;
    for (const auto& edge : edges) {
      if (dist[edge.from_] == INF) continue;

      const ll d = dist[edge.from_] + edge.cost_;
      if (d < dist[edge.to_]) {
        dist[edge.to_] = d;
        changed = true;
      }
    }
    if (!changed) {
      return true;
    }
  }
  return false;
}

}  // namespace