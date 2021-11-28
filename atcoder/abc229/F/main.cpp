// atcoder/abc229/F/main.cpp
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
    vec<lli> a(n), b(n);
    cin >> a >> b;

    const int N = 2 * 1e5 + 3;
    const int K = 3;
    const lli inf = 1LL << 60;
    static lli dp[N][K][K];
    // dp[どこまで見た][iの色][1の色]
    fill(&dp[0][0][0], &dp[N - 1][K - 1][K - 1] + 1, -inf);
    dp[0][2][2] = 0;

    // 0: 0thと同じ色
    // 1: 0thと反対の色
    // 2: 未確定

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 2; ++j) {
        const int p = (j == 2 ? (i + 1) % 2 : j);
        // aだけ
        setmax(dp[i + 1][2][p], dp[i][1][j] + a[i]);
        setmax(dp[i + 1][2][p], dp[i][2][j] + a[i]);

        if (i + 1 == n) {
          // bだけ
          setmax(dp[i + 1][0][0], dp[i][1][0] + b[i]);
          setmax(dp[i + 1][1][1], dp[i][0][1] + b[i]);
          // aとb
          setmax(dp[i + 1][0][0], dp[i][1][0] + a[i] + b[i]);
          setmax(dp[i + 1][0][0], dp[i][2][0] + a[i] + b[i]);
          unless (n % 2) {
            setmax(dp[i + 1][0][0], dp[i][1][2] + a[i] + b[i]);
            setmax(dp[i + 1][0][0], dp[i][2][2] + a[i] + b[i]);
          }
        } else {
          // bだけ
          setmax(dp[i + 1][0][j], dp[i][1][j] + b[i]);
          setmax(dp[i + 1][1][j], dp[i][0][j] + b[i]);
          setmax(dp[i + 1][2][j], dp[i][2][j] + b[i]);
          // aとb
          setmax(dp[i + 1][0][p], dp[i][1][j] + a[i] + b[i]);
          setmax(dp[i + 1][0][p], dp[i][2][j] + a[i] + b[i]);
        }

        if (j != 2) {
          setmax(dp[i + 1][2][j], dp[i][0][j]);
          setmax(dp[i + 1][2][j], dp[i][1][j]);
        }
        if (i == 0) setmax(dp[i + 1][2][j], dp[i][2][j]);
      }
    }

    lli mx = -inf;
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        setmax(mx, dp[n][i][j]);
      }
    }
    lli z = accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL);
    cout << z -  mx << endl;
  }

  return 0;
}
