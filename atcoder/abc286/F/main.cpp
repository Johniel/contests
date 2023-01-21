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

// https://qiita.com/drken/items/ae02240cd1f8edfc86fd
namespace {
  inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
  }

  long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    long long d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
  }

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
  pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
      long long p, q;
      long long d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
      if ((b[i] - r) % d != 0) return make_pair(0, -1);
      long long tmp = (b[i] - r) / d * p % (m[i]/d);
      r += M * tmp;
      M *= m[i]/d;
    }
    return make_pair(mod(r, M), M);
  }
}

vec<lli> rot(vec<lli> a, int N)
{
  vec<lli> c(a.size());
  iota(c.begin(), c.end(), 0LL);
  for (int _ = 0; _ < N; ++_) {
    // cout << "c" << ":" << c << endl;
    vec<lli> b = c;
    for (int i = 0; i < b.size(); ++i) {
      b[i] = a[b[i]];
    }
    c = b;
  }
  return c;
}

int main(int argc, char *argv[])
{
  if (0) {
    vec<lli> a({2, 3, 4, 4});
    vec<lli> b({3, 4, 4, 4});
    each (i, a) --i;
    vec<lli> c = rot(a, 2);
    each (i, a) ++i;
    each (i, c) ++i;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    assert(c == b);
  }
  vec<lli> p({4, 9, 5, 7, 11, 13, 17, 19, 23});
  sort(p.begin(), p.end());
  if (1) {
    lli x = 1;
    each (i, p) x *= i;
    assert(1e9 <= x);
  }
  while (true) {
    const int M = accumulate(p.begin(), p.end(), 0);
    // assert(M <= 110);
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

    if (0) {
      for (int i = 0; i <= 10; ++i) {
        vec<lli> v = rot(a, i);
        each (i, v) cout << i+1 << ' '; cout << endl;
      }
      {
        vec<lli> v = rot(a, 108);
        each (i, v) cout << i+1 << ' '; cout << endl;
      }
      {
        vec<lli> v = rot(a, 89);
        each (i, v) cout << i+1 << ' '; cout << endl;
      }
      cout << endl;
      return 0;
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
      // cout << j << ' ' << x << ' ' << y <<' ' << (x - y) << endl;
      c.push_back(p[i] - (y - x + p[i]) % p[i]);
    }

    // cout << v << endl;
    // cout << u << endl;
    // cout << w << endl;
    // cout << "a:" << a << endl;
    // cout << "b:" << b << endl;
    // cout << "c: " << c << endl;

    pair<lli, lli> z = ChineseRem(c, p);
    // cout << z << endl;
    cout << z.first % z.second<< endl;
    // break;
  }
  return 0;
}
