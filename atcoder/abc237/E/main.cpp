// atcoder/abc237/E/main.cpp
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

const int N = 2 * 1e5 + 3;
lli h[N];
vec<int> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    static lli cost[N];
    const lli inf = 1LL << 60;
    fill(cost, cost + N, inf);
    cost[0] = 0;
    priority_queue<pair<lli, int>> q;
    for (q.push({0, 0}); q.size(); ) {
      auto p = q.top();
      lli c = abs(p.first);
      int curr = p.second;
      q.pop();
      if (cost[curr] != c) continue;
      each (next, g[curr]) {
        lli d = cost[curr];
        if (h[curr] > h[next]) {
          // d += h[curr] - h[next];
        } else {
          d += (h[next] - h[curr]);
        }
        if (cost[next] > d) {
          cost[next] = d;
          q.push({-d, next});
        }
      }
    }
    lli mx = 0;
    for (int i = 1; i < n; ++i) {
      setmax(mx, h[0] - h[i] -cost[i]);
    }
    cout << mx << endl;
  }

  return 0;
}
