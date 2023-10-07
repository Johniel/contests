// github.com/Johniel/contests
// atcoder/abc323/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

// namespace math {
//   lli fact[N], finv[N], inv[N];

//   void init(void)
//   {
//     fact[0] = fact[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for (int i = 2; i < N; i++){
//       fact[i] = fact[i - 1] * i % mod;
//       inv[i] = mod - inv[mod % i] * (mod / i) % mod;
//       finv[i] = finv[i - 1] * inv[i] % mod;
//     }
//     return ;
//   }

//   lli mod_comb(int n, int k)
//   {
//     assert(n < N && k < N);
//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
//   }

//   inline lli nCk(int n, int k)
//   {
//     return mod_comb(n, k);
//   }

//   // n個の箱にm個の何かを分配する場合の数
//   inline lli nHm(int n, int m)
//   {
//     return nCk(n + m - 1, m);
//   }
// };

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
};


int main(int argc, char *argv[])
{
  int n, x;
  while (cin >> n >> x) {
    vec<int> t(n);
    cin >> t;
    const int X = 1e4 + 10;
    static lli dp[X];
    fill(dp, dp + X, 0);
    dp[0] = 1;
    const lli p = math::mod_inverse(t.size(), mod);
    for (int curr = 0; curr < X; ++curr) {
      each (time, t) {
        if (curr + time < X) {
          (dp[curr + time] += (dp[curr] * p) % mod) %= mod;
        }
      }
    }
    lli z = 0;
    for (int curr = 0; curr <= x; ++curr) {
      if (x < curr + t[0]) {
        (z += (dp[curr] * p) % mod) %= mod;
      }
    }
    cout << z << endl;
  }
  return 0;
}
