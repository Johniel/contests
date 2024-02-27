// github.com/Johniel/contests
// atcoder/abc342/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

template<typename F>
struct DualSegTree {
  DualSegTree(size_t n_, F e_)
    : n(n_), e(e_), bit_ceiled_n(bit_ceil(n_)) {
    lazy.resize(2 * bit_ceiled_n, e);
  }
  void apply(size_t begin, size_t end, pair<int, int> p, int op) {
    assert(0 <= begin && begin < n);
    assert(0 <= end && end <= n);
    assert(begin <= end);
    size_t a = begin + bit_ceiled_n;
    size_t b = end + bit_ceiled_n;
    // push((a >> __builtin_ctz(a)), p, op);
    // push((b >> __builtin_ctz(b)) - 1, p, op);
    for (; a < b; a /= 2, b /= 2 ) {
      if (a & 1) {
        if (op == 1) lazy[a].insert(p);
        else         lazy[a].erase(p);
        ++a;
      }
      if (b & 1) {
        --b;
        if (op == 1) lazy[b].insert(p);
        else         lazy[b].erase(p);
      }
    }
    return ;
  }

  int get(int idx) {
    idx += bit_ceiled_n;
    int mx = -1;
    while (idx) {
      if (lazy[idx].size()) setmax(mx, lazy[idx].rbegin()->first);
      idx /= 2;
    }
    return mx;
  }

  vector<F> lazy;
  const F e;
  const size_t n;
  const size_t bit_ceiled_n;
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    int q;
    cin >> q;

    DualSegTree<set<pair<int, int>>> seg(a.size(), set<pair<int, int>>());
    for (int i = 0; i < a.size(); ++i) {
      // pair<int, int> p = make_pair(a[i], -(i + 1));
      pair<int, int> p = make_pair(a[i], -1);
      seg.apply(i, i + 1, p, 1);
    }

    vec<tuple<int, int, int>> v(q);
    for (int i = 0; i < q; ++i) {
      int op;
      cin >> op;

      // each (i, seg.lazy) cout << i << ' '; cout << endl;

      if (op == 1) {
        int begin, end, x;
        cin >> begin >> end >> x;
        --begin;
        seg.apply(begin, end, make_pair(x, i), 1);
        v[i] = make_tuple(begin, end, x);
      }
      if (op == 2) {
        int i;
        cin >> i;
        --i;
        auto [begin, end, x] = v[i];
        seg.apply(begin, end, make_pair(x, i), 2);
      }
      if (op == 3) {
        int x;
        cin >> x;
        --x;
        cout << seg.get(x) << endl;
      }
    }
    break;
  }
  return 0;
}
