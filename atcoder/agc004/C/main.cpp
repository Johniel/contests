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

    const int H = 500;
    const int W = 500;
    char a[H][W];
    char b[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        a[i][j] = b[i][j] = '.';
      }
    }

    auto show = [&] () {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << a[i][j];
        }
        cout << endl;
      }
      cout << endl;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << b[i][j];
        }
        cout << endl;
      }
    };
    
    for (int i = 0; i < h; i += 2) {
      for (int j = 0; j < w - 1; ++j) {
        a[i][j] = '#';
      }
      for (int j = 1; j < w; ++j) {
        b[i + 1][j] = '#';
      }
    }

    
    for (int i = 0; i < h; ++i) {
      a[i][0] = b[i][w - 1] = '#';
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') {
          a[i][j] = '#';
          b[i][j] = '#';
        }
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (a[i][j] == '#' && b[i][j] == '#') {
          assert(g[i][j] == '#');
        }
        if (g[i][j] == '#') {
          assert(a[i][j] == '#' && b[i][j] == '#');
        }
      }
    }
    
    show();
  }
  
  return 0;
}
