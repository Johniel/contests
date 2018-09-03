#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  while (cin >> a >> b >> c) {
    const int N = 50 + 5;
    const int inf = 1 << 28;
    int dp[N][N][N];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, inf);
    dp[a][b][c] = 0;
    for (int i = 0; i < N - 2; ++i) {
      for (int j = 0; j < N - 2; ++j) {
        for (int k = 0; k < N - 2; ++k) {
          dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + 1);
          dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], dp[i][j][k] + 1);
          dp[i][j + 1][k + 1] = min(dp[i][j + 1][k + 1], dp[i][j][k] + 1);

          dp[i + 2][j][k] = min(dp[i + 2][j][k], dp[i][j][k] + 1);
          dp[i][j + 2][k] = min(dp[i][j + 2][k], dp[i][j][k] + 1);
          dp[i][j][k + 2] = min(dp[i][j][k + 2], dp[i][j][k] + 1);
        }
      }
    }

    int mn = inf;
    for (int i = 0; i < N; ++i) {
      mn = min(mn, dp[i][i][i]);
    }
    cout << mn << endl;
  }
  
  return 0;
}
