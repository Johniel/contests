// codeforces/e85/E/main.cpp
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
  const int N = 2 * 1e5 + 5;
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
};

lli fn(lli a, lli b, const vec<lli>& p)
{
  a /= b;
  vec<lli> v;
  int sum = 0;
  each (i, p) {
    if (a % i == 0) {
      v.push_back(0);
      while (a % i == 0) {
        a /= i;
        ++v.back();
        ++sum;
      }
    }
  }
  if (a != 1) {
    v.push_back(1);
    ++sum;
  }

  lli x = 1;
  each (i, v) {
    x *= math::mod_comb(sum, i);
    x %= mod;
    sum -= i;
  }

  return x;
}

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  math::init();

  lli D;
  int q;
  while (cin >> D >> q) {
    vec<lli> p;
    for (lli i = 2; i * i <= D; ++i) {
      if (D % i == 0) {
        p.push_back(i);
        while (D % i == 0) D /= i;
      }
    }
    if (D != 1) p.push_back(D);

    while (q--) {
      lli a, b;
      cin >> a >> b;
      lli c = __gcd(a, b);
      cout << (fn(a, c, p) * fn(b, c, p)) % mod << endl;
    }
  }

  return 0;
}
