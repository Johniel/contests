// atcoder/abc135/D/main.cpp
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

const lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    vector<int> v;
    const lli N = 1e5 + 5;
    const int M = 13;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < M; ++j) {
        if (s[i] == '?') {
          for (int k = 0; k <= 9; ++k) {
            (dp[i + 1][(j * 10 + k) % M] += dp[i][j]) %= mod;
          }
        } else {
          (dp[i + 1][(j * 10 + s[i] - '0') % M] += dp[i][j]) %= mod;
        }
      }
    }
    cout << dp[s.size()][5] << endl;
  }

  return 0;
}
