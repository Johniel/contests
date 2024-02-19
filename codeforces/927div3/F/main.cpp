// github.com/Johniel/contests
// codeforces/927div3/F/main.cpp

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
  inline T operator [] (size_t idx) const { return get(idx); }
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

template<typename S, typename F>
class LazySegTree {
public:
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>; // composition(f(x), g(x)):=f(g(x))

  LazySegTree(size_t n_, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : size(n_), op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_), n(bit_ceil(n_)) {
    value.resize(n * 2 - 1, e);
    lazy.resize(n * 2 - 1, id);
  }

  void set(size_t i, S x) {
    assert(0 <= i && i < size);
    get(i);
    i += n - 1;
    value[i] = x;
    while (0 < i) {
      i = (i - 1) / 2;
      value[i] = op(value.at(i * 2 + 1), value.at(i * 2 + 2));
    }
    return ;
  }

  inline S get(size_t i) { return query(i, i + 1); }
  inline S query(void) { return query(0, size); };
  S query(size_t begin, size_t end) {
    assert(begin <= end);
    assert(end <= size);
    return query(begin, end, 0, 0, n);
  }
  S prod(size_t begin, size_t end) { return query(begin, end); }
  S all_prod(void) { return query(); }

  inline S apply(size_t i, F f) { return apply(i, i + 1, f); }
  S apply(size_t begin, size_t end, F f) {
    assert(begin <= end);
    assert(end <= size);
    return apply(begin, end, f, 0, 0, n);
  }

  void show(ostream& os, int idx = 0, int depth = 0) const {
    if (idx < value.size()) {
      os << string(depth, ' ') << make_pair(value[idx], lazy[idx]) << endl;
      show(os, idx * 2 + 1, depth + 2);
      show(os, idx * 2 + 2, depth + 2);
    }
    return ;
  }

  int max_right(int i, function<bool(S)> pred) {
    assert(pred(e));
    int small = i;
    int large = size;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (pred(query(i, mid))) small = mid;
      else large = mid;
    }
    // unless (pred(query(i, small))) return i;
    return small;
  }

  int min_left() {
    assert("not implemented");
    return 0;
  }

private:
  vector<S> value;
  vector<F> lazy;
  const int n;
  const size_t size;

  op_fn op;
  composition_fn composition;
  mapping_fn mapping;
  const S e;
  const F id;

  inline void push(int k) {
    if(2 * k + 2 < lazy.size()) {
      lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
      lazy[2 * k + 2] = composition(lazy[k], lazy[2 * k + 2]);
    }
    value[k] = mapping(lazy[k], value[k]);
    lazy[k] = id;
    return ;
  }

  S apply(size_t begin, size_t end, F f, size_t k, size_t l, size_t r) {
    push(k);
    if (r <= begin || end <= l) return value[k];

    if (begin <= l && r <= end) {
      lazy[k] = composition(f, lazy[k]);
      push(k);
      return value[k];
    } else {
      S vl = apply(begin, end, f, k * 2 + 1, l, (l + r) / 2);
      S vr = apply(begin, end, f, k * 2 + 2, (l + r) / 2, r);
      return value[k] = op(vl, vr);
    }
  }

  S query(size_t begin, size_t end, size_t k, size_t l, size_t r) {
    if (r <= begin || end <= l) return e;
    push(k);

    if (begin <= l && r <= end) {
      return value[k];
    } else {
      S vl = query(begin, end, k * 2 + 1, l, (l + r) / 2);
      S vr = query(begin, end, k * 2 + 2, (l + r) / 2, r);
      return op(vl, vr);
    }
  }
};
template<typename S, typename F> ostream& operator << (ostream& os, LazySegTree<S, F> seg) { seg.show(os); return os; }

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first;

    int size = 20;
    if (1) {
      map<int, int> m;
      vec<int> u;
      each (i, v) u.push_back(i.first), u.push_back(i.second);
      sort(u.begin(), u.end());
      u.erase(unique(u.begin(), u.end()), u.end());
      for (int i = 0; i < u.size(); ++i) {
        m[u[i]] = i;
      }
      each (i, v) {
        i.first = m[i.first];
        i.second = m[i.second];
      }
      size = m.size() + 4;
    }

    const int N = 4 * 1e5 + 3;
    const int inf = 1 << 29;
    LazySegTree<int, int> mx(
      size,
      [] (auto a, auto b) { return max(a, b); },
      [] (auto a, auto b) { return max(a, b); },
      [] (auto a, auto b) { return max(a, b); },
      0,
      0);
    LazySegTree<int, int> mn(
      size,
      [] (auto a, auto b) { return min(a, b); },
      [] (auto a, auto b) { return min(a, b); },
      [] (auto a, auto b) { return min(a, b); },
      inf,
      inf);
    for (int i = 0; i < v.size(); ++i) {
      mn.apply(v[i].first, v[i].second, v[i].first);
      mx.apply(v[i].first, v[i].second, v[i].second);
    }
    vec<int> u(size, 0);
    each (i, v) {
      ++u[i.first];
      --u[i.second];
    }
    for (int i = 0; i + 1 < u.size(); ++i) {
      u[i + 1] += u[i];
    }
    SegTree<int> seg(vec<int>(size+4, 0), 0, [] (auto a, auto b) { return max(a, b); });
    for (int i = 0; i < size; ++i) {
      if (u[i] == 0) continue;
      int x = seg.query(0, i+1) + u[i];
      const int ni = mx.get(i);
      int curr = seg.get(ni);
      if (curr < x) {
        seg.set(ni, x);
      }
    }
    cout << seg.all_prod() << endl;
  }
  return 0;
}
