// github.com/Johniel/contests
// atcoder/practice2/J/main.cpp

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
struct DynamicSegTree {
  using F = function<T(T, T)>;
  const F op;
  const T e;
  unordered_map<long long int, T> seg;
  DynamicSegTree(F o, T ie) : op(o), e(ie) {}
  T query(void) { return seg.count(1) ? seg[1LL] : e; }
  T query(size_t begin, size_t end) {
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

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<int> a(n);
    cin >> a;
    const int inf = 1 << 29;
    DynamicSegTree<pair<int, int>> seg([] (auto x, auto y) {
      if (x.first == y.first) {
        return x.second > y.second ? x : y;
      }
      return max(x, y);
    },make_pair(-inf, -inf));
    for (int i = 0; i < a.size(); ++i) {
      seg.set(i, make_pair(a[i], i));
    }
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        int idx, val;
        cin >> idx >> val;
        --idx;
        seg.set(idx, make_pair(val, idx));
      }
      if (t == 2) {
        int begin, end;
        cin >> begin >> end;
        --begin;
        cout << seg.query(begin, end).first << endl;
      }
      if (t == 3) {
        int begin, lowerbound;
        cin >> begin >> lowerbound;
        --begin;
        int small = begin;
        int large = n;
        while (small + 1 < large) {
          int mid = (small + large) / 2;
          if (lowerbound <= seg.query(begin, mid).first) large = mid;
          else small = mid;
        }
        if (lowerbound <= seg.query(begin, large).first) cout << large << endl;
        else cout << n+1 << endl;
      }
    }
  }
  return 0;
}
