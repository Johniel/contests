// atcoder/abc151/D/main.cpp
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

const int N = 20 + 3;
char g[N][N];

int gi, gj;
int cost[N][N];
int h, w;

bool vis[N][N];

int bfs(int si, int sj)
{
  assert(g[si][sj] == '.');
  fill(&vis[0][0], &vis[N - 1][N - 1] + 1, false);
  fill(&cost[0][0], &cost[N - 1][N - 1] + 1, -(1 << 29));

  vis[si][sj] = true;
  cost[si][sj] = 0;
  queue<pair<int, int>> q;
  for (q.push(make_pair(si, sj)); q.size(); q.pop()) {
    const int I = q.front().first;
    const int J = q.front().second;
    for (int d = 0; d < 4; ++d) {
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      int ni = I + di[d];
      int nj = J + dj[d];
      unless (0 <= ni && ni < h) continue;
      unless (0 <= nj && nj < w) continue;
      if (vis[ni][nj]) continue;
      if (g[ni][nj] == '#') continue;
      cost[ni][nj] = cost[I][J] + 1;
      vis[ni][nj] = true;
      q.push(make_pair(ni, nj));
    }
  }

  return *max_element(&cost[0][0], &cost[N - 1][N - 1] + 1);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> h >> w) {
    int si, sj;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int mx = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') {
          setmax(mx, bfs(i, j));
          // si = i;
          // sj = j;
        }
      }
    }
    // cout << cost[gi][gj] << endl;
    cout << mx << endl;
  }

  return 0;
}
