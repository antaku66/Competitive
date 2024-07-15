#include <bits/stdc++.h>
using namespace std;

namespace {

struct UnionFind {
  UnionFind(int n) : parants_(n, -1), sizes_(n, 1) {}

  int GetRoot(int x) {
    if (parants_[x] == -1) {
      return x;
    } else {
      return parants_[x] = GetRoot(parants_[x]);  // �o�H���k
    }
  }

  bool IsSame(int x, int y) { return GetRoot(x) == GetRoot(y); }

  bool Unite(int x, int y) {
    // ���܂ňړ�����
    x = GetRoot(x), y = GetRoot(y);
    if (x == y) return false;

    // union by rank(y���̃T�C�Y���������Ȃ�悤�ɂ���)
    if (sizes_[x] < sizes_[y]) swap(x, y);

    // y��x�̎q�Ƃ���
    parants_[y] = x;
    sizes_[x] += sizes_[y];
    return true;
  }

  int GetSize(int x) { return sizes_[GetRoot(x)]; }

 private:
  vector<int> parants_, sizes_;
};

}  // namespace