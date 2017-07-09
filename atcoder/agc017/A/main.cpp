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

  int n, p;
  while (cin >> n >> p) {
    vector<int> a(n);
    each (i, a) cin >> i;

    const int N = n + 1;
    lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, 0);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
      dp[i + 1][(0 + a[i]) % 2] += dp[i][0];
      dp[i + 1][(1 + a[i]) % 2] += dp[i][1];

      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
    }

    cout << dp[n][p] << endl;
  }
  
  return 0;
}
