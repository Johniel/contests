// atcoder/abc215/E/main.cpp
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

  int n;
  str s;
  while (cin >> n >> s) {
    const int M = 12;
    const int N = 1000 + 2;
    const int BIT = (1 << M);

    vec<int> v;
    each (c, s) v.push_back(c - 'A');

    static lli dp[N][BIT][M];
    fill(&dp[0][0][0], &dp[N - 1][BIT - 1][M - 1] + 1, 0);
    dp[0][0][M - 1] = 1;
    for (int i = 0; i < v.size(); ++i) {
      for (int bit = 0; bit < BIT; ++bit) {
        for (int j = 0; j < M; ++j) {
          unless (dp[i][bit][j]) continue;
          if (v[i] == j) {
            (dp[i + 1][bit][j] += dp[i][bit][j]) %= mod;
          } else {
            int b = bit | (1 << v[i]);
            if (b != bit) {
              (dp[i + 1][b][v[i]] += dp[i][bit][j]) %= mod;
            }
          }
          (dp[i + 1][bit][j] += dp[i][bit][j]) %= mod;
        }
      }
    }

    lli x = 0;
    for (int bit = 1; bit < BIT; ++bit) {
      for (int j = 0; j < M; ++j) {
        (x += dp[s.size()][bit][j]) %= mod;
      }
    }
    cout << x << endl;
  }


  return 0;
}
