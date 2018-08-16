# codeforces/344div2/B

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
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    pair<int, int> r[n];
    pair<int, int> c[m];
    fill(r, r + n, make_pair(0, 0));
    fill(c, c + m, make_pair(0, 0));
    for (int i = 0; i < k; ++i) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      if (x == 1) r[y - 1] = make_pair(i, z);
      else        c[y - 1] = make_pair(i, z);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j) printf(" ");
        printf("%d", max(r[i], c[j]).second);
      }
      puts("");
    }
  }
  return 0;
}
```
