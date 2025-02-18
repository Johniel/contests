// github.com/Johniel/contests
// codeforces/e174/C/main.cpp

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

constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    lli dp[n+1][4];
    for (int i = 0; i < n+1; ++i) {
      for (int j = 0; j < 4; ++j) {
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) dp[i][1] = 1;
    }
    lli s1, s2, s3;
    s1 = s2 = s3 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        // dp[i][1] += s1;
      }
      if (a[i] == 2) {
        dp[i][2] += s1 + s2;
      }
      if (a[i] == 3) {
        dp[i][3] += s2;
      }
      for (int j = 0; j < 4; ++j) dp[i][j] %= mod;
      (s1 += (a[i] == 1)) %= mod;
      (s2 += dp[i][2]) %= mod;
      (s3 += dp[i][2]) %= mod;
    }
    // for (int i = 0; i < n+1; ++i) cout << dp[i][1] << ' ' ; cout << endl;
    // for (int i = 0; i < n+1; ++i) cout << dp[i][2] << ' ' ; cout << endl;
    // for (int i = 0; i < n+1; ++i) cout << dp[i][3] << ' ' ; cout << endl;
    // cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    lli z = 0;
    for (int i = 0; i < n; ++i) {
      (z += dp[i][3]) %= mod;
    }
    cout << z << endl;
    // cout << dp[n-1][3] << endl;
  }
  return 0;
}
