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
    vector<int> p(n);
    cin >> p;
    const int N = 100 + 5;
    const int P = N * (100 + 5);
    static bool dp[N][P];
    fill(&dp[0][0], &dp[N - 1][P - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j + p[i] < P; ++j) {
        dp[i + 1][j] |= dp[i][j];
        dp[i + 1][j + p[i]] |= dp[i][j];
      }
    }
    int sum = 0;
    for (int i = 0; i < P; ++i) {
      sum += dp[n][i];
    }
    cout << sum << endl;
  }
  
  return 0;
}
