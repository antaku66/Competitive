#include <bits/stdc++.h>
using namespace std;

namespace {

struct UnionFind {
  UnionFind(int n) : parants_(n, -1), sizes_(n, 1) {}

  int GetRoot(int x) {
    if (parants_[x] == -1) {
      return x;
    } else {
      return parants_[x] = GetRoot(parants_[x]);  // 経路圧縮
    }
  }

  bool IsSame(int x, int y) { return GetRoot(x) == GetRoot(y); }

  bool Unite(int x, int y) {
    // 根まで移動する
    x = GetRoot(x), y = GetRoot(y);
    if (x == y) return false;

    // union by rank(y側のサイズが小さくなるようにする)
    if (sizes_[x] < sizes_[y]) swap(x, y);

    // yをxの子とする
    parants_[y] = x;
    sizes_[x] += sizes_[y];
    return true;
  }

  int GetSize(int x) { return sizes_[GetRoot(x)]; }

 private:
  vector<int> parants_, sizes_;
};

}  // namespace