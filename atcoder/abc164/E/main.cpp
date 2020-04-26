// atcoder/abc164/E/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, s;
  while (cin >> n >> m >> s) {
    const int N = 50 + 5;
    lli c[N];
    lli d[N];

    vec<pair<lli, pair<int, int>>> g[N];
    for (int i = 0; i < m; ++i) {
      int u, v, a, b;
      cin >> u >> v >> a >> b;
      --u;
      --v;
      g[u].push_back(make_pair(v, make_pair(a, b)));
      g[v].push_back(make_pair(u, make_pair(a, b)));
    }

    for (int i = 0; i < n; ++i) {
      cin >> c[i] >> d[i];
    }

    const int M = N * 50;
    static lli cost[N][M];
    const lli inf = 1LL << 60;
    fill(&cost[0][0], &cost[N - 1][M - 1] + 1, inf);
    setmin(s, M - 1);

    priority_queue<pair<lli, pair<int, lli>>> q;
    cost[0][s] = 0;
    q.push(make_pair(0, make_pair(0, s)));
    while (q.size()) {
      auto p = q.top();
      q.pop();
      lli w = -p.first;
      int curr = p.second.first;
      lli silver = p.second.second;
      if (cost[curr][silver] != w) continue;
      each (e, g[curr]) {
        for (int ch = 0; ch < 100; ++ch) {
          lli x = min<lli>(M - 1, silver + ch  * c[curr] - e.second.first);
          lli y = w + ch * d[curr] + e.second.second;
          if (0 <= x && cost[e.first][x] > y) {
            cost[e.first][x] = y;
            q.push(make_pair(-y, make_pair(e.first, x)));
          }
        }
      }
    }

    for (int i = 1; i < n; ++i) {
      lli mn = inf;
      for (int j = 0; j < M; ++j) {
        setmin(mn, cost[i][j]);
      }
      cout << mn << endl;
    }
  }

  return 0;
}
