# codeforces/358div2/C

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

const int N = 100000 + 10;
lli a[N];
vector<pair<int, lli>> g[N];

int rec(int curr, lli cost = 0)
{
  if (a[curr] < cost) return 0;
  int sum = 1;
  each (e, g[curr]) {
    sum += rec(e.first, max(cost + e.second, e.second));
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
    }

    for (int i = 0; i < n - 1; ++i) {
      int p;
      lli w;
      scanf("%d%lld", &p, &w);
      g[p-1].push_back(make_pair(i+1, w));
    }
    
    printf("%d\n", n - rec(0));
  }
  return 0;
}
```
