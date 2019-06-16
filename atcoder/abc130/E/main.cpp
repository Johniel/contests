// atcoder/abc130/E/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<int> s(n);
    vector<int> t(m);
    const int N = 2 * 1000 + 5;
    const lli mod = 1e9 + 7;
    cin >> s >> t;

    static lli dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);

    static lli sum[N][N];
    fill(&sum[0][0], &sum[N - 1][N - 1] + 1, 0);

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size(); ++j) {
        dp[i][j] = 0;
        if (s[i-1] == t[j-1]) {
          dp[i][j] = sum[i - 1][j - 1] + 1;
        }

        sum[i][j] += sum[i - 1][j];
        sum[i][j] += sum[i][j - 1];
        sum[i][j] -= sum[i - 1][j - 1];
        sum[i][j] += mod + dp[i][j];
        sum[i][j] %= mod;
      }
    }

    lli x = 0;
    for (int i = 0; i <= s.size(); ++i) {
      for (int j = 0; j <= t.size(); ++j) {
        x += dp[i][j];
        x %= mod;
      }
    }
    cout << (x + 1) % mod << endl;
  }

  return 0;
}
