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
    vector<int> a(n);
    each (i, a) cin >> i;
 
    map<int, int> no;
    each (i, a) {
      if (no.count(i) == 0) {
        int x = no.size();
        no[i] = x;
      }
    }
    each (i, a) {
      i = no[i];
    }
 
    const int N = 100 + 10;
    int dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 1 << 28);
    dp[0][N - 1] = 0;
 
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < 100; ++k) {
          if (j != k) {
            dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + (k != a[i]));
          }
        }
      }
    }
 
    int mn = 1 << 28;
    for (int i = 0; i < N; ++i) {
      mn = min(mn, dp[n][i]);
    }
    cout << mn << endl;
  }
  
  return 0;
}
