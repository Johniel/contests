# codeforces/353div2/B

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
  int n, a, b, c, d;
  while (scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) == 5) {
    lli cnt = 0;

    const lli mn = min({(a+b), (a+c), (b+d), (c+d)}) + 2;
    const lli mx = max({(a+b), (a+c), (b+d), (c+d)}) + n + n;
      
    for (lli x1 = 1; x1 <= n; ++x1) {
      const lli x5 = (x1 + a + b) - (c + d);
      const lli x2 = (x1 + a + b) - (a + c);
      const lli x4 = (x1 + a + b) - (b + d);

      unless (1 <= x2 && x2 <= n) continue;
      unless (1 <= x4 && x4 <= n) continue;
      unless (1 <= x5 && x5 <= n) continue;
      cnt += n;
    }
    
    printf("%lld\n", cnt);
  }
  return 0;
}
```
