// github.com/Johniel/contests
// atcoder/abc347/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

using mint = modint998244353;
template<int m> ostream& operator << (ostream& os, static_modint<m> x) { os << x.val(); return os; }
template<int m> ostream& operator << (ostream& os, dynamic_modint<m> x) { os << x.val(); return os; }

struct S {
  bool vis;
  lli sum;
};
struct F {
  lli m;
};
S op(S l, S r) { return l; }
S e() { return S{false, 0}; }
S mapping(F l, S r) {
  if (r.vis) r.sum += l.m;
  return r;
} // 区間更新をしないならlを捨てることも考える。
F composition(F l, F r) { return F{r.m + l.m}; } // lが後。
F id() { return F{0}; }
//    vec<S> ini(n, S{0, 1});
//    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);
// https://github.com/atcoder/ac-library/blob/master/document_ja/lazysegtree.md


int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<int> v(q);
    cin >> v;

    const int N = 2 * 1e5 + 3;

    vec<S> ini(N, S{false, 0});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);

    set<int> vis;
    each (i, v) {
      if (vis.count(i)) {
        auto  p = seg.get(i);
        p.vis = false;
        seg.set(i, p);
        vis.erase(i);
      } else {
        auto  p = seg.get(i);
        p.vis = true;
        seg.set(i, p);
        vis.insert(i);
      }
      seg.apply(0, N, F{(lli)vis.size()});
    }
    for (int i = 0; i < n; ++i) {
      cout << seg.get(i + 1).sum << ' ';
    }
    cout << endl;
  }
  return 0;
}
