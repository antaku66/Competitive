#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

namespace {

class SegmentTree {
  // Update  : (0 ~ n-1 の内)pos番目の葉を更新
  // Query   : [a, b)開区間の最大値(最小値)を取得
  // data_   : 1 ~ (n * 2 - 1)
  // size_   : 葉の数
  // getMax_ : 最大値を取得するならTrue 最小値ならFalse
 public:
  SegmentTree(ll n, bool getMax) : getMax_(getMax) {
    while (size_ < n) size_ *= 2;
    data_.resize(2 * size_, (getMax_ ? 0 : INF));
  }

  void Update(ll pos, ll x) {
    pos = pos + size_;
    data_[pos] = x;
    while (pos >= 1) {
      pos = pos / 2;
      data_[pos] = getMax_ ? max(data_[pos * 2], data_[pos * 2 + 1])
                           : min(data_[pos * 2], data_[pos * 2 + 1]);
    }
  }

  ll Query(ll a, ll b) { return DoQuery(a, b, 1, 0, size_); }

 private:
  // k:現在見ているノードの位置  [l,r):data_[k]が表している区間
  ll DoQuery(ll a, ll b, ll k, ll l, ll r) {
    if (r <= a || b <= l) {  // 範囲外なら考えない
      return getMax_ ? 0 : INF;
    } else if (a <= l && r <= b) {  // 範囲内なので自身の値を返す
      return data_[k];
    } else {
      ll vl = DoQuery(a, b, k * 2, l, (l + r) / 2);
      ll vr = DoQuery(a, b, k * 2 + 1, (l + r) / 2, r);
      return getMax_ ? max(vl, vr) : min(vl, vr);
    }
  }

  vector<ll> data_;  // 1 ~ (size_ * 2 - 1)
  size_t size_ = 1;
  bool getMax_;
};

class SumSegmentTree {
 public:
  SumSegmentTree(ll n) {
    while (size_ < n) size_ *= 2;
    data_.resize(2 * size_, 0);
  }

  void Update(ll pos, ll x) {
    pos = pos + size_;
    data_[pos] = x;
    while (pos >= 1) {
      pos = pos / 2;
      data_[pos] = data_[pos * 2] + data_[pos * 2 + 1];
    }
  }

  ll Query(ll a, ll b) { return DoQuery(a, b, 1, 0, size_); }

 private:
  ll DoQuery(ll a, ll b, ll k, ll l, ll r) {
    if (r <= a || b <= l) {
      return 0;
    } else if (a <= l && r <= b) {
      return data_[k];
    } else {
      ll vl = DoQuery(a, b, k * 2, l, (l + r) / 2);
      ll vr = DoQuery(a, b, k * 2 + 1, (l + r) / 2, r);
      return vl + vr;
    }
  }

  vector<ll> data_;
  size_t size_ = 1;
};
}  // namespace