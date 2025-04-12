// github.com/Johniel/contests
// atcoder/abc401/F/main.cpp

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
size_t n;
size_t bitceiln;
int h;
op_fn op;
composition_fn comp;
mapping_fn mapping;
S e;
F id;

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

// const int N = 2 * 1e5 + 3;

// NOT VERIFIED
struct EulerTour {
  vec<vec<int>> g;
  int root = 0;
  vec<int> post, pre;
  // int post[N];
  // int pre[N];
  int ord;
  int size;
  EulerTour() {}
  void init(int root_, int size_) {
    size = size_;
    root = root_;
    pre.resize(size_);
    post.resize(size_);
    g.resize(size_, vec<int>());
    // fill(g, g + N, vec<int>());
    return ;
  }
  void add_edge(int src, int dst) {
    g[src].push_back(dst);
    g[dst].push_back(src);
    return ;
  }
  vec<pair<int, int>> v;
  void build(void) {
    ord = 0;
    rec(root, root);
    for (int i = 0; i < size; ++i) {
      v.push_back(make_pair(pre[i], post[i]));
    }
    return ;
  }
  void rec(int curr, int prev) {
    pre[curr] = ord++;
    each (next, g[curr]) {
      if (next == prev) continue;
      rec(next, curr);
    }
    post[curr] = ord++;
    return ;
  }


  vec<lli> u;
  void fn(int curr, int prev, LazySegTree<lli, lli>& seg) {
    u[curr] = seg.all_prod();
    // cout << curr+1 << ": ";
    // for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << ' '; cout << endl;
    each (next, g[curr]) {
      if (next == prev) continue;
      int begin = v[next].first;
      int end = v[next].second;
      seg.apply(0, seg.size(), +1);
      seg.apply(begin, end, -2);
      fn(next, curr, seg);
      seg.apply(begin, end, +2);
      seg.apply(0, seg.size(), -1);
    }
    return ;
  }

  void fn0(int curr, int prev, int d)
  {
    u[curr] = d;
    each (next, g[curr]) {
      if (next == prev) continue;
      fn0(next, curr, d + 1);
    }
  }

  void dist(int n)
  {
    build();
    LazySegTree<lli,lli>::op_fn op = [] (lli a, lli b) { return max(a, b); };
    LazySegTree<lli, lli>::mapping_fn mapping = [] (lli a, lli b) { return a + b; };
    LazySegTree<lli, lli>::composition_fn composition = [] (lli a, lli b) { return a + b; };
    LazySegTree<lli, lli> seg(n * 2, op, mapping, composition, -(1<<29), 0);
    u.resize(n, 0);
    fn0(0, 0, 0);
    for (int i = 0; i < u.size(); ++i) seg.set(v[i].first, u[i]);
    fn(0, 0, seg);
  }
};

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
  T operator () (size_t end) const {
    return (*this)(0, end);
  }
  int lower_bound(T x) const {
    return std::lower_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  int upper_bound(T x) const {
    return std::upper_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main(int argc, char *argv[])
{
  lli n1, n2;
  while (cin >> n1) {
    EulerTour e1;
    e1.init(0, n1);
    for (int i = 0; i < n1 - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      e1.add_edge(a, b);
    }
    cin >> n2;
    EulerTour e2;
    e2.init(0, n2);
    for (int i = 0; i < n2 - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      e2.add_edge(a, b);
    }
    e1.dist(n1);
    e2.dist(n2);

    const int mx1 = *max_element(e1.u.begin(), e1.u.end());
    const int mx2 = *max_element(e2.u.begin(), e2.u.end());
    const lli mx = max(mx1, mx2);

    vec<lli> a, b;
    each (i, e1.u) a.push_back(i);
    each (i, e2.u) b.push_back(i);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    PrefixSum<lli> sum1(a);
    PrefixSum<lli> sum2(b);

    lli z = 0;
    lli p = 0;
    for (int i = 0; i < n1; ++i) {
      const lli mx = max(mx1, mx2);
      auto itr = lower_bound(b.begin(), b.end(), mx - (e1.u[i] + 1));
      lli w = (b.end() - itr) * (lli)(e1.u[i] + 1);
      p += (b.end() - itr);
      z += w;
      z += sum2(itr - b.begin(), sum2.size());
    }

    z += (n1 * n2 - p) * mx;
    cout << z << endl;
  }
  return 0;
}
