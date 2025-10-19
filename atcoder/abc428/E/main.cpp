// github.com/Johniel/contests
// atcoder/abc428/E/main.cpp

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

struct EulerTour {
  vector<vector<int>> g;
  vector<int> post;
  vector<int> pre;
  const size_t size;
  EulerTour(size_t sz) : size(sz) { g.resize(sz); }
  void add_edge(size_t src, size_t dst) {
    g[src].push_back(dst);
    g[dst].push_back(src);
  }
  // v={(pre[i],post[i]),}を返却する。
  // preとpostは通し番号
  // iを根とする部分木ならseg.query(v[i].first, v[i].second)
  // i,jまでのパスならseg.query(v[i].first, v[j].first+1)
  // size*2のsegに対して事前にseg.set(v[i].first, val)すること
  vector<pair<int, int>> build(int root = 0) {
    post.resize(size, -1);
    pre.resize(size, -1);
    int ord = 0;
    vector<pair<int, int>> v;
    _rec(root, root, ord);
    for (size_t i = 0; i < size; ++i) {
      v.push_back(make_pair(pre[i], post[i]));
    }
    return v;
  }
  void _rec(int curr, int prev, int& ord) {
    pre[curr] = ord++;
    for (const auto& next: g[curr]) {
      if (next != prev) _rec(next, curr, ord);
    }
    post[curr] = ord++;
  }
};


const int N = 5 * 1e5 + 3;
vec<int> g[N];

LazySegTree<pair<int, int>, int>::op_fn op = [] (pair<int, int> a, pair<int, int> b) { return max(a, b); };
LazySegTree<pair<int, int>, int>::mapping_fn mapping = [] (int f, pair<int, int> x) { x.first += f; return x; };
LazySegTree<pair<int, int>, int>::composition_fn composition = [] (int a, int b) { return a + b; };
LazySegTree<pair<int, int>, int> seg(2 * N, op, mapping, composition, make_pair(-1, -1), 0);
vec<pair<int, int>> v;

void rec(int curr, int prev, int depth)
{
  seg.set(v[curr].first, make_pair(depth, curr));
  each (next, g[curr]) {
    if (next == prev) continue;
    rec(next, curr, depth + 1);
  }
  return ;
}

vec<pair<int, int>> u;
void rec2(int curr, int prev)
{
  u[curr] = seg.query(0, seg.size());
  each (next, g[curr]) {
    if (next == prev) continue;
    seg.apply(0, seg.size(), +1);
    seg.apply(v[next].first, v[next].second, -2);
    rec2(next, curr);
    seg.apply(v[next].first, v[next].second, +2);
    seg.apply(0, seg.size(), -1);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + n, vec<int>());
    EulerTour et(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
      et.add_edge(a, b);
    }
    v = et.build(0);
    // cout << v << endl;
    rec(0, 0, 0);
    u.resize(n);
    rec2(0, 0);
    // cout << u << endl;
    for (int i = 0; i < n; ++i) {
      cout << u[i].second + 1 << endl;
    }
  }
  return 0;
}
