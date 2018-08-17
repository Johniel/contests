# codeforces/377div2/C

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

const lli inf = 1LL << 63;


int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);
  lli a, b, c;
  while (cin >> a >> b >> c) {
    const lli mx = max({a, b, c});
    lli mn = 1LL << 62;

    for (int bit = 0; bit < (1 << 4) - 1; ++bit) {
      lli A = mx - (bool)(bit & (1 << 0));
      lli B = mx - (bool)(bit & (1 << 1));
      lli C = mx - (bool)(bit & (1 << 2));
      
      if (A < a) continue;
      if (B < b) continue;
      if (C < c) continue;
      
      lli diff = (A - a) + (B - b) + (C - c);
      // cout << (A - a) << ' ' << (B - b) << ' ' <<  (C - c) << endl;
      // cout << diff << endl;
      mn = min(mn, diff);
    }
    
    cout << mn << endl;
  }
  return 0;
}
```
