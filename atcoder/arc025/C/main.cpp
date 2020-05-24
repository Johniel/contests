// atcoder/arc025/C/main.cpp
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

const int N = 3000;
int cost[N];
vec<pair<int, int>> g[N];
void sssf(int src)
{
  fill(cost, cost + N, 1 << 29);
  priority_queue<vec<int>> q;
  cost[src] = 0;
  q.push({0, src});
  while (q.size()) {
    vec<int> v = q.top();
    q.pop();
    int curr = v[1];
    int c = -v[0];
    if (cost[curr] != c) continue;
    each (e, g[curr]) {
      if (cost[e.first] > cost[curr] + e.second) {
        cost[e.first] = cost[curr] + e.second;
        q.push({-cost[e.first], e.first});
      }
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, r, t;
  while (cin >> n >> m >> r >> t) {
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }

    lli x = 0;
    for (int i = 0; i < n; ++i) {
      sssf(i);
      vec<double> v(cost, cost + n);
      sort(v.begin(), v.end());
      for (int j = 1; j < n; ++j) {
        int y = upper_bound(v.begin() + 1, v.end(), (v[j] / r) * t - 1e-7) - v.begin() - 1;
        if (j <= y) --y;
        x += y;
      }
    }
    cout << x << endl;
  }

  return 0;
}
