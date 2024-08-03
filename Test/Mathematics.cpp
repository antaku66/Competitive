#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = 3.141592653589793;
const ll MAX = numeric_limits<ll>::max();
constexpr int MOD = 1e9 + 7;

namespace {

// 切り捨ての割算(商が負数になる場合は数直線上で左側の値を返す)
ll Floor(ll x, ll m) {
  ll r = (x % m + m) % m;
  return (x - r) / m;
}

// 10進数のnをN進数に変換
string BaseTenToN(ll n, int N) {
  if (n == 0) return "0";
  string str = "";
  while (n) {
    str = to_string(n % N) + str;
    n /= N;
  }
  return str;
}

// N進数を10進数に変換
ll BasenToTen(string str, int N) {
  ll n = 0, m = 1;
  for (ll i = str.size() - 1; i >= 0; --i) {
    n += (str[i] - '0') * m;
    m *= N;
  }
  return n;
}

// a の b 乗を m で割った余りを返す
ll Power(ll a, ll b, ll m) {
  ll p = a, answer = 1;
  for (int i = 0; i < 60; i++) {
    ll wari = (1LL << i);
    if ((b / wari) % 2 == 1) {
      answer = (answer * p) % m;
    }
    p = (p * p) % m;
  }
  return answer;
}

// a ÷ b を m で割った余りを返す
ll Division(ll a, ll b, ll m) { return (a * Power(b, m - 2, m)) % m; }

// nCrをmで割った余りを返す
ll nCr(ll n, ll r, ll m) {
  if (n < r) return 0;
  r = min(r, n - r);
  ll a = 1, b = 1;
  for (ll i = 0; i < r; ++i) {
    a = (a * (n - i)) % m;
    b = (b * (r - i)) % m;
  }
  return Division(a, b, m);
}

// 重複組合せ
ll nHr(ll n, ll r, ll m) { return nCr(n + r - 1, n - 1, m); }

// nCrをそのまま返す(オーバーフローに注意)
ll nCr(ll n, ll r) {
  if (n < r) return 0;
  r = min(r, n - r);
  ll a = 1, b = 1;
  for (ll i = 0; i < r; ++i) {
    a = a * (n - i);
    b = b * (r - i);
  }
  return a / b;
}

// 素数判定
bool IsPrime(ll num) {
  if (num == 2) return true;
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}

// 素因数分解
vector<pair<ll, ll>> PrimeFactorize(ll N) {
  vector<pair<ll, ll>> res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll ex = 0;  // 指数

    while (N % a == 0) {
      ++ex;
      N /= a;  // 割れる限り割り続ける
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});  // 最後に残った数
  return res;
}

// 最大公約数
ll GCD(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return GCD(b, a % b);
}

// 最小公倍数
ll LCM(ll a, ll b) { return a * (b / GCD(a, b)); }

// 拡張ユークリッドの互除法
// ax + by = gcd(a, b) を満たす (x, y) が格納される
// 返り値: a と b の最大公約数
ll ExtGCD(ll a, ll b, ll &x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ExtGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

// 最長増加部分列（LIS）
template <class Type>
size_t LIS(const std::vector<Type>& v) {
  std::vector<Type> dp;
  for (const auto& elem : v) {
    auto it = std::lower_bound(dp.begin(), dp.end(), elem);
    if (it == dp.end()) {
      dp.push_back(elem);
    } else {
      *it = elem;
    }
  }
  return dp.size();
}

}  // namespace