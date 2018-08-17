# codeforces/442div2/D

## Codes
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w, k;
  while (cin >> h >> w >> k) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;
    queue<pair<int, int>> q;
    int cost[h][w];
    const int inf = 1 << 29;
    fill(&cost[0][0], &cost[h - 1][w - 1] + 1, inf);
    cost[a][b] = 0;
    for (q.push(make_pair(a, b)); q.size() && cost[c][d] == inf; q.pop()) {
      pair<int, int> p = q.front();
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      for (int d = 0; d < 4; ++d) {
        for (int x = 1; x <= k; ++x) {
          int ni = p.first + di[d] * x;
          int nj = p.second + dj[d] * x;
          unless (0 <= ni && ni < h) break;
          unless (0 <= nj && nj < w) break;
          if (g[ni][nj] == '#') break;
          if (cost[ni][nj] == inf) {
            cost[ni][nj] = cost[p.first][p.second] + 1;
            q.push(make_pair(ni, nj));
          }
        }
      }
    }
    cout << (cost[c][d] == inf ? -1 : cost[c][d]) << endl;
  }
  
  return 0;
}
```
