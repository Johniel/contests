// github.com/Johniel/contests
// codeforces/e157/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

vec<int> fn(vec<int> a)
{
  const int n = a.size() + 1;
  vec<int> v(30, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 30; ++j) {
      if (i & (1 << j)) ++v[j];
    }
  }
  // cout << v << endl;

  vec<int> b({0});
  each (i, a) b.push_back(b.back() ^ i);
  for (int j = 0; j < 30; ++j) {
    int w = 0;
    for (int i = 0; i < b.size(); ++i) {
      if (b[i] & (1 << j)) ++w;
    }
    if (v[j] != w) {
      each (k, b) k ^= (1 << j);
    }
  }
  return b;
}

int main(int argc, char *argv[])
{
  if (0) {
    while (1) {
      const int len = xorshift() % 10 + 2;
      vec<int> c;
      for (int i = 0; i < len; ++i) c.push_back(xorshift () % 64);
      vec<int> a;
      for (int i = 0; i + 1 < c.size(); ++i) {
        a.push_back(c[i] ^ c[i + 1]);
      }
      vec<int> b = fn(a);
      cout << c << "->" << a << endl;
      cout << b << endl;
      for (int i = 0; i + 1 < b.size(); ++i) {
        assert(a[i] == (b[i] ^ b[i + 1]));
        assert((b[i] ^ b[i + 1]) == (c[i] ^ c[i + 1]));
      }
      assert(set<int>(b.begin(), b.end()).size() == b.size());
    }
  }

  int n;
  while (cin >> n) {
    vec<int> a(n - 1);
    cin >> a;
    vec<int> b = fn(a);
    each (i, b) cout << i << ' '; cout << endl;
    // for (int i = 0; i + 1 < b.size(); ++i) assert(a[i] == (b[i] ^ b[i + 1]));
    // assert(set<int>(b.begin(), b.end()).size() == b.size());
  }
  return 0;
}
