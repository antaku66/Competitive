#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1000000007LL

namespace {

class mint {
  ll value_;

public:
  mint(ll value_ = 0) : value_((value_ % mod + mod) % mod) {}

  mint pow(ll t) const {
    if (!t) {
      return 1;
    }

    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) {
      a *= *this;
    }
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }

  mint operator-() const { return mint(-value_); }

  mint& operator+=(const mint& a) {
    if ((value_ += a.value_) >= mod)
      value_ -= mod;
    return *this;
  }

  mint& operator-=(const mint& a) {
    if ((value_ += mod - a.value_) >= mod)
      value_ -= mod;
    return *this;
  }

  mint& operator*=(const mint& a) {
    (value_ *= a.value_) %= mod;
    return *this;
  }

  mint operator+(const mint& a) const {
    mint res(*this);
    return res += a;
  }

  mint operator-(const mint& a) const {
    mint res(*this);
    return res -= a;
  }

  mint operator*(const mint& a) const {
    mint res(*this);
    return res *= a;
  }

  mint& operator/=(const mint& a) { return (*this) *= a.inv(); }

  mint operator/(const mint& a) const {
    mint res(*this);
    return res /= a;
  }

  friend ostream& operator<<(ostream& os, const mint& m) {
    os << m.value_;
    return os;
  }
};

}  // namespace