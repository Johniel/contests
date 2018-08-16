# codeforces/323div2/B

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
  int n;
  while(scanf("%d", &n) == 1) {
    int a[n];
    bool vis[n];
    for (int i = 0; i < n; ++i) {
      vis[i] = false;
      scanf("%d", a + i);
    }

    int cnt = -1;
    int collected = 0;
    while (collected < n) {
      ++cnt;
      if (cnt % 2) {
        for (int i = n - 1; 0 <= i; --i) {
          if (vis[i]) continue;
          if (a[i] <= collected) {
            vis[i] = true;
            ++collected;
          }
        }
      } else {
        for (int i = 0; i < n; ++i) {
          if (vis[i]) continue;
          if (a[i] <= collected) {
            vis[i] = true;
            ++collected;
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
```
