// codeforces/556div2/B/main.cpp
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

const int N = 50 + 5;
char g[N][N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(&g[0][0], &g[N - 1][N - 1] + 1, '#');

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    const int D = 5;
    int di[D] = {0, +1, +1, +1, +2};
    int dj[D] = {0, -1,  0, +1,  0};

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == '.') {
          bool f = true;
          for (int k = 0; k < D; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            f = f && (0 <= ni && ni < n) && (0 <= nj && nj < n) && (g[ni][nj] == '.');
          }
          if (f) {
            for (int k = 0; k < D; ++k) {
              int ni = i + di[k];
              int nj = j + dj[k];
              g[ni][nj] = '@';
            }
          }
        }
      }
    }

    cout << (count(&g[0][0], &g[N - 1][N - 1] + 1, '.') == 0 ? "YES" : "NO") << endl;
  }

  return 0;
}
