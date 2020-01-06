// atcoder/abc018/C/main.cpp
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

  int h, w, k;
  while (cin >> h >> w >> k) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int r[h][w];
    int l[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        r[i][j] = l[i][j] = (g[i][j] == 'o');
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 1; j < w; ++j) {
        if (g[i][j] == 'o') l[i][j] = l[i][j - 1] + 1;
      }
      for (int j = w - 2; 0 <= j; --j) {
        if (g[i][j] == 'o') r[i][j] = r[i][j + 1] + 1;
      }
    }

    int cnt = 0;
    for (int i = 0; i <= h - k - k + 1; ++i) {
      for (int j = 0; j <= w - k; ++j) {
        vector<int> v;
        for (int x = 0; x < k * 2 - 1; ++x) {
          v.push_back(min(r[i + x][j], l[i + x][j]));
        }
        bool f = true;
        for (int x = 0; x <= v.size() / 2; ++x) {
          int y = v.size() - x - 1;
          f = f && (x + 1) <= v[x];
          f = f && (x + 1) <= v[y];
        }
        cnt += f;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
