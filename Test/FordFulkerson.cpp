#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = s; i < (n); ++i)

namespace {

struct Edge {
  Edge(int a, int b, int c) : to_(a), cap_(b), rev_(c) {}
  int to_, cap_, rev_;
};

class FordFulkerson {
 public:
  // 頂点数 n（ 0 ~ n-1 まで）の残余グラフを準備
  FordFulkerson(int n) : size_(n) {
    graph_.resize(n);
    used_ = vector<bool>(n, false);
  }

  // 頂点 a から b に向かう、上限 c リットル／秒の辺を追加
  void AddEdge(int a, int b, int c) {
    int current_a = graph_[a].size();  // 現時点での graph_[a] の要素数
    int current_b = graph_[b].size();  // 現時点での graph_[b] の要素数
    graph_[a].push_back(Edge{b, c, current_b});
    graph_[b].push_back(Edge{a, 0, current_a});
  }

  // 頂点 s から頂点 t までの最大フローの総流量を返す
  int Calc(int s, int t) {
    int totalFlow = 0;
    while (true) {
      for (int i = 0; i < size_; ++i) used_[i] = false;
      int f = DFS(s, t, 1e9);

      // フローを流せなくなったら操作終了
      if (f == 0) break;
      totalFlow += f;
    }
    return totalFlow;
  }

 private:
  // 深さ優先探索（F はスタートから pos に到達する過程での
  // " 残余グラフの辺の容量 " の最小値）
  // 返り値は流したフローの量（流せない場合 0 を返す）
  int DFS(int pos, int goal, int F) {
    // ゴールに到着：フローを流せる！
    if (pos == goal) return F;
    used_[pos] = true;

    for (int i = 0; i < graph_[pos].size(); i++) {
      // 容量 0 の辺は使えない
      if (graph_[pos][i].cap_ == 0) continue;

      // 既に訪問した頂点に行っても意味がない
      if (used_[graph_[pos][i].to_]) continue;

      // 目的地までのパスを探す
      int flow = DFS(graph_[pos][i].to_, goal, min(F, graph_[pos][i].cap_));

      // フローを流せる場合、残余グラフの容量を flow だけ増減させる
      if (flow >= 1) {
        graph_[pos][i].cap_ -= flow;
        graph_[graph_[pos][i].to_][graph_[pos][i].rev_].cap_ += flow;
        return flow;
      }
    }

    // すべての辺を探索しても見つからなかった
    return 0;
  }

  size_t size_;
  vector<vector<Edge>> graph_;
  vector<bool> used_;
};

}  // namespace