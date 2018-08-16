# atcoder/agc017/B

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

  lli n, a, b, c, d;
  while (cin >> n >> a >> b >> c >> d) {

    bool f = false;

    for (int i = 0; i < n - 1; ++i) {
      const lli s = a - i * c;
      const lli t = a - i * d;

      const lli p = b - (n - 1 - i) * c;
      const lli q = b - (n - 1 - i) * d;

      if (min(p, q) <= min(s, t) && min(s, t) <= max(p, q)) {
        f = true;
        break;
      }
      if (min(p, q) <= max(s, t) && max(s, t) <= max(p, q)) {
        f = true;
        break;
      }
    }

    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
```
