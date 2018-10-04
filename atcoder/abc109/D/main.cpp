#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  while (cin >> h >> w) {
    int g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    vector<pair<pair<int, int>, pair<int, int>>> v;
    for (int i = 0; i < h; ++i) {
      vector<int> odd;
      for (int j = 0; j + 1 < w; ++j) {
        if (g[i][j] % 2) {
          odd.push_back(j);
          v.push_back(make_pair(make_pair(i, j), make_pair(i, j + 1)));
          --g[i][j];
          ++g[i][j + 1];
        }
      }
      if (i + 1 < h && g[i][w - 1] % 2) {
        v.push_back(make_pair(make_pair(i, w - 1), make_pair(i + 1, w - 1)));
        --g[i][w - 1];
        ++g[i + 1][w - 1];
      }
    }

    cout << v.size() << endl;
    each (i, v) {
      int a = i.first.first;
      int b = i.first.second;
      int c = i.second.first;
      int d = i.second.second;
      cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << endl;
    }
  }

  return 0;
}
