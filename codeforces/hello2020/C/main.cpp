// codeforces/hello2020/C/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, mod;
  const int N = 250000 + 5;
  while (cin >> n >> mod) {
    static lli fact[N];
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = (fact[i - 1] * i) % mod;
    }
    lli sum = 0;
    for (int i = 1; i <= n; ++i) {
      lli x;
      x = (fact[n - i] * (n - i + 1)) % mod;
      x = (x * fact[i]) % mod;
      x = (x * (n - i + 1)) % mod;
      // cout << i << ' ' << x << endl;
      (sum += x) %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
