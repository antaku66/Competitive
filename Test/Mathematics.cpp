#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = 3.141592653589793;
const ll MAX = numeric_limits<ll>::max();
constexpr int MOD = 1e9 + 7;

namespace {

// �؂�̂Ă̊��Z(���������ɂȂ�ꍇ�͐�������ō����̒l��Ԃ�)
ll Floor(ll x, ll m) {
  ll r = (x % m + m) % m;
  return (x - r) / m;
}

// 10�i����n��N�i���ɕϊ�
string BaseTenToN(ll n, int N) {
  if (n == 0) return "0";
  string str = "";
  while (n) {
    str = to_string(n % N) + str;
    n /= N;
  }
  return str;
}

// N�i����10�i���ɕϊ�
ll BasenToTen(string str, int N) {
  ll n = 0, m = 1;
  for (ll i = str.size() - 1; i >= 0; --i) {
    n += (str[i] - '0') * m;
    m *= N;
  }
  return n;
}

// a �� b ��� m �Ŋ������]���Ԃ�
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

// a �� b �� m �Ŋ������]���Ԃ�
ll Division(ll a, ll b, ll m) { return (a * Power(b, m - 2, m)) % m; }

// nCr��m�Ŋ������]���Ԃ�
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

// nCr�����̂܂ܕԂ�(�I�[�o�[�t���[�ɒ���)
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

// �f������
bool IsPrime(ll num) {
  if (num == 2) return true;
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}

// �f��������
vector<pair<ll, ll>> PrimeFactorize(ll N) {
  vector<pair<ll, ll>> res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll ex = 0;  // �w��

    while (N % a == 0) {
      ++ex;
      N /= a;  // �������芄�葱����
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});  // �Ō�Ɏc������
  return res;
}

// �ő����
ll GCD(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return GCD(b, a % b);
}

// �ŏ����{��
ll LCM(ll a, ll b) { return a * (b / GCD(a, b)); }

// �g�����[�N���b�h�̌ݏ��@
// ax + by = gcd(a, b) �𖞂��� (x, y) ���i�[�����
// �Ԃ�l: a �� b �̍ő����
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

// �Œ�����������iLIS�j
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