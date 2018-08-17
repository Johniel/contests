# codeforces/423div2/B

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

    int mn_h = 1 << 29;
    int mn_w = 1 << 29;
    int mx_h = -1;
    int mx_w = -1;
    int cnt = 0;
    
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'B') {
          ++cnt;
          mn_h = min(mn_h, i);
          mn_w = min(mn_w, j);
          mx_h = max(mx_h, i);
          mx_w = max(mx_w, j);
        }
      }
    }

    const int inf = 1 << 29;
    int mn = inf;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; i + k < h && j + k < w; ++k) {
          pair<int, int> a = make_pair(i, j);
          pair<int, int> b = make_pair(i + k, j + k);
          if (a.first <= mn_h && a.second <= mn_w && mx_h <= b.first && mx_w <= b.second) {
            mn = min(mn, (k + 1) * (k + 1) - cnt);
          }
        }
      }
    }

    if (cnt == 0) mn = 1;
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
```
