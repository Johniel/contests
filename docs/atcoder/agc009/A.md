# atcoder/agc009/A

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
  while (cin >> n) {
    lli a[n];
    lli b[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    reverse(a, a + n);
    reverse(b, b + n);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      a[i] += sum;
      lli y = (a[i] / b[i]) + (bool)(a[i] % b[i]);
      lli x = y * b[i] - a[i];
      sum += x;
      a[i] += x;
      // cout << "x: " << x << endl;
    }
    // for (int i = 0; i < n; ++i) cout << a[i] << ' ' ; cout << endl;
    // for (int i = 0; i < n; ++i) cout << b[i] << ' ' ; cout << endl;
    cout << sum << endl;
  }
  return 0;
}
```
