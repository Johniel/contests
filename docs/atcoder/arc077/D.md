# atcoder/arc077/D

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

lli extgcd(lli a, lli b, lli& x, lli& y)
{
  lli g = a;
  x = 1;
  y = 0;
  if (b != 0) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return g;
}

lli mod_inverse(lli a, lli m)
{
  lli x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

constexpr lli mod = 1e9 + 7;
constexpr int N = min<lli>(mod, 100000 + 5);
lli fact[N]; // P.263

template<typename T, typename U>
T mod_fact(T n, U p, U &e)
{
  e = 0;
  if (n == 0) return 1;

  T res = mod_fact(n / p, p, e);
  e += n / p;
  if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
  return res * fact[n % p] % p;
}

// nCk mod P O(n log p )
lli mod_comb(lli n, lli k, lli p = mod)
{
  if (n < 0 || k < 0 || n < k) {
    return 0;
  }
  lli e1, e2, e3;
  lli a1 = mod_fact(n, p, e1);
  lli a2 = mod_fact(k, p, e2);
  lli a3 = mod_fact(n - k, p, e3);
  if (e1 > e2 + e3) {
    return 0;
  }
  return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }

  lli n;
  while (cin >> n) {
    ++n;
    vector<int> a(n);
    each (i, a) cin >> i;
    int mn = 0;
    int mx = 0;
    {
      map<int, int> idx;
      for (int i = 0; i < a.size(); ++i) {
        if (idx.count(a[i])) {
          mn = idx[a[i]];
          mx = i;
          break;
        }
        idx[a[i]] = i;
      }
    }

    const int x = mn;
    const int y = mx - mn - 1;
    const int z = n - 2 - x - y;

    cout << n - 1 << endl;
    for (int i = 2; i <= n; ++i) {
      lli m = mod_comb(n, i);
      if (0 < x + z && i - 1 <= x + z) {
        m = (m - mod_comb(x + z, i - 1) + mod) % mod;
      }
      cout << m << endl;
    }
    cout << endl;
  }

  return 0;
}
```
