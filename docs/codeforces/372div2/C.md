# codeforces/372div2/C

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

bool sq(lli x)
{
  static lli i = 1;
  for (; i * i <= x; ++i) {
    if (i * i == x) return true;
  }
  return false;
}

void validate(lli curr, lli x, lli add)
{
  lli next = curr + 1;
  assert(x % curr == 0);
  lli y = x + add * curr;
  assert(0 < y);
  assert(y % next == 0);
  assert(sq(y));
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    lli level = 1;
    lli x = 2;
    while (level <= n) {
      const lli y = (level + 1) * level;
      assert(y % level == 0);
      assert(x % level == 0);
      lli add = y * (y / level) - (x / level);
      printf("%lld\n", add);
      // validate(level, x, add);
      x = y;
      ++level;
    }
  }
  return 0;
}
```
