// atcoder/code-festival-2014-morning-middle/D/main.cpp
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
    vec<pair<lli, lli>> v(n);
    cin >> v;

    each (i, v) {
      i.first -= i.second;
      i.second *= 2;
    }

    lli mn = 1LL << 60;
    each (i, v) setmin(mn, i.first);
    each (i, v) i.first -= mn;

    const int N = 1000 + 5;
    const int M = 2000 + 5;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    for (int i = 0; i <= v[0].second; ++i) {
      dp[0][i] = 1;
    }

    for (int i = 1; i < n; ++i) {
      int k = 0;
      lli sum = 0;
      for (; k <= v[i - 1].second; ++k) {
        unless (v[i - 1].first + k < v[i].first) break;
        (sum += dp[i - 1][k]) %= mod;
      }
      for (int j = 0; j <= v[i].second; ++j) {
        (dp[i][j] += sum) %= mod;
        if (v[i - 1].first + k <= v[i].first + j) {
          (sum += dp[i - 1][min(k++, M - 1)]) %= mod;
        }
      }
    }

    lli sum = 0;
    for (int i = 0; i < M; ++i) {
      (sum += dp[n - 1][i]) %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
