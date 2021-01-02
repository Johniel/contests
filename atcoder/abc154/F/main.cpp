// atcoder/abc154/F/main.cpp
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
constexpr lli mod = 1e9 + 7;

const int N = 2 * 1e6 + 3;

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
  // nHm=n+m-1Cm

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

  // ai * x = bi (mod mi)
  pair<lli, lli> liner_congruence(const vector<lli>& A, const vector<lli>& B, const vector<lli>& M)
  {
    lli x = 0, m = 1;
    for (int i = 0; i < A.size(); ++i) {
      lli a = A[i] * m;
      lli b = B[i] - A[i] * x;
      lli d = __gcd(M[i], a);
      if (b % d) return make_pair(-1, -1);
      lli t = b / d * mod_inverse(a / d, M[i] / d) % (M[i] / d);
      x = x + m * t;
      m *= M[i] / d;
    }
    return {x % m, m};
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  math::init();

  int r1, c1, r2, c2;
  while (cin >> r1 >> c1 >> r2 >> c2) {
    auto fn = [] (lli i, lli j) {
      return math::mod_comb(i + j + 2, j + 1) - 1;
    };
    lli a = fn(r2, c2);
    lli b = fn(r2, c1 - 1);
    lli c = fn(r1 - 1, c2);
    lli d = fn(r1 - 1, c1 - 1);
    cout << (a + mod + mod - c - b + d) % mod << endl;
  }

  return 0;
}
