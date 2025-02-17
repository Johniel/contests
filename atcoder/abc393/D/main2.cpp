// github.com/Johniel/contests
// atcoder/abc393/D/main.cpp

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
  // https://codeforces.com/blog/entry/18051
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  vector<T> v;
  SegTree(size_t n_, T e_, F op_) : e(e_), n(n_), op(op_), v(2 * n, e) { assert(op(e, e) == e); }
  SegTree(const vector<T>& v, T e_, F op_) : SegTree(v.size(), e_, op_) {
    for (int i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    assert(k < n);
    for (v[k += n] = a; k > 1; k >>= 1) v[k >> 1] = op(v[k], v[k ^ 1]);
    return ;
  }
  inline T get(size_t k) const { return v.at(k + n); }
  inline T operator () (void) const { return v[1]; }
  inline T operator () (size_t begin, size_t end) { return query(begin, end); }
  inline T all_prod(void) const { return v[1]; }
  inline T query(void) const { return v[1]; }
  inline T prod(size_t begin, size_t end) const { return query(begin, end); }
  T query(size_t l, size_t r) {
    assert(0 <= l && l <= r && r <= n);
    T res = e;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = op(v[l++], res);
      if (r & 1) res = op(res, v[--r]);
    }
    return res;
  }
  size_t size(void) const { return n; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.size(); ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { os << seg.v; return os; }

int main(int argc, char *argv[])
{
  const int N = 5 * 1e5 + 3;
  vec<lli> D(N, 0);
  for (int i = 1; i < N; ++i) {
    D[i] = D[i - 1] + i;
  }

  int n;
  str s;
  while (cin >> n >> s) {
    SegTree<lli> cnt0(s.size(), 0, [] (lli a, lli b) { return a + b; });
    SegTree<lli> cnt1(s.size(), 0, [] (lli a, lli b) { return a + b; });
    SegTree<lli> seg0(s.size(), 0, [] (lli a, lli b) { return a + b; });
    SegTree<lli> seg1(s.size(), 0, [] (lli a, lli b) { return a + b; });
    int last = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        seg0.set(i, i);
        cnt0.set(i, 1);
      }
      if (s[i] == '1') {
        seg1.set(i, i);
        cnt1.set(i, 1);
        last = i;
      }
    }
    const lli inf = (1LL << 61);
    lli mn = inf;
    bool f = false;
    set<int> vis;
    lli z = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        vis.insert(i);
        f = true;
      }
      unless (f) continue;
      if (s[i] == '0') {
        assert(vis.size());
        int j = *vis.begin();
        swap(s[j], s[i]);
        z += abs(j - i);
        vis.erase(j);
        vis.insert(i);
        cnt0.set(i, 0);
        cnt0.set(j, 1);
        seg0.set(i, 0);
        seg0.set(j, j);
        seg1.set(i, i);
        seg1.set(j, 0);
      }

      if (f) {
        const lli cnt = cnt1.query(i + 1, s.size());
        if (i + cnt == last) break;
        unless (i + 1 <= last + 1) break;
        lli w = seg1.query(i + 1, last + 1) - (D[cnt] + cnt * i);
        assert(0 <= w);
        setmin(mn, z + w);
      }
    }
    if (mn == inf) mn = 0;
    cout << mn << endl;
  }
  return 0;
}
