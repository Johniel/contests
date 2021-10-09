// atcoder/abc221/F/main.cpp
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
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];

int cost[N];
int path[N];
vec<int> bfs(const int src, const int taboo = -1)
{
  queue<int> q;
  const int inf = 1 << 29;
  fill(path, path + N, -1);
  fill(cost, cost + N, inf);
  cost[src] = 0;
  for (q.push(src); q.size(); q.pop()) {
    int curr = q.front();
    each (next, g[curr]) {
      if (next == taboo) continue;
      if (cost[next] == inf) {
        cost[next] = cost[curr] + 1;
        q.push(next);
        path[next] = curr;
      }
    }
  }
  int mx = -1;
  for (int i = 0; i < N; ++i) {
    if (cost[i] != inf) setmax(mx, cost[i]);
  }
  vec<int> v;
  for (int i = 0; i < N; ++i) {
    if (cost[i] == mx) v.push_back(i);
  }
  return v;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<int> v = bfs(0);
    const int q = v.front();
    v = bfs(q);
    vec<int> p;
    for (int i = v.front(); path[i] != -1; i = path[i]) p.push_back(i);
    p.push_back(q);
    const int D = p.size() - 1;
    if (D % 2) {
      const int z = (p.size() - 1) / 2;
      const int x = p[p.size() / 2];
      const int y = p[p.size() / 2 - 1];
      bfs(x, y);
      vec<int> a(cost, cost + N);
      bfs(y, x);
      vec<int> b(cost, cost + N);
      lli s = 0, t = 0;
      for (int i = 0; i < N; ++i) {
        s += (a[i] == z && g[i].size() == 1);
        t += (b[i] == z && g[i].size() == 1);
      }
      cout << (s * t) % mod << endl;
    } else {
      const int y = p.size() / 2;
      const int C = p[p.size() / 2];
      bfs(C);

      static int w[N];
      function<int(int, int)> rec = [&] (int curr, int prev) {
        w[curr] = (g[curr].size() == 1 && cost[curr] == y);
        each (next, g[curr]) {
          unless (next == prev) w[curr] += rec(next, curr);
        }
        return w[curr];
      };
      rec(C, C);
      lli z = 1;
      int x = 0;
      lli one = 0;
      each (i, g[C]) {
        x += !!w[i];
        (z *= w[i] + 1) %= mod;
        one += w[i];
      }
      cout << (z - 1 - one + mod) % mod << endl;
    }
  }

  return 0;
}
