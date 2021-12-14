// atcoder/abc226/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <vector>
#include <array>
#include <cassert>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>

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

const int N = 50 + 2;

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


int gcd(int a, int b)
{
  unless (a > b) swap(a, b);
  if (b == 0) return a;
  return gcd(a % b, b);
}

int lcm(int a, int b)
{
  return a * b / gcd(a, b);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  math::init();

  int n, k;
  while (cin >> n >> k) {
    const int M = 50 * 50 * 50;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    map<int, int> idx;
    idx[1] = 0;
    dp[0][idx[1]] = 1;
    for (int i = 0; i < n; ++i) {
      vec<int> v;
      each (j, idx) v.push_back(j.first);
      each (j, v) {
        unless (dp[i][idx[j]]) continue;
        for (int k = 1; i + k <= n; ++k) {
          const int l = lcm(j, k);
          unless (idx.count(l)) idx[l] = idx.size();
          (dp[i + k][idx[l]] += dp[i][idx[j]] * math::mod_comb(n - i - 1, k - 1) % mod * math::fact[k - 1] % mod) %= mod;
        }
      }
    }
    lli z = 0;
    each (i, idx) {
      (z += math::mod_pow(i.first, k) * dp[n][i.second] % mod) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
