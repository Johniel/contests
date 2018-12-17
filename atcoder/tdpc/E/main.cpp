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

  int d;
  string s;
  while (cin >> d >> s) {
    const lli mod = 1e9 + 7;
    const int N = 10000 + 5;
    const int D = 100 + 5;

    static lli dp[N][D][2];
    fill(&dp[0][0][0], &dp[N - 1][D - 1][2 - 1] + 1, 0);
    dp[0][0][0] = 1;

    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < d; ++j) {
        for (int k = 0; k < 2; ++k) {
          int y = s[i] - '0';
          for (int x = 0; x <= (k ? 9 : y); ++x) {
            (dp[i + 1][(j + x) % d][k | (x < y)] += dp[i][j][k]) %= mod;
          }
        }
      }
    }

    cout << (dp[s.size()][0][0] + dp[s.size()][0][1] - 1 + mod) % mod << endl;
  }
  
  return 0;
}
