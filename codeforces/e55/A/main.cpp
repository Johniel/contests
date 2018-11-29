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

const lli inf = 1LL << 60;

lli fn1(lli n, lli x, lli y, lli d)
{
  if (x % d == y % d) {
    auto z = abs(x - y);
    return z / d;
  }
  return inf;
}

lli fn2(lli n, lli x, lli y, lli d)
{
  if (y % d == 1) {
    return (y / d) + (x / d + bool(x % d));
  }
  return inf;
}

lli fn3(lli n, lli x, lli y, lli d)
{
  if (n % d == y % d) {
    auto z = abs(x - n);
    return (abs(n - y) / d) + (z / d + bool(z % d));
  }
  return inf;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    lli n, x, y, d;
    cin >> n >> x >> y >> d;

    lli z = min(
      {
        fn1(n, x, y, d),
        fn2(n, x, y, d),
        fn3(n, x, y, d),
      }
    );
    cout << (z == inf ? -1 : z) << endl;
  }

  return 0;
}
