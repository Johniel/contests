// github.com/Johniel/contests
// atcoder/arc035/D/main.cpp

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

int main(int argc, char *argv[])
{
  const int N = 4 * 1e5 + 3;
  static double fact[N];
  fact[0] = 0;
  fact[1] = log10(1);
  for (int i = 2; i < N; ++i) {
    fact[i] = fact[i - 1] + log(i);
  }

  int n, q;
  while (cin >> n) {
    vec<pair<int, int>> v(n);

    auto fn = [&] (int i, int j) {
      int dx = abs(v[j].first - v[i].first);
      int dy = abs(v[j].second - v[i].second);
      if (dx == 0 || dy == 0) return 0.0;
      return fact[dx + dy] - fact[dx] - fact[dy];
    };

    cin >> v >> q;
    v.insert(v.begin(), make_pair(0, 0));

    SegTree<double> seg(v.size(), 0, [] (auto a, auto b) { return a + b; });
    for (int i = 1; i < v.size(); ++i) {
      seg.update(i, fn(i, i - 1));
    }

    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int i, x, y;
        cin >> i >> x >> y;
        v[i] = make_pair(x, y);
        seg.update(i, fn(i, i - 1));
        if (i + 1 < v.size()) {
          seg.update(i + 1, fn(i, i + 1));
        }
      }
      if (op == 2) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        auto x = seg.query(a + 1, b + 1);
        auto y = seg.query(c + 1, d + 1);
        cout << (x < y ? "SECOND" : "FIRST") << endl;
      }
    }
  }
  return 0;
}
