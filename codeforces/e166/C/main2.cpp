// github.com/Johniel/contests
// codeforces/e166/C/main.cpp

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


int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, m;
  while (cin >> n >> m) {
    const int size = n + m + 1;
    vec<lli> a(n + m + 1), b(n + m + 1);
    cin >> a >> b;
    const pair<pair<lli, lli>, int> E = make_pair(make_pair(0, 0), 0);
    SegTree<pair<pair<lli, lli>, int>> segA(size, E, [] (auto a, auto b) {
      lli x = a.first.first + b.first.first;
      lli y = a.first.second + b.first.second;
      int z = a.second + b.second;
      return make_pair(make_pair(x, y), z);
    });
    SegTree<pair<pair<lli, lli>, int>> segB(size, E, [] (auto a, auto b) {
      lli x = a.first.first + b.first.first;
      lli y = a.first.second + b.first.second;
      int z = a.second + b.second;
      return make_pair(make_pair(x, y), z);
    });
    for (int i = 0; i < size; ++i) {
      if (a[i] > b[i]) segA.set(i, make_pair(make_pair(a[i], b[i]), 1));
      if (a[i] < b[i]) segB.set(i, make_pair(make_pair(a[i], b[i]), 1));
    }
    SegTree<lli> sumA(a, 0LL, [] (auto a, auto b) { return a + b; });
    SegTree<lli> sumB(b, 0LL, [] (auto a, auto b) { return a + b; });
    vec<lli> v;
    for (int i = 0; i < size; ++i) {
      auto tmpA = segA.get(i);
      auto tmpB = segB.get(i);
      segA.set(i, E);
      segB.set(i, E);
      sumA.set(i, 0);
      sumB.set(i, 0);
      lli A = -1;
      lli B = -1;
      {
        int small = 0;
        int large = size;
        while (small + 1 < large) {
          int mid = (small + large) / 2;
          if (n <= segA.query(0, mid).second) large = mid;
          else small = mid;
        }
        int x = large;
        if (segA.query(0, small).second == n) x = small;
        auto p = segA.query(0, x);
        if (n == p.second) {
          A = 0;
          A += p.first.first;
          A += sumB.query(0, sumB.size());
          A -= p.first.second;
        }
      }
      {
        int small = 0;
        int large = size;
        while (small + 1 < large) {
          int mid = (small + large) / 2;
          if (m <= segB.query(0, mid).second) large = mid;
          else small = mid;
        }
        int x = large;
        if (segB.query(0, small).second == m) x = small;
        auto p = segB.query(0, x);
        if (m == p.second) {
          B = 0;
          B += p.first.second;
          B += sumA.query(0, sumA.size());
          B -= p.first.first;
        }
      }
      // cout << A << ' ' << B << endl;
      segA.set(i, tmpA);
      segB.set(i, tmpB);
      sumA.set(i, a[i]);
      sumB.set(i, b[i]);
      v.push_back(max(A, B));
    }
    each (i, v) {
      assert(0 <= i);
      cout << i << ' ';
    }
    cout << endl;
    // cout << endl;
  }
  return 0;
}
