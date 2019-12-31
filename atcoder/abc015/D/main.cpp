// atcoder/abc015/D/main.cpp
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

  int w, n, k;
  while (cin >> w >> n >> k) {
    vector<pair<int, int>> v(n);
    cin >> v;
    const int N = 50 + 5;
    const int W = 10000 + 5;
    static lli dp[N][N][W];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][W - 1] + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int x = 0; x < k; ++x) {
        for (int j = 0; j < w; ++j) {
          if (j + v[i].first <= w) {
            setmax(dp[i + 1][x + 1][j + v[i].first], dp[i][x][j] + v[i].second);
          }
          setmax(dp[i + 1][x][j], dp[i][x][j]);
        }
      }
    }
    cout << *max_element(&dp[0][0][0], &dp[N - 1][N - 1][W - 1] + 1) << endl;
  }

  return 0;
}
