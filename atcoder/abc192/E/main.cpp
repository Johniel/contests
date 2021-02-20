// atcoder/abc192/E/main.cpp
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


  int n, m, x, y;
  while (cin >> n >> m >> x >> y) {
    --x;
    --y;
    using E = struct {
      int dst;
      lli t, k;
    };
    vec<E> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b, t, k;
      cin >> a >> b >> t >> k;
      --a;
      --b;
      g[a].push_back((E){b, t, k});
      g[b].push_back((E){a, t, k});
    }

    const int N = 2 * 1e5 + 5;
    static lli cost[N];
    const lli inf = 1LL << 60;
    fill(cost, cost + N, inf);
    cost[x] = 0;
    priority_queue<pair<lli, int>> q;
    q.push({0, x});
    while (q.size()) {
      auto p = q.top();
      q.pop();
      int curr = p.second;
      lli c = abs(p.first);
      if (cost[curr] != c) continue;
      each (e, g[curr]) {
        int next = e.dst;
        lli t = e.t;
        lli k = e.k;
        lli nc = c;
        if (nc % k) nc = ((nc - 1) / k + 1) * k;
        nc += t;
        if (nc < cost[next]) {
          cost[next] = nc;
          q.push({-nc, next});
        }
      }
    }
    cout << (cost[y] == inf ? -1 : cost[y]) << endl;
  }

  return 0;
}
