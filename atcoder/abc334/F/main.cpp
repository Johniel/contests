// github.com/Johniel/contests
// atcoder/abc334/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }

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

template<typename S, typename F>
class LazySegTree {
public:
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>; // composition(f(x), g(x)):=f(g(x))

  LazySegTree(int n_, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : size(n_), op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_) {
    n = 1;
    lgn = 0;
    while (n < n_) {
      ++lgn;
      n *= 2;
    }
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

  inline S apply(size_t i, F f) { return apply(i, i + 1, f); }
  S apply(size_t begin, size_t end, F f) {
    assert(begin <= end);
    assert(end <= size);
    return apply(begin, end, f, 0, 0, n);
  }

  void show(int idx = 0, int depth = 0) const {
    if (idx < value.size()) {
      cout << string(depth, ' ') << make_pair(value[idx], lazy[idx]) << endl;
      show(idx * 2 + 1, depth + 2);
      show(idx * 2 + 2, depth + 2);
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
  int n;
  int lgn;
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

template<typename T>
struct SegTree {
  int n;
  const int origin_size;
  vector<T> v;
  using F = function<T(T, T)>;
  const F fn;
  const T e;

  SegTree(int n_, T e_, F fn_) : e(e_), origin_size(n_), fn(fn_) {
    n = 1;
    while (n < n_) n *= 2;
    v.resize(2 * n - 1, e);
  }

  SegTree(const vector<T>& v, T e_, F fn_) : SegTree(v.size(), e_, fn_) {
    for (int i = 0; i < v.size(); ++i) update(i, v[i]);
  }

  void init(const vector<T>& v) {
    assert(origin_size == v.size());
    for (size_t i = 0; i < v.size(); ++i) update(i, v[i]);
    return ;
  }

  void update(size_t k, T a) {
    k += n - 1;
    v[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      v[k] = fn(v[k * 2 + 1], v[k * 2 + 2]);
    }
    return ;
  }

  inline T operator [] (size_t idx) const { return v.at(idx + n - 1); }
  inline T operator () () const { return query(0, origin_size, 0, 0, n); }
  inline T operator () (size_t begin, size_t end) const { return query(begin, end, 0, 0, n); }

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
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.origin_size; ++i) { T t; is >> t; seg.update(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { vector<T> v; for (int i = 0; i < seg.n; ++i) v.push_back(seg[i]); os << v; return os; }

template<typename T>
int max_right(SegTree<T>& seg, const int left, function<bool(T)> pred)
{
  // verified: ABC330E
  assert(left <= seg.size());
  assert(pred(seg.e));
  int small = left;
  int large = seg.size();
  while (small + 1 < large) {
    int mid = (small + large) / 2;
    if (pred(seg(left, mid))) small = mid;
    else large = mid;
  }
  return pred(seg(left, large)) ? large : small;
  // MEX:
  // SegTree<int> seg(N, (1 << 29), [] (auto i, auto j) { return min(i, j); });
  // max_right<int>(seg, 0, [] (int x) { return (0 < x); })
}

double fn(pair<int, int> a, pair<int, int> b) {
  double x = a.first - b.first;
  double y = a.second - b.second;
  return sqrt(x * x + y * y);
}

struct S {
  pair<int, int> src, dst;
  double cost;
  S() : cost(-1) {}
  S(pair<int, int> src_, pair<int, int> dst_, double cost_) : src(src_), dst(dst_), cost(cost_) {}
  S(pair<int, int> p) : src(p), dst(p), cost(0) {}
};

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    pair<int, int> src;
    vec<pair<int, int>> v(n);
    cin >> src >> v;

    LazySegTree<S, S>::op_fn op = [] (auto a, auto b) {
      if (a.cost < b.cost) return a;
      else return b;
    };
    LazySegTree<S, S>::mapping_fn mapping = [] (auto a, auto b) {
      if (a.cost == -1) return b;
      S s;
      s.src = b.src;
      s.dst = a.dst;
      s.cost = b.cost + a.cost + fn(a.src, b.dst);
      return s;
    };
    // composition(f(x), g(x)):=f(g(x))
    LazySegTree<S, S>::composition_fn composition = [] (auto a, auto b) {
      if (a.cost == -1) return b;
      if (b.cost == -1) return a;
      return S(b.src, a.dst, a.cost + b.cost + fn(b.dst, a.src));
    };

    S e;
    e.cost = 1e128;
    LazySegTree<S, S> A(n+3,op, mapping, composition,e,S());

    A.set(0, S(src));
    for (int i = 0; i < n; ++i) {
      auto a = A.query(max(0, i - k + 1), i + 1);
      a.cost += fn(a.dst, src);
      a.cost += fn(v[i], src);
      a.dst = v[i];
      A.set(i + 1, a);
      A.apply(0, i + 1, S(v[i]));
    }
    A.apply(0, n + 3, S(src));
    cout << A.query(max(n - k + 1, 0), n + 1).cost << endl;
  }
  return 0;
}
