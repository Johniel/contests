// github.com/Johniel/contests
// atcoder/abc265/G/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

struct S {
  lli _0;
  lli _1;
  lli _2;
  lli _10;
  lli _21;
  lli _20;
  S() : _0(0), _1(0), _2(0), _10(0), _21(0), _20(0) {}
  S(int a, int b, int c, int d, int e, int f) : _0(a), _1(b), _2(c), _10(d), _21(e), _20(f) {}
};
struct F {
  int s, t, u;
};
S op(S l, S r)
{
  return S(
    l._0 + r._0,
    l._1 + r._1,
    l._2 + r._2,
    (l._10 + r._10) + (l._1 * r._0),
    (l._21 + r._21) + (l._2 * r._1),
    (l._20 + r._20) + (l._2 * r._0)
    );
}
S e() { return S(0, 0, 0, 0, 0, 0); }
S mapping(F l, S r)
{
  S x;

  {
    if (l.s == 0) x._0 += r._0;
    if (l.s == 1) x._1 += r._0;
    if (l.s == 2) x._2 += r._0;

    if (l.t == 0) x._0 += r._1;
    if (l.t == 1) x._1 += r._1;
    if (l.t == 2) x._2 += r._1;

    if (l.u == 0) x._0 += r._2;
    if (l.u == 1) x._1 += r._2;
    if (l.u == 2) x._2 += r._2;
  }

  {
    lli g[3][3];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        g[i][j] = 0;
      }
    }
    // g[1][0] = r._10;
    // g[2][0] = r._20;
    // g[2][1] = r._21;
    // g[0][1] = r._0 * r._1 - r._10;
    // g[0][2] = r._0 * r._2 - r._20;
    // g[1][2] = r._1 * r._2 - r._21;
    // x._10 = g[l.t][l.s];
    // x._20 = g[l.u][l.s];
    // x._21 = g[l.u][l.t];

    g[l.t][l.s] += r._10;
    g[l.u][l.s] += r._20;
    g[l.u][l.t] += r._21;
    g[l.s][l.t] += r._0 * r._1 - r._10;
    g[l.s][l.u] += r._0 * r._2 - r._20;
    g[l.t][l.u] += r._1 * r._2 - r._21;
    x._10 = g[1][0];
    x._20 = g[2][0];
    x._21 = g[2][1];
  }

  return x;
}
F composition(F l, F r)// lが後。
{
  vec<int> a({l.s, l.t, l.u});
  return F{a[r.s], a[r.t], a[r.u]};

  // vec<int> a({0, 1, 2}), b(3), c(3);
  // b[0] = a[r.s];
  // b[1] = a[r.t];
  // b[2] = a[r.u];
  // c[0] = b[l.s];
  // c[1] = b[l.t];
  // c[2] = b[l.u];
  // return F{c[0], c[1], c[2]};

  // vec<int> a({0, 1, 2}), b(3), c(3);
  // b[r.s] = a[0];
  // b[r.t] = a[1];
  // b[r.u] = a[2];
  // c[l.s] = b[0];
  // c[l.t] = b[1];
  // c[l.u] = b[2];
  // return F{c[0], c[1], c[2]};


  // F z;

  // if (l.s == 0) z.s = r.s;
  // if (l.s == 1) z.s = r.t;
  // if (l.s == 2) z.s = r.u;

  // if (l.t == 0) z.t = r.s;
  // if (l.t == 1) z.t = r.t;
  // if (l.t == 2) z.t = r.u;

  // if (l.u == 0) z.u = r.s;
  // if (l.u == 1) z.u = r.t;
  // if (l.u == 2) z.u = r.u;

  // return z;
}
F id() { return F{0, 1, 2}; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  while (cin >> n >> q) {
    vec<int> a(n);
    cin >> a;

    vec<S> ini;
    {
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) ini.push_back(S(1, 0, 0, 0, 0, 0));
        if (a[i] == 1) ini.push_back(S(0, 1, 0, 0, 0, 0));
        if (a[i] == 2) ini.push_back(S(0, 0, 1, 0, 0, 0));
      }
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);
    while (q--) {
      int op, begin, end, s, t, u;
      cin >> op;
      if (op == 1) {
        cin >> begin >> end;
        --begin;
        auto x = seg.prod(begin, end);
        cout << x._10 + x._20 + x._21 << endl;
      }
      if (op == 2) {
        cin >> begin >> end >> s >> t >> u;
        --begin;
        seg.apply(begin, end, F{s, t, u});
      }
    }
  }

  return 0;
}
