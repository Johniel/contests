// atcoder/keyence2021/C/main.cpp
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

namespace math {

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
  // nHm=n+m-1Cm

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
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, k;
  while (cin >> h >> w >> k) {
    const int N = 5000 + 2;
    static char g[N][N];
    static lli dp[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, '@');
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);

    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      char c;
      cin >> c;
      --a;
      --b;
      g[a][b] = c;
    }

    dp[0][0] = 1;
    for (int i = 0; i < h * w - k; ++i) {
      (dp[0][0] *= 3) %= mod;
    }


    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'D' || g[i][j] == 'X') (dp[i + 1][j] += dp[i][j]) %= mod;
        if (g[i][j] == 'R' || g[i][j] == 'X') (dp[i][j + 1] += dp[i][j]) %= mod;
        if (g[i][j] == '@') {
          (dp[i + 1][j] += dp[i][j] * 2 * math::mod_inverse(3, mod)) %= mod;
          (dp[i][j + 1] += dp[i][j] * 2 * math::mod_inverse(3, mod)) %= mod;
        }
      }
    }

    cout << dp[h - 1][w - 1] << endl;
  }

  return 0;
}
