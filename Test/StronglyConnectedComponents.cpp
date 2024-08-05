#include <bits/stdc++.h>

using namespace std;
#define REP(i, e) rep(i, 0, e)
#define rep(i, s, e) for (int i = s; i < (e); ++i)
#define all(x) (x).begin(), (x).end()

class StronglyConnectedComponents {
public:
  StronglyConnectedComponents(const vector<vector<int>>& graph)
    : graph_(graph) {
    graphRev_.resize(graph_.size());
    components_.assign(graph_.size(), -1);
    used_.resize(graph_.size());
    REP(now, graph_.size()) {
      for (auto to : graph_[now]) graphRev_[to].push_back(now);
    }

    REP(v, graph_.size()) if (!used_[v]) DFS(v);
    reverse(all(orders_));
    for (auto v : orders_) {
      if (components_[v] == -1) {
        RDFS(v);
        ++componentsNum_;
      }
    }
  }

  // 強連結成分をvector<vector<int>>に纏めて取得
  vector<vector<int>> GetResult() {
    vector<vector<int>> scc(componentsNum_);
    REP(v, components_.size()) scc[components_[v]].push_back(v);
    return scc;
  }

  // 強連結成分を1つのノードに潰したグラフを再構築する
  vector<vector<int>> Rebuild() {
    vector<vector<int>> rebuildedGraph(componentsNum_);
    set<pair<int, int>> connected;
    REP(now, componentsNum_) {
      for (auto to : graph_[now]) {
        if (components_[now] != components_[to] &&
            !connected.count({now, to})) {
          connected.insert({now, to});
          rebuildedGraph[components_[now]].push_back(components_[to]);
        }
      }
    }
    return rebuildedGraph;
  }

private:
  void DFS(int now) {
    used_[now] = true;
    for (auto to : graph_[now]) {
      if (!used_[to])
        DFS(to);
    }
    orders_.push_back(now);
  }

  void RDFS(int now) {
    components_[now] = componentsNum_;
    for (auto to : graphRev_[now]) {
      if (components_[to] == -1)
        RDFS(to);
    }
  }

  int componentsNum_ = 0;
  vector<vector<int>> graph_, graphRev_;
  vector<int> orders_, components_;
  vector<bool> used_;
};