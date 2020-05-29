// atcoder/code-festival-2016-quala/D/main.cpp
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

  str s;
  int k;
  while (cin >> s >> k) {
    vec<lli> v(s.begin(), s.end());
    each (i, v) i -= '0';

    const lli inf = 1LL << 58;
    const int N = 15 + 3;
    const int BIT = 1 << 10;
    static lli dp[N][BIT][3];
    fill(&dp[0][0][0], &dp[N - 1][BIT - 1][3 - 1] + 1, inf);
    dp[0][0][0] = 0;

    for (int i = 0; i < v.size(); ++i) {
      for (int bit = 0; bit < BIT; ++bit) {
        setmin(dp[i][bit][0], inf);
        setmin(dp[i][bit][1], inf);
        setmin(dp[i][bit][2], inf);

        if (k < __builtin_popcount(bit)) continue;
        for (int j = 0; j < 10; ++j) {
          int b = bit | (1 << j);
          if (j == 0 && bit == 0) b = 0;
          if (k < __builtin_popcount(b)) continue;

          if (v[i] == j) {
            setmin(dp[i + 1][b][0], dp[i][bit][0] * 10LL);
            setmin(dp[i + 1][b][1], dp[i][bit][1] * 10LL);
            setmin(dp[i + 1][b][2], dp[i][bit][2] * 10LL);
          }
          if (j < v[i]) {
            setmin(dp[i + 1][b][1], dp[i][bit][0] * 10LL + abs(v[i] - j));
          }
          if (v[i] < j) {
            setmin(dp[i + 1][b][2], dp[i][bit][0] * 10LL + abs(v[i] - j));
          }
          setmin(dp[i + 1][b][1], dp[i][bit][1] * 10LL + v[i] - j);
          setmin(dp[i + 1][b][2], dp[i][bit][2] * 10LL + j - v[i]);
        }
      }
    }

    lli mn = inf;
    for (int bit = 0; bit < BIT; ++bit) {
      setmin(mn, dp[v.size()][bit][0]);
      setmin(mn, dp[v.size()][bit][1]);
      setmin(mn, dp[v.size()][bit][2]);
    }
    cout << mn << endl;
  }

  return 0;
}
