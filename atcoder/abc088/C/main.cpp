// atcoder/abc088/C/main.cpp
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

  while (true) {
    bool f = true;
    int g[3][3];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        f = f && (cin >> g[i][j]);
      }
    }
    if (!f) break;

    bool x = false;
    for (int a0 = 0; a0 <= 100; ++a0) {
      for (int a1 = 0; a1 <= 100; ++a1) {
        for (int b0 = 0; b0 <= 100; ++b0) {
          for (int b1 = 0; b1 <= 100; ++b1) {
            int a2 = g[2][0] - b0;
            int b2 = g[0][2] - a0;

            if (g[0][0] != a0 + b0) continue;
            if (g[0][1] != a0 + b1) continue;
            if (g[0][2] != a0 + b2) continue;

            if (g[1][0] != a1 + b0) continue;
            if (g[1][1] != a1 + b1) continue;
            if (g[1][2] != a1 + b2) continue;

            if (g[2][0] != a2 + b0) continue;
            if (g[2][1] != a2 + b1) continue;
            if (g[2][2] != a2 + b2) continue;

            x = true;
          }
        }
      }
    }
    cout << (x ? "Yes" : "No") << endl;
  }

  return 0;
}
