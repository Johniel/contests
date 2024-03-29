// atcoder/abc246/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

lli mod_pow(lli n, lli p)
{
  if (p == 0) return 1;
  if (p == 1) return n;
  lli m = mod_pow(n, p / 2);
  m *= m;
  m %= mod;
  if (p % 2) m = (m * n) % mod;
  return m;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, len;
  while (cin >> n >> len) {
    vec<str> v(n);
    cin >> v;

    vec<int> u(n, 0);
    for (int i = 0; i < v.size(); ++i) {
      each (c, v[i]) u[i] |= (1 << (c - 'a'));
    }

    lli z = 0;
    for (int bit = 1; bit < (1 << n); ++bit) {
      int b = (1 << 30) - 1;
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) b &= u[i];
      }
      int pc = mod_pow(__builtin_popcount(b), len);
      if (__builtin_popcount(bit) % 2) (z += pc) %= mod;
      else z = (z - pc + mod) % mod;
    }
    cout << z << endl;
  }

  return 0;
}
