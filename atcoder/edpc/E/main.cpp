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
  lli w;
  while (cin >> n >> w) {
    const int N = 100 + 5;
    const int M = 1000 * N;
    static lli dp[N][M];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, inf);
    dp[0][0] = 0;

    lli x[n];
    lli y[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < M; ++j) {
        setmin(dp[i + 1][j], dp[i][j]);
        if (j + y[i] < M) setmin(dp[i + 1][j + y[i]], dp[i][j] + x[i]);
      }
    }

    lli mx = 0;
    for (int j = 0; j < M; ++j) {
      if (dp[n][j] <= w) {
        mx = j;
      }
    }
    cout << mx << endl;
  }
  
  return 0;
}
