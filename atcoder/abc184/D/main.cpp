// atcoder/abc184/D/main.cpp
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

  int a, b, c;
  while (cin >> a >> b >> c) {
    const int N = 100 + 5;
    static long double dp[N][N][N];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, 0);
    dp[a][b][c] = 1;

    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        for (int k = 0; k < 100; ++k) {
          if (i + j + k == 0) continue;
          dp[i + 1][j][k] += dp[i][j][k] * (long double)i / (long double)(i + j + k);
          dp[i][j + 1][k] += dp[i][j][k] * (long double)j / (long double)(i + j + k);
          dp[i][j][k + 1] += dp[i][j][k] * (long double)k / (long double)(i + j + k);
        }
      }
    }

    long double x = 0;
    for (int i = a; i < 100; ++i) {
      for (int j = b; j < 100; ++j) {
        const int k = 100;
        long double y = (i - a) + (j - b) + (k - c);
        x += dp[i][j][k] * y;
      }
    }
    for (int i = a; i < 100; ++i) {
      for (int k = c; k < 100; ++k) {
        const int j = 100;
        long double y = (i - a) + (j - b) + (k - c);
        x += dp[i][j][k] * y;
      }
    }
    for (int j = b; j < 100; ++j) {
      for (int k = c; k < 100; ++k) {
        const int i = 100;
        long double y = (i - a) + (j - b) + (k - c);
        x += dp[i][j][k] * y;
      }
    }
    cout << x << endl;
  }

  return 0;
}
