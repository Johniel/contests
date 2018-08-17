# atcoder/arc060/C

## Codes
```cpp
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
  int n, a;
  while (cin >> n >> a) {
    int x[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }

    const int N = 53;
    const int SUM = N * 51;
    static lli dp[N][N][SUM];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][SUM - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < SUM; ++k) {
          unless (dp[i][j][k]) continue;
          // choose
          dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
          // ignore
          dp[i + 1][j][k] += dp[i][j][k];
        }
      }
    }
    
    lli s = 0;
    for (int card = 1; card < N; ++card) {
      for (int sum = 0; sum < SUM; ++sum) {
        if (sum % card == 0 && sum / card == a) {
          s += dp[n][card][sum];
        }
      }
    }

    cout << s << endl;
  }
  return 0;
}
```
