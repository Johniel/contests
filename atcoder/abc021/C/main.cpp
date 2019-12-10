// atcoder/abc021/C/main.cpp
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

const int N = 100 + 5;
int g[N][N];
int h[N][N];
const int inf = 1 << 29;
int a, b;

lli memo[N];
const lli mod = 1e9 + 7;
lli rec(int curr, int prev)
{
  lli& ret = memo[curr];
  if (curr == b) return 1;
  if (ret != -1) return ret;

  lli sum = 0;
  for (int next = 0; next < N; ++next) {
    if (g[curr][next] == inf) continue;
    if (g[a][next] - g[a][curr] == h[curr][next]) {
      (sum += rec(next, curr)) %= mod;
    }
  }

  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> a >> b) {
    fill(memo, memo + N, -1);
    fill(&g[0][0], &g[N - 1][N - 1] + 1, inf);
    fill(&h[0][0], &h[N - 1][N - 1] + 1, inf);
    --a;
    --b;
    cin >> m;
    g[a][a] = 0;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x][y] = g[y][x] = 1;
      h[x][y] = h[y][x] = 1;
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    // for (int i = 0; i < N; ++i) {
    //   for (int j = i; j < N; ++j) {
    //     if (g[i][j] == inf) continue;
    //     if (h[i][j] == inf) continue;
    //     cout << make_pair(i+1, j+1) << ": " << g[a][i] << ' ' << g[a][j] << ' ' << h[i][j] << ", " <<  (g[a][j] - g[a][i] == h[i][j]) << endl;
    //   }
    // }

    cout << rec(a, -1) << endl;
  }

  return 0;
}
