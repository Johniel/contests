// github.com/Johniel/contests
// atcoder/practice2/L/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

template<typename S, typename F>
struct LazySegTree {
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>; // comp(f(x), g(x)):=f(g(x))

  LazySegTree(size_t n_, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : n(n_), op(op_), mapping(mapping_), comp(composition_), e(e_), id(id_), bitceiln(bit_ceil(n_)), h(__builtin_ctz(bitceiln)) {
    assert(op(e, e) == e);
    assert(comp(id_, id_) == id_);
    assert(countr_zero(bitceiln) == h);
    value.resize(bitceiln * 2, e);
    lazy.resize(bitceiln, id);
  }

  LazySegTree(vector<S> v, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : LazySegTree(v.size(), op_, mapping_, composition_, e_, id_) {
    for (int i = 0; i < v.size(); ++i) set(i, v[i]);
  }

  void set(size_t i, S x) {
    assert(i < n);
    i += bitceiln;
    push_all(i);
    value[i] = x;
    update_all(i);
    return ;
  }

  S get(size_t i) {
    assert(i < n);
    return push_all(i + bitceiln);
  }

  S query(void) const { return value[1]; }
  S all_prod(void) const { return value[1]; }
  S prod(int l, int r) { return query(l, r); }
  S query(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    l += bitceiln;
    r += bitceiln;
    for (int j = h; 1 <= j; --j) {
      if (has_right_descendant(l, j)) push(l >> j);
      if (has_right_descendant(r, j)) push((r - 1) >> j);
    }
    S resL = e, resR = e;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resL = op(resL, value[l++]);
      if (r & 1) resR = op(value[--r], resR);
    }
    return op(resL, resR);
  }

  void apply(int p, F f) {
    assert(p < n);
    p += bitceiln;
    push_all(p);
    value[p] = mapping(f, value[p]);
    update_all(p);
    return ;
  }

  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n);
    l += bitceiln;
    r += bitceiln;
    for (int j = h; 1 <= j; --j) {
      if (has_right_descendant(l, j)) push(l >> j);
      if (has_right_descendant(r, j)) push((r - 1) >> j);
    }
    for (int a = l, b = r; a < b; a >>= 1, b >>= 1) {
      if (a & 1) apply1(a++, f);
      if (b & 1) apply1(--b, f);
    }
    for (int j = 1; j <= h; ++j) {
      if (has_right_descendant(l, j)) update(l >> j);
      if (has_right_descendant(r, j)) update((r - 1) >> j);
    }
    return ;
  }

  size_t size(void) const { return n; }

  vector<S> value;
  vector<F> lazy;
  const size_t n;
  const size_t bitceiln;
  const int h;
  const op_fn op;
  const composition_fn comp;
  const mapping_fn mapping;
  const S e;
  const F id;

private:
  inline bool has_right_descendant(int k, int depth) const {
    return ((k >> depth) << depth) != k;
  }

  inline bool is_leaf(int k) const { return bitceiln <= k; }

  inline void update(int k) {
    value[k] = op(value[2 * k + 0], value[2 * k + 1]);
    return ;
  }
  inline void update_all(int k) {
    for (int j = 1; j <= h; ++j) update(k >> j);
    return ;
  }

  inline void apply1(int k, F f) {
    value[k] = mapping(f, value[k]);
    if (!is_leaf(k)) lazy[k] = comp(f, lazy[k]);
    return ;
  }

  inline void push(int k) {
    if (lazy[k] != id) {
      apply1(2 * k + 0, lazy[k]);
      apply1(2 * k + 1, lazy[k]);
      lazy[k] = id;
    }
    return ;
  }

  inline S push_all(int k) {
    for (int j = h; 1 <= j; --j) push(k >> j);
    return value[k];
  }
};

using S = pair<lli, pair<lli, lli>>; // 転倒数,0の個数,1の個数
using F = int;
using lazy_segtree = LazySegTree<S, F>;

S op(S a, S b) {
  auto [a0, a1] = a.second;
  auto [b0, b1] = b.second;
  lli inv = (a.first + b.first) + (a1 * b0);
  S c = make_pair(inv, make_pair(a0 + b0, a1 + b1));
  return c;
}

S mapping(F a, S b) {
  if (a) {
    swap(b.second.first, b.second.second);
    lli n = b.second.first * b.second.second;
    b.first = n - b.first;
  }
  return b;
};
F composition(F a, F b) { return a ^ b; };
lazy_segtree seg(2 * 1e5 + 3, op, mapping, composition, make_pair(0, make_pair(0, 0)), 0);

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<int> a(n);
    cin >> a;

    // lazy_segtree::op_fn op = [] (S a, S b) {
    //   auto [a0, a1] = a.second;
    //   auto [b0, b1] = b.second;
    //   lli inv = (a.first + b.first) + (a1 * b0);
    //   S c = make_pair(inv, make_pair(a0 + b0, a1 + b1));
    //   return c;
    // };
    // lazy_segtree::mapping_fn mapping = [] (F a, S b) {
    //   if (a) {
    //     swap(b.second.first, b.second.second);
    //     lli n = b.second.first * b.second.second;
    //     b.first = n - b.first;
    //   }
    //   return b;
    // };
    // lazy_segtree::composition_fn composition = [] (F a, F b) { return a ^ b; };
    // lazy_segtree seg(n, op, mapping, composition, make_pair(0, make_pair(0, 0)), 0);
    for (int i = 0; i < a.size(); ++i) {
      seg.set(i, make_pair(0, make_pair(a[i] == 0, a[i] == 1)));
    }
    while (q--) {
      int op, begin, end;
      cin >> op >> begin >> end;
      --begin;
      if (op == 1) {
        seg.apply(begin, end, 1);
      }
      if (op == 2) {
        cout << seg.query(begin, end).first << endl;
      }
    }
  }

  return 0;
}
