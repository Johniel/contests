// atcoder/abc249/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n >> mod) {
    const int M = 100;
    const int N = 3000 + 30;
    const int K = 5;

    vec<int> m[K];
    fill(m, m + K, vec<int>());
    for (int i = 1; i <= n; ++i) {
      char buff[10];
      sprintf(buff, "%d", i);
      m[strlen(buff)].push_back(i);
    }

    static lli dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][j] == 0) continue;
        for (int len = 1; len < K; ++len) {
          if (m[len].empty()) continue;
          unless (i + len < N) continue;
          int mx = min(m[len].back(), n - j);
          int mn = m[len].front();
          if (mn <= mx && j + mx + 1 < N) {
            const lli y = i ? ('z' - 'a') : ('z' - 'a' + 1);
            const lli w = dp[i][j] * y % mod;
            // cout << i << ' ' << j << ' ' << len << ", " << make_pair(mn, mx) << ' ' << w << ", ->" << i + len + 1 << ",+" << j+mn << ",-" << j+mx+1 << "*" << dp[i][j] << ' ' << ('z' - 'a' + 1) << ',' << y << endl;
            // cout << mn << ' ' << mx << endl;
            (dp[i + len + 1][j + mn] += w) %= mod;
            dp[i + len + 1][j + mx + 1] = (dp[i + len + 1][j + mx + 1] - w + mod) % mod;
          }
        }
      }
      for (int j = 0; j + 1 < N; ++j) {
        dp[i + 1][j + 1] += dp[i + 1][j];
      }
    }

    // cout << dp[2][3] << endl;

    lli z = 0;
    for (int i = 1; i < n; ++i) {
      // if (dp[i][n]) cout << make_pair(i, n) << ' ' << dp[i][n] << endl;
      (z += dp[i][n]) %= mod;
    }
    cout << z << endl;
    // break;
  }

  return 0;
}
