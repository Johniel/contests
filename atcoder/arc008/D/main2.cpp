// github.com/Johniel/contests
// atcoder/arc008/D/main.cpp

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
struct DynamicSegTree {
  const long long int SIZE = (1LL << 41);
  using F = function<T(T, T)>;
  const F op;
  const T e;
  unordered_map<long long int, T> seg;
  DynamicSegTree(F o, T ie) : op(o), e(ie) {}
  T query(void) { return seg.count(1LL) ? seg[1LL] : e; }
  T query(long long int begin, long long int end) {
    // not verifyed
    assert(begin <= end);
    T res = e;
    auto l = begin + SIZE;
    auto r = end + SIZE;
    for (; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        if (seg.count(l)) res = op(seg[l], res);
        ++l;
      }
      if (r & 1) {
        --r;
        if (seg.count(r)) res = op(res, seg[r]);
      }
    }
    return res;
  }
  T get(long long int idx) {
    assert(idx < SIZE);
    const auto i = idx + SIZE;
    return seg.count(i) ? seg[i] : e;
  }
  void set(long long int idx, T v) {
    assert(idx < SIZE);
    auto i = idx + SIZE;
    seg[i] = v;
    while (i /= 2) {
      const auto l = i * 2;
      const auto r = i * 2 + 1;
      T t = e;
      if (seg.count(l)) t = op(seg[l], t);
      if (seg.count(r)) t = op(t, seg[r]);
      seg[i] = t;
    }
  }
};


#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;
using Real = long double;
// using Real = double;
// using Real = cpp_dec_float_100;

struct S {
  Real a;
  Real b;
};

int main(int argc, char *argv[])
{
  lli n;
  int m;
  while (cin >> n >> m) {
    DynamicSegTree<S>::F op = [] (S l, S r) {
      return S{r.a * l.a, r.a * l.b + r.b};
    };
    DynamicSegTree<S> seg(op, S{1,0});
    Real mn = 1;
    Real mx = 1;
    while (m--) {
      lli p;
      Real a, b;
      cin >> p >> a >> b;
      seg.set(p, S{a, b});
      auto s = seg.query();
      auto x = s.a + s.b;
      if (mn > x) mn = x;
      if (mx < x) mx = x;
      // setmin(mn, x);
      // setmax(mx, x);
    }
    cout << mn << endl;
    cout << mx << endl;
  }
  return 0;
}
