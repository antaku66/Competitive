#include <bits/stdc++.h>
using namespace std;

namespace {

/* 木 graph に対する根を root として 最近共通祖先を求めるクラス
   Query(u,v): u と v の LCA を求める。計算量 O(logn)
   GetDist(v): v と root の距離を求める。計算量 O(1)
   前処理: O(nlogn)時間, O(nlogn)空間
*/
class LowestCommonAncestor {
public:
  LowestCommonAncestor(const vector<vector<int>>& graph, int root = 0) {
    Init(graph, root);
  }

  int Query(int u, int v) {
    if (dists[u] < dists[v]) {
      swap(u, v);  // u の方が深いとする
    }
    // LCA までの距離を同じにする
    int diff = dists[u] - dists[v];
    for (int k = parents.size() - 1; k >= 0; --k) {
      if (diff >= pow(2, k)) {
        u = parents[k][u];
        diff -= pow(2, k);
      }
    }
    // 二分探索で LCA を求める
    if (u == v) {
      return u;
    }
    for (int k = static_cast<int>(parents.size()) - 1; k >= 0; --k) {
      if (parents[k][u] != parents[k][v]) {
        u = parents[k][u];
        v = parents[k][v];
      }
    }
    return parents[0][u];
  }

  int GetDist(int v) { return dists[v]; }

private:
  void Init(const vector<vector<int>>& graph, int root = 0) {
    int max_log = 1;
    while (pow(2, max_log) < graph.size()) {
      ++max_log;
    }
    parents.assign(max_log, vector<int>(graph.size(), -1));
    dists.assign(graph.size(), -1);
    DFS(graph, root, -1, 0);
    for (int k = 0; k + 1 < max_log; ++k) {
      for (int v = 0; v < graph.size(); ++v) {
        if (parents[k][v] < 0) {
          parents[k + 1][v] = -1;
        } else {
          parents[k + 1][v] = parents[k][parents[k][v]];
        }
      }
    }
  }

  // 根からの距離と1つ先の頂点を求める
  void DFS(const vector<vector<int>>& graph, int now, int parent, int dist) {
    parents[0][now] = parent;
    dists[now] = dist;
    for (auto to : graph[now]) {
      if (to != parent) {
        DFS(graph, to, now, dist + 1);
      }
    }
  }

  vector<vector<int>> parents;  // parents[k][u]:= u の 2^k 先の親
  vector<int> dists;            // root からの距離
};

}  // namespace