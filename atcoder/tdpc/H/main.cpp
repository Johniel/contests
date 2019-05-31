// atcoder/tdpc/H/main.cpp
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

  int n, w, c;
  while (cin >> n >> w >> c) {
    const int W = 10000 + 2;
    const int C = 50 + 2;
    static int dp[2][W][C][2];
    fill(&dp[0][0][0][0], &dp[2 - 1][W - 1][C - 1][2 - 1] + 1, 0);

    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; ++i) {
      int w, v, c;
      cin >> w >> v >> c;
      m[c].push_back({w, v});
    }

    int curr = 0;
    int next = 1;
    each (_, m) {
      for (int j = 0; j < W; ++j) {
        for (int k = 0; k < C; ++k) {
          setmax(dp[curr][j][k][true], dp[curr][j][k][false]);
          dp[curr][j][k][false] = 0;
          dp[next][j][k][false] = dp[next][j][k][true] = 0;
        }
      }
      each (i, _.second) {
        for (int j = 0; j < W; ++j) {
          for (int k = 0; k < C; ++k) {
            for (int b = 0; b < 2; ++b) {
              setmax(dp[next][j][k][b], dp[curr][j][k][b]);
              if (j + i.first <= w && k + b < c) {
                setmax(dp[next][j + i.first][k + b][false], dp[curr][j][k][b] + i.second);
              }
            }
          }
        }
        curr ^= 1;
        next ^= 1;
      }
    }

    cout << *max_element(&dp[0][0][0][0], &dp[2 - 1][W - 1][C - 1][2 - 1] + 1) << endl;
  }

  return 0;
}
