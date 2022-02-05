// atcoder/abc238/C/main.cpp
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

  const int N = 20;
  lli w[N];
  w[0] = 1;
  for (int i = 1; i < N; ++i) {
    (w[i] = w[i - 1] * 10) %= mod;
  }
  for (int i = 0; i < N; ++i) {
    --w[i];
  }

  // for (int i = 0; i < N; ++i) cout << i << ' ' << w[i] << endl;

  lli n;
  while (cin >> n) {
    const int len = to_string(n).size();
    lli z = 0;
    for (int i = 1; i < len; ++i) {
      lli a = (w[i] - w[i - 1] + mod) % mod;
      z += a * (a + 1) / 2 % mod;
      z %= mod;
    }
    lli b = (n - w[len - 1] + 1 + mod) % mod;
    z += b * (b - 1) / 2 % mod;
    z %= mod;
    cout << z << endl;
  }

  return 0;
}
