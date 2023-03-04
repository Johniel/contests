// github.com/Johniel/contests
// codeforces/856div2/D/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

namespace math {
   const int N = 1e6 + 3;
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
    static map<lli, lli> memo;
    if (memo.count(a)) return memo[a];

    lli x, y;
    extgcd(a, m, x, y);
    return memo[a] = (m + x % m) % m;
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
};

int main(int argc, char *argv[])
{
  math::init();

  const int N = math::N;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }

  int n;
  while (cin >> n) {
    vec<lli> a(2 * n);
    cin >> a;

    // map<lli, lli> m;
    // each (i, a) ++m[i];
    lli m[N];
    fill(m, m + N, 0);
    each (i, a) ++m[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    const lli N = (2 * 2022) + 3;
    static lli dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    dp[0][0] = 1;
    lli s = 0;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < N; ++j) {
        unless (dp[i][j]) continue;

        assert(0 <= s - j);

        lli x = math::fact[s - j];
        lli y = math::fact[s - j + m[a[i]]];
        lli w = (math::mod_inverse(x, mod) * y) % mod;
        lli u = math::fact[m[a[i]]];
        u = math::mod_inverse(u, mod);
        (dp[i + 1][j] += dp[i][j] * w % mod * u % mod) %= mod;

        if (prime[a[i]]) {
          lli x = math::fact[s - j];
          lli y = math::fact[s - j + m[a[i]] - 1];
          lli w = (math::mod_inverse(x, mod) * y) % mod;
          lli u = math::fact[m[a[i]] - 1];
          u = math::mod_inverse(u, mod);
          (dp[i + 1][j + 1] += dp[i][j] * w % mod * u % mod) %= mod;
        }
      }
      s += m[a[i]];
    }
    cout << dp[a.size()][n] << endl;
  }
  return 0;
}
