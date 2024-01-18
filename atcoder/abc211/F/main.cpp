// github.com/Johniel/contests
// atcoder/abc211/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
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
  int n;
  while (cin >> n) {
    vec<vec<pair<int, int>>> vs;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      vec<pair<int, int>> v(m);
      cin >> v;
      vs.push_back(v);
    }
    int q;
    cin >> q;
    vec<pair<int, int>> w(q);
    cin >> w;

    each (v, vs) each (i, v) {
      i.first *= 2;
      i.second *= 2;
    }
    each (i, w) {
      i.first = i.first * 2;
      i.second = i.second * 2;
    }

    const auto tmp = w;
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    map<int, vec<pair<int, int>>> add;
    map<int, vec<pair<int, int>>> sub;

    each (v, vs) {
      int src = 0;
      for (int i = 0; i < v.size(); i += 2) {
        if (v[src].first > v[i].first) src = i;
      }

      const bool is_asc = (v[src].second < v[(src + 1) % v.size()].second);
      for (int k = 0; k < v.size(); k += 2) {
        int i = (k + src) % v.size();
        int j = (i + 1) % v.size();
        assert(v[i].first == v[j].first);
        int x = v[i].first;
        int mny = min(v[i].second, v[j].second);
        int mxy = max(v[i].second, v[j].second);
        if ((v[i].second < v[j].second) == is_asc) {
          add[x].push_back(make_pair(mny, mxy));
        } else {
          sub[x].push_back(make_pair(mny, mxy));
        }
      }
    }

    const int X = 2 * 1e5 + 3;
    const int Y = 2 * 1e5 + 3;
    using S = int;
    using F = int;
    using lazy_segtree = LazySegTree<S, F>;
    lazy_segtree::op_fn op = [] (S a, S b) { return a + b; };
    lazy_segtree::mapping_fn mapping = [] (F a, S b) { return a + b; };
    lazy_segtree::composition_fn composition = [] (F a, F b) { return a + b; };
    lazy_segtree seg(Y, op, mapping, composition, 0, 0);

    map<pair<int, int>, int> ans;
    for (int x = 0; x < X; ++x) {
      if (add.count(x)) {
        each (i, add[x]) {
          seg.apply(i.first, i.second, +1);
        }
      }
      if (sub.count(x)) {
        each (i, sub[x]) {
          seg.apply(i.first, i.second, -1);
        }
      }
      while (w.size() && w.back().first == x) {
        ans[w.back()] = seg.get(w.back().second);
        w.pop_back();
      }
    }
    each (i, tmp) cout << ans[i] << endl;
  }
  return 0;
}
