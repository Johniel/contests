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

  int n;
  lli small, large;
  while (cin >> n >> small >> large) {
    int rem[3];

    rem[0] = large / 3;
    rem[1] = large / 3;
    rem[2] = large / 3;
    if (large % 3 == 0) {
    } else if (large % 3 == 1) {
      ++rem[1];
    } else if (large % 3 == 2) {
      ++rem[1];
      ++rem[2];
    }

    int s = small - 1;
    rem[0] -= s / 3;
    rem[1] -= s / 3;
    rem[2] -= s / 3;
    if (s % 3 == 0) {
    } else if (s % 3 == 1) {
      --rem[1];
    } else if (s % 3 == 2) {
      --rem[1];
      --rem[2];
    }

    const  lli mod = 1e9 + 7;
    const int N = 2 * 1e5 + 5;
    lli dp[N][3];
    fill(&dp[0][0], &dp[N - 1][3 - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          lli a = (dp[i][j] * rem[k]) % mod;
          (dp[i + 1][(k + j) % 3] += a) %= mod;
        }
      }
    }
    cout << dp[n][0] << endl;
  }

  return 0;
}
