# atcoder/agc010/B

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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    lli b[n];
    for (int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      b[i] = a[j] - a[i];
    }
    lli sum = accumulate(a, a + n, 0LL);
    lli m = (n + 1) * n / 2;
    bool f = true;
    f = f && (sum % m == 0);
    lli k = sum / m;
    for (int i = 0; i < n; ++i) {
      b[i] -= k;
    }
    for (int i = 0; i < n; ++i) {
      f = f && (b[i] <= 0) && (b[i] % n == 0);
    }
    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
```
