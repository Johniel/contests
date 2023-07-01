// github.com/Johniel/contests
// atcoder/abc292/H/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

template<typename S, typename F>
class LazySegTree {
public:
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>;

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

  void push(int k) {
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

int main(int argc, char *argv[])
{
  int n, q;
  lli b;
  while (cin >> n >> b >> q) {
    vec<lli> a(n);
    cin >> a;

    vec<lli> v({0});
    each (i, a) v.push_back(v.back() + i - b);
    v.erase(v.begin());

    LazySegTree<lli, lli> seg(
      n,
      [] (lli a, lli b) { return max(a, b); },
      [] (lli a, lli b) { return a + b; },
      [] (lli a, lli b) { return a + b; },
      -(1LL << 60), 0);
    for (int i = 0; i < v.size(); ++i) {
      seg.set(i, v[i]);
    }
    // seg.show();

    while (q--) {
      int c, x;
      cin >> c >> x;
      --c;
      lli diff = x - a[c];
      a[c] = x;
      seg.apply(c, n, diff);
      int i = seg.max_right(0, [] (lli x) { return x < 0; });
      if (i == n) i = n - 1;
      cout << (double)seg.get(i) / (i + 1.0) + b << endl;
      // cout << "i:" << i << ", " << seg.get(i) << endl; seg.show();
    }
  }
  return 0;
}

// 6.000000000000000
// -1,-6,-3,0,2,i:3
// 7.500000000000000
// -1,3,6,9,11,i:1
// 6.333333333333333
// -6,-2,1,4,6,i:2
// 5.400000000000000
// -6,-2,-8,-5,-3,i:4
// 13.333333333333332
// -6,-2,22,25,27,i:2
// 13.333333333333332
// -6,-2,22,25,119,i:2
// 100.000000000000000
// 94,98,122,125,219,i:0
