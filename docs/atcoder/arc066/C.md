# atcoder/arc066/C

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

int solve(int n)
{
  const lli mod = 1000000000 + 7;
  lli m = 1;
  for (int i = 0; i < n / 2; ++i) {
    m *= 2;
    m %= mod;
  }
  return m;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i]];
    }
    bool f = true;
    if (n % 2) {
      int x = 2;
      for (int i = 0; i < n / 2; ++i) {
        f = (cnt[x] == 2);
        x += 2;
      }
      f = (cnt[0] == 1);
    } else {
      int x = 1;
      for (int i = 0; i < n / 2; ++i) {
        f = (cnt[x] == 2);
        x += 2;
      }      
    }
    printf("%d\n", f ? solve(n) : 0);
  }
  
  return 0;
}
```
