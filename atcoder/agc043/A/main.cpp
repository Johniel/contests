// atcoder/agc043/main.cpp
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
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int H = 100 + 5;
    const int W = 100 + 5;
    int dp[H][W][2];
    fill(&dp[0][0][0], &dp[H - 1][W - 1][2 - 1] + 1, 1 << 28);
    if (g[0][0] == '.') {
      dp[0][0][0] = 0;
    }
    if (g[0][0] == '#') {
      dp[0][0][1] = 1;
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (i + 1 < h) {
          if (g[i + 1][j] == '.') {
            setmin(dp[i + 1][j][0], dp[i][j][0] + 0);
            setmin(dp[i + 1][j][0], dp[i][j][1] + 1);
          }
          if (g[i + 1][j] == '#') {
            setmin(dp[i + 1][j][1], dp[i][j][1] + 0);
            setmin(dp[i + 1][j][1], dp[i][j][0] + 1);
          }
        }
        if (j + 1 < w) {
          if (g[i][j + 1] == '.') {
            setmin(dp[i][j + 1][0], dp[i][j][0] + 0);
            setmin(dp[i][j + 1][0], dp[i][j][1] + 1);
          }
          if (g[i][j + 1] == '#') {
            setmin(dp[i][j + 1][1], dp[i][j][0] + 1);
            setmin(dp[i][j + 1][1], dp[i][j][1] + 0);
          }
        }
      }
    }

    cout << (min(dp[h - 1][w - 1][0], dp[h - 1][w - 1][1]) + 1) / 2 << endl;
  }

  return 0;
}
