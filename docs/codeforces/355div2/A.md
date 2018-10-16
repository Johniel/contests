# codeforces/355div2/A

## Codes
main.cpp
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
  int n, h;
  while (scanf("%d%d", &n, &h) == 2) {
    int sum = n;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      sum += h < m;
    }
    printf("%d\n", sum);
  }
  return 0;
}
```

---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/355div2/A)
{% endraw %}
