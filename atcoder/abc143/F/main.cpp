// github.com/Johniel/contests
// atcoder/abc143/F/main.cpp

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
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
  T operator () (size_t end) const {
    return (*this)(0, end);
  }
  int lower_bound(T x) const {
    return std::lower_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  int upper_bound(T x) const {
    return std::upper_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    const int N = 3 * 1e5 + 3;
    vec<int> freq(N, 0);
    each (i, a) ++freq[i];
    vec<int> freqfreq(N, 0);
    for (int i = 0; i < freq.size(); ++i) {
      ++freqfreq[freq[i]];
    }

    vec<int> mff = freqfreq;
    for (int i = 0; i < mff.size(); ++i) {
      mff[i] *= i;
    }
    PrefixSum<int> b(mff);
    PrefixSum<int> c(freqfreq);

    vec<int> r(n+1, 0);
    for (int x = 1; x <= n; ++x) {

      // int s = 0;

      // for (int m = 0; m <= n; ++m) {
      //   s += min(freq[m], x);
      // }

      // for (int m = 0; m <= n; ++m) {
      //   s += min(m, x) * freqfreq[m];
      // }

      // for (int m = 0; m < x; ++m) {
      //   s += m * freqfreq[m];
      // }
      // for (int m = x; m <= n; ++m) {
      //   s += x * freqfreq[m];
      // }

      // x個取り出す
      int s = b(0, x + 1) + x * c(x + 1, N);
      int len = s / x;
      r[len] = x;
    }
    for (int i = n; 0 < i; --i) {
      setmax(r[i - 1], r[i]);
    }
    for (int i = 1; i < r.size(); ++i) {
      cout << r[i] << endl;
    }
    // cout << endl;
  }
  return 0;
}
