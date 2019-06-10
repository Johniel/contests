// atcoder/abc129/D/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    const int H = 2000 + 5;
    const int W = 2000 + 5;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int inf = 1 << 27;
    static int mx_w[H][W];
    static int mx_h[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        mx_h[i][j] = mx_w[i][j] = (g[i][j] == '#' ? -inf : 1);
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 1; j < w; ++j) {
        if (g[i][j] == '#') continue;
        setmax(mx_w[i][j], mx_w[i][j - 1] + mx_w[i][j]);
      }
      for (int j = w - 2; 0 <= j; --j) {
        if (g[i][j] == '#') continue;
        setmax(mx_w[i][j], mx_w[i][j + 1]);
      }
    }

    for (int j = 0; j < w; ++j) {
      for (int i = 1; i < h; ++i) {
        if (g[i][j] == '#') continue;
        setmax(mx_h[i][j], mx_h[i - 1][j] + mx_h[i][j]);
      }
      for (int i = h - 2; 0 <= i; --i) {
        if (g[i][j] == '#') continue;
        setmax(mx_h[i][j], mx_h[i + 1][j]);
      }
    }

    int mx = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        setmax(mx, mx_h[i][j] + mx_w[i][j] - 1);
      }
    }
    cout << mx << endl;
  }

  return 0;
}
