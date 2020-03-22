# codeforces/336div2/A

## Code
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
  int n, s;
  while (scanf("%d%d", &n, &s) == 2) {
    int f, t;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &f, &t);
      if (abs(s - f) <= t) {
        mx = max(mx, f + t);
      } else {
        mx = max(mx, f + abs(s - f));
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
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/336div2/A)
