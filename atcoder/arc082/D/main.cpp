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

  int n;
  while (cin >> n) {
    vector<int> p(n);
    each (i, p) cin >> i;
    each (i, p) --i;

    const int N = 1e5 + 5;
    int dp[N][2];
    const int inf = 1 << 29;
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);

    dp[0][p[0] == 0] = 0;

    for (int i = 0; i + 1 < n; ++i) {
      if (dp[i][0] < inf) {
        int& x = dp[i + 1][p[i + 1] == i + 1];
        x = min(x, dp[i][0]);
      }
      if (dp[i][1] < inf) {
        int& x = dp[i + 1][0];
        x = min(x, dp[i][1] + 1);
      }
    }

    cout << min(dp[n - 1][0], dp[n - 1][1] + 1) << endl;
  }

  return 0;
}
