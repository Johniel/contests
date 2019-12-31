// atcoder/abc015/C/main.cpp
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

  int n, k;
  while (cin >> n >> k) {
    int g[5][5];
    fill(&g[0][0], &g[4][4] + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        cin >> g[i][j];
      }
    }
    bool f = false;
    for (int a = 0; a < k; ++a) {
      for (int b = 0; b < k; ++b) {
        for (int c = 0; c < k; ++c) {
          for (int d = 0; d < k; ++d) {
            for (int e = 0; e < k; ++e) {
              f = f || ((g[0][a] ^ g[1][b] ^ g[2][c] ^ g[3][d] ^ g[4][e]) == 0);
            }
          }
        }
      }
    }
    cout << (f ? "Found" : "Nothing") << endl;
  }

  return 0;
}
