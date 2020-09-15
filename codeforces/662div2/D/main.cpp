// codeforces/662div2/D/main.cpp
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
    const int H = 2000 + 5;
    const int W = 2000 + 5;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      s[i] = "";
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        s[i] += g[i][j];
      }
    }

    static int up[H][W];
    static int down[H][W];
    static int right[H][W];
    static int left[H][W];
    fill(&up[0][0], &up[H - 1][W - 1] + 1, -(1 << 29));
    fill(&down[0][0], &down[H - 1][W - 1] + 1, -(1 << 29));
    fill(&right[0][0], &right[H - 1][W - 1] + 1, -(1 << 29));
    fill(&left[0][0], &left[H - 1][W - 1] + 1, -(1 << 29));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        up[i][j] = down[i][j] = right[i][j] = left[i][j] = 0;
      }
    }


    for (int j = 0; j < w; ++j) {
      for (int i = 1; i < h; ++i) {
        up[i][j] = (g[i][j] == g[i - 1][j]) * (up[i - 1][j] + 1);
      }
    }
    for (int j = 0; j < w; ++j) {
      for (int i = h - 2; 0 <= i; --i) {
        down[i][j] = (g[i][j] == g[i + 1][j]) * (down[i + 1][j] + 1);
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = w - 2; 0 <= j; --j) {
        int x = min(up[i][j + 1], down[i][j + 1]);
        int y = min(up[i][j], down[i][j]);
        right[i][j] = (g[i][j + 1] == g[i][j]) * (right[i][j + 1] + 1);
        right[i][j] = min({right[i][j], x + 1, y});
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 1; j < w; ++j) {
        int x = min(up[i][j - 1], down[i][j - 1]);
        int y = min(up[i][j], down[i][j]);
        left[i][j] = (g[i][j - 1] == g[i][j]) * (left[i][j - 1] + 1);
        left[i][j] = min({left[i][j], x + 1, y});
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        ++up[i][j];
        ++down[i][j];
        ++right[i][j];
        ++left[i][j];
      }
    }

    lli x = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        x += min(right[i][j], left[i][j]);
      }
    }
    cout << x << endl;
  }

  return 0;
}
