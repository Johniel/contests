// atcoder/abc232/E/main.cpp
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

const int N = 1e6 + 5;

namespace math {
  lli fact[N], finv[N], inv[N];

  void init()
  {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++){
      fact[i] = fact[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
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

  math::init();

  lli h, w, k;
  lli x1, y1, x2, y2;
  while (cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2) {
    if (k == 1) {
      if (0) ;
      else if (x1 == x2 && y1 != y2) cout << 1 << endl;
      else if (x1 != x2 && y1 == y2) cout << 1 << endl;
      else cout << 0 << endl;
      continue;
    }

    static lli dp1[N][2];
    fill(&dp1[0][0], &dp1[N - 1][2 - 1], 0);
    dp1[0][false] = (x1 != x2);
    dp1[0][true] = (x1 == x2);
    for (int i = 0; i <= k; ++i) {
      dp1[i + 1][true] = dp1[i][false] * (w - 1) % mod;
      dp1[i + 1][false] = (dp1[i][false] * (w - 2) + dp1[i][true]) % mod;
    }

    static lli dp2[N][2];
    fill(&dp2[0][0], &dp2[N - 1][2 - 1], 0);
    dp2[0][false] = (y1 != y2);
    dp2[0][true] = (y1 == y2);
    for (int i = 0; i <= k; ++i) {
      dp2[i + 1][true] = dp2[i][false] * (h - 1) % mod;
      dp2[i + 1][false] = (dp2[i][false] * (h - 2) + dp2[i][true]) % mod;
    }

    lli z = 0;
    for (int i = 0; i <= k; ++i) {
      z += dp1[i][true] * dp2[k - i][true] % mod * math::mod_comb(k, i) % mod;
      z %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
