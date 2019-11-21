/// vjudge/344019/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  while (cin >> tc) {
    while (tc--) {
      string a, b, c;
      cin >> a >> b >> c;

      const int N = 10 + 2;
      static int dp[N][N][N][N];
      fill(&dp[0][0][0][0], &dp[N - 1][N - 1][N - 1][N - 1] + 1, -(1 << 29));
      {
        int x = count(a.begin(), a.end(), '1');
        int y = count(b.begin(), b.end(), '1');
        int z = count(c.begin(), c.end(), '1');
        dp[0][x][y][z] = 0;
      }
      for (int len = 0; len < 10; ++len) {
        for (int i = 0; i <= 10; ++i) {
          for (int j = 0; j <= 10; ++j) {
            for (int k = 0; k <= 10; ++k) {
              for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                  for (int z = 0; z < 2; ++z) {
                    unless (0 <= i - x) continue;
                    unless (0 <= j - y) continue;
                    unless (0 <= k - z) continue;
                    setmax(dp[len + 1][i - x][j - y][k - z], dp[len][i][j][k] + ((x ^ y ^ z) << (9 - len)));
                  }
                }
              }
            }
          }
        }
      }
      string s;
      int x = dp[10][0][0][0];
      // cout << x << endl;
      for (int i = 0; i < 10; ++i) {
        if (x & (1 << i)) s += '1';
       else s += '0';
      }
      reverse(s.begin(), s.end());
      cout << s << endl;
    }
  }

  return 0;
}
