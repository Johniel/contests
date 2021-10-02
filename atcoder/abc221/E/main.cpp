// atcoder/abc221/E/main.cpp
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
constexpr lli mod = 998244353;


#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

using mint = modint998244353;

struct S {
    mint a;
    int size;
};

struct F {
    mint m;
};

S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }

S e() { return S{0, 0}; }

S mapping(F l, S r) { return S{r.a * l.m, r.size}; }

F composition(F l, F r) { return F{r.m * l.m}; }

F id() { return F{1}; }


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 3 * 1e5 + 3;
  static lli w[N];
  w[0] = 1;
  for (int i = 1; i < N; ++i) {
    w[i] = (w[i - 1] * 2) % mod;
  }

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    vec<pair<int, int>> b;
    for (int i = 0; i < a.size(); ++i) {
      b.push_back(make_pair(a[i], i));
    }
    sort(b.begin(), b.end());

    map<lli, int> m;
    int cnt = 0;
    for (int i = 0; i < b.size(); ++i) {
      a[b[i].second] = i;
    }

    vec<int> c(n, 0);
    for (int i = 0; i < b.size(); ++i) {
      c[b[i].second] = i;
    }

    vec<S> ini(n, S{0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);

    mint z = 0;
    for (int i = 0; i < a.size(); ++i) {
      z += seg.prod(0, c[i]).a / mint(2);
      seg.set(c[i], S{1, 1});
      seg.apply(0, n, F{2});
    }
    cout << z.val() << endl;
  }

  return 0;
}
