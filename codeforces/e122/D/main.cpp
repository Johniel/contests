// codeforces/e122/D/main.cpp
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

  int _;
  cin >> _;

  const int N = 10000 + 3;
  static int cost[N];
  const int int29 = 1 << 29;
  fill(cost, cost + N, int29);
  cost[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i && i + i / j < N; ++j) {
      setmin(cost[i + i / j], cost[i] + 1);
    }
  }
  int n, k;
  while (cin >> n >> k) {
    vec<lli> b(n), c(n);
    cin >> b >> c;
    const int M = 13 * N;
    static lli dp[2][M];
    const lli inf = 1LL << 60;
    // fill(&dp[0][0], &dp[N - 1][M - 1] + 1, -inf);
    fill(&dp[0][0], &dp[2 - 1][M - 1] + 1, -inf);
    dp[0][0] = 0;
    for (int i = 0; i < b.size(); ++i) {
      const int curr = i % 2;
      const int next = (i + 1) % 2;
      for (int j = 0; j < M; ++j) {
        setmax(dp[next][j], dp[curr][j]);
      }
      for (int j = 0; j + cost[b[i]] < M; ++j) {
        setmax(dp[next][j + cost[b[i]]], dp[curr][j] + c[i]);
      }
    }
    lli mx = -inf;
    for (int i = 0; i <= k && i < M; ++i) {
      setmax(mx, dp[b.size() % 2][i]);
    }
    if (mx == -inf) mx = 0;
    cout << mx << endl;
  }

  return 0;
}
