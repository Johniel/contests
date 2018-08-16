# codeforces/453div2/A

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

  int n, m;
  while (cin >> n >> m) {
    const int N = 100 + 5;
    static bool g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, false);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      for (int j = a; j <= b; ++j) {
        g[a][j] = true;
      }
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          g[i][j] |= (g[i][k] && g[k][j]);
        }
      }
    }
    cout << (g[0][m] ? "YES" : "NO") << endl;
  }
  return 0;
}
```
