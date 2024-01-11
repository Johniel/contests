// github.com/Johniel/contests
// atcoder/arc012/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

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

  // bi = r (mod mi)となる(r,mod)を返す
  // 解なしなら(0,-1)
  pair<lli, lli> chinese_remainder_theorem(const vector<lli> &b, const vector<lli> &m)
  {
    lli r = 0;
    lli M = 1;
    for (int i = 0; i < b.size(); ++i) {
      lli p, q;
      lli d = extgcd(M, m[i], p, q);
      if ((b[i] - r) % d != 0) return make_pair(0, -1);
      lli tmp = (b[i] - r) / d * p % (m[i] / d);
      r += M * tmp;
      M *= m[i] / d;
    }
    return make_pair((r + M) % M, M);
  }
};

// nCk mod mをk=0...nの範囲で求める。mは合成数でも良い。
struct arbitrary_mod_binomial_coefficient {
  // ARC012D
  using T = long long int;
  // modを素因数分解して Π p^e で表したもの。
  vector<pair<T, int>> pfactors;
  // pfactorsを使って0〜Nの階乗を素因数分解したもの。
  vector<vector<pair<T, int>>> ffactors;
  // 実際にpをe乗した値。
  vector<T> mods;
  const T mod;
  const int N;
  arbitrary_mod_binomial_coefficient(int N_, T mod_) : N(N_), mod(mod_) {
    pfactors = factorize(mod);
    mods = exp_factors();
    ffactors = factorize_factorials(N);
    assert(pfactors.size() == mods.size());
    assert(pfactors.size() == ffactors.size());
  }
  vector<T> exp_factors(void) {
    vector<T> v;
    for (const auto& i: pfactors) {
      auto [p, exp] = i;
      T x = 1;
      while (exp--) x *= p;
      v.push_back(x);
    }
    return v;
  }
  vector<pair<T, int>> factorize(T n) {
    vector<pair<T, int>> v;
    for (long long int i = 2; i * i <= n; ++i) {
      int p = 0;
      while (n % i == 0) {
        n /= i;
        ++p;
      }
      if (p) v.push_back(make_pair(i, p));
    }
    if (n != 1) v.push_back(make_pair(n, 1));
    return v;
  }
  vector<vector<pair<T, int>>> factorize_factorials(const int N) {
    vector<vector<pair<T, int>>> v;
    for (int i = 0; i < pfactors.size(); ++i) {
      const auto [p, _] = pfactors[i];
      // u[j]! mod p^e
      // u[j]!以下の素因数分解に登場するp[i]
      vector<pair<T, int>> u(N + 1);
      u[0] = make_pair(T(1), 0);
      for (int j = 1; j <= N; ++j) {
        u[j] = u[j - 1];
        int n = j;
        while (n % p == 0) {
          n /= p;
          ++u[j].second;
        }
        u[j].first = (u[j].first * n) % mods[i];
      }
      v.push_back(u);
    }
    return v;
  }
  T mod_comb_1(int n, int k, int nthp) const {
    const auto pfactor = pfactors[nthp];
    const auto mod = mods[nthp];
    // n!/(n-k)!/k!
    const auto& a = ffactors[nthp][n];
    const auto& b = ffactors[nthp][k];
    const auto& c = ffactors[nthp][n - k];
    int e = a.second - b.second - c.second;
    if (pfactor.second <= e) return 0;
    T x = a.first;
    (x *= math::mod_inverse(b.first, mod)) %= mod;
    (x *= math::mod_inverse(c.first, mod)) %= mod;
    while (e--) (x *= pfactor.first) %= mod;
    return x;
  }
  T mod_comb(int n, int k) const {
    vector<long long int> b;
    for (int i = 0; i < pfactors.size(); ++i) {
      b.push_back(mod_comb_1(n, k, i));
    }
    return math::chinese_remainder_theorem(b, mods).first;
  }
};

int main(int argc, char *argv[])
{
  lli mod;
  int n, t;
  while (cin >> n >> t >> mod) {
    vec<pair<int, int>> v(n);
    cin >> v;
    each (i, v) i.first = abs(i.first), i.second = abs(i.second);
    bool f = true;
    each (i, v) {
      int xy = i.first + i.second;
      f = f && (xy <= t && (t - xy) % 2 == 0);
    }
    unless (f) {
      cout << 0 << endl;
      continue;
    }
    const int N = 1e5 + 3;
    arbitrary_mod_binomial_coefficient bc(N, mod);
    lli z = 1;
    each (i, v) {
      int r = (t - (i.first + i.second)) / 2;
      (z *= bc.mod_comb(t, i.first + r) * bc.mod_comb(t, r) % mod) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
