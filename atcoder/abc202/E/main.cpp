// atcoder/abc202/E/main.cpp
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

const int N = 2 * 1e5 + 5;
vec<int> g[N];
vec<pair<int, int>> ord;
void rec(int curr, int depth)
{
  ord.push_back(make_pair(curr, depth));
  each (next, g[curr]) {
    rec(next, depth + 1);
  }
  ord.push_back(make_pair(curr, depth));
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    ord.clear();
    fill(g, g + N, vec<int>());
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
    }
    rec(0, 0);
    map<int, int> in, out;
    set<int> vis;
    int cnt = 0;
    static vec<int> v[N];
    fill(v, v + N, vec<int>());
    each (i, ord) {
      if (vis.count(i.first) == 0) {
        in[i.first] = cnt;
        vis.insert(i.first);
        v[i.second].push_back(cnt);
      } else {
        out[i.first] = cnt;
      }
      ++cnt;
    }
    for (int i = 0; i < N; ++i) {
      sort(v[i].begin(), v[i].end());
    }

    int q;
    cin >> q;
    while (q--) {
      int u, d;
      cin >> u >> d;
      --u;
      const int mn = in[u];
      const int mx = out[u];
      auto a = lower_bound(v[d].begin(), v[d].end(), mn);
      auto b = lower_bound(v[d].begin(), v[d].end(), mx);
      cout << b - a << endl;
    }
  }

  return 0;
}
