// codeforces/612div2/C/main.cpp
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

  int n;
  while (cin >> n) {
    vector<int> v(n);
    cin >> v;

    set<int> s;
    for (int i = 1; i <= n; ++i) {
      s.insert(i);
    }
    each (i, v) s.erase(i);
    int odd = 0;
    each (i, s) odd += i % 2;

    const int N = 100 + 5;
    const int M = 2;
    static int dp[N][N][M];
    fill(&dp[0][0][0], &dp[N - 1][N][M - 1] + 1, 1 << 29);
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int last = 0; last < 2; ++last) {
          if (v[i]) {
            setmin(dp[i + 1][j][v[i] % 2], dp[i][j][last] + (v[i] % 2 != last));
          } else {
            setmin(dp[i + 1][j + 1][1], dp[i][j][last] + (last == 0));
            setmin(dp[i + 1][j + 0][0], dp[i][j][last] + (last == 1));
          }
        }
      }
    }
    cout << min(dp[n][odd][0], dp[n][odd][1]) << endl;
  }

  return 0;
}
