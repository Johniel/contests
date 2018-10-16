# codeforces/353div2/A

## Codes
main.cpp
{% raw %}{{
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
    if (c) {
      puts(((b - a) % c == 0) && ((b - a) / c >= 0) ? "YES" : "NO");
    } else {
      puts(b == a? "YES" : "NO");
    }
  }
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/353div2/A)
