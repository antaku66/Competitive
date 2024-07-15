#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

namespace {

/**
 * @brief 単一始点から各頂点への最短経路を求める
 * @brief 負辺が存在する場合は使用不可(BellmanFord法が有効)
 * @brief graph の各要素の各辺は <to, cost>
 * @brief dists の全要素を INF で初期化しておくこと
 */
void Dijkstra(const vector<vector<pair<int, ll>>>& graph, vector<ll>& dists,
              int s) {
  using Pair = pair<ll, int>;  // <cost, from>
  priority_queue<Pair, vector<Pair>, greater<Pair>> q;
  q.emplace((dists[s] = 0), s);

  while (!q.empty()) {
    ll dist = q.top().first;
    int from = q.top().second;
    q.pop();

    if (dists[from] < dist) continue;

    for (const auto& edge : graph[from]) {
      auto to = edge.first;
      auto cost = edge.second;
      const ll d = (dists[from] + cost);

      if (d < dists[to]) {
        q.emplace((dists[to] = d), to);
      }
    }
  }
}

}  // namespace