// atcoder/abc199/D/main.cpp
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

const int N = 20 + 2;
vec<int> g[N];
int color[N];

bool vis[N];
vec<int> h[N];
vec<int> v;
lli tree(int curr)
{
  v.push_back(curr);
  vis[curr] = true;
  lli x = 1;
  each (next, g[curr]) {
    if (vis[next]) continue;
    h[curr].push_back(next);
    tree(next);
  }
  return x;
}

map<int, int> r;
void rec(int curr)
{
  each (next, h[curr]) {
    color[next] = (color[curr] + 1 + r[next]) % 3;
    rec(next);
  }
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
    fill(h, h + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    fill(color, color + N, -1);
    fill(vis, vis + N, false);

    vec<vec<int>> u;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        v.clear();
        tree(i);
        u.push_back(v);
      }
    }

    lli x = 1;
    each (w, u) {
      lli y = 0;
      for (int bit = 0; bit < (1 << w.size()); ++bit) {
        for (int i = 0; i < w.size(); ++i) {
          r[w[i]] = !!(bit & (1 << i));
        }
        unless (r[w[0]] == 0) continue;
        color[w[0]] = 0;
        rec(w[0]);
        bool ok = true;
        each (a, w) {
          each (b, g[a]) {
            ok = ok && (color[a] != color[b]);
          }
        }
        if (ok) y += 3;
      }
      // cout << w << ' ' << y / 3 << endl;
      x *= y;
    }

    cout << x << endl;
  }

  return 0;
}
