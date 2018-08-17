# atcoder/agc014/C

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

const int H = 800 + 10;
const int W = 800 + 10;

char g[H][W];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w, k;
  while (cin >> h >> w >> k) {
    pair<int, int> ini;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') ini = make_pair(i, j);
      }
    }

    const int inf = 1 << 29;
    static int cost[H][W];
    fill(&cost[0][0], &cost[H - 1][W - 1] + 1, inf);
    cost[ini.first][ini.second] = 0;
    queue<pair<int, int>> q;
    for (q.push(ini); q.size(); q.pop()) {
      const int i = q.front().first;
      const int j = q.front().second;
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      for (int d = 0; d < 4; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (cost[ni][nj] != inf) continue;
        if (g[ni][nj] == '#') continue;
        cost[ni][nj] = cost[i][j] + 1;
        q.push(make_pair(ni, nj));
      }
    }

    int mn = inf;
    
    for (int i = 0; i < h; ++i) {
      if (cost[i][0] < k || cost[i][w - 1] < k) mn = 1;
    }
    for (int j = 0; j < w; ++j) {
      if (cost[0][j] < k || cost[h - 1][j] < k) mn = 1;
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (cost[i][j] <= k) {
          int a = (h - i - 1 + k - 1) / k + 1;
          int b = (i + k - 1) / k + 1;
          int c = (j + k - 1) / k + 1;
          int d = (w - j - 1 + k - 1) / k + 1;
          mn = min({mn, a, b, c, d});
        }
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
