// atcoder/code-formula-2014-qualb/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    const int N = 70 + 3;
    const int M = 50000;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n + 10; ++i) {
      for (int j = 0; j < M; ++j) {
        int y = (i < a.size() ? a[i] + j : j);
        for (int k = 0; k <= min(y, 9); ++k) {
          lli& x = dp[i + 1][(y - k) / 10];
          x += dp[i][j];
          x %= mod;
        }
      }
    }

    // for (int i = 0; i <= n; ++i) {
    //   for (int j = 0; j <= 10; ++j) {
    //     cout << make_pair(i, j) << ' ' << dp[i][j] << endl;
    //   }
    // }

    lli sum = 0;
    for (int i = 0; i < M; ++i) {
      sum += dp[n+10][i];
      sum %= mod;
    }
    cout << (sum - 1 + mod) % mod << endl;
  }

  return 0;
}
