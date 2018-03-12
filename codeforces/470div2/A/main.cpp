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
    replace(&g[0][0], &g[h - 1][w - 1] + 1, '.', 'D');

    bool f = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] != 'S') continue;
        int di[] = {0, 0, -1, +1};
        int dj[] = {-1, +1, 0, 0};
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == 'W') {
            f = false;
          }
        }
      }
    }
    if (f) {
      cout << "Yes" << endl;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << g[i][j];
        }
        cout << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
  
  return 0;
}
