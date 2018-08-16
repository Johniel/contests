# codeforces/446div2/C

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

lli gcd(lli a, lli b)
{
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    each (i, v) cin >> i;


    {
      lli x = v[0];
      each (i, v) x = gcd(x, i);
      if (x != 1) {
        cout << -1 << endl;
        continue;
      }
    }

    const lli one = count(v.begin(), v.end(), 1);
    const lli inf = 1LL << 60;
    lli x = one ? n - one : inf;

    for (int i = 0; i < n; ++i) {
      lli z = v[i];
      int cnt = 0;
      for (int j = i + 1; j < n; ++j) {
        z = gcd(z, v[j]);
        ++cnt;
        if (z == 1) {
          x = min<lli>(x, cnt + n - 1);
          break;
        }
      }
    }
    cout << (x == inf ? -1 : x) << endl;
  }
  
  return 0;
}
```
