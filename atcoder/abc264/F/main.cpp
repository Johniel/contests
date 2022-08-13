// github.com/Johniel/contests
// atcoder/abc264/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int H = 2000 + 3;
const int W = 2000 + 3;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    vec<lli> costh(h), costw(w);
    cin >> costh >> costw;
    static int g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        g[i][j] = (c - '0');
      }
    }
    static lli dp[H][W][2][2][2];
    const lli inf = 1LL << 60;
    fill(&dp[0][0][0][0][0], &dp[H - 1][W - 1][1][1][1] + 1, inf);
    const int R = 0;
    const int D = 1;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        lli c = 0;
        if (i) c += costh[0];
        if (j) c += costw[0];
        dp[0][0][(g[0][0] ^ i ^ j)][i][j] = c;
      }
    }
    // dp(今どこ、縦が反転、横が反転)
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int x = 0; x < 2; ++x) {
          for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
              // v
              if (i + 1 < h) {
                if ((g[i + 1][j] ^ b) == x) {
                  setmin(dp[i + 1][j][x][0][b], dp[i][j][x][a][b]);
                } else {
                  setmin(dp[i + 1][j][x][1][b], dp[i][j][x][a][b] + costh[i + 1]);
                }
              }
              // >
              if (j + 1 < w) {
                if ((g[i][j + 1] ^ a) == x) {
                  setmin(dp[i][j + 1][x][a][0], dp[i][j][x][a][b]);
                } else {
                  setmin(dp[i][j + 1][x][a][1], dp[i][j][x][a][b] + costw[j + 1]);
                }
              }
            }
          }
        }
      }
    }

    lli mn = inf;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          setmin(mn, dp[h - 1][w - 1][k][i][j]);
        }
      }
    }
    cout << mn << endl;
  }

  return 0;
}
