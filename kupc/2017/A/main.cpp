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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    each (i, a) cin >> i;
    const int inf = 1 << 28;
    const int N = 50 + 5;
    const int K = 1000 + 5;
    int dp[N][K];
    fill(&dp[0][0], &dp[N - 1][K - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= K; ++j) {
        {
          int& x = dp[i + 1][min(K, j + a[i])];
          x = min(x, dp[i][j] + 1);
        }
        {
          int& x = dp[i + 1][j];
          x = min(x, dp[i][j]);
        }
      }
    }
    cout << (dp[n][k] == inf ? -1 : dp[n][k]) << endl;
  }
  
  return 0;
}
