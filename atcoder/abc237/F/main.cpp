// atcoder/abc237/F/main.cpp
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

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    const int N = 1000 + 3;
    const int M = 12;
    static lli dp[N][M][M][M];
    fill(&dp[0][0][0][0], &dp[N - 1][M - 1][M - 1][M - 1] + 1, 0);
    dp[0][m][m][m] = 1;

    for (int i = 0; i < n; ++i) {
      for (int a = 0; a <= m; ++a) {
        for (int b = 0; b <= m; ++b) {
          for (int c = 0; c <= m; ++c) {
            for (int j = 0; j < m; ++j) {
              if (j <= a) (dp[i + 1][j][b][c] += dp[i][a][b][c]) %= mod;
              if (a < j && j <= b) (dp[i + 1][a][min(j, b)][c] += dp[i][a][b][c]) %= mod;
              if (b < j && j <= c) (dp[i + 1][a][b][min(c, j)] += dp[i][a][b][c]) %= mod;
            }
          }
        }
      }
    }
    lli z = 0;
    for (int a = 0; a < m; ++a) {
      for (int b = 0; b < m; ++b) {
        for (int c = 0; c < m; ++c) {
          (z += dp[n][a][b][c]) %= mod;
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
