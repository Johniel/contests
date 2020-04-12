// atcoder/abc162/F/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    if (n == 2) {
      cout << max(a[0], a[1]) << endl;
      continue;
    }

    // for (int bit = 0; bit < (1 << n); ++bit) {
    //   if (__builtin_popcount(bit) == (n / 2)) {
    //     lli sum = 0;
    //     vec<lli> v;
    //     for (int i = 0; i < n; ++i) {
    //       const int j = i + 1;
    //       if (bit & (1 << i)) {
    //         if (bit & (1 << j)) sum = -(1LL << 60);
    //         else {
    //           v.push_back(a[i]);
    //           sum += a[i];
    //         }
    //       }
    //     }
    //     if (sum == 295) {
    //       cout << v << ", " << sum << endl;
    //       break;
    //     }
    //   }
    // }

    lli x = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2) x += a[i];
    }

    const lli inf = 1LL << 60;
    const int N = 2 * 1e5 + 5;
    static lli dp[N][3];
    fill(&dp[0][0], &dp[N - 1][3 - 1] + 1, -inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      setmax(dp[i + 2][2], dp[i][2] + a[i]);
      setmax(dp[i + 2][1], dp[i][1] + a[i]);
      setmax(dp[i + 2][0], dp[i][0] + a[i]);

      if (n % 2) {
        setmax(dp[i + 2][1], dp[i][0]);
        setmax(dp[i + 1][2], dp[i][0]);
        setmax(dp[i + 1][1], dp[i][2]);
      } else {
        setmax(dp[i + 1][1], dp[i][0]);
      }
    }

    setmax(x, dp[n][1]);
    setmax(x, dp[n+1][1]);
    setmax(x, dp[n][2]);

    // for (int i = 0; i <= n+1; ++i) {
    //   if (dp[i][0] != -inf) cout << dp[i][0] <<  ' ';
    //   else  cout << "_ ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n+1; ++i) {
    //   if (dp[i][1] != -inf) cout << dp[i][1] <<  ' ';
    //   else  cout << "_ ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n+1; ++i) {
    //   if (dp[i][2] != -inf) cout << dp[i][2] <<  ' ';
    //   else  cout << "_ ";
    // }
    // cout << endl;


    cout << x << endl;

  }

  return 0;
}
