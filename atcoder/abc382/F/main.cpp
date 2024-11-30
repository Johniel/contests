// github.com/Johniel/contests
// atcoder/abc382/F/main.cpp

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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

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

int main(int argc, char *argv[])
{
  int h, w, n;
  while (cin >> h >> w >> n) {
    int r[n];
    int c[n];
    int len[n];
    for (int i = 0; i < n; ++i) {
      cin >> r[i] >> c[i] >> len[i];
      --r[i];
      --c[i];
    }

    vec<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
      return r[i] > r[j];
    });

    LazySegTree<int, int>::op_fn op = [] (auto x, auto y) { return max(x, y); };
    LazySegTree<int, int>::mapping_fn mapping = [] (auto x, auto y) { return max(x, y); };
    LazySegTree<int, int>::composition_fn composition = [] (auto x, auto y) { return max(x, y); };
    LazySegTree<int, int> seg(w, op, mapping, composition, 0, 0);
    vec<int> v(n, -(1 << 29));
    // cout << idx << endl;
    each (i, idx) {
      int begin = c[i];
      int end = c[i] + len[i];
      int mx = seg.query(begin, end);
      v[i] = h - mx;
      seg.apply(begin, end, mx + 1);
      // for (int i = 0; i < w; ++i) cout << seg.get(i) << ' '; cout << endl;
    }
    each (i, v) cout << i << endl;
    // break;
  }
  return 0;
}
