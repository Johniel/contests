# codeforces/350div2/A

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
  while (scanf("%d", &n) == 1) {
    int mn = n * 2, mx = 0;

    for (int base = 0; base < 7; ++base) {
      int cnt = 0;
      for (int d = 0; d < n; ++d) {
        cnt += (5 <= (base + d) % 7);
      }
      mn = min(mn, cnt);
      mx = max(mx, cnt);
    }
    printf("%d %d\n", mn, mx);
  }
  return 0;
}
```
