// atcoder/keyence2020/D/main.cpp
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
    vec<int> a(n), b(n);
    cin >> a >> b;

    const int N = 18;
    const int BIT = 1 << N;
    const int M = 50 + 2;
    static int dp[BIT][M];
    const int inf = 1 << 29;
    fill(&dp[0][0], &dp[BIT - 1][M - 1] + 1, inf);
    dp[0][0] = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      const int nth = __builtin_popcount(bit);
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) continue;
        int cost = 0;
        for (int j = 0; j <= i; ++j) {
          if (j == i) continue;
          unless (bit & (1 << j)) ++cost;
        }
        // cout << bit << ": " << i << "->" << nth << ", "<< cost << endl;
        for (int j = 0; j < M; ++j) {
          if (abs(nth - i) % 2) {
            if (j <= b[i]) {
              setmin(dp[bit | (1 << i)][b[i]], dp[bit][j] + cost);
            }
          } else {
            if (j <= a[i]) {
              setmin(dp[bit | (1 << i)][a[i]], dp[bit][j] + cost);
            }
          }
        }
      }
    }
    int mn = inf;
    for (int i = 0; i < M; ++i) {
      setmin(mn, dp[(1 << n) - 1][i]);
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
