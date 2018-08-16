# codeforces/419div2/C

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

  const int M = 100 + 5;
  static int g[M][M];
  
  int h, w;
  while (cin >> h >> w) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int s, t, u;
    s = t = -1;
    int best = 1 << 29;
    
    auto show = [&] () {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << g[i][j] << ' ';
        }
        cout << endl;
      }
      return ;
    };
    
    static int x[M][M];
    copy(&g[0][0], &g[M - 1][M - 1] + 1, &x[0][0]);
    const int A = g[0][0];
    for (int _a = 0; _a <= A; ++_a) {
      copy(&x[0][0], &x[M - 1][M - 1] + 1, &g[0][0]);
      const int a = _a;
      const int b = max(g[0][0] - a, a - g[0][0]);
      u = g[0][0];
      
      for (int i = 0; i < h; ++i) g[i][0] -= a;
      for (int j = 0; j < w; ++j) g[0][j] -= b;

      for (int i = 0; i < h; ++i) {
        const int sub = abs(g[i][0]);
        for (int j = 0; j < w; ++j) g[i][j] -= sub;
        u += sub;
      }

      for (int j = 0; j < w; ++j) {
        const int sub = abs(g[0][j]);
        for (int i = 0; i < h; ++i) g[i][j] -= sub;
        u += sub;
      }

      int cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cnt += (g[i][j] == 0);
        }
      }
      if (cnt == h * w && best > u) {
        s = a;
        t = b;
        best = u;
      }
    }

    if (s == -1 && t == -1) cout << -1 << endl;
    else {
      cout << best << endl;
      copy(&x[0][0], &x[M - 1][M - 1] + 1, &g[0][0]);
      const int a = s;
      const int b = t;

      for (int i = 0; i < h; ++i) g[i][0] -= a;
      for (int k = 0; k < a; ++k) cout << "col " << 1 << endl;
      for (int j = 0; j < w; ++j) g[0][j] -= b;
      for (int k = 0; k < b; ++k) cout << "row " << 1 << endl;

      for (int i = 0; i < h; ++i) {
        const int sub = g[i][0];
        for (int j = 0; j < w; ++j) g[i][j] -= sub;
        for (int j = 0; j < sub; ++j) cout << "row " << i + 1 << endl;
      }

      for (int j = 0; j < w; ++j) {
        const int sub = g[0][j];
        for (int i = 0; i < h; ++i) g[i][j] -= sub;
        for (int i = 0; i < sub; ++i) cout << "col " << j + 1 << endl;
      }
    }
  }
  
  return 0;
}
```
