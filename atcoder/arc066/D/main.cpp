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
  lli n;
  while (cin >> n) {
    const int N = 70;
    const int M = 20;
    const lli mod = 1e9 + 7;
    lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    dp[0][0] = 1;

    // cout << ">>>> " << n << endl;

    vector<int> v;
    for (lli i = 1; i <= n; i *= 2LL) {
      v.push_back((bool)(n & i));
    }
    reverse(v.begin(), v.end());

    for (int nth = 0; nth < v.size(); ++nth) {
      for (int i = 0; i < 3; ++i) {
        for (int a = 0; a < 2; ++a) {
          for (int b = 0; b < 2; ++b) {
            if (a && !b) continue;
            const int j = i * 2 + v[nth] - a - b;
            if (0 <= j) {
              (dp[nth + 1][min(j, 2)] += dp[nth][i]) %= mod;
            }
          }
        }
      }
    }
    lli sum = dp[v.size()][0] + dp[v.size()][1] + dp[v.size()][2];
    sum %= mod;
    cout << sum << endl;
  }
  return 0;
}
