// atcoder/abc220/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 2 * 1e6 + 3;

  static lli w[N];
  w[0] = 1;
  for (int i = 1; i < N; ++i) {
    w[i] = (w[i - 1] * 2) % mod;
  }

  lli n, d;
  while (cin >> n >> d) {
    lli z = 0;
    lli a = 1;
    lli b = d - a;
    for (int i = 0; i < n; ++i) {
      if (i + d < n) {
        (z += (w[d] * w[i]) % mod) %= mod;
      }
      while (!(i + (d - a) < n) && 0 <= b) {
        ++a;
        --b;
      }
      if (0 <= d - 2 && max(a, b) + i < n && 0 < b && a < d) {
        lli y = w[i] * w[d - 2] % mod;
        y = y * (b - a + 1) % mod;
        z += y;
        z %= mod;
      }
    }
    cout << (z * 2) % mod << endl;
  }

  return 0;
}