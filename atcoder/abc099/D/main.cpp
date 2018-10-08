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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  while (cin >> n >> c) {
    int d[c][c];
    for (int i = 0; i < c; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> d[i][j];
      }
    }
    int g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
        --g[i][j];
      }
    }

    map<int, int> cnt[3];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ++cnt[(i + j) % 3][g[i][j]];
      }
    }

    int mn = 1 << 29;
    for (int x = 0; x < c; ++x) {
      for (int y = 0; y < c; ++y) {
        for (int z = 0; z < c; ++z) {
          if (x == y || x == z || y == z) continue;
          int sum = 0;
          each (i, cnt[0]) sum += d[i.first][x] * i.second;
          each (i, cnt[1]) sum += d[i.first][y] * i.second;
          each (i, cnt[2]) sum += d[i.first][z] * i.second;
          mn = min(mn, sum);
        }
      }
    }
    cout << mn << endl;
  }

  return 0;
}
