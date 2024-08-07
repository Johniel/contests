// github.com/Johniel/contests
// atcoder/abc342/F/main.cpp

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

template<typename T>
struct SegTree {
  const int n;
  const int origin_size;
  vector<T> v;
  using F = function<T(T, T)>;
  const F fn;
  const T e;
  SegTree(size_t n_, T e_, F fn_) : e(e_), origin_size(n_), fn(fn_), n(bit_ceil(n_)) {
    assert(fn(e, e) == e);
    v.resize(2 * n - 1, e);
  }
  SegTree(const vector<T>& v, T e_, F fn_) : SegTree(v.size(), e_, fn_) {
    for (int i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    k += n - 1;
    v[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      v[k] = fn(v[k * 2 + 1], v[k * 2 + 2]);
    }
    return ;
  }
  inline T get(size_t idx) const { return v.at(idx + n - 1); }
  inline T operator () (void) const { return query(0, origin_size, 0, 0, n); }
  inline T operator () (size_t begin, size_t end) const { return query(begin, end, 0, 0, n); }
  inline T all_prod(void) const { return query(0, origin_size, 0, 0, n); }
  inline T prod(size_t begin, size_t end) const { return query(begin, end, 0, 0, n); }
  inline T query(size_t begin, size_t end) const {
    assert(begin <= end);
    assert(end <= origin_size);
    return query(begin, end, 0, 0, n);
  }
  T query(size_t a, size_t b, size_t k, size_t l, size_t r) const {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return v.at(k);
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return fn(vl, vr);
  }
  size_t size(void) const { return origin_size; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.origin_size; ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { vector<T> v; for (int i = 0; i < seg.n; ++i) v.push_back(seg[i]); os << v; return os; }

template<typename F>
struct DualSegTree {
  // ABC017D,ABC347E
  using composition_fn = function<F(F, F)>; // composition(f(x), g(x)):=f(g(x))
  DualSegTree(size_t n_, composition_fn composition_, F e_)
    : n(n_), composition(composition_), e(e_), bit_ceiled_n(bit_ceil(n_)) {
    lazy.resize(2 * bit_ceiled_n, e);
  }
  void apply(size_t begin, size_t end, F f) {
    assert(0 <= begin && begin < n);
    assert(0 <= end && end <= n);
    assert(begin <= end);
    size_t a = begin + bit_ceiled_n;
    size_t b = end + bit_ceiled_n;
    push((a >> __builtin_ctz(a)));
    push((b >> __builtin_ctz(b)) - 1);
    for (; a < b; a /= 2, b /= 2 ) {
      if (a & 1) {
        lazy[a] = composition(f, lazy[a]);
        ++a;
      }
      if (b & 1) {
        --b;
        lazy[b] = composition(f, lazy[b]);
      }
    }
    return ;
  }
  void set(size_t idx, F f) {
    assert(idx < n);
    push(idx + bit_ceiled_n);
    lazy[idx + bit_ceiled_n] = f;
    return ;
  }
  F get(size_t idx) {
    assert(idx < n);
    push(idx + bit_ceiled_n);
    return lazy[idx + bit_ceiled_n];
  }
  void clear(size_t idx) {
    assert(idx < n);
    get(idx);
    set(idx, e);
    return ;
  }
  size_t size(void) const { return n; } ;
  vector<F> lazy;
  const composition_fn composition;
  const F e;
  const size_t n;
  const size_t bit_ceiled_n;
  void push(size_t idx) {
    int depth = bit_width(idx);
    for (int d = depth - 1; 0 < d; --d) {
      size_t i = idx >> d;
      if (lazy[i] != e) {
        lazy[i * 2 + 0] = composition(lazy[i], lazy.at(i * 2 + 0));
        lazy[i * 2 + 1] = composition(lazy[i], lazy.at(i * 2 + 1));
        lazy[i] = e;
      }
    }
    return ;
  }
};

double fn(int n, int l, int d)
{
  vec<double> dealer(n + 1, 0);
  vec<double> player(n + 1, 0);
  {
    DualSegTree<double> seg(n + d + 1, [] (auto x, auto y) { return x + y; }, 0.0);
    seg.set(0, +1);
    for (int i = 0; i < l; ++i) {
      double sum = seg.get(i);
      seg.apply(i + 1, i + d + 1, sum / d);
    }
    for (int i = l; i <= n && i < seg.size(); ++i) {
      dealer[i] = seg.get(i);
    }
    for (int i = 0; i <= n && seg.size(); ++i) {
      player[i] = seg.get(i);
    }
  }

  SegTree<double> D(dealer, 0.0, [] (auto a, auto b) { return a + b; });
  SegTree<double> P(player.size(), 0.0, [] (auto a, auto b) { return a + b; });

  for (int i = n; 0 <= i; --i) {
    int begin =min<int>(P.size(), i + 1);
    int end = min<int>(P.size(), i + d + 1);
    double x = P.query(begin, end) / d;
    double y = 1.0 - D.query(i, D.size());
    P.set(i, max(x, y));
  }
  return P.get(0);
}

int main(int argc, char *argv[])
{
  for (int n, l, d; cin >> n >> l >> d; cout << fn(n, l, d) << endl) ;
  return 0;
}
