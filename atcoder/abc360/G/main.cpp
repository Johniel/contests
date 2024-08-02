// github.com/Johniel/contests
// atcoder/abc360/G/main.cpp

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

template<typename T>
struct RollbackSegTree {
  // ABC360G
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  vector<T> v;
  vector<pair<int, T>> history;
  RollbackSegTree(size_t n_, T e_, F op_) : e(e_), n(n_), op(op_), v(2 * n, e) { assert(op(e, e) == e); }
  RollbackSegTree(const vector<T>& v, T e_, F op_) : RollbackSegTree(v.size(), e_, op_) {
    for (int i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    assert(k < n);
    history.push_back(make_pair(k, get(k)));
    for (v[k += n] = a; k > 1; k >>= 1) v[k >> 1] = op(v[k], v[k ^ 1]);
    return ;
  }
  void rollback(void) {
    assert(history.size());
    set(history.back().first, history.back().second);
    history.pop_back();
    history.pop_back();
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    if (n == 1 || n == 2) {
      cout << n << endl;
      continue;
    }

    {
      vec<int> b = a;
      sort(b.begin(), b.end());
      b.erase(unique(b.begin(), b.end()), b.end());
      int x = 1;
      map<int, int> m;
      for (int i = 0; i < b.size(); ++i) {
        if (i) {
          if (b[i - 1] + 1 == b[i]) m[b[i]] = x;
          else m[b[i]] = ++x;
          ++x;
        } else {
          m[b[i]] = x++;
        }
      }
      each (i, a) i = m[i];
    }

    const int N = 4 * 1e5 + 3;
    const int inf = 1LL << 28;

    RollbackSegTree<int> pref(N, -inf, [] (auto a, auto b) { return max(a, b); });
    RollbackSegTree<int> suff(N, -inf, [] (auto a, auto b) { return max(a, b); });

    int z = 2;

    for (int i = 0; i < a.size(); ++i) {
      int x = pref.query(0, a[i]);
      int mx = max(x + 1, 1);
      pref.set(a[i], mx);
      setmax(z, mx + (i + 1 != a.size()));
    }
    setmax(z, pref.query());

    pref.rollback();
    for (int i = a.size() - 1; 0 < i; --i) {
      int x = suff.query(a[i] + 1, suff.size());
      int mx = max(x + 1, 1);
      suff.set(a[i], mx);
      setmax(z, mx + !!i);

      pref.rollback();
      int y = pref.query(0, max(a[i] - 1, 0));
      setmax(z, mx + y + 1);
    }

    cout << z << endl;
  }
  return 0;
}
