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
 
int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  while (cin >> n) {
    lli g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    bool dummy[n][n];
    fill(&dummy[0][0], &dummy[n - 1][n - 1] + 1, false);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        for (int k = 0; k < n; ++k) {
          if (i == k || j == k) continue;
          dummy[i][j] = dummy[i][j] || (g[i][j] == g[i][k] + g[k][j]);
        }
      }
    }
 
    const lli inf = 1LL << 60;
    lli h[n][n];
    fill(&h[0][0], &h[n - 1][n - 1] + 1, inf);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        unless (dummy[i][j]) {
          h[i][j] = g[i][j];
          sum += h[i][j];
        }
      }
    }
 
    bool f = true;
    for (int i = 0; i < n; ++i) {
      f = f && (g[i][i] == 0);
      for (int j = 0; j < n; ++j) {
        f = f && (g[i][j] == g[j][i]);
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f = f && (g[i][j] == h[i][j]);
      }
    }
    if (!f) cout << -1 << endl;
    else cout << sum / 2 << endl;
  }
 
  return 0;
}
