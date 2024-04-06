// github.com/Johniel/contests
// codeforces/895div3/E/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

template<typename S, typename F>
class LazySegTree {
public:
  using op_fn = function<S(S, S)>;
  using mapping_fn = function<S(F, S)>;
  using composition_fn = function<F(F, F)>; // composition(f(x), g(x)):=f(g(x))

  LazySegTree(size_t n_, op_fn op_, mapping_fn mapping_, composition_fn composition_, S e_, F id_)
    : n(n_), op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_), bitceiln(bit_ceil(n_)) {
    value.resize(bitceiln * 2, e);
    lazy.resize(bitceiln * 2, id);
  }

  S set(size_t i, S x) {
    assert(i < n);
    get(i);
    i += bitceiln;
    value[i] = x;
    while (1 < i) {
      i /= 2;
      value[i] = op(value.at(i * 2 + 0), value.at(i * 2 + 1));
    }
    return x;
  }

  S get(size_t i) {
    assert(i < n);
    i += bitceiln;
    for (int j = 30; 0 <= j; --j) push(i >> j);
    return value.at(i);
  }

  S query(size_t begin, size_t end) {
    assert(begin <= end);
    assert(end <= n);
    return query(begin, end, 1, 0, bitceiln);
  }
  S prod(size_t begin, size_t end) { return query(begin, end); }

  S query(void) { return query(0, n); };
  S all_prod(void) { return query(0, n); }

  void apply(size_t i, F f) { apply(i, i + 1, f); return ; }
  void apply(size_t begin, size_t end, F f) {
    assert(begin <= end);
    assert(end <= n);
    apply(begin, end, f, 1, 0, bitceiln);
    return ;
  }

  void show(ostream& os, int idx = 1, int indent = 0) const {
    if (idx < value.size()) {
      os << string(indent, ' ') << make_pair(value[idx], lazy[idx]) << endl;
      show(os, idx * 2 + 0, indent + 2);
      show(os, idx * 2 + 1, indent + 2);
    }
    return ;
  }

  size_t size(void) const { return n; }

private:
  vector<S> value;
  vector<F> lazy;
  const int bitceiln;
  const size_t n;

  const op_fn op;
  const composition_fn composition;
  const mapping_fn mapping;
  const S e;
  const F id;

  void push(int k) {
    if(2 * k + 1 < lazy.size()) {
      lazy[2 * k + 0] = composition(lazy[k], lazy[2 * k + 0]);
      lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
    }
    value.at(k) = mapping(lazy.at(k), value.at(k));
    lazy.at(k) = id;
    return ;
  }

  S apply(size_t begin, size_t end, F f, size_t k, size_t l, size_t r) { // kだけ1origin,他は0origin
    push(k);
    if (r <= begin || end <= l) return value[k];

    if (begin <= l && r <= end) {
      lazy[k] = composition(f, lazy[k]);
      push(k);
      return value[k];
    } else {
      S vl = apply(begin, end, f, k * 2 + 0, l, (l + r) / 2);
      S vr = apply(begin, end, f, k * 2 + 1, (l + r) / 2, r);
      return value[k] = op(vl, vr);
    }
  }

  S query(size_t begin, size_t end, size_t k, size_t l, size_t r) { // kだけ1origin,他は0origin
    if (r <= begin || end <= l) return e;
    push(k);

    if (begin <= l && r <= end) {
      return value[k];
    } else {
      S vl = query(begin, end, k * 2 + 0, l, (l + r) / 2);
      S vr = query(begin, end, k * 2 + 1, (l + r) / 2, r);
      return op(vl, vr);
    }
  }
};
template<typename S, typename F> ostream& operator << (ostream& os, LazySegTree<S, F> seg) { seg.show(os); return os; }

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<int> a(n);
    str s;
    cin >> a >> s;
    int q;
    cin >> q;

    using S = pair<int, int>;
    using F = int;
    using lazysegtree = LazySegTree<S, F>;
    lazysegtree::op_fn op = [] (S a, S b) {
      pair<int, int> c = make_pair(0, 0);
      c.first ^= a.first;
      c.first ^= b.first;
      c.second ^= a.second;
      c.second ^= b.second;
      return c;
    };
    lazysegtree::mapping_fn mapping = [] (F a, S b) { if (a) swap(b.first, b.second); return b; };
    lazysegtree::composition_fn composition = [] (F a, F b) { return a ^ b; }; // composition(f(x), g(x)):=f(g(x))
    lazysegtree seg(n, op, mapping, composition, make_pair(0, 0), 0);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') seg.set(i, make_pair(a[i], 0));
      else             seg.set(i, make_pair(0, a[i]));
    }

    vec<int> v;
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int begin, end;
        cin >> begin >> end;
        --begin;
        seg.apply(begin, end, 1);
      }
      if (op == 2) {
        int g;
        cin >> g;
        if (g) v.push_back(seg.query().second);
        else   v.push_back(seg.query().first);
      }
    }
    each (i, v) cout << i << ' '; cout << endl;
  }
  return 0;
}
