// atcoder/abc242/F/main.cpp
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 50 * 50 + 3;

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
};

const int M = 2500 + 3;
const int H = 50 + 3;
const int W = 50 + 3;
lli memo[H][W][M];
lli rec(int h, int w, int x)
{
  lli& ret = memo[h][w][x];
  if (ret != -1) return ret;

  lli z = math::mod_comb(h * w, x);
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (i == h && j == w) continue;
      lli a = math::mod_comb(h, i);
      lli b = math::mod_comb(w, j);
      lli c = a * b % mod;
      z = (z - (c * rec(i, j, x) % mod) + mod) % mod;
    }
  }

  return ret = z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  math::init();

  int h, w, b, r;
  while (cin >> h >> w >> b >> r) {
    fill(&memo[0][0][0], &memo[H - 1][W - 1][M - 1] + 1, -1);
    lli z = 0;
    for (int bi = 1; bi <= h; ++bi) {
      for (int bj = 1; bj <= w; ++bj) {
        for (int ri = 1; ri + bi <= h; ++ri) {
          for (int rj = 1; rj + bj <= w; ++rj) {
            lli x = math::mod_comb(h, bi) * math::mod_comb(h - bi, ri) % mod;
            lli y = math::mod_comb(w, bj) * math::mod_comb(w - bj, rj) % mod;
            lli p = x * y % mod;
            lli q = rec(bi, bj, b) * rec(ri, rj, r) % mod;
            (z += p * q % mod) %= mod;
          }
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
