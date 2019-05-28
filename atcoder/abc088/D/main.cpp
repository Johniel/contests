// atcoder/abc088/D/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int inf = 1 << 29;
    int cost[h][w];
    fill(&cost[0][0], &cost[h - 1][w - 1] + 1, inf);
    cost[0][0] = 1;

    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};

    queue<pair<int, int>> q;
    for (q.push({0, 0}); q.size(); q.pop()) {
      pair<int, int> p = q.front();
      for (int d = 0; d < 4; ++d) {
        int ni = p.first + di[d];
        int nj = p.second + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (cost[ni][nj] < inf) continue;
        if (g[ni][nj] != '.') continue;
        cost[ni][nj] = cost[p.first][p.second] + 1;
        q.push({ni, nj});
      }
    }

    if (cost[h - 1][w - 1] == inf) cout << -1 << endl;
    else cout << count(&g[0][0], &g[h - 1][w - 1] + 1, '.') - cost[h - 1][w - 1] << endl;
  }

  return 0;
}
