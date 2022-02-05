// atcoder/abc238/F/main.cpp
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
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, x;
  while (cin >> n >> x) {
    vec<int> p(n), q(n);
    cin >> p >> q;
    each (i, p) --i;
    each (i, q) --i;
    vec<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    sort(v.begin(), v.end(), [&] (auto i, auto j) { return p[i] < p[j]; });
    const int N = 300 + 3;
    static lli dp[N][N][N]; // [どこまで見た][いくつ選択した][最大値]
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, 0);
    dp[0][0][N - 1] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= x; ++j) {
        for (int k = 0; k < N; ++k) {
          unless (dp[i][j][k]) continue;
          (dp[i + 1][j][min(k, q[v[i]])] += dp[i][j][k]) %= mod;
          if (j + 1 <= x && k > q[v[i]]) {
            (dp[i + 1][j + 1][k] += dp[i][j][k]) %= mod;
          }
        }
      }
    }
    lli z = 0;
    for (int i = 0; i < N; ++i) {
      (z += dp[n][x][i]) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
