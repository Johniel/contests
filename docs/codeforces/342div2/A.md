# codeforces/342div2/A

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

lli a, b, c;

lli g(lli m)
{
  lli ret = max(0LL, m - b) / (b - c);
  m -= ret * (b - c);
  while (b <= m) {
    ++ret;
    m -= b;
    m += c;
  }
  return ret + (m / a);
}

lli f(lli m)
{
  return (m / a) + g(m % a);
}

int main(int argc, char *argv[])
{
  lli n;
  while (scanf("%lld%lld%lld%lld", &n, &a, &b, &c) == 4) {
    printf("%lld\n", max(g(n), f(n)));
  }
  return 0;
}
```
