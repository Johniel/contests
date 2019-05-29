// atcoder/tdpc/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    const int N = 1e6 + 5;
    const lli mod = 1e9 + 7;
    static lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, 0);
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
      (dp[i + 1][0] += dp[i][0] + dp[i][1]) %= mod;
      (dp[i + 1][1] += dp[i][0] + dp[i][1]) %= mod;
      int j = i + 1 - k;
      if (0 <= j) {
        (dp[i + 1][1] += mod - dp[j][0]) %= mod;
      }
    }
    cout << dp[n][1] << endl;
  }

  return 0;
}
