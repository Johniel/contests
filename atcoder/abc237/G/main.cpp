// atcoder/abc237/G/main.cpp
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

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

using S = pair<int, int>;
using F = int;
S op(S l, S r) { return S{l.first + r.first, l.second + r.second}; }
S e() { return S{0, 0}; }
S mapping(F f, S r) {
  if (f == -1) return r;
  return S{r.second * f, r.second};
}
F composition(F l, F r)
{
  if (l == -1) return r;
  return l;
}
F id() { return F{-1}; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q, x;
  while (cin >> n >> q >> x) {
    vec<int> v(n);
    cin >> v;
    vec<S> ini;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == x) ini.push_back(S{1, 1});
      else if (v[i] < x) ini.push_back(S{0, 1});
      else if (v[i] > x) ini.push_back(S{2, 1});
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);
    while (q--) {
      int c, l, r;
      cin >> c >> l >> r;
      --l;
      S s = seg.prod(l, r);
      int one  = s.first % 2;
      int two  = (s.first - one) / 2;
      int zero = s.second - one - two;
      if (c == 1) {
        int p = l + zero;
        int q = l + zero + one;
        seg.apply(l, p, F{0});
        seg.apply(p, q, F{1});
        seg.apply(q, r, F{2});
      }
      if (c == 2) {
        int p = l + two;
        int q = l + two + one;
        seg.apply(l, p, F{2});
        seg.apply(p, q, F{1});
        seg.apply(q, r, F{0});
      }
    }
    for (int i = 0; i < n; ++i) {
      if (seg.get(i).first % 2 == 1) {
        cout << i + 1 << endl;
      }
    }
  }

  return 0;
}
