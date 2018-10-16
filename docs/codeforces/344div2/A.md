# codeforces/344div2/A

## Codes
main.cpp
{% raw %}
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
    int b[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
    }
    int mx = 0;
    int or_a = 0;
    int or_b = 0;
    for (int l = 0; l < n; ++l) {
      or_a |= a[l];
      or_b |= b[l];
      int x = or_a;
      int y = or_b;
      for (int r = l; r < n; ++r) {
        x |= a[r];
        y |= b[l];
        mx = max(mx, x + y);
      }
    }
    printf("%d\n", mx);
  }
  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/344div2/A)
