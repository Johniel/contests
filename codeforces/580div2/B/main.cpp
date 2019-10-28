// codeforces/580div2/B/main.cpp
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

    const int N = 1e5 + 5;
    lli dp[N][2];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);
    dp[0][1] = 0; // +1
    map<int, int> m;
    m[-1] = 0;
    m[+1] = 1;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = -1; j <= +1; ++j) {
        for (int k = -1; k <= +1; ++k) {
          if (j == 0 || k == 0) continue;
          setmin(dp[i + 1][m[j * k]], dp[i][m[j]] + abs(a[i] - k));
        }
      }
    }
    cout << dp[n][1] << endl;
  }

  return 0;
}
