// github.com/Johniel/contests
// atcoder/abc326/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

lli fn(vec<lli> v, lli req)
{
  vec<lli> a, b;
  for (int i = 0; i < v.size(); ++i) {
    if (i < v.size() / 2) a.push_back(v[i]);
    else b.push_back(v[i]);
  }

  assert(a.size() <= 20);
  assert(b.size() <= 20);

  // map<lli, lli> m1;
  // for (int bit = 0; bit < (1 << a.size()); ++bit) {
  //   lli x = 0;
  //   for (int i = 0; i < a.size(); ++i) {
  //     if (bit & (1 << i)) x += a[i];
  //     else x -= a[i];
  //   }
  //   m1[x] = bit;
  // }

  map<lli, lli> m2;
  for (int bit = 0; bit < (1 << b.size()); ++bit) {
    lli x = 0;
    for (int i = 0; i < b.size(); ++i) {
      if (bit & (1 << i)) x += b[i];
      else x -= b[i];
    }
    m2[x] = bit;
  }

  for (int bit = 0; bit < (1 << a.size()); ++bit) {
    lli x = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (bit & (1 << i)) x += a[i];
      else x -= a[i];
    }
    lli y = req - x;
    if (m2.contains(y)) return (1LL << a.size()) * m2[y] + bit;
  }


  // each (i, m1) {
  //   lli x = req - i.first;
  //   if (m2.contains(x)) return (1LL << a.size()) * m2[x] + i.second;
  // }
  return -1;
}

int main(int argc, char *argv[])
{
  int n;
  lli dst_x, dst_y;
  while (cin >> n >> dst_x >> dst_y) {
    vec<lli> a(n);
    cin >> a;

    vec<lli> v;
    vec<lli> u;
    for (int i = 0; i < a.size(); ++i) {
      unless (i % 2) v.push_back(a[i]); // y
      else u.push_back(a[i]);
    }

    auto y = fn(v, dst_y);
    auto x = fn(u, dst_x);

    if (x == -1 || y == -1) {
      cout << "No" << endl;
    } else {
      str s(a.size(), '.');
      // positive:=1
      int prev = 1;
      for (int i = 0, j = 0, k = 0; i < s.size(); ++i) {
        unless (i % 2) { // y
          const int curr = !!(y & (1LL << j));
          if (prev) s[i] = (curr ? 'L' : 'R');
          else      s[i] = (curr ? 'R' : 'L');
          prev = curr;
          ++j;
        } else {
          const int curr = !!(x & (1LL << k));
          if (prev) s[i] = (curr ? 'R' : 'L');
          else      s[i] = (curr ? 'L' : 'R');
          prev = curr;
          ++k;
        }
      }
      assert(count(s.begin(), s.end(), '.') == 0);
      cout << "Yes" << endl;
      cout << s << endl;
    }
  }
  return 0;
}
