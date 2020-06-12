// atcoder/yahoo-procon/2019-qual/D/main.cpp
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
    vec<lli> a(n);
    cin >> a;

    const int N = 2 * 1e5 + 5;
    static lli dp[N][5];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][5 - 1] + 1, inf);
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
      {
        setmin(dp[i + 1][0], dp[i][0] + a[i]);
      }

      {
        lli x = (a[i] == 0) ? 2 : (a[i] % 2);
        setmin(dp[i + 1][1], dp[i][0] + x);
        setmin(dp[i + 1][1], dp[i][1] + x);
      }

      {
        lli x = (a[i] == 0) ? 1 : !(a[i] % 2);
        setmin(dp[i + 1][2], dp[i][0] + x);
        setmin(dp[i + 1][2], dp[i][1] + x);
        setmin(dp[i + 1][2], dp[i][2] + x);
      }

      {
        lli x = (a[i] == 0) ? 2 : (a[i] % 2);
        setmin(dp[i + 1][3], dp[i][0] + x);
        setmin(dp[i + 1][3], dp[i][1] + x);
        setmin(dp[i + 1][3], dp[i][2] + x);
        setmin(dp[i + 1][3], dp[i][3] + x);
      }

      {
        lli x = a[i];
        setmin(dp[i + 1][4], dp[i][0] + x);
        setmin(dp[i + 1][4], dp[i][1] + x);
        setmin(dp[i + 1][4], dp[i][2] + x);
        setmin(dp[i + 1][4], dp[i][3] + x);
        setmin(dp[i + 1][4], dp[i][4] + x);
      }
    }

    lli mn = inf;
    setmin(mn, dp[n][0]);
    setmin(mn, dp[n][1]);
    setmin(mn, dp[n][2]);
    setmin(mn, dp[n][3]);
    setmin(mn, dp[n][4]);
    cout << mn << endl;
  }

  return 0;
}
