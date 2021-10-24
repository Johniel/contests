// atcoder/typical90/064/main.cpp
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

using namespace std;
using namespace atcoder;

struct S {
    lli a;
    int size;
};
struct F {
    lli m;
};
S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }
S e() { return S{0, 0}; }
S mapping(F f, S s) { return S{s.a + s.size * f.m, s.size}; }
F composition(F l, F r) { return F{r.m + l.m}; }
F id() { return F{0}; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  while (cin >> n >> q) {
    vec<lli> v(n);
    cin >> v;

    vec<S> ini;
    each (i, v) ini.push_back(S{i, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);

    lli z = 0;
    for (int i = 0; i + 1 < v.size(); ++i) {
      z += abs(v[i] - v[i + 1]);
    }

    while (q--) {
      int a, b, v;
      cin >> a >> b >> v;
      --a;
      --b;
      if (0 <= a - 1)z -= abs(seg.get(a).a - seg.get(a - 1).a);
      if (b + 1 < n) z -= abs(seg.get(b).a - seg.get(b + 1).a);
      seg.apply(a, b + 1, F{v});
      if (0 <= a - 1) z += abs(seg.get(a).a - seg.get(a - 1).a);
      if (b + 1 < n) z += abs(seg.get(b).a - seg.get(b + 1).a);
      cout << z << endl;
    }
  }

  return 0;
}
