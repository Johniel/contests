// atcoder/abc164/D/main.cpp
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

  // for (int i = 1; i < 60; ++i) {
  //   cout << i * 2019 << endl;
  // }

  str s;
  while (cin >> s) {
    lli sum = 0;
    const int M = 2019;
    const int N = 2;
    const lli K = 2;
    static int dp[2][M][K];
    fill(&dp[0][0][0], &dp[N - 1][M - 1][K - 1] + 1, 0);
    dp[0][0][false] = 1;
    for (int i = 0; i < s.size(); ++i) {
      int curr = i % 2;
      int next = (curr + 1) % 2;
      for (int j = 0; j < M; ++j) {
        dp[next][j][false] = dp[next][j][true] = 0;
      }
      for (int j = 0; j < M; ++j) {
        {
          dp[next][(j * 10 + s[i] - '0') % M][true] += dp[curr][j][true];
        }
        {
          dp[next][j][false] += dp[curr][j][false];
        }
        {
          dp[next][(j * 10 + s[i] - '0') % M][true] += dp[curr][j][false];
        }
      }
      sum += dp[next][0][true];
    }
    cout << sum << endl;
  }


  return 0;
}
