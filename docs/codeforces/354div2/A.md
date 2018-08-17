# codeforces/354div2/A

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
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(a[i], a[j]);
        int x, y;
        for (int k = 0; k < n; ++k) {
          if (a[k] == 1) x = k;
          if (a[k] == n) y = k;
        }
        mx = max(mx, abs(x - y));
        swap(a[i], a[j]);
      }
    }
    printf("%d\n", mx);
  }
  return 0;
}
```
