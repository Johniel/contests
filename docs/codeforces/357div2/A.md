# codeforces/357div2/A

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
  int n;
  while (scanf("%d", &n) == 1) {
    char buff[100];
    bool f = false;
    for (int i = 0; i < n; ++i) {
      int b, a;
      scanf("%s%d%d", buff, &b, &a);
      if (2400 <= b && b < a) f = true;
    }
    puts(f ? "YES" : "NO");
  }
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/357div2/A)
{% endraw %}
