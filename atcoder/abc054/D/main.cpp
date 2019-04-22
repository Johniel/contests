// atcoder/abc054/D/main.cpp
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

  int n, ma, mb;
  while (cin >> n >> ma >> mb) {
    using T = struct{
      int a, b, c;
    };
    vector<T> v(n);
    each (i, v) cin >> i.a >> i.b >> i.c;

    const int N = 40 + 5;
    const int M = (N * 10) + 5;
    static int dp[N][M][M];
    const int inf = 1 << 29;
    fill(&dp[0][0][0], &dp[N - 1][M - 1][M - 1] + 1, inf);
    dp[0][0][0] = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          setmin(dp[i + 1][j][k], dp[i][j][k]);
          int p = j + v[i].a;
          int q = k + v[i].b;
          if (max(p, q) < M) {
            setmin(dp[i +  1][p][q], dp[i][j][k] + v[i].c);
          }
        }
      }
    }
    int x = inf;
    for (int i = 1; max(ma, mb) * i < M; ++i) {
      setmin(x, dp[n][ma * i][mb * i]);
    }
    cout << (inf == x ? -1 : x) << endl;
  }
  
  return 0;
}
