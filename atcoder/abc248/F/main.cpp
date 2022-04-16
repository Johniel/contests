// atcoder/abc248/F/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  lli mod;
  while (cin >> n >> mod) {
    --n;
    const int N = 3000 + 10;
    static lli dp[N][N][2];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][2 - 1] + 1, 0);
    dp[0][0][true] = 1;
    dp[0][1][false] = 1;
    for (int i = 0; i < n; ++i) {
      for (int del = 0; del <= n+5; ++del) {
        { // connected
          (dp[i + 1][del + 2][false] += dp[i][del][true]) %= mod;
          (dp[i + 1][del + 2][false] += dp[i][del][true]) %= mod;
          (dp[i + 1][del + 1][true] += dp[i][del][true]) %= mod;
          (dp[i + 1][del + 1][true] += dp[i][del][true]) %= mod;
          (dp[i + 1][del + 1][true] += dp[i][del][true]) %= mod;
          (dp[i + 1][del + 0][true] += dp[i][del][true]) %= mod;
        }
        { // not connected
          (dp[i + 1][del + 1][false] += dp[i][del][false]) %= mod;
          (dp[i + 1][del + 0][true] += dp[i][del][false]) %= mod;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      unless (dp[n][i][true]) break;
      cout << dp[n][i][true] << ' ';
    }
    cout << endl;
  }

  return 0;
}
