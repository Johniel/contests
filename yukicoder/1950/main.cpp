// yukicoder/1950/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];
bool vis[N];
vec<lli> x, a;
lli mx[N];
int idx;
void rec(int curr)
{
  vis[curr] = true;
  mx[curr] = mx[idx];
  each (next, g[curr]) unless (vis[next]) rec(next);
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    a.resize(n);
    x.resize(n);
    cin >> x >> a;
    map<lli, int> m;
    for (int i = 0; i < n; ++i) {
      m[x[i]] = i;
    }
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n; ++i) {
      lli s = x[i] + a[i];
      lli t = x[i] - a[i];
      if (m.count(s)) g[m[s]].push_back(i);
      if (m.count(t)) g[m[t]].push_back(i);
    }
    vec<pair<lli, int>> v;
    for (int i = 0; i < n; ++i) {
      v.push_back({x[i] + a[i], i});
    }
    for (int i = 0; i < n; ++i) {
      mx[i] = x[i] + a[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    fill(vis, vis + N, false);
    for (int i = 0; i < v.size(); ++i) {
      idx = v[i].second;
      unless (vis[v[i].second]) rec(v[i].second);
    }
    for (int i = 0; i < n; ++i) {
      cout << mx[i] - x[i] << endl;
    }
  }

  return 0;
}
