// github.com/Johniel/contests
// atcoder/abc369/F/main.cpp

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
  int h, w, k;
  while (cin >> h >> w >> k) {
    const int H = 2 * 1e5 + 3;
    const int W = 2 * 1e5 + 3;

    map<int, vec<int>> cs;
    set<pair<int, int>> vis;
    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      vis.insert(make_pair(a, b));
      cs[a].push_back(b);
    }
    {
      pair<int, int> p = make_pair(h - 1, w - 1);
      vis.insert(p);
      cs[p.first].push_back(p.second);
    }
    each (i, cs) {
      sort(i.second.begin(), i.second.end());
    }

    map<pair<int, int>, pair<int, int>> path;
    SegTree<pair<int, int>> seg(w, make_pair(-(1<<28), -1), [] (auto a, auto b) { return max(a, b); });
    {
      int acc = 0;
      int prev = 0;
      for (int j = 0; j < w; ++j) {
        const int i = 0;
        pair<int, int> p = make_pair(i, j);
        if (vis.count(p)) {
          ++acc;
          path[p] = make_pair(0, prev);
          prev = j;
        }
        seg.set(j, make_pair(acc, j));
      }
    }

    for (int i = 1; i < h; ++i) {
      each (j, cs[i]) {
        auto a = seg.get(j); // v
        auto b = seg.query(0, j); // >
        auto c = max(a, b);

          auto mx = max(a, b);
          ++mx.first;
          mx.second = j;
          seg.set(j, mx);

        pair<int, int> curr = make_pair(i, j);
        pair<int, int> prev;

        if (a == c) {
          prev = make_pair(i - 1, c.second);
        } else {
          prev = make_pair(i, b.second);
        }
        path[curr] = prev;
      }
    }
    pair<int, int> p = make_pair(h - 1, w - 1);
    vec<pair<int, int>> v;
    while (v.size() < h + w - 2) {
      v.push_back(p);
      if (path.count(p)) p = path[p];
      else --p.first;
      if (p.first < 0) {
        break;
      }
    }
    v.push_back(make_pair(0, 0));
    reverse(v.begin(), v.end());

    str s;
    for (int i = 0; i + 1 < v.size(); ++i) {
      int a = abs(v[i].first - v[i + 1].first);
      int b = abs(v[i].second - v[i + 1].second);
      s += str(b, 'R');
      s += str(a, 'D');
    }
    cout << seg.get(w - 1).first  - 1 << endl;
    cout << s << endl;
    assert(h + w  - 2 == s.size());
  }
  return 0;
}
