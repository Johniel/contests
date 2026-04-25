// github.com/Johniel/contests
// atcoder/abc455/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

namespace math {
  // gcd(a,b)を返す。xとyにはax+by=±gcd(a,b)を満たす数を設定する。
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }

  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }
};

template<typename S, typename F>
struct LazySegTree {
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>; // comp(f(x), g(x)):=f(g(x))

  LazySegTree(size_t n_, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : n(n_), op(op_), mapping(mapping_), comp(composition_), e(e_), id(id_), bitceiln(bit_ceil(n_)), h(__builtin_ctz(bitceiln)) {
    // assert(op(e, e) == e);
    // assert(comp(id_, id_) == id_);
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

struct S {
  lli sum;
  lli cost;
  lli len;
};

struct F {
  lli val;
};
bool operator == (F a, F b) { return a.val == b.val; }

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    const int N = 2 * 1e5 + 3;
    LazySegTree<S, F>::op_fn op = [] (S a, S b) {
      S c;
      c.sum = (a.sum + b.sum) % mod;
      c.cost = (a.cost + b.cost + ((a.sum * b.sum) % mod)) % mod;
      c.len = (a.len + b.len) % mod;
      return c;
    };
    LazySegTree<S, F>::mapping_fn mapping = [] (F f, S x) {
      const lli inv2 = math::mod_inverse(2, mod);
      // lli a = (x.sum * (x.len - 1) % mod * f.val) % mod;
      // lli b = x.len * math::mod_pow(f.val, x.len - 1) % mod;
      // lli b = (x.len - 1 + mod) % mod * ((f.val * f.val) % mod) % mod;
      // lli b = (x.len - 1) * ((f.val * f.val) % mod) % mod;
      lli a = (((((x.len - 1 + mod) % mod) * f.val) % mod) * x.sum) % mod;
      lli b = (f.val * f.val) % mod;
      lli c = (((x.len * (x.len - 1 + mod)) % mod) * inv2) % mod;
      (x.cost += (a + (b * c) % mod) % mod) %= mod;
      (x.sum += (x.len * f.val) % mod) %= mod;
      return x;
    };
    LazySegTree<S, F>::composition_fn composition = [] (F a, F b) {
      F c;
      c.val = (a.val + b.val) % mod;
      return c;
    };
    LazySegTree<S, F> seg(n, op, mapping, composition, S{0, 0, 0}, F{0});
    for (int i = 0; i < n; ++i) {
      seg.set(i, S{0, 0, 1});
    }
    while (q--) {
      int begin, end;
      lli a;
      cin >> begin >> end >> a;
      a %= mod;
      --begin;
      seg.apply(begin, end, F{a});
      // for (int i = 0; i < n; ++i) {
      //   auto s = seg.get(i);
      //   cout << s.sum << ' ' << s.cost << ' ' << s.len << endl;
      // }
      auto s = seg.query(begin, end);
      // cout << s.sum << ' ' << s.cost << ' ' << s.len << endl;
      cout << s.cost << endl;
    }
  }
  return 0;
}
