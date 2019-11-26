// atcoder/abc145/E/main.cpp
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

  int n, t;
  while (cin >> n >> t) {
    vector<pair<int, int>> v(n);
    cin >> v;

    const int N = 3000 + 5;
    const int T = 3000 + 5;

    static int dp1[N][T];
    fill(&dp1[0][0], &dp1[N - 1][T - 1] + 1, -(1 << 29));
    dp1[0][0] = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < t; ++j) {
        if (j + v[i].first < t) {
          setmax(dp1[i + 1][j + v[i].first], dp1[i][j] + v[i].second);
        }
        setmax(dp1[i + 1][j], dp1[i][j]);
      }
    }

    reverse(v.begin(), v.end());
    static int dp2[N][T];
    fill(&dp2[0][0], &dp2[N - 1][T - 1] + 1, -(1 << 29));
    dp2[0][0] = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < t; ++j) {
        if (j + v[i].first < t) {
          setmax(dp2[i + 1][j + v[i].first], dp2[i][j] + v[i].second);
        }
        setmax(dp2[i + 1][j], dp2[i][j]);
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 1; j < t; ++j) {
        setmax(dp1[i][j], dp1[i][j - 1]);
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j < t; ++j) {
        setmax(dp2[i][j], dp2[i][j - 1]);
      }
    }

    reverse(v.begin(), v.end());
    int mx = 0;
    static int x[T];
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < t; ++j) {
        setmax(mx, dp1[i][j] + dp2[n - i - 1][t - j - 1] + v[i].second);
      }
    }
    cout << mx << endl;
  }

  return 0;
}
