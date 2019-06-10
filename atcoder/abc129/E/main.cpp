// atcoder/abc129/E/main.cpp
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

  string s;
  while (cin >> s) {
    const int N = 100000 + 5;
    const lli mod = 1e9 + 7;

    lli dp[N][2];
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= s.size(); ++i) {
      if (s[i - 1] == '0') {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = (dp[i - 1][1] * 3) % mod;
      } else {
        dp[i][0] = (dp[i - 1][0] * 2) % mod;
        dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % mod;
      }
    }

    cout << (dp[s.size()][0] + dp[s.size()][1]) % mod << endl;
  }

  return 0;
}
