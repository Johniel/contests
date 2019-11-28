// atcoder/abc047/B/main.cpp
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

  int h, w, n;
  while (cin >> w >> h >> n) {
    const int N = 100 + 5;
    int g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, 1);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        g[i][j] = 0;
      }
    }
    for (int _ = 0; _ < n; ++_) {
      int I, J, a;
      cin >> J >> I >> a;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          g[i][j] = g[i][j] || (a == 1 && J > j);
          g[i][j] = g[i][j] || (a == 2 && J <= j);
          g[i][j] = g[i][j] || (a == 3 && I > i);
          g[i][j] = g[i][j] || (a == 4 && I <= i);
        }
      }
    }

    cout << count(&g[0][0], &g[N - 1][N - 1] + 1, 0) << endl;
  }

  return 0;
}
