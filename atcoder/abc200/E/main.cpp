// atcoder/abc201/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli n, k;
  while (cin >> n >> k) {
    const int M = 5;
    const int N = 3 * 1e6 + 3;
    static lli dp[M][N];
    fill(&dp[0][0], &dp[M - 1][N - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j <= n * i; ++j) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1 + n] -= dp[i][j];
      }
      for (int j = 1; j < N; ++j) {
        dp[i + 1][j] += dp[i + 1][j - 1];
      }
    }

    // for (int i = 0; i < 3; ++i) {
    //   for (int j = 0; j < 15; ++j) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    lli x = -1;
    for (int i = 0; i < N; ++i) {
      if (k <= dp[3][i]) {
        x = i;
        break;
      } else {
        k -= dp[3][i];
      }
    }
    // cout << make_pair(k, x) << endl;
    for (int i = 1; i <= n; ++i) {
      lli a = max<lli>(1, x - i - n);
      lli b = min<lli>(n, x - i - 1);
      unless (0 < a && a <= n) continue;
      unless (0 < b && b <= n) continue;
      // cout << i << ' ' << make_pair(a, b) << " patterns" << endl;
      if ((abs(b - a) + 1) < k) {
        k -= abs(b - a) + 1;
      } else {
        lli j = a + k - 1;
        cout << i << ' ' << j << ' ' << x - (i + j) << endl;
        break;
      }
    }
  }

  return 0;
}
