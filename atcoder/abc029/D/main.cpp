// atcoder/abc029/D/main.cpp
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

// void fn(string s)
// {
//   const int N = 10 + 2;
//   const int M = 10;
//   const int K = 2;
//   static int dp[N][M][K];
//   fill(&dp[0][0][0], &dp[N - 1][M - 1][K - 1] + 1, -(1 << 29));
//   dp[0][0][false] = 0;
//   for (int i = 0; i < s.size(); ++i) {
//     for (int j = 0; j <= 9; ++j) {
//       for (int k = false; k <= true; ++k) {
//         if (dp[i][j][k] < 0) continue;
//         for (int x = 0; x <= (k ? 9 : s[i] - '0'); ++x) {
//           int& y = dp[i + 1][x][k || (x < s[i] - '0')];
//           setmax(y, 0);
//           y += dp[i][j][k] + (x == 1);
//         }
//       }
//     }
//   }
//   lli sum = 0;
//   for (int i = 0; i <= 9; ++i) {
//     sum += max(0, dp[s.size()][i][false]);
//     sum += max(0, dp[s.size()][i][true]);
//   }
//   cout << sum << endl;
// }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    lli sum = 0;
    lli w = 10;
    for (int _ = 0; _ < 12; ++_) {
      sum += (n / w) * (w / 10);
      lli x = (n % w) - (w / 10) + 1;
      if (0 <= x) {
        sum += min(w / 10, x);
      }
      w *= 10;
    }
    cout << sum << endl;
  }

  return 0;
}
