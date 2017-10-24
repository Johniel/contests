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

  string s;
  while (cin >> s) {
    const int N = 5000 + 10;
    const int inf = 1 << 29;
    int dp[N][3];
    fill(&dp[0][0], &dp[N - 1][3 - 1] + 1, 0);

    for (int i = 0; i < s.size(); ++i) {
      { // Aba
        int& x = dp[i + 1][0];
        int& y = dp[i + 1][1];
        x = max(x, dp[i][0] + (s[i] == 'a'));
        y = max(y, dp[i][0] + (s[i] == 'b'));
      }
      { // aBa
        int& x = dp[i + 1][1];
        int& y = dp[i + 1][2];
        x = max(x, dp[i][1] + (s[i] == 'b'));
        y = max(y, dp[i][1] + (s[i] == 'a'));
      }
      { // abA
        int& x = dp[i + 1][2];
        x = max(x, dp[i][2] + (s[i] == 'a'));
      }
    }
    
    int mx = 0;
    for (int i = 0; i < N; ++i) {
      mx = max(mx, dp[i][0]);
      mx = max(mx, dp[i][1]);
      mx = max(mx, dp[i][2]);
    }
    cout << mx << endl;
  }
  
  return 0;
}
