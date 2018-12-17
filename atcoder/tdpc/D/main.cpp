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
  lli d;
  while (cin >> n >> d) {
    const int N = 100 + 5;
    const int M = N * 2;
    static double dp[2][M][N][N];
    fill(&dp[0][0][0][0], &dp[2 - 1][M - 1][N - 1][N - 1] + 1, 0);
    dp[0][0][0][0] = 1;
    dp[1][0][0][0] = 1;

    vector<vector<int>> v;
    v.push_back({0, 0, 0}); // 1
    v.push_back({1, 0, 0}); // 2
    v.push_back({0, 1, 0}); // 3
    v.push_back({2, 0, 0}); // 4
    v.push_back({0, 0, 1}); // 5
    v.push_back({1, 1, 0}); // 6

    int curr, next;
    for (int turn = 0; turn < n; ++turn) {
      curr = turn % 2;
      next = (turn + 1) % 2;
      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          for (int k = 0; k < N; ++k) {
            dp[next][i][j][k] = 0;
          }
        }
      }
      for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int k = 0; k < n; ++k) {
            if (dp[curr][i][j][k] == 0) continue;
            each (x, v) {
              dp[next][i + x[0]][j + x[1]][k + x[2]] += dp[curr][i][j][k] / v.size();
            }
          }
        }
      }
    }

    int _2 = 0;
    int _3 = 0;
    int _5 = 0;
    for (; d % 2 == 0; ++_2) d /= 2;
    for (; d % 3 == 0; ++_3) d /= 3;
    for (; d % 5 == 0; ++_5) d /= 5;
    if (d != 1) {
      cout << 0 << endl;
      continue;
    }

    double sum = 0;
    for (int i = _2; i < M; ++i) {
      for (int j = _3; j < N; ++j) {
        for (int k = _5; k < N; ++k) {
          sum += dp[next][i][j][k];
        }
      }
    }
    cout << sum << endl;
  }

  return 0;
}
