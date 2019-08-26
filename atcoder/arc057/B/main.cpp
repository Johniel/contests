// atcoder/arc057/B/main.cpp
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

  int n;
  lli k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    cin >> a;

    if (accumulate(a.begin(), a.end(), 0LL) == k) {
      cout << 1 << endl;
      continue;
    }

    const int N = 2000 + 5;
    static lli dp[N][N];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, inf);
    dp[0][0] = 0;

    static lli sum[N];
    sum[0] = 0;
    for (int i = 0; i < a.size(); ++i) {
      sum[i + 1] = sum[i] + a[i];
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j + 1 < N; ++j) {
        if (inf <= dp[i][j]) continue;
        setmin(dp[i + 1][j], dp[i][j]);
        lli y = 1 + (i ? dp[i][j] * a[i] / sum[i] : 0);
        if (y <= a[i]) {
          setmin(dp[i + 1][j + 1], dp[i][j] + y);
        }
      }
    }

    int mx = 0;
    for (int i = 0; i < N; ++i) {
      if (dp[n][i] <= k) {
        mx = i;
      }
    }
    cout << mx << endl;
  }

  return 0;
}
