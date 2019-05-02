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

  int k;
  while (cin >> k) {
    const int K = 10 + 1;
    const int N = 1 << K;

    vector<int> r(1 << k);
    cin >> r;

    static double p[N][N];
    for (int i = 0; i < r.size(); ++i) {
      for (int j = 0; j < r.size(); ++j) {
        p[i][j] = 1.0 / (1.0 + pow(10, (r[j] - r[i]) / 400.0));
      }
    }

    static double dp[K][N];
    fill(&dp[0][0], &dp[K - 1][N - 1] + 1, 0);
    for (int i = 0; i < r.size(); ++i) {
      dp[0][i] = 1;
    }
    int mask = (1 << k) - 1;
    for (int x = 0; x < k; ++x) {
      mask ^= (1 << x);
      for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r.size(); ++j) {
          if (i == j) continue;
          if ((i & mask) == (j & mask) && (i & (1 << x)) != (j & (1 << x))) {
            dp[x + 1][i] += dp[x][i] * dp[x][j] * p[i][j];
          }
        }
      }
    }

    for (int i = 0; i < (1 << k); ++i) {
      printf("%.10lf\n", dp[k][i]);
    }
  }

  return 0;
}
