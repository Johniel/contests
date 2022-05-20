// yukicoder/1948/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    const int H = 500 + 3;
    const int W = 500 + 3;
    const int K = 2;
    static lli dp[K][H][W];
    const lli inf = 1LL << 60;
    fill(&dp[0][0][0], &dp[K - 1][H - 1][W - 1] + 1, -inf);
    static lli a[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
      }
    }
    dp[0][0][0] = a[0][0];
    a[0][0] = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; k < K; ++k) {
          if (dp[k][i][j] > a[i][j]) {
            setmax(dp[k][i + 1][j], dp[k][i][j] + a[i][j]);
            setmax(dp[k][i][j + 1], dp[k][i][j] + a[i][j]);
          } else if (k == 0) {
            setmax(dp[k + 1][i + 1][j], dp[k][i][j]);
            setmax(dp[k + 1][i][j + 1], dp[k][i][j]);
          }
        }
      }
    }
    cout << (max(dp[0][h - 1][w - 1], dp[1][h - 1][w - 1]) > a[h - 1][w - 1] ? "Yes" : "No") << endl;
  }

  return 0;
}
