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

  int h, w, k;
  while (cin >> h >> w >> k) {

    vector<int> v;
    for (int bit = 0; bit < (1 << (w - 1)); ++bit) {
      bool f = true;
      for (int i = 0; i < w - 1; ++i) {
        int a = 1 << i;
        int b = 1 << (i + 1);
        if ((bit & a) && (bit & b)) f = false;
      }
      if (f) v.push_back(bit);
    }

    const int mod = 1000000007;
    const int H = 100 + 5;
    const int K = 8 + 5;
    lli dp[H][K];
    fill(&dp[0][0], &dp[H - 1][K - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        each (b, v) {
          if (b & (1 << j)) {
            (dp[i + 1][j + 1] += dp[i][j]) %= mod;
          } else if (j && (b & (1 << (j - 1)))) {
            (dp[i + 1][j - 1] += dp[i][j]) %= mod;
          } else {
            (dp[i + 1][j] += dp[i][j]) %= mod;
          }
        }
      }
    }

    cout << dp[h][k - 1] << endl;
  }

  return 0;
}
