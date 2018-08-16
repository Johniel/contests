# codeforces/332div2/A

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
  lli a, b, c;
  while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
    const lli inf = 1LL << 60;
    lli g[3][3];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        g[i][j] = inf;
      }
    }
    g[0][1] = g[1][0] = a;
    g[0][2] = g[2][0] = b;
    g[1][2] = g[2][1] = c;
    for (int k = 0; k < 3; ++k) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    printf("%lld\n", g[0][1] + g[1][2] + g[2][0]);
  }
  return 0;
}
```
