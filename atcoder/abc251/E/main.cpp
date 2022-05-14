// atcoder/abc251/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    const lli inf = 1LL << 62;

    lli mn = inf;

    const int M = 2;
    static lli dp[2][M][M];
    fill(&dp[0][0][0], &dp[2 - 1][M - 1][M - 1] + 1, inf);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      const int curr = i % 2;
      const int next = (i + 1) % 2;
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          dp[next][j][k] = inf;
        }
      }
      setmin(dp[next][0][1], dp[curr][0][0] + a[i]);
      setmin(dp[next][0][0], dp[curr][0][1]);
      setmin(dp[next][0][1], dp[curr][0][1] + a[i]);
      // cout << i << "th " << dp[next][0][0] << ' ' << dp[next][0][1] << endl;
    }
    mn = min(dp[(n - 1) % 2][0][1], dp[n % 2][0][1]);

    fill(&dp[0][0][0], &dp[2 - 1][M - 1][M - 1] + 1, inf);
    dp[0][0][1] = a.back();
    for (int i = 0; i < n; ++i) {
      const int curr = i % 2;
      const int next = (i + 1) % 2;
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          dp[next][j][k] = inf;
        }
      }
      setmin(dp[next][0][1], dp[curr][0][0] + a[i]);
      setmin(dp[next][0][0], dp[curr][0][1]);
      setmin(dp[next][0][1], dp[curr][0][1] + a[i]);
      // cout << i+1 << "th " << dp[next][0][0] << ' ' << dp[next][0][1] << endl;
    }
    setmin(mn, dp[(n - 1) % 2][0][0]);
    setmin(mn, dp[(n - 1) % 2][0][1]);
    cout << mn << endl;
  }

  return 0;
}
