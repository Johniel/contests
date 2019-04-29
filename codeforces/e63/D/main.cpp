// codeforces/e63/D/main.cpp
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

  int n, x;
  while (cin >> n >> x) {
    vector<lli> a(n);
    cin >> a;

    const int N = 3 * 1e5 + 5;
    const int M = 4;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
      setmax(dp[i + 1][0], dp[i][0] + a[i]);
      setmax(dp[i + 1][1], dp[i][0] + a[i]);
      setmax(dp[i + 1][1], dp[i][1] + a[i] * x);
      setmax(dp[i + 1][2], dp[i][1] + a[i] * x);
      setmax(dp[i + 1][2], dp[i][2] + a[i]);
    }
    cout << *max_element(&dp[0][0], &dp[N - 1][M - 1] + 1) << endl;
  }

  return 0;
}
