// atcoder/abc157/D/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<int> g[n];

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    vector<int> h[n];
    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      h[a].push_back(b);
      h[b].push_back(a);
    }

    int cnt = 0;
    int color[n];
    fill(color, color + n, -1);
    int x[n];
    fill(x, x + n, -1);
    auto bfs = [&] (int src) {
      set<int> vis;
      vis.insert(src);
      queue<int> q;
      for (q.push(src); q.size(); q.pop()) {
        int curr = q.front();
        each (next, g[curr]) {
          if (vis.count(next)) continue;
          vis.insert(next);
          q.push(next);
        }
      }
      each (i, vis) {
        x[i] = vis.size();
        color[i] = cnt;
      }
      ++cnt;
    };
    for (int i = 0; i < n; ++i) {
      if (x[i] == -1) bfs(i);
    }

    int y[n];
    for (int i = 0; i < n; ++i) {
      y[i] = x[i];
      y[i] -= g[i].size();
      each (j, h[i]) {
        if (color[i] == color[j]) {
          --y[i];
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << y[i] - 1;
    }
    cout << endl;
  }

  return 0;
}
