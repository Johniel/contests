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

int main(int argc, char *argv[])
{
  int n, t;
  while (scanf("%d%d", &n, &t) == 2) {
    const int N = 15;
    double dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    dp[0][0] = t;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (1 < dp[i][j]) {
          double f = dp[i][j] - 1.0;
          dp[i][j] = 1.0;
          dp[i + 1][j] += f / 2;
          dp[i + 1][j + 1] += f / 2;
        }
      }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt += (dp[i][j] == 1.0);
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
