// atcoder/arc108/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

const int N = 2 * 1e5 + 5;

vec<pair<int, int>> g[N];
vec<pair<int, int>> es;

bool vis[N];
int color[N];
int n, m;
void rec(int curr)
{
  vis[curr] = true;
  each (e, g[curr]) {
    if (vis[e.first]) continue;
    if (color[curr] == e.second) {
      color[e.first] = (color[curr] + 1) % n;
    } else {
      color[e.first] = e.second;
    }
    rec(e.first);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n >> m) {
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      --c;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }
    fill(vis, vis + N, false);
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      color[i] = 0;
      rec(i);
    }
    for (int i = 0; i < n; ++i) {
      cout << color[i] + 1 << endl;
    }
  }

  return 0;
}
