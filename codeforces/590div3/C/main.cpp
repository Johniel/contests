// codeforces/590div3/C/main.cpp
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

  int q;
  while (cin >> q) {
    while (q--) {
      int n;
      cin >> n;
      const int W = 2 * 1e5 + 5;
      static char g[2][W];
      fill(&g[0][0], &g[2 - 1][W - 1] + 1, '1');

      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
          cin >> g[i][j];
          if (g[i][j] == '1' || g[i][j] == '2') g[i][j] = '-';
          else g[i][j] = 'L';
        }
      }

      auto fn = [&] (int i) {
        for (int j = 0; j < n; ++j) {
          if (g[i][j] == '-') ;
          else if (g[i][j] == 'L' && g[i ^ 1][j] == 'L') i ^= 1;
          else return false;
        }
        return i == 1;
      };

      cout << (fn(0) ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
