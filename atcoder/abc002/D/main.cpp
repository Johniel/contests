// atcoder/abc002/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    bool g[n][n];
    fill(&g[0][0], &g[n - 1][n - 1] + 1, false);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a][b] = g[b][a] = true;
    }
    int mx = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      bool f = true;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          unless (bit & (1 << i)) continue;
          unless (bit & (1 << j)) continue;
          f = f && g[i][j];
        }
      }
      if (f) setmax(mx, __builtin_popcount(bit));
    }
    cout << mx << endl;
  }

  return 0;
}
