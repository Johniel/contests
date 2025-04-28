// github.com/Johniel/contests
// atcoder/abc403/G/main.cpp

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
// constexpr lli mod = 998244353;

template<typename T>
struct DynamicSegTree {
  using F = function<T(T, T)>;
  const F op;
  const T e;
  unordered_map<long long int, T> seg;
  DynamicSegTree(F o, T ie) : op(o), e(ie) {}
  T query(void) { return seg.count(1) ? seg[1LL] : e; }
  T query(size_t begin, size_t end) {
    // not verifyed
    T res = e;
    auto l = begin + (1LL << 33);
    auto r = end + (1LL << 33);
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
  T get(size_t idx) {
    const auto i = idx + (1LL << 33);
    return seg.count(i) ? seg[i] : e;
  }
  void set(size_t idx, T v) {
    auto i = idx + (1LL << 33);
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

struct S {
  lli even;
  lli odd;
  int size;
  S () : even(0), odd(0), size(0) {}
  S (lli val) : even(0), odd(val), size(1) {}
  S (lli e, lli o, int s) : even(e), odd(e), size(s) {}
};

S op(S a, S b) {
  S c;
  if (a.size % 2) {
    c.odd = a.odd + b.even;
    c.even = a.even + b.odd;
    c.size = a.size + b.size;
  } else {
    c.odd = a.odd + b.odd;
    c.even = a.even + b.even;
    c.size = a.size + b.size;
  }
  return c;
}

int main(int argc, char *argv[])
{
  int q;
  while (cin >> q) {
    DynamicSegTree<S> seg(op, S());
    lli z = 0;
    for (int i = 0; i < q; ++i) {
      lli y;
      cin >> y;
      const lli m = 1e9;
      lli x = ((y + z) % m) + 1;
      S a = seg.get(x);
      S b(x);
      seg.set(x, op(a, b));
      cout << (z = seg.query().odd) << endl;
    }
  }
  return 0;
}
