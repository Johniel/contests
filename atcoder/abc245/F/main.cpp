// atcoder/abc245/F/main.cpp
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
namespace SCC {
  vec<int> h[N];
  bool vis[N];
  int cnt;

  void rec(vector<int> g[N], int ord[N], int curr)
  {
    vis[curr] = true;
    for (auto& next: g[curr]) {
      if (!vis[next]) rec(g, ord, next);
    }
    ord[--cnt] = curr;
    return ;
  }

  int ord[N], scc[N];

  vector<vector<int>> run(const int size)
  {
    fill(ord, ord + size, -1);
    fill(scc, scc + size, -1);
    fill(h, h + size, vector<int>());
    for (int i = 0; i < size; ++i) {
      for (auto& j: g[i]) h[j].push_back(i);
    }
    cnt = size;
    fill(vis, vis + size, false);
    for (int i = 0; i < size; ++i) {
      if (!vis[i]) rec(g, ord, i);
    }
    cnt = size;
    fill(vis, vis + size, false);
    vector<vector<int>> v;
    int prev = size - 1;
    for (int _i = 0; _i < size; ++_i) {
      const int i = ord[_i];
      if (!vis[i]) {
        rec(h, scc, i);
        vector<int> u;
        int j;
        for (j = prev; 0 <= j && scc[j] != -1; --j) {
          u.push_back(scc[j]);
        }
        prev = j;
        v.push_back(u);
      }
    }
    return v;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
    }
    vec<vec<int>> scc = SCC::run(n);
    static bool vis[N];
    fill(vis, vis + N, false);
    static bool z[N];
    fill(z, z + N, false);
    each (i, scc) {
      if (1 < i.size()) {
        each (j, i) z[j] = true;
      }
    }
    function<void(int)> rec = [&] (int curr) {
      vis[curr] = true;
      each (next, g[curr]) {
        if (!vis[next]) rec(next);
        z[curr] = (z[curr] || z[next]);
      }
      return ;
    };
    for (int i = 0; i < n; ++i) {
      unless (vis[i]) rec(i);
    }
    cout << count(z, z + N, true) << endl;
  }

  return 0;
}
