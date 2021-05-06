// codeforces/718/D/main.cpp
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

  int h, w, k;
  while (cin >> h >> w >> k) {
    const int H = 500 + 2, W = 500 + 2;
    static lli R[H][W];
    static lli D[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w - 1; ++j) {
        cin >> R[i][j];
      }
    }
    for (int i = 0; i < h - 1; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> D[i][j];
      }
    }

    if (k % 2) {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << -1 << ' ';
        }
        cout << endl;
      }
      continue;
    }

    static lli dp[22][H][W];
    const lli inf = 1LL << 60;
    fill(&dp[0][0][0], &dp[22 - 1][H - 1][W - 1] + 1, inf);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        dp[0][i][j] = 0;
      }
    }

    for (int len = 0; len < k / 2; ++len) {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          for (int dir = 0; dir < 4; ++dir) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            unless (0 <= ni && ni < h) continue;
            unless (0 <= nj && nj < w) continue;
            lli e = inf;
            if (dir == 0) { // >
              e = R[i][j];
            }
            if (dir == 1) { // v
              e = D[i][j];
            }
            if (dir == 2) { // ^
              e = D[i - 1][j];
            }
            if (dir == 3) { // <
              e = R[i][j - 1];
            }

            setmin(dp[len + 1][ni][nj], dp[len][i][j] + e);
          }
        }
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << dp[k / 2][i][j] * 2 << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
