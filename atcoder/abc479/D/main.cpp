// github.com/Johniel/contests
// atcoder/abc479/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

template<typename T>
struct SegTree {
  // https://codeforces.com/blog/entry/18051
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  const int bitceiln;
  vector<T> v;
  SegTree(size_t n_, T e_, F op_) : n(n_), e(e_), op(op_), bitceiln(std::bit_ceil((unsigned int)n)) {
    assert(op(e, e) == e);
    v.resize(2 * bitceiln, e);
  }
  SegTree(const vector<T>& u, T e_, F op_) : SegTree(u.size(), e_, op_) {
    for (int i = 0; i < (int)u.size(); ++i) v[i + bitceiln] = u[i];
    for (int i = bitceiln - 1; i >= 1; --i) v[i] = op(v[2 * i], v[2 * i + 1]);
  }
  void set(size_t k, T a) {
    assert(k < n);
    for (v[k += bitceiln] = a; k >>= 1; v[k] = op(v[k * 2], v[k * 2 + 1])) ;
  }
  T get(size_t k) const { assert(k < n); return v[k + bitceiln]; }
  T operator () (void) const { return v.at(1); }
  T operator () (size_t begin, size_t end) const { return query(begin, end); }
  T query(void) const { return v.at(1); }
  T query(size_t l, size_t r) const {
    assert(0 <= l && l <= r && r <= n);
    T L = e, R = e;
    for (l += bitceiln, r += bitceiln; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, v[l++]);
      if (r & 1) R = op(v[--r], R);
    }
    return op(L, R);
  }
  size_t size(void) const { return n; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (size_t i = 0; i < seg.size(); ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { os << seg.v; return os; }

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<lli> L(n - 1);
    vec<lli> R(n - 1);
    cin >> L >> R;
    const int N = 2 * 1e5 + 3;

    const lli inf = (1LL << 60);
    SegTree<lli> a(L, inf, [] (lli x, lli y) { return min(x, y);  });
    SegTree<lli> b(R, inf, [] (lli x, lli y) { return min(x, y);  });

    // cout << L << endl;
    // cout << R << endl;

    while (q--) {
      int s, t;
      cin >> s >> t;
      --s;
      --t;
      if (s < t) {
        cout << min(R[s], L[s - 1] + b.query(0, s)) << endl;
      }
      if (s > t) {
        cout << min(L[s - 1], R[s] + a.query(s, a.size())) << endl;
      }
      if (s == t) cout << 0 << endl;
    }
  }
  return 0;
}
