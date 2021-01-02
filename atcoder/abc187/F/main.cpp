// atcoder/abc187/F/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    int g[n];
    fill(g, g + n, 0);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a] |= (1 << b);
      g[b] |= (1 << a);
    }

    const int N = 18 + 1;
    const int BIT = (1 << N) + 2;
    static int dp[BIT];
    fill(dp, dp + BIT, (1 << 29));
    dp[0] = 1;

    for (int bit = 0; bit < (1 << n); ++bit) {
      if (dp[bit] != 1) continue;
      for (int i = 0; i < n; ++i) {
        if ((g[i] & bit) == bit) {
          dp[bit | (1 << i)] = 1;
        }
      }
    }
    int mn = 1 << 29;
    for (int bit = 0; bit < (1 << n); ++bit) {
      for (int i = bit - 1; i; i = (i - 1) & bit) {
        setmin(dp[bit], dp[bit ^ i] + dp[i]);
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }

  return 0;
}
