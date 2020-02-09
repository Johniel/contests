// atcoder/abc011/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, d, x, y;
  while (cin >> n >> d >> x >> y) {
    if (x % d || y % d) {
      cout << 0 << endl;
      continue;
    }
    if (n < (x / d) + (y / d)) {
      cout << 0 << endl;
      continue;
    }

    const int N = 1000 + 5;
    const int M = 2000 + 5;
    static double dp[N][M];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    const int BASE = 1000;
    dp[0][BASE] = 1.0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= +2000; ++j) {
        int a = j - 1;
        int b = j + 1;
        if (0 <= a && a < M) dp[i + 1][a] += dp[i][j] * 0.25;
        if (0 <= b && b < M) dp[i + 1][b] += dp[i][j] * 0.25;
      }
    }

    static double nck[N][N];
    fill(&nck[0][0], &nck[N - 1][N - 1] + 1, 0);
    for (int i = 0; i < N; ++i) {
      nck[i][0] = 1;
    }
    for (int n = 1; n < N; ++n) {
      for (int k = 1; k < N; ++k) {
        nck[n][k] = nck[n - 1][k - 1] + nck[n - 1][k];
      }
    }

    double z = 0;
    for (int i = 0; i <= n; ++i) {
      z += (dp[i][x / d + BASE] * dp[n - i][y / d + BASE]) * nck[n][i];
    }
    printf("%.10lf\n", z);
  }

  return 0;
}
