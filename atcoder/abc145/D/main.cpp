// atcoder/abc145/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

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
constexpr int N = 2 * 1e6 + 5;
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

void init(void)
{
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  init();

  lli x, y;
  while (cin >> x >> y) {
    int a, b;
    a = b = -1;
    for (int i = 0; i <= x; ++i) {
      lli p = x - i;
      lli q = y - 2 * i;
      if (0 <= q && p == q * 2) {
        a = i;
        b = q;
      }
    }
    if (a == -1) {
      cout << 0 << endl;
    } else {
      cout << mod_comb(a + b, a) << endl;
    }
  }

  return 0;
}
