# codeforces/manthan16/B

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

int f(lli n)
{
  int cnt = 0;
  while (n && n % 5 == 0) {
    n /= 5;
    ++cnt;
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  lli n;
  while (scanf("%lld", &n) == 1) {
    lli _5 = 0;
    vector<lli> v;
    for (int i = 5; _5 <= n; ++i) {
      if (i % 5 == 0) _5 += f(i);
      if (_5 == n) v.push_back(i);
    }
    printf("%d\n", (int)v.size());
    for (int i = 0; i < v.size(); ++i) {
      if (i) printf(" ");
      printf("%lld", v[i]);
    }
    if (v.size()) puts("");
  }
  return 0;
}
```
