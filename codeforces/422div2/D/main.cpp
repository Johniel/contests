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

  const lli mod = 1e9 + 7;
  const int N = 5 * 1000000 + 4;

  static lli fact[N];
  for (int i = 0; i < N; ++i) {
    fact[i] = i;
  }
  for (int i = 2; i < N; ++i) {
    if (fact[i] == i) {
      for (int j = 2; i * j < N; ++j) {
        fact[i * j] = min<lli>({i, fact[i * j]});
      }
    }
  }
  
  static lli z[N];
  for (lli i = 1; i < N; ++i) {
    z[i] = i * (i - 1) / 2LL;
  }
  for (lli i = 2; i < N; ++i) {
    for (lli j = i; 1 < j; j /= fact[j]) {
      z[i] = min(z[i], z[i / fact[j]] + (i * (fact[j] - 1LL) / 2LL));
    }
  }

  lli t, small, large;
  while (cin >> t >> small >> large) {
    lli x = 0;
    lli y = 1;
    for (int i = small; i <= large; ++i) {
      (x += z[i] % mod * y) %= mod;
      (y *= t) %= mod;
    }
    cout << x << endl;
  }

  return 0;
}
