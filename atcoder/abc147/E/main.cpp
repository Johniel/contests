// atcoder/abc147/E/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    const int N = 80 + 3;
    int a[N][N];
    int b[N][N];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> b[i][j];
      }
    }

    const int D = 80 * N * 2;
    static bool dp[N][N][D];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][D - 1] + 1, false);
    dp[0][0][a[0][0] - b[0][0] + (D / 2)] = true;
    dp[0][0][b[0][0] - a[0][0] + (D / 2)] = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; k < D; ++k) {
          if (dp[i][j][k]) {
            if (i + 1 < h) dp[i + 1][j][k + (a[i + 1][j] - b[i + 1][j])] |= dp[i][j][k];
            if (i + 1 < h) dp[i + 1][j][k + (b[i + 1][j] - a[i + 1][j])] |= dp[i][j][k];
            if (j + 1 < w) dp[i][j + 1][k + (a[i][j + 1] - b[i][j + 1])] |= dp[i][j][k];
            if (j + 1 < w) dp[i][j + 1][k + (b[i][j + 1] - a[i][j + 1])] |= dp[i][j][k];
          }
        }
      }
    }

    int mn = 1 << 29;
    for (int k = 0; k < D; ++k) {
      if (dp[h - 1][w - 1][k]) {
        setmin(mn, abs(k - (D / 2)));
      }
    }
    cout << mn << endl;
  }

  return 0;
}
