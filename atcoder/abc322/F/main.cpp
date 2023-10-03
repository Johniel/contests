// github.com/Johniel/contests
// atcoder/abc322/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (const auto p = make_pair(_i, c.at(_i)); true)
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

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

using mint = modint998244353;

struct S {
  int len;
  array<int, 2> r, l, mx;
  S() {
    len = 0;
    fill(r.begin(), r.end(), 0);
    fill(l.begin(), l.end(), 0);
    fill(mx.begin(), mx.end(), 0);
  }
};
struct F { int flip; };
S op(S l, S r)
{
  S merged;
  merged.len = l.len + r.len;
  for (int i = 0; i < 2; ++i) {

    // |00000|00111|
    // |00001|00111|
    if (l.len == l.l[i]) {
      merged.l[i] = r.l[i] + l.len;
    } else {
      merged.l[i] = l.l[i];
    }

    // |11100|00000|
    // |11100|01000|
    if (r.len == r.r[i]) {
      merged.r[i] = l.r[i] + r.len;
    } else {
      merged.r[i] = r.r[i];
    }
  }
  merged.mx[0] = max({r.mx[0], l.mx[0], l.r[0] + r.l[0]});
  merged.mx[1] = max({r.mx[1], l.mx[1], l.r[1] + r.l[1]});
  return merged;
}
S e() { return S(); }
S mapping(F l, S r) {
  if (l.flip) {
    swap(r.r[0], r.r[1]);
    swap(r.l[0], r.l[1]);
    swap(r.mx[0], r.mx[1]);
  }
  return r;
}
F composition(F l, F r) { return F{r.flip ^ l.flip}; } // lが後。
F id() { return F{0}; }

int main(int argc, char *argv[])
{
  int n, q;
  str s;
  while (cin >> n >> q >> s) {
    vec<S> ini;
    each (c, s) {
      S t;
      int k = (c - '0');
      t.len = 1;
      t.l[k] = t.r[k] = 1;
      t.mx[k] = 1;
      ini.push_back(t);
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);
    while (q--) {
      int op, begin, end;
      cin >> op >> begin >> end;
      --begin;
      if (op == 1) {
        seg.apply(begin, end, F{1});
      }
      if (op == 2) {
        auto x = seg.prod(begin, end);
        cout << x.mx[1] << endl;
      }
    }
  }
  return 0;
}
