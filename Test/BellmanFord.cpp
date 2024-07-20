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
 * @brief  単一始点から各頂点への最短経路を求める
 * @brief  dists の全要素を INF で初期化しておくこと
 * @return 負閉路が存在するときfalse 無ければtrue
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