// atcoder/abc079/D/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    const int N = 10;
    int g[N][N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> g[i][j];
      }
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          setmin(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    int sum = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        int a;
        cin >> a;
        if (a != -1) sum += g[a][1];
      }
    }
    cout << sum << endl;
  }

  return 0;
}
