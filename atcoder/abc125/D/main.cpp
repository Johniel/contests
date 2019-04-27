// atcoder/abc125/D/main.cpp
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
    vector<lli> a(n);
    cin >> a;

    const lli inf = 1LL << 60;
    const int N = 1e5 + 5;
    lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, -inf);
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          setmax(dp[i + 1][k], dp[i][j] + a[i] * (j ^ k ? -1 : +1));
        }
      }
    }
    lli x = dp[n - 1][1] + a.back() * -1;
    lli y = dp[n - 1][0] + a.back();
    cout << max(x, y) << endl;
  }

  return 0;
}
