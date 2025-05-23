// github.com/Johniel/contests
// atcoder/abc405/F/main.cpp

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

template<typename T = long long int>
struct BIT {
  vector<T> v;
  const int n;

  BIT(int n_ = 0) : n(n_), v(n_ + 1, 0) {}

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      s += v.at(i);
      i -= i & -i;
    }
    return s;
  }

  T query(int begin, int end) const {
    assert(begin <= end);
    return (*this)(end) - (*this)(begin);
  }

  T operator () (int begin, int end) const {
    return query(begin, end);
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v.at(i) += x;
      i += i & -i;
    }
    return ;
  }

  size_t lower_bound(const T query) const {
    int small = 0;
    int large = v.size();
    while (small + 1 < large) {
      auto mid = (small + large) / 2;
      if ((*this)(mid) <= query) small = mid;
      else large = mid;
    }
    if (query <= (*this)(small)) return small;
    if (query <= (*this)(large)) return large;
    return size();
  }

  size_t size(void) const { return n; }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first, --i.second;
    int q;
    cin >> q;
    vec<pair<int, int>> u(q);
    cin >> u;
    each (i, u) --i.first, --i.second;
    // for (int i = 0; i < u.size(); ++i) {
    //   rev[]
    // }

    vec<vec<int>> w;
    const int BEGIN = 0;
    const int END = 1;
    const int V = 0;
    const int U = 1;
    for (int i = 0; i < v.size(); ++i) {
      w.push_back({v[i].first, V, BEGIN, i});
      w.push_back({v[i].second, V, END, i});
    }
    for (int i = 0; i < u.size(); ++i) {
      w.push_back({u[i].first, U, BEGIN, i});
      w.push_back({u[i].second, U, END, i});
    }
    sort(w.begin(), w.end());
    vec<lli> a(q, 0);

    const int N = 2 * 1e6 + 3;
    {
      BIT<lli> bit(N);
      int x = 0;
      each (t, w) {
        int idx = t[0];
        int type = t[1];
        int kind = t[2];
        int j = t[3];
        if (type == V) {
          if (kind == BEGIN) bit.add(v[j].first, +1);
          if (kind == END)   bit.add(v[j].first, -1);
        }
        if (type == U) {
          if (kind == END) {
            a[j] += bit.query(u[j].first, u[j].second + 1);
          }
        }
      }
    }
    {
      BIT<lli> bit(N);
      int x = 0;
      each (t, w) {
        int idx = t[0];
        int type = t[1];
        int kind = t[2];
        int j = t[3];
        if (type == V) {
          if (kind == BEGIN) bit.add(v[j].second, +1);
          if (kind == END)   bit.add(v[j].second, -1);
        }
        if (type == U) {
          if (kind == BEGIN) {
            a[j] += bit.query(u[j].first, u[j].second + 1);
          }
        }
      }
    }

    each (i, a) cout << i << endl;
    // break;
  }
  return 0;
}
