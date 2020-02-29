// atcoder/abc003/D/main.cpp
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

constexpr lli mod = 1e9 + 7;
const int N = 3000;

namespace math {
  lli fact[N], finv[N], inv[N];
  bool initialized = false;
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
    return ;
  }

  lli mod_comb(int n, int k)
  {
    assert(n < N && k < N);
    if (!initialized) init();
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
  }

  // MEMO:
  // kHn = (n+k−1)Cn
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli r, c, x, y, d, l;
  while (cin >> r >> c >> x >> y >> d >> l) {

    lli z = 0;

    for (int bit = 0; bit < (1 << 4); ++bit) {
      int a, b;
      a = b = 0;

      if (bit & (1 << 0)) ++a;
      if (bit & (1 << 1)) ++a;
      if (bit & (1 << 2)) ++b;
      if (bit & (1 << 3)) ++b;

      if ((x - a) < 0 || (y - b) < 0) continue;

      lli p = math::mod_comb((x - a) * (y - b), d + l);
      p %= mod;
      if (__builtin_popcount(bit) % 2) z -= p;
      else z += p;
      z = (z + mod) % mod;
    }
    z *= math::mod_comb(d + l, d);
    z %= mod;
    z *= (r - x + 1) * (c - y + 1);
    z %= mod;
    cout << z << endl;
  }

  return 0;
}
