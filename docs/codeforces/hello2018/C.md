# codeforces/hello2018/C

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  lli L;
  while (cin >> n >> L) {
    const lli N = 35;
    lli cost[N];
    fill(cost, cost + N, 1LL << 60);
    for (int i = 0; i < n; ++i) {
      cin >> cost[i];
    }

    for (int i = 0; i + 1 < N; ++i) {
      cost[i + 1] = min(cost[i + 1], cost[i] * 2);
    }
    
    lli v[N];
    for (int i = 0; i < N; ++i) {
      v[i] = 1LL << i;
    }

    lli mn = 1LL << 60;
    for (int i = n - 1; 0 <= i; --i) {
      lli sum = 0;
      lli x = L;
      for (int j = i; 0 <= j; --j) {
        lli a = x / v[j];
        if (x % v[j]) ++a;
        mn = min(mn, sum + cost[j] * a);

        sum += cost[j] * (x / v[j]);
        x %= v[j];
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
