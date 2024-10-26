#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
const vector<int> dy = { 0, 1, 0, -1 };
const vector<int> dx = { 1, 0, -1, 0 };

#define PI  double(3.141592653589793)
#define MOD int(1000000007)
#define mod int(998244353)
#define INF 1LL << 60
#define VEC2D(T, name, n, m, ini) vector<vector<T>> name(n, vector<T>(m, ini))
#define VEC3D(T, name, n, m, l, ini) vector<vector<vector<T>>> name(n, vector<vector<T>>(m, vector<T>(l, ini)))
#define REP(i, e) rep(i, 0, e)
#define rep(i, s, e) for (int i = s; i < static_cast<int>(e); ++i)
#define RREP(i, s) rrep(i, s, 0) 
#define rrep(i, s, e) for (int i = s - 1; i >= static_cast<int>(e); --i)
#define ITREP(arr) for (auto it = arr.begin(); it != arr.end(); ++it)
#define ALL(x) (x).begin(), (x).end()

template<typename... Args>
void Input(Args&... args) { (cin >> ... >> args); }
template<typename T, typename... Vecs>
void InputVecs(int n, Vecs&... vecs) { (vecs.resize(n), ...); REP(i, n) { (cin >> ... >> vecs[i]); } }
#define DIN(type, ...) type __VA_ARGS__; Input(__VA_ARGS__);
#define VECDIN(type, n, ...) vector<type> __VA_ARGS__; InputVecs<type>(n, __VA_ARGS__);
#define IOS_ACCELERATION ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() {
  IOS_ACCELERATION;

  return 0;
}
