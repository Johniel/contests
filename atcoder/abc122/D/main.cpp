// atcoder/abc122/D/main.cpp
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

  int n;
  while (cin >> n) {
    const int A = 0;
    const int C = 1;
    const int G = 2;
    const int T = 3;

    const lli mod = 1e9 + 7;

    const int N = 100 + 5;
    const int M = 4;
    lli dp[N][M][M][M];
    fill(&dp[0][0][0][0], &dp[N - 1][M - 1][M - 1][M - 1] + 1, 0);
    dp[0][T][T][T] = 1;
    for (int i = 0; i < n; ++i) {
      for (int a = 0; a < M; ++a) {
        for (int b = 0; b < M; ++b) {
          for (int c = 0; c < M; ++c) {
            for (int d = 0; d < M; ++d) {
              if (b == A && c == G && d == C) continue;
              if (b == A && c == C && d == G) continue;
              if (b == G && c == A && d == C) continue;
              if (a == A && c == G && d == C) continue;
              if (a == A && b == G && d == C) continue;
              (dp[i + 1][b][c][d] += dp[i][a][b][c]) %= mod;
            }
          }
        }
      }
    }
    lli sum = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          (sum += dp[n][i][j][k]) %= mod;
        }
      }
    }
    cout << sum << endl;
  }

  return 0;
}
