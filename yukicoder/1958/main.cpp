// yukicoder/1958/main.cpp
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
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, x, y;
  while (cin >> n >> x >> y) {
    vec<lli> a(x), b(y);
    cin >> a >> b;

    lli z = 0;
    for (int i = 0; i < 61; ++i) {
      const lli w = 1LL << i;
      vec<lli> s(2, 0);
      vec<lli> t(2, 0);
      each (j, a) ++s[!!(j & w)];
      each (j, b) ++t[!!(j & w)];
      const int N = 2 * 1e5 + 3;
      static lli dp[N][2];
      fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, 0);
      dp[0][0] = 1;
      for (int j = 0; j < n; ++j) {
        for (int x = 0; x < 2; ++x) {
          for (int y = 0; y < 2; ++y) {
            for (int z = 0; z < 2; ++z) {
              lli u = dp[j][x];
              (u *= s[y]) %= mod;
              (u *= t[z]) %= mod;
              (dp[j + 1][(x | y) & z] += u) %= mod;
            }
          }
        }
      }
      (z += dp[n][1] * (w % mod) % mod) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
