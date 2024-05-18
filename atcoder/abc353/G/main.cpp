// github.com/Johniel/contests
// atcoder/abc353/G/main.cpp

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
struct SegTree {
  // https://codeforces.com/blog/entry/18051
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  vector<T> v;
  SegTree(size_t n_, T e_, F op_) : e(e_), n(n_), op(op_) {
    assert(op(e, e) == e);
    v.resize(2 * n, e);
  }
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
  inline T operator () (size_t begin, size_t end) const { return query(begin, end); }
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
  lli c;
  while (cin >> n >> c >> m) {
    vec<pair<int, lli>> v(m);
    cin >> v;
    each (i, v) --i.first;

    // 前からと
    // 1C, 2C, 3C ...
    // 後ろから
    // ..., 3C, 2C, 1C

    // dp[i][j] = max{ dp[i - 1][k] + P[i] - C * |j - k| };
    // 1点更新
    // 区間クエリ

    // dp[i][j] = max{ dp[i - 1][k] + P[i] - C * |j - k| };
    // T[i]に対してjとP[i]は固定であることを忘れない。
    // dp[i][j] = max{ dp[i-1][k] - C * |j-k| } + P[i];

    // dp[i-1][k]とC*|j-k|を一緒に扱う方法があれば解決する。
    // |j-k|を場合分けして。
    // j < k
    // dp[i][j] = max{ dp[i-1][k] - C * (k-j) } + P[i];
    // dp[i][j] = max{ dp[i-1][k] - C*k + C*j } + P[i];
    // otherwise
    // dp[i][j] = max{ dp[i-1][k] - C * (j-k) } + P[i];
    // dp[i][j] = max{ dp[i-1][k] - C*j + C*k } + P[i];
    // jは固定だから
    // dp[i][j] = max{ dp[i-1][k] - C*k } + P[i] + C*j;
    // と
    // dp[i][j] = max{ dp[i-1][k] + C*k } + P[i] - C*j;


    // https://github.com/Johniel/contests/blob/master/docs/memo.md
    // が役に立った。ABC351Eと同じ。
    // なぜGができてCができないんだ。
    // このテクニックに名前が欲しい。絶対値の場合分けとでも呼ぶ？

    // 右移動用と左移動用を作ればok

    const lli inf = 1LL << 60;

    // j < k
    // dp[i][j] = max{ dp[i-1][k] - C*k } + P[i] + C*j;
    SegTree<lli> moveR(n, -inf, [] (auto a, auto b) { return max(a, b); });

    // othrewise
    // dp[i][j] = max{ dp[i-1][k] + C*k } + P[i] - C*j;
    SegTree<lli> moveL(n, -inf, [] (auto a, auto b) { return max(a, b); });

    moveR.set(0, 0);
    moveL.set(0, 0);

    lli z = -inf;
    for (int i = 0; i < v.size(); ++i) {
      auto [pos, income] = v[i];
      lli R = income - c * pos + moveR.query(0, pos + 1);
      lli L = income + c * pos + moveL.query(pos, n);
      lli mx = max(R, L);
      moveR.set(pos, mx + c * pos);
      moveL.set(pos, mx - c * pos);
      setmax(z, mx);
    }
    cout << max(z, 0LL) << endl;
  }
  return 0;
}
