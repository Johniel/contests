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

  string s;
  int d;
  while (cin >> s >> d) {
    const lli mod = 1e9 + 7;
    const int N = 10000 + 5;
    const int M = 100;
    static lli dp[N][M][2];
    fill(&dp[0][0][0], &dp[N - 1][M - 1][2 - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < d; ++j) {
        for (int k = 0; k < 10; ++k) {
          (dp[i + 1][(j + k) % d][true] += dp[i][j][true]) %= mod;
          if (s[i] - '0' >= k) {
            (dp[i + 1][(j + k) % d][s[i] - '0' > k] += dp[i][j][false]) %= mod;
          }
        }
      }
    }
    lli sum = (dp[s.size()][0][true] + dp[s.size()][0][false]) % mod;
    cout << (sum + mod - 1) % mod << endl;
  }

  return 0;
}
