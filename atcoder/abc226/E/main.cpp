// atcoder/abc226/E/main.cpp
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

const int N = 2 * 1e5 + 10;
vec<int> g[N];
bool vis[N];

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
      g[b].push_back(a);
    }

    vec<int> v;
    function<bool(int, int)> rec = [&] (int curr, int prev) {
      v.push_back(curr);
      int f = 0;
      vis[curr] = true;
      each (next, g[curr]) {
        if (prev == next) continue;
        unless (vis[next]) {
          f += rec(next, curr);
        } else {
          f = 1;
        }
      }
      return !!f;
    };

    fill(vis, vis + N, false);
    lli z = 1;
    for (int i = 0; i < n; ++i) {
      unless (vis[i]) {
        v.clear();
        unless (rec(i, i)) z = 0;
        int cnt = 0;
        each (j, v) cnt += g[j].size();
        // cout << cnt << ' ' << v << ' ' << v.size() << endl;
        unless (v.size() == cnt / 2) z = 0;
        (z *= 2) %= mod;
      }
    }
    cout << z % mod << endl;
  }


  return 0;
}
