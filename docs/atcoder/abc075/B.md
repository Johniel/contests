# atcoder/abc075/B

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

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    
    int di[] = {-1, -1, -1,  0,  0, +1, +1, +1};
    int dj[] = {-1,  0, +1, -1, +1, -1,  0, +1};
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') {
          cout << '#' << flush;
        } else {
          int cnt = 0;
          for (int dir = 0; dir < 8; ++dir) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            unless (0 <= i && i < h) continue;
            unless (0 <= j && j < w) continue;
            cnt += (g[ni][nj] == '#');
          }
          cout << cnt << flush;
        }
      }
      cout << endl;
    }
  }
  
  return 0;
}
```
