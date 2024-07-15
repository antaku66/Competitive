#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

namespace {

class LazySegmentTree {
 public:
  LazySegmentTree(int n, bool getMax) : getMax_(getMax) {
    while (size_ < n) size_ *= 2;
    node_.resize(2 * size_ - 1, (getMax_ ? -INF : INF));
    lazy_.resize(2 * size_ - 1, (getMax_ ? -INF : INF));
    lazyFlag_.resize(2 * size_ - 1, false);
  }

  void Update(int a, int b, ll x) { return UpdateImpl(a, b, x, 0, 0, size_); }
  ll Query(int a, int b) { return QueryImpl(a, b, 0, 0, size_); }

 private:
  void EvalLazy(int k, int l, int r) {
    if (lazyFlag_[k]) {
      node_[k] = lazy_[k];
      if (r - l > 1) {
        lazy_[k * 2 + 1] = lazy_[k * 2 + 2] = lazy_[k];
        lazyFlag_[k * 2 + 1] = lazyFlag_[k * 2 + 2] = true;
      }
      lazyFlag_[k] = false;
    }
  }

  void UpdateImpl(int a, int b, ll x, int k, int l, int r) {
    EvalLazy(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy_[k] = x;
      lazyFlag_[k] = true;
      EvalLazy(k, l, r);
    } else {
      UpdateImpl(a, b, x, 2 * k + 1, l, (l + r) / 2);
      UpdateImpl(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node_[k] = getMax_ ? max(node_[2 * k + 1], node_[2 * k + 2])
                         : min(node_[2 * k + 1], node_[2 * k + 2]);
    }
  }

  ll QueryImpl(int a, int b, int k, int l, int r) {
    EvalLazy(k, l, r);
    if (b <= l || r <= a) return (getMax_ ? -INF : INF);
    if (a <= l && r <= b) return node_[k];
    ll vl = QueryImpl(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = QueryImpl(a, b, 2 * k + 2, (l + r) / 2, r);
    return getMax_ ? max(vl, vr) : min(vl, vr);
  }

  vector<ll> node_, lazy_;
  vector<bool> lazyFlag_;
  int size_ = 1;
  bool getMax_;
};


class LazySumSegmentTree {
 public:
  LazySumSegmentTree(int n) {
    while (size_ < n) size_ *= 2;
    node_.resize(2 * size_ - 1, 0);
    lazy_.resize(2 * size_ - 1, 0);
  }
  void Add(int a, int b, ll v) { AddImpl(a, b, v, 0, 0, size_); }
  ll Query(int a, int b) { return QueryImpl(a, b, 0, 0, size_); }

 private:
  void EvalLazy(int k, int l, int r) {
    // �x���z�񂪋�łȂ��ꍇ�A���m�[�h�y�юq�m�[�h�ւ̒l�̓`�d���N����
    if (lazy_[k] != 0) {
      node_[k] += lazy_[k];

      // �ŉ��i���ǂ����̃`�F�b�N
      // �q�͐e�� 1/2 �͈̔͂ł��邽�ߓ`�d������Ƃ��͔���
      if (r - l > 1) {
        lazy_[2 * k + 1] += lazy_[k] / 2;
        lazy_[2 * k + 2] += lazy_[k] / 2;
      }
      lazy_[k] = 0;  // �`�d���I������̂Ŏ��m�[�h�̒x���z�����ɂ���
    }
  }

  void AddImpl(int a, int b, ll x, int k, int l, int r) {
    EvalLazy(k, l, r);  // k �Ԗڂ̃m�[�h�ɑ΂��Ēx���]�����s��
    if (b <= l || r <= a) return;  // �͈͊O�Ȃ牽�����Ȃ�

    // ���S�ɔ핢���Ă���Ȃ�΁A�x���z��ɒl����ꂽ��ɕ]��
    if (a <= l && r <= b) {
      lazy_[k] += (r - l) * x;
      EvalLazy(k, l, r);
    }
    // �����łȂ���Ύq�̒l���ċA�I�Ɍv�Z���Čv�Z�ς݂̒l��Ⴄ
    else {
      AddImpl(a, b, x, 2 * k + 1, l, (l + r) / 2);
      AddImpl(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node_[k] = node_[2 * k + 1] + node_[2 * k + 2];
    }
  }

  ll QueryImpl(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) return 0;
    EvalLazy(k, l, r);  // �֐����Ăяo���ꂽ��]��
    if (a <= l && r <= b) return node_[k];
    ll vl = QueryImpl(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = QueryImpl(a, b, 2 * k + 2, (l + r) / 2, r);
    return vl + vr;
  }

  vector<ll> node_, lazy_;
  int size_ = 1;
};

}  // namespace