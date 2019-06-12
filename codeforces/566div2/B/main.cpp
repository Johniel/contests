// codeforces/566div2/B/main.cpp
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
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};

    pair<int, int> c = {-1, -1};
    for (int i = 1; i + 1 < h; ++i) {
      for (int j = 1; j + 1 < w; ++j) {
        int cnt = (g[i][j] == '*');
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          cnt += (g[ni][nj] == '*');
        }
        if (cnt == 5) {
          c = {i, j};
          i = j = 1 << 29;
        }
      }
    }

    if (c != make_pair(-1, -1)) {
      g[c.first][c.second] = '+';
      for (int d = 0; d < 4; ++d) {
        for (int k = 1; k < max(h, w); ++k) {
          int i = c.first + di[d] * k;
          int j = c.second + dj[d] * k;
          unless (0 <= i && i < h) continue;
          unless (0 <= j && j < w) continue;
          if (g[i][j] != '*') break;
          g[i][j] = '+';
        }
      }
    }

    int x = count(&g[0][0], &g[h - 1][w - 1] + 1, '+');
    int y = count(&g[0][0], &g[h - 1][w - 1] + 1, '.');
    if (5 <= x && x + y == h * w) {
      cout << "YES" << endl;
    } else {
      cout <<  "NO"  << endl;
    }
  }

  return 0;
}
