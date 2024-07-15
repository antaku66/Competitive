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
 * @brief  ’PˆêŽn“_‚©‚çŠe’¸“_‚Ö‚ÌÅ’ZŒo˜H‚ð‹‚ß‚é
 * @brief  dists ‚Ì‘S—v‘f‚ð INF ‚Å‰Šú‰»‚µ‚Ä‚¨‚­‚±‚Æ
 * @return •‰•Â˜H‚ª‘¶Ý‚·‚é‚Æ‚«false –³‚¯‚ê‚Îtrue
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