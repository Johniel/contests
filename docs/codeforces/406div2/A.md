# codeforces/406div2/A

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    lli x = b;
    lli y = d;
    for (int i = 0; i < 100000000; ++i) {
      if (x == y) break;
      if (x < y) x += a;
      else y += c;
    }
    cout << (x == y ? x : -1) << endl;
  }
  
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/406div2/A)
{% endraw %}
