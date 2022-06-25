// atcoder/abc257/F/main.cpp
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
// constexpr lli mod = 998244353;

const int N = 3 * 1e5 + 3;
vec<int> g[N];
bool f[N];
const int inf = 1 << 29;
void bfs(const int src, vec<lli>& cost)
{
  static bool vis[N];
  fill(vis, vis + N, false);
  fill(cost.begin(), cost.end(), inf);
  vis[src] = true;
  cost[src] = 0;
  queue<int> q;
  for (q.push(src); q.size(); q.pop()) {
    int curr = q.front();
    each (next, g[curr]) {
      if (vis[next]) continue;
      vis[next] = true;
      cost[next] = cost[curr] + 1;
      q.push(next);
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

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    fill(f, f + N, false);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      if (a == -1) {
        f[b] = true;
      } else {
        g[a].push_back(b);
        g[b].push_back(a);
      }
    }

    int mn;

    vec<lli> a(n);
    bfs(0, a);
    int x = -1;
    mn = inf;
    for (int i = 0; i < n; ++i) {
      if (f[i] && mn > a[i]) {
        mn = a[i];
        x = i;
      }
    }

    vec<lli> b(n);
    bfs(n - 1, b);
    int y = -1;
    mn = inf;
    for (int i = 0; i < n; ++i) {
      if (f[i] && mn > b[i]) {
        mn = b[i];
        y = i;
      }
    }

    // cout << make_pair(x, mn) << endl;
    // cout << a << endl;
    // cout << b << endl;
    const lli def = a[n - 1];
    for (int i = 0; i < n; ++i) {
      lli p = inf;
      lli q = inf;
      lli r = inf;
      if (x != -1) {
        p = a[x] + b[i] + 1;
      }
      if (y != -1) {
        q = a[i] + b[y] + 1;
      }
      if (x != -1 && y != -1) {
        r = a[x] + b[y] + 2;
      }
      lli z = min({def, p, q, r});
      cout << (inf <= z ? -1 : z) << ' ';
    }
    cout << endl;
  }

  return 0;
}
