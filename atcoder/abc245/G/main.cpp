// atcoder/abc245/G/main.cpp
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
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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

  int n, m, k, l;
  while (cin >> n >> m >> k >> l) {
    vec<int> a(n);
    cin >> a;
    each (i, a) --i;
    vec<int> b(l);
    cin >> b;
    each (i, b) --i;
    const int N = 2 * 1e5 + 3;
    static vec<pair<int, int>> g[N];
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }
    static lli cost[N][2];
    static lli country[N][2];
    const lli inf = 1LL << 50;
    fill(&cost[0][0], &cost[N - 1][2 - 1] + 1, inf);
    fill(&country[0][0], &country[N - 1][2 - 1] + 1, -1);
    using E = array<lli, 4>;
    priority_queue<E> q;
    each (i, b) {
      q.push({0, i, a[i], 0});
      q.push({0, i, a[i], 1});
    }
    const int COST = 0;
    const int INDEX = 1;
    const int COUNTRY = 2;
    const int ORD = 3;
    static int vis[N];
    fill(vis, vis + N, 0);
    while (!q.empty()) {
      E curr = q.top();
      q.pop();
      curr[COST] *= -1;

      if (2 <= vis[curr[INDEX]]) {
        continue;
      } else if (curr[ORD] == 0 && cost[curr[INDEX]][curr[ORD]] > curr[COST]) {
      } else if (curr[ORD] == 1 && cost[curr[INDEX]][curr[ORD]] > curr[COST] && country[curr[INDEX]][0] != curr[COUNTRY] && country[curr[INDEX]][0] != -1) {
      } else {
        continue;
      }
      cost[curr[INDEX]][curr[ORD]] = curr[COST];
      country[curr[INDEX]][curr[ORD]] = curr[COUNTRY];
      ++vis[curr[INDEX]];

      each (e, g[curr[INDEX]]) {
        if (2 <= vis[e.first]) continue;
        const lli c = curr[COST] + e.second;
        if (cost[e.first][0] > c) q.push(E{-c, e.first, curr[COUNTRY], 0});
        if (cost[e.first][1] > c) q.push(E{-c, e.first, curr[COUNTRY], 1});
      }
    }

    for (int i = 0; i < n; ++i) {
      lli c = (country[i][0] != a[i] ? cost[i][0] : cost[i][1]);
      if (c == inf) c = -1;
      cout << c << ' ';
    }
    cout << endl;
  }

  return 0;
}
