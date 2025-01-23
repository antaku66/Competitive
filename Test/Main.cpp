#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const vector<ll> dy = { 0, 1, 0, -1 };
const vector<ll> dx = { 1, 0, -1, 0 };
#define PI 3.141592653589793
#define MOD 1000000007LL
#define mod 998244353LL
#define INF 1LL << 60
#define VEC2D(T, name, n, m, ini) vector<vector<T>> name(n, vector<T>(m, ini))
#define VEC3D(T, name, n, m, l, ini) vector<vector<vector<T>>> name(n, vector<vector<T>>(m, vector<T>(l, ini)))
#define VEC4D(T, name, n, m, l, k, ini) vector<vector<vector<vector<T>>>> name(n, vector<vector<vector<T>>>(m, vector<vector<T>>(l, vector<T>(k, ini))))
#define REP(i, e) rep(i, 0, e)
#define rep(i, s, e) for (ll i = s; i < static_cast<ll>(e); ++i)
#define RREP(i, s) rrep(i, s, 0) 
#define rrep(i, s, e) for (ll i = s - 1; i >= static_cast<ll>(e); --i)
#define ITREP(arr) for (auto it = arr.begin(); it != arr.end(); ++it)
#define ALL(x) (x).begin(), (x).end()
#define DIN(type, ...) type __VA_ARGS__; Input(__VA_ARGS__);
#define VDIN(type, n, ...) vector<type> __VA_ARGS__; InputVecs<type>(n, __VA_ARGS__);
#define GDIN(name, n, m) vector<vector<ll>> name(n); REP(_, m) { DIN(ll, u, v); g[--u].push_back(--v); g[v].push_back(u); }
#define DGDIN(name, n, m) vector<vector<ll>> name(n); REP(_, m) { DIN(ll, u, v); g[--u].push_back(--v); }
template<typename... Args>
void Input(Args&... args) { (cin >> ... >> args); }
template<typename T, typename... Vecs>
void InputVecs(ll n, Vecs&... vecs) { (vecs.resize(n), ...); REP(i, n) { (cin >> ... >> vecs[i]); } }
struct IOSInitializer {
IOSInitializer() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
} ios_initializer;
bool IsInGrid(ll y, ll x, ll h, ll w) { return 0 <= y && y < h && 0 <= x && x < w; }


int main() {

  return 0;
}
