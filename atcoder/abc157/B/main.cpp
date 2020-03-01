// atcoder/abc157/B/main.cpp
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

  const int N = 3;
  int g[N][N];
  while (true) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> g[i][j];
      }
    }
    int n;
    unless (cin >> n) break;
    set<int> vis;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      vis.insert(x);
    }

    bool f = false;

    const int D = 8;
    int di[D] = {-1, 0, +1, -1, +1, -1, 0, +1};
    int dj[D] = {-1, -1, -1, 0, 0, +1, +1, +1};
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int d = 0; d < D; ++d) {
          int ai = i + di[d];
          int aj = j + dj[d];
          int bi = ai + di[d];
          int bj = aj + dj[d];
          unless (0 <= ai && ai < N) continue;
          unless (0 <= bi && bi < N) continue;
          unless (0 <= aj && aj < N) continue;
          unless (0 <= bj && bj < N) continue;
          bool p = vis.count(g[i][j]) && vis.count(g[ai][aj]) && vis.count(g[bi][bj]);
          f = f || p;
        }
      }
    }

    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
