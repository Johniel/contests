// atcoder/abc054/B/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    char a[n][n];
    char b[m][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> b[i][j];
      }
    }
    bool f = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = 0;
        for (int p = 0; i + p < n && p < m; ++p) {
          for (int q = 0; j + q < n && q < m; ++q) {
            cnt += (a[i + p][j + q] == b[p][q]);
          }
        }
        f = f || (cnt == m * m);
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  
  return 0;
}
