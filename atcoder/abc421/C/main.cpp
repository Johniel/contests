// github.com/Johniel/contests
// atcoder/abc421/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

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

lli fn(str s)
{
  vec<int> v;
  int A = 0;
  int B = 0;
  each (c, s) {
    if (c == 'A') {
      v.push_back(A * 2);
      ++A;
    }
    if (c == 'B') {
      v.push_back(B * 2 + 1);
      ++B;
    }
  }
  // cout << v << endl;

  BIT<lli> bit(v.size());
  lli z = 0;
  each (i, v) {
    z += bit(i, v.size());
    bit.add(i, 1);
  }
  return z;
}

int main(int argc, char *argv[])
{
  int n;
  str s;
  while (cin >> n >> s) {
    str t = s;
    replace(t.begin(), t.end(), 'A', 'C');
    replace(t.begin(), t.end(), 'B', 'A');
    replace(t.begin(), t.end(), 'C', 'B');
    lli x = fn(s);
    lli y = fn(t);
    cout << min(x, y) << endl;
  }
  return 0;
}
