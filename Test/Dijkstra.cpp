#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

namespace {

/**
 * @brief �P��n�_����e���_�ւ̍ŒZ�o�H�����߂�
 * @brief ���ӂ����݂���ꍇ�͎g�p�s��(BellmanFord�@���L��)
 * @brief graph �̊e�v�f�̊e�ӂ� <to, cost>
 * @brief dists �̑S�v�f�� INF �ŏ��������Ă�������
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