# codeforces/342div2/B

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
  const int N = 100000 + 5;
  const int M = 30 + 5;
  char g[N];
  char a[M];
  while (scanf("%s%s", g, a) == 2) {
    int cnt = 0;
    const int n = strlen(g);
    const int m = strlen(a);
    for (int i = 0; i < n; ++i) {
      int f = 0;
      for (int j = 0; i + j < n && j < m; ++j) {
        f += (g[i + j] == a[j]);
      }
      if (f == m) {
        ++cnt;
        i += f - 1;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
```
