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

  int n, v;
  while (cin >> n >> v) {
    const int N = 100 + 10;
    const int V = 100 + 10;
    int dp[N][V];
    const int inf = 1 << 29;
    fill(&dp[0][0], &dp[N - 1][V - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= v; ++j) {
        for (int k = max(1, j); k <= v; ++k) {
          setmin(dp[i + 1][k - 1], dp[i][j] + (k - j) * (i + 1));
        }
      }
    }
    
    int mn = inf;
    for (int i = 0; i <= v; ++i) {
      setmin(mn, dp[n - 1][i]);
    }
    cout << mn << endl;
  }
  
  return 0;
}
