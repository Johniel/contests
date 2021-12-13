// codeforces/748div3/B/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <complex>
#include <array>

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

  const int N = 20;
  const int R = 25;
  static int dp[N][R];
  str s;
  while (cin >> s) {
    const int inf = 1 << 29;
    fill(&dp[0][0], &dp[N - 1][R - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int k = 0; k < 25; ++k) {
        // 消す
        setmin(dp[i + 1][k], dp[i][k] + 1);
        // 残す
        setmin(dp[i + 1][(k * 10 + (s[i] - '0')) % 25], dp[i][k]);
      }
    }
    cout << dp[s.size()][0] << endl;
  }

  return 0;
}
