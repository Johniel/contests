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

  vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  int n;
  while (cin >> n) {
    vector<int> v;
    each (i, p) if (i <= n) v.push_back(i);

    map<int, int> fact;
    for (int x = 2; x <= n; ++x) {
      int y = x;
      each (i, v) {
        while (y % i == 0) {
          y /= i;
          ++fact[i];
        }
      }
    }

    const int N = 100;
    const int M = 100;
    int dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    dp[0][1] = 1;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k <= fact[v[i]]; ++k) {
          if (j * (k + 1) < M) {
            dp[i + 1][j * (k + 1)] += dp[i][j];
          }
        }
      }
    }
    cout << dp[v.size()][75] << endl;
  }
  
  return 0;
}
