// github.com/Johniel/contests
// atcoder/abc310/F/main.cpp

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
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    const int N = 100 + 3;
    const int B = 1 << 11;
    static lli dp[N][B];
    fill(&dp[0][0], &dp[N - 1][B - 1] + 1, 0);
    dp[0][1 << 0] = 1;

    for (int i = 0; i < a.size(); ++i) {
      const lli p = math::mod_inverse(a[i], mod);
      for (int bit = 0; bit < B; ++bit) {
        for (int j = 1; j <= min(a[i], 10); ++j) {
          int b = bit | (1 << j);
          for (int k = 0; j + k <= 10; ++k) {
            if (bit & (1 << k)) b |= (1 << (j + k));
          }
          (dp[i + 1][b] += dp[i][bit] * p % mod) %= mod;
        }
        lli rest = p * max(0, a[i] - 10) % mod;
        (dp[i + 1][bit] += dp[i][bit] * rest % mod) %= mod;
      }
    }

    lli z = 0;
    for (int bit = 0; bit < B; ++bit) {
      if (bit & (1 << 10)) (z += dp[a.size()][bit]) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
