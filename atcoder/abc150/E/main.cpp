// atcoder/abc150/E/main.cpp
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

const int N = 2 * 1e5 + 5;
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
  // 蟻本P.261
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

  int n;
  while (cin >> n) {
    vec<lli> c(n);
    cin >> c;
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    lli p2[N];
    p2[0] = 1;
    for (int i = 1; i < N; ++i) {
      p2[i] = (p2[i - 1] * 2) % mod;
    }

    lli w[N];
    w[0] = 1;
    for (int i = 1; i < n; ++i) {
      // https://drken1215.hatenablog.com/entry/2020/01/12/142100
      // C(n,0)+C(n,1)+⋯+C(n,n)=2n
      // 0×C(n,0)+1×C(n,1)+⋯+n×C(n,n)=n2n−1
      w[i] = (p2[i] + (i * p2[i - 1]) % mod) % mod;
      // w[i] = 0;
      // for (int j = 0; j <= i; ++j) {
      //   w[i] += math::mod_comb(i, j) * (j + 1);
      //   w[i] %= mod;
      // }
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      lli x = c[i];
      (x *= w[i]) %= mod;
      (x *= p2[n - i - 1]) %= mod;
      (sum += x) %= mod;
    }
    cout << (sum * p2[n]) % mod << endl;
  }

  return 0;
}
