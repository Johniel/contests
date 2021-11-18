// atcoder/typical90/037/main.cpp
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

struct S { lli value; };
struct F { lli value; };
S op(S l, S r) { return S{max(l.value, r.value)}; }
S e() { return S{-(1LL << 60)}; }
S mapping(F l, S r) { return S{max(l.value, r.value)}; }
F composition(F l, F r) { return F{max(r.value, l.value)}; }
F id() { return F{-(1LL << 60)}; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int w, n;
  while (cin >> w >> n) {
    int l[n], r[n], v[n];
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i] >> v[i];
    }

    const int W = 1e4 + 5;
    using RMQ = lazy_segtree<S, op, e, F, mapping, composition, id>;
    vec<S> ini(W, S{-(1LL << 60)});
    RMQ seg[2] = {RMQ(ini), RMQ(ini)};
    seg[0].apply(0, 1, F{0});

    for (int i = 0; i < n; ++i) {
      int curr = i % 2;
      int next = (curr + 1) % 2;
      seg[next] = seg[curr];
      for (int j = 0; j <= w; ++j) {
        lli x = seg[curr].get(j).value;
        if (j + l[i] <= w && 0 <= x) {
          int begin = j + l[i];
          int end = min(j + r[i], w) + 1;
          seg[next].apply(begin, end, F{x + v[i]});
        }
      }
    }

    cout << max({seg[0].get(w).value, seg[1].get(w).value, -(1LL)}) << endl;
  }

  return 0;
}
