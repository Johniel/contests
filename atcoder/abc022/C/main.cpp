// atcoder/abc022/C/main.cpp
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

template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "("; each (i, s) os << i << ","; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "("; each (i, m) os << i << ","; os << ")"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename P, typename Q> inline pair<Q, P> swap(pair<P, Q> p) { return make_pair(p.second, p.first); }

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    const int N = 300 + 3;
    static lli g[N][N];
    static lli h[N][N];
    const lli inf = 1LL << 60;
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);
    fill(&h[0][0], &h[N - 1][N - 1] + 1, inf);

    for (int i = 0; i < m; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a][b] = g[b][a] = c;
      if (a && b) h[a][b] = h[b][a] = c;
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          setmin(h[i][j], h[i][k] + h[k][j]);
        }
      }
    }

    lli mn = inf;
    for (int i = 1; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        if (i == j) continue;
        setmin(mn, g[0][i] + g[j][0] + h[i][j]);
      }
    }
    cout << (mn < inf ? mn : -1) << endl;
  }

  return 0;
}
