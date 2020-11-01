// atcoder/abc180/E/main.cpp
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
    lli x[n];
    lli y[n];
    lli z[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> z[i];
    }
    const int N = 18;
    const int BIT = 1 << N;
    static lli dp[BIT][N];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[BIT - 1][N - 1] + 1, inf);
    dp[1 << 0][0] = 0;
    for (int bit = 0; bit < BIT; ++bit) {
      for (int i = 0; i < n; ++i) {
        unless (bit & (1 << i)) continue;
        for (int j = 0; j < n; ++j) {
          lli cost = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0LL, z[j] - z[i]);
          setmin(dp[bit | (1 << j)][j], dp[bit][i] + cost);
        }
      }
    }
    lli mn = inf;
    for (int i = 0; i < n; ++i) {
      lli cost = abs(x[i] - x[0]) + abs(y[i] - y[0]) + max(0LL, z[0] - z[i]);
      if (i == 0) cost = 0;
      setmin(mn, dp[(1 << n) - 1][i] + cost);
    }
    cout << mn << endl;
  }

  return 0;
}
