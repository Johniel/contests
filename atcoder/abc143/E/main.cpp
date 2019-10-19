// atcoder/abc143/E/main.cpp
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

const int N = 300 + 5;
lli g[N][N];
lli cost[N][N];
const lli inf = 1LL << 60;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, L;
  while (cin >> n >> m >> L) {
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);
    fill(&cost[0][0], &cost[N - 1][N - 1] + 1, inf);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a][b] = g[b][a] = c;
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    for (int src = 0; src < n; ++src) {
      queue<int> q;
      cost[src][src] = 0;
      for (q.push(src); q.size(); q.pop()) {
        int curr = q.front();
        for (int next = 0; next < n; ++next) {
          if (g[curr][next] <= L && (cost[src][next] == inf)) {
            cost[src][next] = cost[src][curr] + 1;
            q.push(next);
          }
        }
      }
    }

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      cout << (cost[a][b] < inf ? cost[a][b] - 1 : -1) << endl;
    }
  }

  return 0;
}
