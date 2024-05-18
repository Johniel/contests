// github.com/Johniel/contests
// atcoder/abc354/F/main.cpp

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

  int n;
  while (cin >> n) {
    vec<lli> v(n);
    cin >> v;
    const int N = n + 3;

    map<int, int> rename;
    {
      vec<lli> u = v;
      sort(u.begin(), u.end());
      u.erase(unique(u.begin(), u.end()), u.end());
      for (int i = 0; i < u.size(); ++i) {
        rename[u[i]] = i + 1;
      }
      each (i, v) i = rename[i];
      // cout << v << endl;
    }
    // v.insert(v.begin(), 0); v.push_back(N - 1);
    // cout << v << endl;

    vec<int> pref(n, N);
    vec<int> suff(n, N);
    int mx;
    {
      SegTree<pair<int, int>> seg(N, make_pair(-9999, -9999), [] (auto a, auto b) { return max(a, b); });
      seg.set(v[0], make_pair(1, 0));
      for (int i = 0; i < v.size(); ++i) {
        auto p = seg.query(0, v[i]);
        auto [len, idx] = p;
        unless (1 <= len) {
          pref[i] = 0;
          seg.set(v[i], make_pair(1, i));
          continue;
        }
        // cout << p << "<=" << i << ' ' << v[i] << endl;
        pref[i] = len;
        seg.set(v[i], make_pair(len+1, i));
      }
      mx = seg(1, seg.size() - 1).first;
    }

    {
      SegTree<pair<int, int>> seg(N, make_pair(-9999, -9999), [] (auto a, auto b) { return max(a, b); });
      seg.set(v[n - 1], make_pair(1, n - 1));
      for (int i = v.size() - 1; 0 <= i; --i) {
        auto p = seg.query(v[i] + 1, N);
        auto [len, idx] = p;
        unless (1 <= len) {
          suff[i] = 0;
          seg.set(v[i], make_pair(1, i));
          continue;
        }
        suff[i] = len;
        seg.set(v[i], make_pair(len+1, i));
      }
    }

    // cout << mx << endl;
    // cout << pref << endl;
    // cout << suff << endl;
    // for (int i = 0; i < pref.size(); ++i) {
    //   cout << pref[i] << "+" << suff[i] << "=" << pref[i] + suff[i] << endl;
    // }

    vec<int> u;

    for (int i = 0; i < v.size(); ++i) {
      if (pref[i] + suff[i] + 1 == mx) u.push_back(i);
    }

    cout << u.size() << endl;
    each (i, u) cout << i+1 << ' '; cout << endl;
    // break;
  }
  return 0;
}
