// github.com/Johniel/contests
// atcoder/abc360/D/main.cpp

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
  int n;
  lli t;
  str s;
  while (cin >> n >> t >> s) {
    vec<lli> v(n);
    cin >> v;
    vec<pair<lli, int>> idx;
    for (int i = 0; i < v.size(); ++i) {
      idx.push_back(make_pair(v[i], i));
    }
    sort(idx.begin(), idx.end());
    vec<pair<lli, int>> u;
    for (int i = 0; i < idx.size(); ++i) {
      int j = idx[i].second;
      u.push_back(make_pair(v[j] * 10, i));
      u.back().first += (s[j] == '0' ? -1 : +1) * (t * 10 + 1);
    }
    sort(u.begin(), u.end());
    BIT<int> bit(n);
    lli z = 0;
    for (int i = 0; i < u.size(); ++i) {
      z += bit(u[i].second, n);
      bit.add(u[i].second, 1);
    }
    cout << z << endl;
  }
  return 0;
}