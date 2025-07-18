// github.com/Johniel/contests
// atcoder/abc415/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

template<typename T>
struct SegTree {
  // https://codeforces.com/blog/entry/18051
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  const int bitceiln;
  vector<T> v;
  SegTree(size_t n_, T e_, F op_) : e(e_), n(n_), op(op_), bitceiln(__bit_ceil(n)) {
    // assert(op(e, e) == e);
    v.resize(2 * bitceiln, e);
  }
  SegTree(const vector<T>& v, T e_, F op_) : SegTree(v.size(), e_, op_) {
    for (size_t i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    assert(k < n);
    for (v[k += bitceiln] = a; k >>= 1; v[k] = op(v[k * 2], v[k * 2 + 1])) ;
  }
  T get(size_t k) const { assert(k < n); return v[k + bitceiln]; }
  T operator () (void) const { return v.at(1); }
  T operator () (size_t begin, size_t end) { return query(begin, end); }
  T all_prod(void) const { return v.at(1); }
  T query(void) const { return v.at(1); }
  T prod(size_t begin, size_t end) const { return query(begin, end); }
  T query(size_t l, size_t r) {
    assert(0 <= l && l <= r && r <= n);
    T L = e, R = e;
    for (l += bitceiln, r += bitceiln; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, v[l++]);
      if (r & 1) R = op(v[--r], R);
    }
    return op(L, R);
  }
  size_t size(void) const { return n; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (size_t i = 0; i < seg.size(); ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { os << seg.v; return os; }

struct S {
  pair<char, int> left;
  pair<char, int> right;
  int best;
  int len;
};

int main(int argc, char *argv[])
{
  int n, q;
  str s;
  while (cin >> n >> q >> s) {

    S E;
    E.left = make_pair(0, 0);
    E.right = make_pair(0, 0);
    E.best = 0;
    E.len = 0;

    SegTree<S> seg(s.size(), E, [&] (const auto& a, const auto& b) {
      if (a.len == 0) return b;
      if (b.len == 0) return a;

      S c;
      c.len = a.len + b.len;
      c.left = a.left;
      c.right = b.right;

      if (a.len == a.left.second && a.left.first == b.left.first) {
        c.left.second += b.left.second;
      }
      if (b.len == b.right.second && b.right.first == a.right.first) {
        c.right.second += a.right.second;
      }

      int mx = max(a.best, b.best);
      if (a.right.first == b.left.first) {
        setmax(mx, a.right.second + b.left.second);
      }
      setmax(mx, c.right.second);
      setmax(mx, c.left.second);
      c.best = mx;
      return c;
    });

    for (int i = 0; i < s.size(); ++i) {
      S c;
      c.right = make_pair(s[i], 1);
      c.left = make_pair(s[i], 1);
      c.best = 1;
      c.len = 1;
      seg.set(i, c);
    }

    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int idx;
        char x;
        cin >> idx >> x;
        --idx;

        S c;
        c.right = make_pair(x, 1);
        c.left = make_pair(x, 1);
        c.best = 1;
        c.len = 1;
        seg.set(idx, c);
        s[idx] = x;
      }
      if (op == 2) {
        int begin, end;
        cin >> begin >> end;
        --begin;
        auto c = seg.query(begin, end);
        cout << c.best << endl;
      }
    }
  }
  return 0;
}
