// github.com/Johniel/contests
// atcoder/abc292/H/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

using mint = modint998244353;

using S = lli;
using F = lli;
S op(S l, S r) { return max(l, r); }
S mapping(F l, S r) { return l + r; }
F composition(F l, F r) { return l + r; } // lが後。
S e() { return -(1LL << 60); }
F id() { return 0; }

int main(int argc, char *argv[])
{
  int n, q;
  lli b;
  while (cin >> n >> b >> q) {
    vec<lli> a(n);
    cin >> a;

    // (1/n)*(Σpi)>=B
    // Σpi>=nB

    // 区間add
    // 区間max

    vec<lli> v({0});
    each (i, a) v.push_back(v.back() + i - b);
    v.erase(v.begin());

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    while (q--) {
      int c, x;
      cin >> c >> x;
      --c;
      lli diff = x - a[c];
      a[c] = x;
      seg.apply(c, n, diff);
      int i = seg.max_right(0, [] (S x) { return x < 0; });
      if (i == n) i = n - 1;
      cout << (double)seg.get(i) / (i + 1.0) + b << endl;
    }
  }
  return 0;
}
