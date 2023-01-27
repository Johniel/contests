// github.com/Johniel/contests
// atcoder/abc286/F/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

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

  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }

  // ai * x = bi (mod mi)
  // 蟻本P.261
  // x=b(mod m)の(b,m)を返す
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
      lli tmp = (b[i] - r) / d * p % (m[i]/d);
      r += M * tmp;
      M *= m[i]/d;
    }
    return make_pair((r + M) % M, M);
  }
};

int main(int argc, char *argv[])
{
  vec<lli> p({4, 9, 5, 7, 11, 13, 17, 19, 23});
  sort(p.begin(), p.end());
  while (true) {
    const int M = accumulate(p.begin(), p.end(), 0);
    vec<lli> a(M);
    {
      iota(a.begin(), a.end(), 0);
      vec<lli> b = a;
      int x = 0;
      for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j < p[i]; ++j) {
          a[j + x] = b[x + (j + 1) % p[i]];
        }
        x += p[i];
      }
    }

    cout << M << endl;
    each (i, a) cout << i+1 << ' ' ; cout << endl;

    vec<int> v;
    vec<int> u;
    vec<int> w;
    for (int i = 0; i < p.size(); ++i) {
      int origin = v.size();
      w.push_back(a[v.size()]);
      for (int j = 0; j < p[i]; ++j) {
        v.push_back(p[i]);
        u.push_back(origin);
      }
    }

    vec<int> b(M);
    unless (cin >> b) break;
    each (i, b) --i;

    map<int, int> src;
    for (int i = 0; i < a.size(); ++i) {
      src[a[i]] = i;
    }
    map<int, int> dst;
    for (int i = 0; i < b.size(); ++i) {
      dst[b[i]] = i;
    }

    vec<lli> c;
    for (int i = 0; i < p.size(); ++i) {
      int j = w[i];
      int x = j - u[src[j]];
      int y = dst[j] - u[src[j]];
      c.push_back(p[i] - (y - x + p[i]) % p[i]);
    }

    pair<lli, lli> z = math::chinese_remainder_theorem(c, p);
    cout << z.first % z.second<< endl;
  }
  return 0;
}
