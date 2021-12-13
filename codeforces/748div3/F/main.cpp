// codeforces/748div3/F/main.cpp
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

  int n, a, b;
  str s;
  while (cin >> n >> a >> b >> s) {
    const int N = 40 + 2;
    const int A = 40 + 1;
    const int B = 40 + 1;
    static bool dp[N][N][A][B];
    static vec<int> pa[N][N][A][B];
    fill(&dp[0][0][0][0], &dp[N - 1][N - 1][A - 1][B - 1] + 1, false);
    fill(&pa[0][0][0][0], &pa[N - 1][N - 1][A - 1][B - 1] + 1, vec<int>());
    dp[0][0][0][0] = true;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < s.size(); ++j) {
        for (int x = 0; x < a; ++x) {
          for (int y = 0; y < b; ++y) {
            unless (dp[i][j][x][y]) continue;

            int x2 = (x * 10 + s[i] - '0') % a;
            dp[i + 1][j + 1][x2][y] = true;
            pa[i + 1][j + 1][x2][y] = {j, x, y};

            int y2 = (y * 10 + s[i] - '0') % b;
            dp[i + 1][j][x][y2] = true;
            pa[i + 1][j][x][y2] = {j, x, y};
          }
        }
      }
    }
    const int inf = 1 << 29;
    pair<int, int> mn = {inf, inf};
    for (int j = 1; j < n; ++j) {
      if (dp[n][j][0][0]) {
        setmin(mn, {abs((n / 2) - j), j});
      }
    }
    if (mn.first == inf) {
      cout << -1 << endl;
      continue;
    }
    int i = n;
    int j = mn.second;
    int x = 0;
    int y = 0;
    str t;
    while (0 < i) {
      assert(dp[i][j][x][y]);
      auto tmp = pa[i][j][x][y];
      if (tmp[0] != j) t += 'R';
      else t += 'B';
      if (tmp.empty()) break;
      --i;
      j = tmp[0];
      x = tmp[1];
      y = tmp[2];
    }
    reverse(t.begin(), t.end());
    cout << t << endl;
  }

  return 0;
}
