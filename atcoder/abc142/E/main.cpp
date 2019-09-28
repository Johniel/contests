// atcoder/abc142/E/main.cpp
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
    int a[m];
    int mask[m];
    for (int i = 0; i < m; ++i) {
      int b;
      cin >> a[i] >> b;
      vector<int> c(b);
      cin >> c;
      mask[i] = 0;
      each (j, c) mask[i] += (1 << (j - 1));
    }

    const int M = 1000 + 5;
    const int BIT = (1 << 12) + 1;
    const lli inf = 1LL << 60;
    static lli dp[M][BIT];
    fill(&dp[0][0], &dp[M - 1][BIT - 1] + 1, inf);
    dp[0][0] = 0;

    for (int i = 0; i < m; ++i) {
      for (int bit = 0; bit < BIT; ++bit) {
        setmin(dp[i + 1][bit], dp[i][bit]);
        setmin(dp[i + 1][bit | mask[i]], dp[i][bit] + a[i]);
      }
    }

    lli mn = 1LL << 60;
    for (int i = 0; i < M; ++i) {
      setmin(mn, dp[i][(1 << n) - 1]);
    }
    cout << (mn != inf ? mn : -1) << endl;
  }

  return 0;
}
