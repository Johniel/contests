// github.com/Johniel/contests
// atcoder/abc387/C/main.cpp

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

lli fn(const str s)
{
  const int N = 20;
  const int D = 11;
  const int H = D - 1; // 1文字目未定
  lli dp[N][D][2]; // dp[何桁目][1文字目][sより小さい]
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < D; ++j) {
      dp[i][j][false] = dp[i][j][true] = 0;
    }
  }
  dp[0][H][false] = 1;
  for (int i = 0; i < s.size(); ++i) {
    const int p = s[0] - '0';
    const int x = s[i] - '0';
    { // sより小さくない
      if (i == 0) {
        for (int k = 1; k < p; ++k) {
          // k???
          dp[i + 1][k][true] += dp[i][H][false];
        }
        // same as `s`
        dp[i + 1][p][false] += dp[i][H][false];
      } else {
        for (int k = 0; k < min(x, p); ++k) {
          // s[0]s[1]...s[i-1]k???
          dp[i + 1][p][true] += dp[i][p][false];
        }
        // same as `s`
        if (x < p) dp[i + 1][p][false] += dp[i][p][false];
      }
      // 00???
      dp[i + 1][H][true] += dp[i][H][false];
    }
    { // sより小さい
      for (int j = 1; j <= 9; ++j) {
        for (int k = 0; k < j; ++k) {
          dp[i + 1][j][true] += dp[i][j][true];
        }
      }
      for (int k = 1; k <= 9; ++k) {
        // 00..00k???
        dp[i + 1][k][true] += dp[i][H][true];
      }
      // 00???
      dp[i + 1][H][true] += dp[i][H][true];
    }
  }

  lli z = 0;
  for (int i = 0; i < D; ++i) {
    z += dp[s.size()][i][0];
    z += dp[s.size()][i][1];
  }
  return z;
}

int main(int argc, char *argv[])
{
  lli mn, mx;
  while (cin >> mn >> mx) {
    cout << fn(to_string(mx)) - fn(to_string(mn - 1)) << endl;
  }
  return 0;
}
