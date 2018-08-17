# codeforces/404div2/C

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

lli f(const lli n, const lli m)
{
  auto fn = [&] (lli mid) {
    return (mid * (mid + 1) / 2) - ((mid - 1) * m) + (mid * m);
  };
  lli small = 0;
  lli large = 1LL << 31;
  while (small + 1 < large) {
    lli mid = (small + large) / 2;
    if (n <= fn(mid)) large = mid;
    else small = mid;
  }
  return large + m;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  while (cin >> n >> m) {
    cout << (n <= m ? n : f(n, m)) << endl;
  }

  return 0;
}
```
