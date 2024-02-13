// github.com/Johniel/contests
// atcoder/abc340/E/main.cpp

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
template<int m> ostream& operator << (ostream& os, static_modint<m> x) { os << x.val(); return os; }
template<int m> ostream& operator << (ostream& os, dynamic_modint<m> x) { os << x.val(); return os; }

using S = lli;
using F = lli;
S op(S l, S r) { return r + l; }
S e() { return 0; }
S mapping(F l, S r) { return l + r; }
F composition(F l, F r) { return r + l; } // lが後。
F id() { return 0; }
//    vec<S> ini(n, S{0, 1});
//    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);
// https://github.com/atcoder/ac-library/blob/master/document_ja/lazysegtree.md

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<lli> a(n), b(m);
    cin >> a >> b;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    for (int i = 0; i < b.size(); ++i) {
      int x = b[i];
      lli ball = seg.get(x);
      seg.set(x, 0);

      ++x;
      {
        lli mn = min<lli>(a.size() - x, ball);
        seg.apply(x, x + mn, 1);
        ball -= mn;
      }
      {
        lli cycle = ball / a.size();
        seg.apply(0, a.size(), cycle);
        ball -= cycle * a.size();
      }
      {
        seg.apply(0, ball, 1);
      }
    }
    for (int i = 0; i < a.size(); ++i) {
      cout << seg.get(i) << ' ';
    }
    cout << endl;
  }
  return 0;
}
