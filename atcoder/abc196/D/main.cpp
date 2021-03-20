// atcoder/abc196/D/main.cpp
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

  int h, w, a, b;
  while (cin >> h >> w >> a >> b) {
    if (h < w) swap(h, w); // 縦長

    const int H = 16 + 1;
    const int A = 8+1;
    const int B = 16+1;
    const int BIT = 1 << 4;
    lli dp[H][A][B][BIT];
    fill(&dp[0][0][0][0], &dp[H - 1][A - 1][B - 1][BIT - 1] + 1, 0);
    dp[0][a][b][0] = 1;
    for (int i = 0; i < h; ++i) {
      for (int x = 0; x <= a; ++x) {
        for (int y = 0; y <= b; ++y) {
          for (int bit = 0; bit < BIT; ++bit) {
            if (dp[i][x][y][bit] == 0) continue;
            for (int z = 0; z < (1 << (w * 2)); ++z) {
              int curr = bit;
              int next = 0;
              bool f = true;
              int patt = z;
              int req_a = 0;
              int req_b = 0;
              for (int j = 0; j < w; ++j) {
                if (patt % 4 == 0) {
                  unless (curr & (1 << j)) f = false;
                }
                if (patt % 4 == 1) { // 縦置き
                  if (curr & (1 << j)) f = false;
                  curr |= (1 << j);
                  next |= (1 << j);
                  ++req_a;
                }
                if (patt % 4 == 2) { // 横置き
                  if (curr & (1 << j)) f = false;
                  unless (j + 1 < w) f = false;
                  curr |= (1 << j);
                  curr |= (1 << (j + 1));
                  ++req_a;
                }
                if (patt % 4 == 3) { // 正方形
                  if (curr & (1 << j)) f = false;
                  curr |= (1 << j);
                  ++req_b;
                }
                patt /= 4;
              }
              f = f && (req_a <= x) && (req_b <= y) && (curr == ((1 << w) - 1));
              if (f) {
                dp[i + 1][x - req_a][y - req_b][next] += dp[i][x][y][bit];
              }
            }
          }
        }
      }
    }
    cout << dp[h][0][0][0] << endl;
  }

  return 0;
}
