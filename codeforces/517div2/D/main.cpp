#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = max<T>(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = min<T>(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    char g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    map<int, vector<pair<int,int>>> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        m[i + j].push_back({i, j});
      }
    }

    const int N = 2000 + 10;
    static int dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    dp[0][0] = (g[0][0] == 'a') + k;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i + 1 < n) setmax(dp[i + 1][j], dp[i][j] - (g[i + 1][j] != 'a'));
        if (j + 1 < n) setmax(dp[i][j + 1], dp[i][j] - (g[i][j + 1] != 'a'));
      }
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][j]) setmax(mx, i + j + 1);
      }
    }
    if (mx == 0) dp[0][0] = -1;

    string s(mx, 'a');
    if (mx == 0) s[0] = g[0][0];
    for (int i = mx - 1; ; ++i) {
      each (j, m[i]) {
        if (dp[j.first][j.second]) {
          if (j.first + 1 < n) dp[j.first + 1][j.second] = -1;
          if (j.second + 1 < n) dp[j.first][j.second + 1] = -1;
        }
      }

      char mn = 'z' + 1;
      each (j, m[i + 1]) {
        if (dp[j.first][j.second]) {
          mn = min(mn, g[j.first][j.second]);
        }
      }
      if (mn == 'z' + 1) break;
      s += mn;
      each (j, m[i + 1]) {
        if (dp[j.first][j.second] && g[j.first][j.second] != mn) {
          dp[j.first][j.second] = 0;
        }
      }
    }
    cout << s << endl;
  }

  return 0;
}
