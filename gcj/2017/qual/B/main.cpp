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

  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    vector<lli> v(s.begin(), s.end());
    each (i, v) i -= '0';

    const int N = s.size() + 10;
    const int M = 11;
    lli dp[N][M][2];
    fill(&dp[0][0][0], &dp[N - 1][M - 1][2 - 1] + 1, -(1LL << 60));
    dp[0][0][0] = 0;

    for (int nth = 0; nth < s.size(); ++nth) {
      for (int prev = 0; prev < M; ++prev) {
        if (0 <= dp[nth][prev][false]) {
          for (int next = prev; next <= v[nth]; ++next) {
            lli& x = dp[nth + 1][next][next < v[nth]];
            x = max(x, dp[nth][prev][false] * 10LL + next);
          }
        }
        if (0 <= dp[nth][prev][true]) {
          for (int next = prev; next <= 9; ++next) {
            lli& x = dp[nth + 1][next][true];
            x = max(x, dp[nth][prev][true] * 10LL + next);
          }
        }
      }
    }

    lli mx = 0;
    for (int i = 0; i <= 9; ++i) {
      mx = max({mx, dp[s.size()][i][true], dp[s.size()][i][false]});
    }
    static int tc = 0;
    cout << "Case #" << ++tc << ": " << mx << endl;
  }

  return 0;
}
