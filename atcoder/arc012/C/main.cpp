// atcoder/arc012/C/main.cpp
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

  const int H = 20;
  const int W = 20;
  char g[H][W];
  fill(&g[0][0], &g[H - 1][W - 1] + 1, '.');
  while (true) {
    const int h = 19;
    const int w = 19;
    bool f = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        f = f && (cin >> g[i][j]);
      }
    }
    if (!f) break;

    const int a = count(&g[0][0], &g[H - 1][W - 1] + 1, 'o');
    const int b = count(&g[0][0], &g[H - 1][W - 1] + 1, 'x');
    if (a == 0 && b == 0) {
      cout << "YES" << endl;
      continue;
    }
    if (a == 1 && b == 0) {
      cout << "YES" << endl;
      continue;
    }
    unless (a == b || a - 1 == b) {
      cout << "NO" << endl;
      continue;
    }

    auto fn = [&] () {
      int mxa = 0;
      int mxb = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (g[i][j] == '.') continue;
          for (int d = 0; d < 8; ++d) {
            for (int k = 0; k <= 10; ++k) {
              int ni = i + di[d] * k;
              int nj = j + dj[d] * k;
              unless (0 <= ni && ni < h) break;
              unless (0 <= nj && nj < w) break;
              if (g[i][j] != g[ni][nj]) break;
              if (g[i][j] == 'o') setmax(mxa, k + 1);
              if (g[i][j] == 'x') setmax(mxb, k + 1);
            }
          }
        }
      }
      return make_pair(mxa, mxb);
    };

    if (a - 1 == b) {
      bool f = false;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (g[i][j] == 'o') {
            g[i][j] = '.';
            int p, q;
            tie(p, q) = fn();
            g[i][j] = 'o';
            if (max(p, q) < 5) {
              f = true;
              i = j = (1 << 29);
            }
          }
        }
      }
      if (!f) {
        cout << "NO" << endl;
        continue;
      }
    }
    if (a == b) {
      bool f = false;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (g[i][j] == 'x') {
            g[i][j] = '.';
            int p, q;
            tie(p, q) = fn();
            g[i][j] = 'x';
            if (max(p, q) < 5) {
              f = true;
              i = j = (1 << 29);
            }
          }
        }
      }
      if (!f) {
        cout << "NO" << endl;
        continue;
      }
    }

    cout << "YES" << endl;
  }

  return 0;
}
