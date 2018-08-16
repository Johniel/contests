# atcoder/agc004/B

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

const int N = 2000 + 10;
const lli inf = 1LL << 50;

int main(int argc, char *argv[])
{
  int n, x;
  while (cin >> n >> x) {
    lli a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    lli dp[n];
    for (int i = 0; i < n; ++i) {
      dp[i] = a[i];
    }

    lli mn = inf;
    for (lli ench = 0; ench <= 2 * n; ++ench) {
      for (int slime = 0; slime < n; ++slime) {
        const int i = (slime - ench + n * 10) % n;
        dp[slime] = min(dp[slime], a[i]);
      }
      mn = min(mn, accumulate(dp, dp + n, 0LL) + ench * x);
    }
    
    cout << mn << endl;
  }
  return 0;
}
```
