// github.com/Johniel/contests
// atcoder/abc386/D/main.cpp

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
  int n, m;
  while (cin >> n >> m) {
    int h[m], w[m];
    char c[m];
    for (int i = 0; i < m; ++i) {
      cin >> h[i] >> w[i] >> c[i];
      --h[i];
      --w[i];
    }
    const int M = 2 * 1e5 + 3;
    for (int _ = 0; _ < 2; ++_) {
      vec<int> v(h, h + m);
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      map<int, int> rename;
      for (int i = 0; i < v.size(); ++i) rename[v[i]] = i;
      for (int i = 0; i < m; ++i) h[i] = rename[h[i]];
      for (int i = 0; i < m; ++i) swap(h[i], w[i]);
    }
    bool f = true;
    for (int _ = 0; _ < 2; ++_) {
      const int inf = (1 << 29);
      auto fn = [] (int x, int y) { return min(x, y); };
      SegTree<int> seg(M, inf, fn);
      map<int, vec<pair<int, char>>> a;
      for (int i = 0; i < m; ++i) {
        a[h[i]].push_back(make_pair(w[i], c[i]));
        if (c[i] == 'W') seg.set(w[i], fn(h[i], seg.get(w[i])));
      }
      each (k, a) {
        sort(k.second.begin(), k.second.end());
        str s;
        each (i, k.second) {
          s += i.second;
          if (i.second == 'B') {
            // cout << make_pair(k.first, i.first) << ' ' << seg.query(0, i.first) << ", " << (i.first <= seg.query(0, i.first)) << endl;
            f = f && (k.first <= seg.query(0, i.first));
          }
        }
        for (int i = 0; i + 1 < s.size(); ++i) {
          if (s[i] == 'W' && s[i + 1] == 'B') f = false;
        }
      }
      for (int i = 0; i < m; ++i) swap(h[i], w[i]);
    }
    cout << (f ? "Yes" : "No") << endl;
    // break;
  }
  return 0;
}
