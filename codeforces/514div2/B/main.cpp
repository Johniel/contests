#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

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

    vector<pair<int, int>> v;
    for (int i = 0; i + 2 < h; ++i) {
      for (int j = 0; j + 2 < w; ++j) {
        if (g[i][j] == '#') {
          bool f = true;
          for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
              if (a == 1 && b == 1) continue;
              f = f && (g[i + a][j + b] == '#');
            }
          }
          if (f) v.push_back(make_pair(i, j));
        }
      }
    }

    char x[h][w];
    fill(&x[0][0], &x[h - 1][w - 1] + 1, '.');
    each (i, v) {
      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
          if (a == 1 && b == 1) continue;
          x[i.first + a][i.second + b] = '#';
        }
      }
    }

    bool f = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        f = f && (x[i][j] == g[i][j]);
      }
    }
    cout << (f ? "YES" : "NO") << endl;
  }
  
  return 0;
}
