// github.com/Johniel/contests
// atcoder/abc301/F/main.cpp

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
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

namespace math {
  const int N = 4 * 1e5 + 3;
  lli fact[N], finv[N], inv[N];

  void init(void)
  {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++){
      fact[i] = fact[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
    return ;
  }

  lli mod_comb(int n, int k)
  {
    assert(n < N && k < N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
  }

  inline lli nCk(int n, int k)
  {
    return mod_comb(n, k);
  }

  // n個の箱にm個の何かを分配する場合の数
  inline lli nHm(int n, int m)
  {
    return nCk(n + m - 1, m);
  }
};

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

  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }
}

int main(int argc, char *argv[])
{
  math::init();

  str s;
  while (cin >> s) {
    const int N = 3 * 1e5 + 3;
    const int M = 30;
    const int U2 = 27;
    const int L = 28;
    static lli dp[N][M]; // [何文字目][状態]
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    dp[0][0] = 1;
    int fixed = 0;
    for (int i = 0; i < s.size(); ++i) {
      if ('a' <= s[i] && s[i] <= 'z') {
        (dp[i + 1][0] += dp[i][0]) %= mod;
        for (int k = 1; k <= 26; ++k) (dp[i + 1][k] += dp[i][k]) %= mod;
        (dp[i + 1][L] += dp[i][U2]) %= mod;
        (dp[i + 1][L] += dp[i][L]) %= mod;
      }
      if ('A' <= s[i] && s[i] <= 'Z') {
        (dp[i + 1][1] += dp[i][0]) %= mod;
        if (fixed & (1 << (s[i] - 'A'))) {
          for (int k = 1; k <= 26; ++k) {
            (dp[i + 1][U2] += dp[i][k]) %= mod;
          }
        } else {
          const int f = __builtin_popcount(fixed);
          if (f == 26) {
            (dp[i + 1][U2] += dp[i][26]) %= mod;
          } else {
            for (int k = 1; k <= 26; ++k) {
              {
                const lli d = (k - f) * math::mod_inverse(26 - f, mod) % mod;
                (dp[i + 1][U2] += dp[i][k] * d % mod) %= mod;
              }
              if (k < 26) {
                const lli d = (26 - k) * math::mod_inverse(26 - f, mod) % mod;
                (dp[i + 1][k + 1] += dp[i][k] * d % mod) %= mod;
              }
            }
          }
        }
        (dp[i + 1][U2] += dp[i][U2]) %= mod;
        fixed |= (1 << (s[i] - 'A'));
      }
      if (s[i] == '?') {
        {
          (dp[i + 1][0] += dp[i][0] * 26) %= mod;
          for (int k = 1; k <= 26; ++k) {
            (dp[i + 1][k] += dp[i][k] * 26 % mod) %= mod;
          }
          (dp[i + 1][L] += dp[i][U2] * 26) %= mod;
          (dp[i + 1][L] += dp[i][L]  * 26) %= mod;
        }
        {
          (dp[i + 1][1] += dp[i][0] * 26) %= mod;
          for (int k = 1; k <= 26; ++k) {
            if (k < 26) {
              (dp[i + 1][k + 1] += dp[i][k] * (26 - k) % mod) %= mod;
            }
            (dp[i + 1][U2] += dp[i][k] * k % mod) %= mod;
          }
          (dp[i + 1][U2] += dp[i][U2] * 26) %= mod;
        }
      }
    }
    lli z = 0;
    for (int i = 0; i < M; ++i) {
      (z += dp[s.size()][i]) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
