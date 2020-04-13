// atcoder/arc041/B/main.cpp
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

const int N = 500 + 3;
int g[N][N];

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    fill(&g[0][0], &g[N - 1][N - 1] + 1, 0);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }

    static int z[N][N];
    fill(&z[0][0], &z[N - 1][N - 1] + 1, 0);
    auto fn = [&] (int i, int j, int x) {
      z[i][j] += x;
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        g[ni][nj] -= x;
      }
      return ;
    };

    for (int d = 0; d < N; ++d) {
      if (0 + d < w - 1 - d) {
        for (int i = 0; i < h; ++i) {
          if (g[i][0 + d]) {
            fn(i, 0 + d + 1, g[i][0 + d]);
          }
          if (g[i][w - 1 - d]) {
            fn(i, w - 1 - d - 1, g[i][w - 1 - d]);
          }
        }
      }
      if (0 + d < h - 1 - d) {
        for (int j = 0; j < w; ++j) {
          if (g[0 + d][j]) {
            fn(0 + d + 1, j, g[0 + d][j]);
          }
          if (g[h - 1 - d][j]) {
            fn(h - 1 - d - 1, j, g[h - 1 - d][j]);
          }
        }
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << z[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
