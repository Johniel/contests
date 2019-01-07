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
  while (cin >> n) {
    int x[n][3];
    for (int i = 0; i < n; ++i) {
      cin >> x[i][0] >> x[i][1] >> x[i][2];
    }

    const int N = 1e5 + 5;
    int dp[N][3];
    fill(&dp[0][0], &dp[N - 1][3 - 1] + 1, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (j == k) continue;
          setmax(dp[i + 1][k], dp[i][j] + x[i][k]);
        }
      }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
  }
  
  return 0;
}
