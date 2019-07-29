// atcoder/abc078/C/main.cpp
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
    cout << 1900.0 * m * (1 << m) + 100.0 * (n - m) * (1 << m) << endl;
    // const int N = 1e6;
    // static double dp[N];
    // const double p = double((1 << m) - 1.0) / (1 << m);
    // dp[1] = 1.0 / (1 << m);
    // for (int i = 2; i < N; ++i) {
    //   dp[i] = (1.0 - dp[i - 1]) / p;
    // }
    // lli sum = 0;
    // for (int i = 1; i < N; ++i) {
    //   sum += dp[i] * (m * 1900.0 + (n - m) * 100.0) * i;
    // }
    // cout << sum << endl;
  }

  return 0;
}
