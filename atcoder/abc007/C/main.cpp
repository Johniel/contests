// atcoder/abc007/C/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  while (cin >> h >> w) {
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    --si;
    --sj;
    --di;
    --dj;

    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int cost[h][w];
    const int inf = 1 << 29;
    fill(&cost[0][0], &cost[h - 1][w - 1] + 1, inf);
    cost[si][sj] = 0;

    queue<pair<int, int>> q;
    for (q.push({si, sj}); q.size(); q.pop()) {
      int i = q.front().first;
      int j = q.front().second;
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '#') continue;
        if (cost[ni][nj] != inf) continue;
        cost[ni][nj] = cost[i][j] + 1;
        q.push(make_pair(ni, nj));
      }
    }
    cout << cost[di][dj] << endl;
  }

  return 0;
}
