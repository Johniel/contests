# atcoder/arc075/D

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

bool f(vector<lli> v, lli a, lli b, lli x)
{
  each (i, v) i = max<lli>(0, i - b * x);
  const lli c = a - b;
  each (i, v) x -= (i / c) + (bool)(i % c);
  return 0 <= x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, a, b;
  while (cin >> n >> a >> b) {
    vector<lli> v(n);
    each (i, v) cin >> i;

    auto g = [&] (lli x) { return f(v, a, b, x); };
    
    lli small = 0;
    lli large = 1e9 + 100;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (g(mid)) large = mid;
      else small = mid;
    }
    cout << (g(small) ? small : large) << endl;
  }
  
  return 0;
}
```
