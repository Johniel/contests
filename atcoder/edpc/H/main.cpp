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
    const int H = 1000 + 5;
    const int W = 1000 + 5;
    char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const lli mod = 1e9 + 7;
    static lli dp[H][W];
    fill(&dp[0][0], &dp[H - 1][W - 1] + 1, 0);
    dp[0][0] = 1;

    int di[] = {0, 1};
    int dj[] = {1, 0};
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int d = 0; d < 2; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == '#') continue;
          (dp[ni][nj] += dp[i][j]) %= mod;
        }
      }
    }
    cout << dp[h - 1][w - 1] << endl;
  }
  
  return 0;
}
