# codeforces/manthan16/A

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
  lli a, b, c;
  while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
    bool f = false;
    for (int i = 0; i <= 10000; ++i) {
      lli d = (c - a * i);
      f = f || (0 <= d && d % b == 0);
    }
    puts(f ? "Yes" : "No");
  }
  return 0;
}
```
