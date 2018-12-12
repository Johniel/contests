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

lli ext_gcd(lli a, lli b, lli &x, lli &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

lli mod_inverse(lli a, lli m)
{
  lli x, y;
  ext_gcd(a, m, x, y);
  return (m + x % m) % m;
}

constexpr lli mod = 1e9 + 7;
constexpr int N = 1e5 * 2 + 10;
lli fact[N];
lli fact_inverse[N];

lli nCr(lli n, lli r)
{
  return (((fact[n] * fact_inverse[r]) % mod) * fact_inverse[n - r]) % mod;
}
int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  for (int i = 0; i < N; ++i) {
    fact_inverse[i] = mod_inverse(fact[i], mod);
  }

  int h, w, a, b;
  while (cin >> h >> w >> a >> b) {
    lli sum = 0;
    for (int i = 0; i < h - a; ++i) {
      int p = w - b - 1 + h - i - 1;
      int q = w - b - 1;
      lli x = nCr(b + i - 1, i) * nCr(p, q);
      (sum += x % mod) %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
