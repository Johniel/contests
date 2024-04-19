// github.com/Johniel/contests
// atcoder/abc020/D/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;


// 1以上n以下でxと互いに素な数の総和%mod
lli sum_coprime(int n, int x, const lli mod)
{
  if (x == 1) return lli(n) * (n + 1) / 2;
  vec<lli> pf;
  for (lli i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      pf.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x != 1) pf.push_back(x);
  lli z = 0;
  for (int bit = 0; bit < (1 << pf.size()); ++bit) {
    lli y = 1;
    for (int i = 0; i < pf.size(); ++i) {
      if (bit & (1 << i)) y *= pf[i];
    }
    lli m = (n / y) % mod;
    lli s = (m * (m + 1) / 2) % mod * y % mod;
    if (__builtin_popcount(bit) % 2) {
      z = (z - s + mod) % mod;
    } else {
      (z += s) %= mod;
    }
  }
  return z;
}

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    vec<lli> v;
    for (lli i = 1; i * i <= k; ++i) {
      if (k % i == 0) {
        v.push_back(i);
        v.push_back(k / i);
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());


    lli z = 0;
    each (y, v) {
      lli w = sum_coprime(n / y, k / y, mod);
      (z += w * k % mod) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
