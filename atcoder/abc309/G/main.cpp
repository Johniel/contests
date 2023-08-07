// github.com/Johniel/contests
// atcoder/abc309/G/main.cpp

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

// from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
template<int MOD> istream& operator >> (istream& is, Fp<MOD>& m) { is >> m.val; m.val %= MOD; return is; }
template<int MOD> ostream& operator << (ostream& os, const Fp<MOD>& m) { os << m.val; return os; }
using mint = Fp<mod>;

int main(int argc, char *argv[])
{
  int n, x;
  while (cin >> n >> x) {
    const int N = 100 + 3;
    const int M = (1 << 5);
    static mint dp[N][N][M][M];
    fill(&dp[0][0][0][0], &dp[N - 1][N - 1][M - 1][M - 1], mint(0));
    dp[0][0][0][0] = mint(1);
    // 添字側をA, 順列側をBとしたとき、
    // dp[i][j][s][t] :=
    //   AとBの要素をi番目まで見たとき、使われていない（保留）ものがそれぞれj個あって、
    //   直近x個ではA側ではs(ビット表現)の位置に保留があり、B側ではt(ビット表現)にあるようなパターン数
    // (100^2)*((2^5)^2)=10000*1024。10^7くらい。
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        const int mask = (1 << x) - 1;
        // const int mask = (1 << (x - 1)) - 1;
        for (int s = 0; s <= mask; ++s) {
          for (int t = 0; t <= mask; ++t) {
            if (dp[i][j][s][t] == 0) continue;
            const int ja = j - __builtin_popcount(mask & (s << 1));
            const int jb = j - __builtin_popcount(mask & (t << 1));
            if (ja < 0 || jb < 0) continue;
            // AiもBiも使わない
            dp[i + 1][j + 1][mask & ((s << 1) + 1)][mask & ((t << 1) + 1)] += dp[i][j][s][t];
            // AiとBの残りを使う
            if (jb) dp[i + 1][j][mask & ((s << 1) + 0)][mask & ((t << 1) + 1)] += dp[i][j][s][t] * jb;
            // Aの残りとBiを使う
            if (ja) dp[i + 1][j][mask & ((s << 1) + 1)][mask & ((t << 1) + 0)] += dp[i][j][s][t] * ja;
            // AiとBの残りを使う && Aの残りとBiを使う
            if (ja && jb) dp[i + 1][j - 1][mask & ((s << 1) + 0)][mask & ((t << 1) + 0)] += dp[i][j][s][t] * ja * jb;
          }
        }
      }
    }
    cout << dp[n][0][0][0] << endl;
  }

  return 0;
}

// 3 1

// 1, 2, 0
// 2, 0, 1

// 01
// 12
// 20

// AiもBiも使わない
// AiとBの残りを使う
// AiとBの残りを使う && Aの残りとBiを使う

// 5 2

// (0,1,2,3,4,) (2,3,4,0,1,)
// (0,1,2,3,4,) (2,3,4,1,0,)
// (0,1,2,3,4,) (3,4,0,1,2,)
// (0,1,2,3,4,) (4,3,0,1,2,)

// 02
// 13
// 24
// 30
// 41
// AiもBiも使わない
// AiもBiも使わない
// Aの残りとBiを使う
// AiとBの残りを使う && Aの残りとBiを使う
// AiとBの残りを使う && Aの残りとBiを使う

// 04
// 13
// 20
// 31
// 42
// AiもBiも使わない
// AiもBiも使わない
// AiとBの残りを使う
// AiとBの残りを使う && Aの残りとBiを使う
// AiとBの残りを使う && Aの残りとBiを使う
