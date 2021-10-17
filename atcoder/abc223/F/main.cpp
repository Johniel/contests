// atcoder/abc223/F/main.cpp
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
using namespace atcoder;

const lli inf = 1LL << 60;

struct S { lli a; };
struct F { lli m; };
S op(S l, S r) { return S{min(l.a, r.a)}; }
S e() { return S{inf}; }
S mapping(F l, S r) { return S{r.a + l.m}; }
F composition(F l, F r) { return F{r.m + l.m}; }
F id() { return F{0}; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  str s;
  while (cin >> n >> q >> s) {
    vec<int> v;
    v.push_back(0);
    each (c, s) {
      if (c == '(') v.push_back(v.back() + 1);
      if (c == ')') v.push_back(v.back() - 1);
    }
    vec<S> ini;
    each (i, v) ini.push_back(S{i});
    auto seg = lazy_segtree<S, op, e, F, mapping, composition, id>(ini);
    while (q--) {
      int op, a, b;
      cin >> op >> a >> b;
      --a;
      --b;
      if (op == 1) {
        char x = s[a];
        char y = s[b];
        swap(s[a], s[b]);
        // (は+1
        // )は-1

        // 打ち消し
        if (x == '(') seg.apply(a + 1, ini.size(), F{-1});
        if (x == ')') seg.apply(a + 1, ini.size(), F{+1});
        if (y == '(') seg.apply(b + 1, ini.size(), F{-1});
        if (y == ')') seg.apply(b + 1, ini.size(), F{+1});
        // 書き換え
        if (x == '(') seg.apply(b + 1, ini.size(), F{+1});
        if (x == ')') seg.apply(b + 1, ini.size(), F{-1});
        if (y == '(') seg.apply(a + 1, ini.size(), F{+1});
        if (y == ')') seg.apply(a + 1, ini.size(), F{-1});
      }
      if (op == 2) {
        int x = seg.prod(a, b + 1).a - seg.prod(a, a + 1).a;
        int y = seg.prod(b+1, b + 2).a - seg.prod(a, a + 1).a;
        cout << (x == 0 && y == 0 ? "Yes" : "No") << endl;
      }
    }
  }

  return 0;
}
